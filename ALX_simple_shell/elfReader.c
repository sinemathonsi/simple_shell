#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <unistd.h>
#include <fcntl.h>

#define ei e_ident

int is_Elf(Elf64_Ehdr *h, char *file)
{
	if (h->ei[0] != 127 || h->ei[1] != 69 || h->ei[2] != 76 || h->ei[3] != 70)
	{
		dprintf(2, "%s is not an ELF file\n", file);
		exit(98);
	}
	return (0);
}

void print_e_ident(Elf64_Ehdr *h)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x ", h->ei[i]);
	}
	printf("\n");
}

void print_class(Elf64_Ehdr *h)
{
	printf("  Class:                        "); // 24
	switch (h->ei[4])
	{
	case 0:
		printf("     Invalid Class\n");
		break;
	case 1:
		printf("     ELF32\n");
		break;
	case 2:
		printf("     ELF64\n");
	}
}

void print_data(Elf64_Ehdr *h)
{
	printf("  Data:                        "); // 24/30
	switch (h->ei[5])
	{
	case 0:
		printf("      Invalid data encoding\n");
		break;
	case 1:
		printf("      2's complement, little endian\n");
		break;
	case 2:
		printf("      2's complement, big endian\n");
		break;
	}
}

void print_version(Elf64_Ehdr *h)
{
	printf("  Version:                    "); // 20/27
	switch (h->ei[6])
	{
	case 0:
		printf("       Invalid version\n");
		break;
	default:
		printf("       %d (current)\n", h->ei[6]);
		break;
	}
}

void print_osabi(Elf64_Ehdr *h)
{
	printf("  OS/ABI:                    "); // 20/28
	switch (h->ei[7])
	{
	case ELFOSABI_SYSV:
		printf("        UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("        HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("        NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("        Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("        Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("        IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("        FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("        TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("        ARM architecture\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("        Stand-alone (embedded)\n");
		break;
	}
}

void print_abi_version(Elf64_Ehdr *h)
{
	printf("  ABI Version:                       %d\n", h->ei[8]);
}

void print_type(Elf64_Ehdr *h)
{
	printf("  Type:                         "); // 25/30
	switch (h->e_type)
	{
	case ET_NONE:
		printf("     NONE (Unknown file type)\n");
		break;
	case ET_REL:
		printf("     REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("     EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("     DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("     CORE (Core file)\n");
		break;
	}
}

void print_entry_addr(Elf64_Ehdr *h)
{
	printf("  Entry point address:               0x%lx\n", h->e_entry); // 12/15
}

int main(int ac, char **argv)
{
	int o, r, i;
	Elf64_Ehdr my_elf64;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		perror("Open-error");
		return (1);
	}

	r = read(o, &my_elf64, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		perror("Read-error");
		return (2);
	}
	is_Elf(&my_elf64, argv[1]);
	printf("Elf Header:\n");
	print_e_ident(&my_elf64);
	print_class(&my_elf64);
	print_data(&my_elf64);
	print_version(&my_elf64);
	print_osabi(&my_elf64);
	print_abi_version(&my_elf64);
	print_type(&my_elf64);
	print_entry_addr(&my_elf64);

	return (0);
}
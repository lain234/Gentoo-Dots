cmd_fs/efivarfs/efivarfs.o := ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o fs/efivarfs/efivarfs.o @fs/efivarfs/efivarfs.mod 

cmd_/home/embedded/clab/ldd/kernel/main.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id  -T ./scripts/module-common.lds -o /home/embedded/clab/ldd/kernel/main.ko /home/embedded/clab/ldd/kernel/main.o /home/embedded/clab/ldd/kernel/main.mod.o;  true
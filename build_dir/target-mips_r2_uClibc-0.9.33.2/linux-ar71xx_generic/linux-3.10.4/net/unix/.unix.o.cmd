cmd_net/unix/unix.o := mips-openwrt-linux-uclibc-ld  -m elf32btsmip   -r -o net/unix/unix.o net/unix/af_unix.o net/unix/garbage.o net/unix/sysctl_net_unix.o 

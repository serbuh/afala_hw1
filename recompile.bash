echo Copying...
cp Makefile fork.c exit.c count_sons.c /usr/src/linux-2.4.18-14custom/kernel/
cp sched.h /usr/src/linux-2.4.18-14custom/include/linux/
cp entry.S /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
echo Recompiling...
cd /usr/src/linux-2.4.18-14custom
make bzImage
echo Replacing boot
cd arch/i386/boot
cp bzImage /boot/vmlinuz-2.4.18-14custom
echo Done. You can reboot now.
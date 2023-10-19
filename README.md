das U-Boot for FriendlyArm mini210
---
19.10.23 polprog

This is the experimental U-Boot 2016.11 source tree based on the SourceLink port. The original readme is in the README file.

I've finished it up to the point of U-Boot shell booting. Linux booting is not tested yet.

Build instructions

Source environment:

    export PATH=/opt/FriendlyARM/toolschain/4.5.1/bin/:$PATH

Build u-boot

    make mini210_defconfig
	make -j`nproc`
	
Install to SD card:

     sudo dd if=u-boot-all.bin of=/dev/sdX seek=1

Switch S2 to "SDBOOT" position, insert the card into the slot. Attach a serial cable to the DB9 connector. Baudrate is 115200. 3v3-level console is available on CON1. 

The SPL has an infinite loop placed just before jumping to BL2. This is to allow for debugger attach, as S5PV210 powers JTAG down on reset.

Once you attach, inspect the instructions in $pc and resume at the next instruction after the loop:

    0xd0020124 in ?? ()
    (gdb) x/3i $pc
    => 0xd0020124:	b	0xd0020124
       0xd0020128:	mov	pc, #536870912	; 0x20000000
       0xd002012c:	mov	r9, lr
    (gdb) mon resume 0xd0020128
    (gdb) 
    
    
    

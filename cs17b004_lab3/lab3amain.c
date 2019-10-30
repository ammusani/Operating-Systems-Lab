/*  main.c  - main */

#include <xinu.h>

p1() {
	while(TRUE) {
		//kprintf("a");
	}
}

p2() {
	while(TRUE) {
		//kprintf("b");
	}
}

p3() {
	while(TRUE) {
		//kprintf("c");
	}
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */
	
	resume(create(p1, 4096, 20, "p1", 0, CONSOLE));
	resume(create(p2, 4096, 20, "p2", 0, CONSOLE));
	resume(create(p3, 4096, 20, "p3", 0, CONSOLE));
	
	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}

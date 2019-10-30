/*  main.c  - main */

#include <xinu.h>
int n = 0;

prA() {
	int i = 0;
	while(i < 10) {
		n += 1;
		i++;
		kprintf("%d\n", n);
	}
	return 0;
}

prB() {
	int i = 0;
	while(i < 10) {
		n -= 1;
		i++;
		kprintf("%d\n", n);
	}
	return 0;
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	
	int prA();
	int prB();
	resume(create(prA, 4096, 20, "shell", 0, CONSOLE));
	resume(create(prB, 4096, 20, "shell", 0, CONSOLE));
	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}

/*  main.c  - main */

#include <xinu.h>

prA() {
	kprintf("Process-A\n");
	return 0;
}
prB() {
	kprintf("Process-B\n");
	return 0;
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 20, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	int prA();
	int prB();
	resume(create(prA, 1024, 20, "prA", 0, CONSOLE));
	resume(create(prB, 1024, 20, "prB", 0, CONSOLE));
	
	return OK;
    
}

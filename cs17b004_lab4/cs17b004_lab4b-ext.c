/*  main.c  - main */

#include <xinu.h>
int n = 0;

prA(sem1) {
	int i = 0;
	
	while(i < 10) {
		wait(sem1);	
		n += 1;
		kprintf("%d\n", n);
		signal(sem1);
		i++;
	}
	
	return 0;
}

prB(sem1) {
	int i = 0;
	
	while(i < 10) {
		wait(sem1);	
		n -= 1;		
		kprintf("%d\n", n);
		signal(sem1);	
		i++;
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
	int sem1 = semcreate(1);
	resume(create(prA, 4096, 20, "shell", 1, sem1));
	resume(create(prB, 4096, 20, "shell", 1, sem1));
	/* Wait for shell to exit and recreate it */
	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	
	return OK;
    
}

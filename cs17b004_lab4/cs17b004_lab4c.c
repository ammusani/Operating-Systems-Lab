/*  main.c  - main */

#include <xinu.h>
int n = 0;
int sem1;
int sem2;

prA() {
	int i = 0;
	wait(sem2);
	while(i < 10) {
		wait(sem1);	
		n += 1;
		kprintf("%d\n", n);
		signal(sem2);
		i++;
	}
	signal(sem1);
	
	return 0;
}

prB() {
	int i = 0;
	
	while(i < 10) {
		wait(sem1);
		wait(sem2);	
		n -= 1;		
		kprintf("%d\n", n);
		signal(sem1);
		signal(sem2);	
		i++;
	}
	
	return 0;
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	sem1 = semcreate(1);
	sem2 = semcreate(1);	
	int prA();
	int prB();
	resume(create(prA, 4096, 20, "pra", 0));
	resume(create(prB, 4096, 20, "prb", 0));
	/* Wait for shell to exit and recreate it */
	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	
	return OK;
    
}

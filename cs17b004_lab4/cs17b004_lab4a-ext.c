/*  main.c  - main */

#include <xinu.h>

prA(A, B) {
	int i;
	wait(B);
	for(i = 0; i < 5; i++) kprintf("Process-A\n");
	signal(A);
	return 0;
}
prB(A, B) {
	int i;	
	wait(A);	
	for(i = 0; i < 5; i++) kprintf("Process-B\n");
	signal(B);
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
	int A;
	int B;
	A = 0;
	B = 1;
	resume(create(prA, 1024, 20, "prA", 2, A, B));
	resume(create(prB, 1024, 20, "prB", 2, A, B));
	
	return OK;
    
}

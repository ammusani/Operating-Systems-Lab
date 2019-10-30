/*  main.c  - main */

#include <xinu.h>

struct lock {
	int held;
};


void acquire(struct lock *A) {
	while(A -> held);
	A -> held = 1;
}

int critical = 0;

void release(struct lock *A) {
	A -> held = 0;
}

prA(struct lock *A) {
	int a = 10;
	int i;
	while(a--){
		i = 1000000;
		acquire(A);
		critical++;
		kprintf("%d\n", critical);
		release(A);
		while(i--);
	}
	return 0;
}

prB(struct lock *A) {
	int a = 10;
	int i;
	while(a--){
		i = 1000000;
		acquire(A);
		critical--;
		kprintf("%d\n", critical);
		release(A);
		while(i--);
	}
	return 0;
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	
	struct lock A = {0};
	

	/* Wait for shell to exit and recreate it */
	resume(create(prA, 1024, 20, "prA", 1, &A));
	resume(create(prB, 1024, 20, "prB", 1, &A));

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	
	return OK;
    
}

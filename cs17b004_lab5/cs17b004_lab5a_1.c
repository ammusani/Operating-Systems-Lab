/*  main.c  - main */

#include <xinu.h>

struct lock {
	int held;
};


void acquire(struct lock *A) {
	while(A -> held);
	A -> held = 1;
}

void release(struct lock *A) {
	A -> held = 0;
}

prA(struct lock *A, struct lock *B) {
	int a = 10;
	while(a--){
		acquire(A);
		kprintf("Process 1\n");
		release(B);
	}
	return 0;
}

prB(struct lock *A, struct lock *B) {
	int a = 10;
	while(a--){
		acquire(B);
		kprintf("Process 2\n");
		release(A);
	}
	return 0;
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	
	struct lock A = {0};
	struct lock B = {1};

	/* Wait for shell to exit and recreate it */
	resume(create(prA, 1024, 20, "prA", 2, &A, &B));
	resume(create(prB, 1024, 20, "prB", 2, &A, &B));

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	
	return OK;
    
}

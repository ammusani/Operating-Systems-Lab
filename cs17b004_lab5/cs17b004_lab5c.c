/*  main.c  - main */

#include <xinu.h>
int sem[5];

p1() {
	while(1){
		wait(sem[0]);
		kprintf("1t\n");
		signal(sem[0]);
		wait(sem[0]);
		wait(sem[1]);
		kprintf("1e\n");
		signal(sem[0]);
		signal(sem[1]);
	}
	return 0;
}

p2() {
	while(1){
		wait(sem[1]);
		kprintf("2t\n");
		signal(sem[1]);
		wait(sem[2]);
		wait(sem[1]);
		kprintf("2e\n");
		signal(sem[1]);
		signal(sem[2]);
	}
	return 0;
}

p3() {
	while(1){
		wait(sem[2]);
		kprintf("3t\n");
		wait(sem[2]);
		signal(sem[2]);
		wait(sem[3]);
		kprintf("3e\n");
		signal(sem[2]);
		signal(sem[3]);
	}
	return 0;
}



p4() {
	while(1){
		wait(sem[3]);
		kprintf("4t\n");
		signal(sem[3]);
		wait(sem[4]);
		wait(sem[3]);
		kprintf("4e\n");
		signal(sem[3]);
		signal(sem[4]);
	}
	return 0;
}

p5() {
	while(1){
		wait(sem[4]);
		kprintf("5t\n");
		signal(sem[4]);
		wait(sem[4]);
		wait(sem[0]);
		kprintf("5e\n");
		signal(sem[4]);
		signal(sem[0]);
	}
	return 0;
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */
	int i;
	for(i = 0; i < 5; i++) sem[i] = semcreate(1);
	int p1();
	int p2();
	int p3();
	int p4();
	int p5();	
	resume(create(p1, 8192, 20, "p1", 1, CONSOLE));
	resume(create(p4, 8192, 20, "p2", 1, CONSOLE));
	resume(create(p3, 8192, 20, "p3", 1, CONSOLE));
	resume(create(p4, 8192, 20, "p4", 1, CONSOLE));
	resume(create(p5, 8192, 20, "p5", 1, CONSOLE));
	return OK;
    
}

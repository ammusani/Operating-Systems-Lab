/*  main.c  - main */

#include <xinu.h>

pid32 pA;
pid32 pB;

process prA() {
	umsg32 msg = "cs17b004";
	send(pB, msg);
	umsg32 msg2 = receive();
	kprintf("");
	kprintf("process B -> process A: %d\n", msg2);
}

process prB() {
	umsg32 msg3 = receive();
	kprintf("");
	kprintf("process A -> process B: %s\n", msg3);
	umsg32 msg4 = rand();
	send(pA, msg4);
}

process	main(void)
{

	/* Run the Xinu shell */

	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */
	pA = create(prA, 2048, 20, "prA", 0);
	pB = create(prB, 2048, 20, "prB", 0);
	resume(pA);
	resume(pB);

	
	return OK;
    
}

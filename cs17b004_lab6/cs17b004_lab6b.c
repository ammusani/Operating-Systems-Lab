/*  main.c  - main */

#include <xinu.h>


pid32 pA;
pid32 pB;


process prA() {
	umsg32 msg = "cs17b004";
	umsg32 msg1 = "HELLO";
	cs17b004send(pB, msg, msg1);
}

process prB() {
	umsg32 msg = cs17b004receive();
	kprintf("msg1: process A -> process B: %s\n", msg);	
	umsg32 msg1 = cs17b004receive();	
	kprintf("msg2: processs A -> process B: %s\n", msg1);	
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

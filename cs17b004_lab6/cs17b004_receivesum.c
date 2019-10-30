/* receive.c - receive */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  receive  -  Wait for a message and return the message to the caller
 *------------------------------------------------------------------------
 */
umsg32	cs17b004_receivesum(void)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	procent *prptr;		/* Ptr to process's table entry	*/
	umsg32	msg;			/* Message to return		*/

	mask = disable();
	prptr = &proctab[currpid];
	if (prptr->prhasmsg == FALSE && prptr->prhasmsg1 == FALSE) {
		prptr->prstate = PR_RECV;
		resched();		/* Block until message arrives	*/
	}
	else {
		msg = (prptr->prmsg1 + prptr->prmsg);
		prptr->prhasmsg = FALSE;
		prptr->prhasmsg1 = FALSE;
	}
	restore(mask);
	return msg;
}

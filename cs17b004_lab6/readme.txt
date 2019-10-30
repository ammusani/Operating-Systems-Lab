#Author: Aliasgar Musani <cs17b004 at iittp dot ac dot in>
#Roll Number: CS17B004
#Course: Operating Systems Lab
#Lab No: 6

Question 1:
	i.	Created two pids.
	ii.	Created two processes.
	iii.	Stored the pid of the processes in the respective variables.
	iv.	Inside both the processes, used send and receive commands to send and receive msgs.

Files created/edited: cs17b004_lab6a.c


Question 2:
	i.	Created two new files with following functions:
			a. cs17b004send.c - To send two msgs at once.
			b. cs17b004receive.c - To receive msg one at a time from the newly created send function.
	ii.	Edited prototype.h to add two new files. Its copy is made, and available with name cs17b004prototype.h in the root folder.
	iii.	Edited process.h to add two new variables in the process structure, one is extra msg and othe is extra flag, its copy is available with name cs17b004process.h
	iv.	Major function of cs17b004_lab6b.c is to send two msgs at a time from prA and received one by one in prB.

Files created/edited: cs17b004_lab6b.c, cs17b004send.c, cs17b004receive.c, protoype.h(available as cs17b004prototype.h in root), process.h(available as cs17b004prototype.h in root).

Question 3:
	i.	Created a file:
			a. cs17b004_receivesum.c - To receive the sum of two numbers send by the cs17b004send.c
	ii. 	Added in prototype.h(available in the same cs17b004prototype.h)
	iii.	Major function of cs17b004_lab6c.c is to send two numbers at a time from prA and receive their sum in prB.

Files created/edited: cs17b004_lab6c.c, cs17b004_receivesum.c, protoype.h(available as cs17b004prototype.h in root).


Note:	i.	prototype.h and process.h copies are made available in root folder as cs17b004prototype.h and cs17b004process.h
	ii.	copies of cs17b004_receivesum.c, cs17b004send.c, cs17b004receive.c are available in root.
	iii.	cs17b004_lab6a.c, cs17b004_lab6b.c, cs17b004_lab6c.c and their respective screenshots are only available in root folder.
	iv. Original main file was put back in the folder.


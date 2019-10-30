Author: Aliasgar Musani <cs17b004 at iittp dot ac dot in>
Course: Operating Systems Lab
Lab: 2

Here's the brief description of the workflow:

1. Made the following changes in 'xinu/system/main.c':
	a. added two processes p1, p2.
	b. added a global variable flag.
	c. the processes transfer the control from one to another through the global flag, flag == 1 will run p2 and flag == 0 will run p1.
	d. Both the processes will print a character.
	e. Added two process calls in the main process which will call both of the processes.
	f. Both processes are successfully printing A & B 5 alternatively.

2. To add my own command:
	a. In 'xinu/shell/shell.c' added a command 
		{"cs17b004", FALSE, xsh_cs17b004}

	b. Created a new file 'xsh_cs17b004.c' in 'xinu/shell', copied the code of xsh_ps.c and added an if condition to print only when process state is "ready".

	c. In 'xinu/include/shprototypes.h' added a command 
		extern shellcmd xsh_cs17b004 (int32, char *[]);

	d. The code was executed and was successfully printing ready process with the command 'cs17b004'.

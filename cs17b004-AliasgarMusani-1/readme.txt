So the following changes have been made in the folder:

1. a. i. Pulled the Xinu - Vbox File tar file.
      ii. Extracted it.
      iii. After extracting created two seperate vmachines for two seperate ova files.
      iv. Changed their RAM sizes to 2gb.
      v. Started them.
    b. Located the Xinu folder in home and created a copy on a folder with required name on desktop.

2. i. Used Grep to find 'welcome' in Xinu folder.
   ii. Found it in shell.h
   iii. Saw the variable which was defined to the welcome string.
   iv. Found the variable in shell.c
   v. Added a new fprintf statement below it printing the required string.

   a. Used the command to take a snapshot: 
	VBoxManage snapshot development-system take myfirstsnapshot -live
   b. Similarly used to restore snapshot:
	VBoxManage snapshot restore myfirstsnapshot

3. a. Created cs17b004details.txt in Desktop/cs17b004-AliasgarMusani-1/xinu and then explored 1st level folders and filled the cs17b004details with details on each file.

   b. Went to shell.c file and just after the end of all variable declarations added:
	fprintf(dev, "\n\n%s\n\n", "Hello Everyone!");

   c. i. When typed exit, the process ended and then again the process of shell started.
      ii. At the end of the shell process added a new fprintf statement:
	fprintf(dev, SHELL_EXITMSG2);
      iii. Defined a new variable in shell.h below SHELL_EXITMSG:
	#define SHELL_EXITMSG2	"WELCOME to IIT Tirupati by, Aliasgar Musani\n\n"
4. i. In the system folder in main.c created a new process inside a main process:
	resume(create(processes, 50, 50, "Process", 0));
   ii. Then defined the function processes:
	void processes() {
		int i;
		for(i = 0; i < 5; i++) kprintf("%s", "CS17B004\n\n");
	}
   iii. Had to remove:
	resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	else it was creating two processes.

Note: 1. After each edit in any of the files, had to compile it again by going to compile folder and by giving the command 'make' in the shell.
2.After compilataion had to restart backend.
3. And then to give a command 'sudo minicom' to start the shell.

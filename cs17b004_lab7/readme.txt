#Author: Aliasgar Musani <cs17b004 at iittp dot ac dot in>
#Roll Number: CS17B004
#Course: Operating Systems Lab
#Lab: 7

Note: In case of compilation error both the solutions are written with c-11 standards compile it with a suitable compiler.

1. First program creates asked functions and its implementation of detectDeadlock is done by powering up the to greatest length of a path a possible 
   and by checking for non-zero diagonal elements. If they exists at any iteration that symbolizes the condition for a deadlock.

2. Second program is just a simple implementation of Banker's Algorithm. By running few loops and checking for presence of a safe sequence.
   The outermost while loop takes care of the code re-checking on elements in-case if they weren't chosen in the first place, 
   it will run until all n elements aren't chosen or a break isn't called.

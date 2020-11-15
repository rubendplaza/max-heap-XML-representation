Everything Worked. (On my machine)
The make command works on my machine.
If the code does not compile on your environment. Try manually compiling with:

$ gcc -o heapXML intStack.c intHeap.c main.c
$ ./heapXML
OR
$ heapXML

My assumptions and things to consider when testing this code are written below:

The way the input is read by the skeletal code given to us in main.c does not accept non integer values. (Result of using the scanf() function)
Please consider this when testing the code. 
The requirements summary explicitly states that integers will be read from stdin. If you input a non integer just press CTRL+C and re-run the code with expected input.

When you are finished inputting integer values, press ENTER and then press CTRL+D to signify EOF for the scanf() function. Then the program will output and exit.

I used an implementation of a max heap from the website geeksforgeeks.org and changed it for our purposes, this may be the reason for similarities with other students' programs.

Since the lab document does not specify what to do with inputs of 0, I will assume they are not considered as a valid id/integer.

The implementation of the max-heap does not always hold the condition of the left child being the greater element, since it is not specified in the lab document then this should be okay.









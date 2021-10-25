Name: Zach Taylor
ONID: 933633772
Section: CS 162-020
Assignment 5

Description: This program simulates a data structure known as a linked list. These lists are made up of pieces called nodes which contain data like numbers or words.
Each node is linked to another node into a long chain of data. The program contains a user created linked list and adds numbers to it either at the front or back of the list.
Then the numbers are sorted into ascending and descending order. Finally, the program counts how many prime numbers are in the list and prints it to the screen.

Instructions: To compile and run the program, simply type "make" into the command line you are using. This creates an executable file called "prog" and to run it, simply type prog.
The program will then execute and to navigate from one part to another, press the enter key. There are also displays in the program that explain what to do.

Limitations: In order to proceed to the next part of the program, you must press enter when the display message says to. You cannot type any words or phrases into the command line
to move on. The program also doesn't take command line arguments or user input of any kind.

Complexity Analysis:
    sort_ascending(): This function implements the recursive merge sort algorithm to sort the linked list into ascending order. It has a time complexity of O(nlogn) and a space 
    complexity of O(logn).

    sort_descending(): This function implements the recursive merge sort algorithm to sort the linked list into descending order. It has a time complexity of O(nlogn) and a space 
    complexity of O(logn).

    count_prime(): This function counts the number of prime nodes by iterating through until the last node is found. The time complexity is O(N*sqrt(P)) where P is the maximum element 
    in the list. 
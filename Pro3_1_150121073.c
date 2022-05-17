
// Name = Yigit Tuncer
// Student ID = o150121073


#include <stdio.h>

int printRabbits(int i, int variable);
int bunnyEars2(int index);

int main() {
    //This part gets the number from the user
    int index = 0;
    printf("Please enter the number of lines (index=):");
    scanf("%d", &index);

    //Prints the result
    int i = 1;
    printRabbits(i, index);
    return 0;
}

//Recursive method to get number of ears
int bunnyEars2(int index) {

    //Checks if its 0 otherwise it would run forever
    if (index == 0) {
        return 0;
    }

    //Calculates the number of ears using recursion
    if (index % 2 == 0) {
        return 3 + bunnyEars2(index - 1);
    } else {
        return 2 + bunnyEars2(index - 1);
    }

}

//Prints the output
int printRabbits(int i, int iterations) {

    //Checks if all the lines have already been printed
    if (i < iterations + 1) {

        int ears = bunnyEars2(i);
        printf("bunnyEars2(%d) -> %d\n", i, ears);
        i++;

        //Recursion
        printRabbits(i, iterations);
        return 0;
    } else {
        return 0;
    }
}


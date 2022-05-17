/*
 * Name = Yigit Tuncer;
 * Student ID = o150121073;
 */

#include <stdio.h>
#include <math.h>

void printTriangles(char triangleArray[32][63], int iterations);

int main() {

    //Creates the character array
    char charArray[32][63] = {};

    //Creates the integers
    int iterations;
    int i;
    int j;

    //Takes the number of iterations from the user
    printf("Enter the number of iterations:");
    scanf("%d", &iterations);

    for (i = 0; i < 32; i++) {
        for (j = 0; j < 63; j++) {
            charArray[i][j] = '_';
        }
    }

    for (i = 0; i < 32; i++) {
        for (j = i; j < 32; j++) {
            charArray[j][31 + i] = '1';
            charArray[j][31 - i] = '1';
        }
    }

    //Calls the method to create the triangle array
    printTriangles(charArray, iterations);

    for (i = 0; i < 32; i++) {
        for (j = 0; j < 63; j++) {
            printf("%c", charArray[i][j]);
        }
        printf("\n");
    }

    return 0;

}

//The recursive method
void printTriangles(char triangleArray[32][63], int iterations) {

    //Creates the integers
    int rowInt;
    int skip;
    int middleInt;
    int i;
    int j;
    int k;
    int l;

    rowInt = (double) 32 / pow(2, iterations);
    skip = (double) 32 / pow(2, iterations);

    if (iterations != 0) {
        for (k = 0; k < pow(2, iterations - 1); k++) {
            middleInt = 63 / 2 - skip * k * 2;
            for (l = 0; l < k + 1; l++) {
                for (j = 0; j < skip; j++) {
                    for (i = skip + rowInt - l - j; i >= rowInt; i--) {
                        triangleArray[i][middleInt + j] = '_';
                        triangleArray[i][middleInt - j] = '_';
                    }
                }
                middleInt = middleInt + skip * 4;
            }
            rowInt = rowInt + skip * 2;
        }
        //Recursion
        printTriangles(triangleArray, iterations - 1);
    }
    return;

}

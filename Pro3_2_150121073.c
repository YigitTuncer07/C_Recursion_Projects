#include <stdio.h>

int superDigit(int number);

int getDigits(int n);

//Main method
int main() {

    //Declares variables
    int n;
    int k;
    int number;

    //Stores variables
    printf("Please enter a number (n=) : ");
    scanf("%d", &n);
    printf("Please enter repetition factor (k=) :");
    scanf("%d", &k);

    //This part makes the number with n and k variables
    //Makes an array out of n
    int length = getDigits(n);
    int array[length];
    int temp = n % 10;
    array[0] = temp;
    for (int i = 1; i < length; i++) {
        n = n / 10;
        temp = n % 10;
        array[i] = temp;
    }
    //Inverses the array as it is in the wrong direction
    int array1[length];
    for (int m = length - 1, g = 0; g < length; m--, g++) {
        array1[g] = array[m];
    }

    //Creates the full number
    int numberArray[length * k];
    for (int i = 0, j = 0; i < length * k; i++, j++) {
        if (j == length) {
            j = 0;
        }
        numberArray[i] = array1[j];
    }
    for (int i = 0; i < length * k; i++) {
        number = 10 * number + numberArray[i];
    }
    printf("The total is %d", superDigit(number));
    return 0;
}

//This method gets the super digit
int superDigit(int number) {

    //Gets length of number
    int length = getDigits(number);

    //Stops the recursion if the number is at one digit
    if (length == 1) {
        return number;
    }

    //Puts the number into an array
    int array[length];
    int temp = number % 10;
    array[0] = temp;
    for (int i = 1; i < length; i++) {
        number = number / 10;
        temp = number % 10;
        array[i] = temp;
    }

    //Adds the elements of the array
    int total = 0;
    for (int k = 0; k < length; k++) {
        total += array[k];
    }

    //Recursion
    superDigit(total);
}

//This method returns the number of digits a number has
int getDigits(int n) {

    int count = 0;
    do {
        n /= 10;
        ++count;
    } while (n != 0);
    return count;

}

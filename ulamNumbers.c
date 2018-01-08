#include <stdio.h>

int main () {
    int n = 0; // The number of terms user wants
    int i = 0, j = 0; // Used for counting in for loops
    int count = 0; // Number of times combinations work to add to that number
    int currentUnk = 0; // Number currently being checked
    int curIndex = 2; // Index of the current Ulam Number being searched for
    int result = 0; // The result of the subtraction

    while ( n < 2 ) {
        printf ( "Please enter term number: " );
        scanf ( " %d", &n ); // Getting user input
    }

    int ulamNums[n - 1];
    ulamNums[0] = 1; // a1 is always equal to 1
    ulamNums[1] = 2; // a2 is always equal to 2
    currentUnk = ulamNums[1] + 1;

    while ( curIndex < n ) {
        // For every Ulam number
        for ( i = 0; i < curIndex; i++ ) {
            // Subtract current Ulam number from currentChecking
            result = currentUnk - ulamNums[i];

            for ( j = ( i + 1 ); j < curIndex; j++ ) {
                // Check to see if that number is Ulam
                if ( result == ulamNums[j] ) {
                    // If it is add one to count
                    count++;
                }
            }
        }
        if ( count == 1 ) {
            // If the count is one add to list of ulam numbers
            ulamNums[curIndex] = currentUnk;
            curIndex++;
        }
        // Setting variables for next round
        currentUnk++;
        count = 0;
    }

    // Printing the found numbers
    for ( i = 0; i < n; i++ ) {
        printf("%d ", ulamNums[i] );
    }
    printf("\n");

}
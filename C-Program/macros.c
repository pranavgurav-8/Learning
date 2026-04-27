// OUTPUT - The maximum value between 5 and 10 is 10

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 5;
    int y = 10;
    int max_value = MAX(x, y);

    printf("The maximum value between %d and %d is: %d\n", x, y, max_value);

    return 0;
}

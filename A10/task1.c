#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MAX;
    printf("a = %d\n", a);
    a += 1;
    printf("a = %d\n", a);
    a = INT_MIN;
    printf("a = %d\n", a);
    a -= 1;
    printf("a = %d\n", a);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    int x, y;
    printf("%d", ~(~0 + 1) >> 31);
}
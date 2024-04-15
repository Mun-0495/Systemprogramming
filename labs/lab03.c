#include <stdio.h>

void bitsmove(unsigned int val, int len) {
    for(int i=0; i<len; i++, val <<= 1) {
        printf("%d", !!(val & 0x80000000U));
    }
}

void printIEEEfields(float val) {
    unsigned int bits = *((unsigned int*) &val);
    
    // printf("all bit : ");
    // bitsmove(bits, 32);
    // printf("\n");
    
    printf("signed bit : %d ", !!(bits & 0x80000000U));
    

    //signed bit remove;
    bits <<= 1;
    printf("exp : ");
    bitsmove(bits, 8);
    printf(" ");

    bits <<= 8;
    printf("frac : ");
    bitsmove(bits, 23);
    printf("\n");
}

int main() {
    float val;
    float inf, nan;
    *((int*) &inf) = 0b01111111100000000000000000000000;
    *((int*) &nan) = 0b01111111100000000000000000000001;
    //scanf("%f", &val);
    
    printIEEEfields(inf + 0.0f);
    printIEEEfields(inf + 0.1f);
    printIEEEfields(inf + inf);
    printIEEEfields(inf -inf);
    printIEEEfields(nan + 0.0f);
    printIEEEfields(nan + 1.0f);
    printIEEEfields(nan + nan);
    printIEEEfields(nan -nan);
    return 0;
}

// int main(void) {
//     float inf, nan;
//     *((int*) &inf) = 0b01111111100000000000000000000000;
//     *((int*) &nan) = 0b01111111100000000000000000000001;
//     printf("%d\n", nan < nan);
//     printf("%d\n", nan > nan);
//     printf("%d\n", nan == nan);
//     printf("%d\n", inf > nan);
//     printf("%d\n", nan > inf);
//     printf("%d\n", inf == nan);
//     printf("%d\n", inf > inf);
//     printf("%d\n", inf == inf);
//     return 0;
// }
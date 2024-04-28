//Program that counts number of ones in binary representation of number

#include <stdio.h>

int main() {
    int x = 0x39D;
    int y = 0;
    asm(
        "mov eax, %1;"
        "xor ebx, ebx;"
    "petla:"
        "shl eax;"
        "jnc skok;"
        "inc ebx;"
    "skok:"
        "and eax, eax;"
        "jnz petla;"
        "mov %0, ebx;"
        :"=r"(y)
        :"r"(x)
        :"eax", "ebx"
    );
    printf("x=%i y=%i\n", x, y);
    
    return 0;
}
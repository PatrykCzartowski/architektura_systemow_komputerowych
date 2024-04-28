//Program that founds the longest sequence of ones in binary representation of number

#include <stdio.h>

int main() {
    int x = 0x1D39;
    int y;

    asm (
    "mov eax, %1;"
    "mov ecx, 0;"
    "xor ebx, ebx;"
    "loop: "
        "cmp ebx, ecx;"
        "jle noswap;"
        "mov ecx, ebx;"
    "noswap:"
        "cmp eax, 0;"
        "je end;"
        "mov ebx, 0;"
    "one:"
        "shl eax;"
        "jnc loop;"
        "inc ebx;"
        "jmp one;"
    "end:"
    "mov %0, ecx;"
    : "=r" (y)
    : "r"(x)
    : "eax", "ebx", "ecx"
);

    printf("x=%i y==%i\n", x, y);

    return 0;
}
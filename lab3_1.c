//Program that inverts string

#include <stdio.h>

int main(){

    char s[] = "Abc xyz";

    asm(
        "mov rbx, %0;"
        "mov rcx, rbx;"
    "petla:"
        "mov al, [rcx];"
        "cmp al, 0;"
        "je skok;"
        "inc rcx;"
        "jmp petla;"
    "skok:"
        "dec rcx;"
    "petla2:"
        "cmp rcx, rbx;"
        "jbe koniec;"
        "mov al, [rcx];"
        "mov ah, [rbx];"
        "mov [rcx], ah;"
        "mov [rbx], al;"
        "inc rbx;"
        "dec rcx;"
        "jmp petla2;"
    "koniec:"
        :
        : "r"(s)
        : "rax", "rbx", "rcx"
    );

    printf("%s\n", s);

    return 0;
}
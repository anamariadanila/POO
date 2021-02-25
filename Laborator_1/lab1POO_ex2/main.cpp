#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;

int Char_To_Number(char s[10]) {
    unsigned number = 0, digit;
    for (int i = 0; i < strlen(s); i++) {
        digit = s[i] - '0';
        number = number * 10 + digit;
    }
    return number;
}

int main()
{
    char s[10];
    int sum = 0;
    FILE* ptr;
    if (fopen_s(&ptr, "in.txt", "r") != 0) {
        printf("Eroare. Nu am putut deschide fisierul\n");
    }
    else {
        printf("Am deschis fisierul cu success!\n");
        while (fscanf(ptr, "%s", s) == 1)
            sum = sum + Char_To_Number(s);
        printf("%d", sum);
    }
    return 0;
}


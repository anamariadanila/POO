#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
    char s[50], * p, * array[100], * aux;
    int i = 0;
    printf("Insert the senctence:");
    scanf_s("%[^\n]", s, sizeof(s));
    p = strtok(s, " ");

    while (p != NULL)
    {
        array[i] = p;
        //printf("%s.", array[i]);
        i++;
        p = strtok(NULL, " ");

    }
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if ((strlen(array[j])) < (strlen(array[k])))
            {
                aux = array[j];
                array[j] = array[k];
                array[k] = aux;
            }
            else if ((strlen(array[j])) == (strlen(array[k])))
                if (strcmp(array[j], array[k]) > 0)
                {
                    aux = array[j];
                    array[j] = array[k];
                    array[k] = aux;
                }

        }

    }
    for (int n = 0; n < i; n++)
    {
        printf("%s\n", array[n]);
    }
    return 0;
}
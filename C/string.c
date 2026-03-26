#include <stdio.h>
#include <string.h>
int main()
{
    char str1[40];
    char str2[40];
    printf("Input string :\n");
    fgets(str1, sizeof(str1), stdin);
    int i, j, count, max = 0;
    char ch;
    for (i = 0; str1[i] != '\0'; i++)
    {
        count = 0;
        max = max;
        for (j = 0; str1[j] != '\0'; j++)
        {
            if (str1[j] == str1[i])
                count++;
        }
        if (count > max)
        {
            max = count;
            ch = str1[j];
        }
    }
    printf("character with most frequency %c", ch);
    return 0;
}

// prints in single loop
/*
 H
 H e
 H e l
 H e l l
 H e l l o
*/
int main() {
    for(int i = 1; i <= strlen("Hello"); i++){
        printf("%.s\n", i, "Hello");
    }
    return 0;
}
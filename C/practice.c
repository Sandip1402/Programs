#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  FILE *f1;
  // f1 = fopen("hello.txt", "w");
  // char str[] = "Input a sentence to put into a file.";
  // fprintf(f1,str);
  f1 = fopen("hello.txt", "r");
  char ch;
  while(ch != EOF)
  {
    ch = getc(f1);
    printf("%c", ch);
  }
  fclose(f1);
  return 0;
}
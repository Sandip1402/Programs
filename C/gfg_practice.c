// C Program to illustrate the static variable lifetime
#include <stdio.h>
// #include <stdlib.h>
// function with static variable
// int fun()
// {
//     static int count = 0;
// 	fun();
// 	count++;
// 	return count;
// }

// int* reallocate(int *arr)
// {
// 	int *a = (int*)realloc(arr,10);
// 	if(a=NULL)
// 	{
// 		printf("memory can't be alloacted");
// 		return NULL;
// 	}
// 	else
// 	{	
// 		printf("enter new values :\n");
// 		for(int i=5; i<10; i++)
// 		scanf("%d", a+i);
// 		return a;
// 	}
// }

void pointer()
{
	float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
	float *ptr1 = &arr[0];
	float *ptr2 = ptr1 + 3;
	printf("%lu ",sizeof(ptr1));
	printf("%f ", *ptr2);
	printf("%lu ", ptr2);
	printf("%lu ", ptr1);
	printf("%f ", *ptr2 - *ptr1);
	printf("%lu ", ptr2 - ptr1); // how?? addresses are always long unsigned type
}

int main()
{
	// printf("%d ", fun());
	// printf("%d ", fun());
	// printf("%d ", fun());
	// int *arr = (int*)malloc(5*sizeof(int));
	// for(int i=0; i<5; i++)
	// scanf("%d", arr+i);
	// arr=reallocate(arr);
	// printf("after allocation :\n");
	// for(int i=0; i<10; i++)
	// printf("%d ", *(arr+i));
	pointer();
	// int a = 2147483647;
	// int b = 1073741824;
	// int c = 2147483648;
	// printf("%d ",a);
	// printf("%d ", b);
	// printf("%d", ~c);
	return 0;
}

#include<stdio.h>
#include<string.h>
int max=0; // DAY-1
int min=0;

int pft[50]; // DAY-2
int wght[50];
char item[20][30];
float rto[50];
int n,m;

// DAY-1
int maxmin1(int arr[], int n)
{
    int max,min,count;
    max=min=arr[0];
    count=0;
    for(int i=1; i<n; i++)
    {
        count++;
        if(arr[i]>max)
        max=arr[i];
        count++;
        if(arr[i]<min)
        min=arr[i];
    }
    return count;
}
int maxmin2(int arr[], int n)
{
    int max,min,count;
    max=min=arr[0];
    count=0;
    for(int i=1; i<n; i++)
    {
        count++;
        if(arr[i]>max)
        max=arr[i];
        else{
            count++;
            if(arr[i]<min)
            min=arr[i];
        }
    }
    return count;
}
void maxmin_dac(int arr[], int l, int h){
	int mid;
	if(l==h){
		min=max=arr[l];
	}
	else if(l==h-1){
		if(arr[l]<arr[h]){
			max=arr[h];
			min=arr[l];
		}
		else{
			max=arr[l];
			min=arr[h];
		}
	}
	else{
		mid=(l+h)/2; // l+(h-l)/2 to avoid overflow of large arrays
		maxmin_dac(arr,l,mid);
		int max1=max;
		int min1=min;
		maxmin_dac(arr,mid+1,h);
		if(max1>max)
		max=max1;
		if(min1<min)
		min=min1;
	}
}

// DAY-2
void input(){
    printf("enter no. of items :\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("enter item name :");
        scanf("%s", &item[i]);
        printf("enter weight :");
        scanf("%d", &wght[i]);
        printf("enter profit :");
        scanf("%d", &pft[i]);
    }
    printf("enter knapsack capacity :");
    scanf("%d", &m);
    for(int i=0; i<n; i++){
        rto[i]=(float)(pft[i]/wght[i]);
    }
}
void sort(){
    for(int i=n-1; i>0; i--){
        for(int j=0; j>i; j++){
            if(rto[j]<rto[i]){
                // swap ratio
                float t = rto[i];
                rto[i] = rto[j];
                rto[j] = t;
                // swap item
                char* ch;
                strcpy(ch,item[i]);
                strcpy(item[i],item[j]);
                strcpy(item[j],ch);
                // swap pft
                int temp = pft[i];
                pft[i] = pft[j];
                pft[j] = temp;
                // swap weight
                temp = wght[i];
                wght[i] = wght[j];
                wght[j] = temp;
            }
        }
    }
}
void knap_sack(){
    float x[n];
    float profit=0;
    for(int i=0; i<n; i++){
        if(wght[i]<m){
            printf("All %s is taken.\n",item[i]);
            m-=wght[i];
            profit+=wght[i]*pft[i];
        }else {
            float x = (float)(m/wght[i]);
            printf("Item %s is taken %.2f %\n",item[i],x*100);
            profit += x * pft[i];
        }
    }
    printf("Max profit is %.2f.\n", profit);
}
int main()
{
    // int n; 
    // printf("enter size of array: \n");
    // scanf("%d", &n);
    // int arr[n];
    // printf("enter the elements :\n");
    // for(int i=0; i<n; i++)
    // scanf("%d", &arr[i]);
    // // int count1=maxmin1(arr,n);
    // // int count2=maxmin2(arr,n);
    // // if(count1>count2)
    // // printf("maxmin2 is better, ");
    // // else if(count1<count2)
    // // printf("maxmin1 is better, ");
    // // else
    // // printf("both are same, ");
    // // printf("count1=%d,count2=%d",count1,count2);
    // maxmin_dac(arr,0,n-1);
    // printf("maximum is %d, minimum is %d", max,min);
    // input();
    // sort();
    // knap_sack();
    float a = 2.6;
    if(a==2.6)
        printf("A");
    else
        printf("B");
return 0;
}
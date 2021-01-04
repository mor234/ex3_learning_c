    
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#define SIZE 50
void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);
int main(int argc, char* argv[]) {
    int arr [SIZE];
	for(int i=0;i<SIZE;i++)
    {
       if(scanf("%d",arr+i)!=1)
       {
           return -1;
       }
    }
    for(int i=0;i<SIZE-1;i++)
    {
       printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+SIZE-1));
    insertion_sort(arr,SIZE);
    for(int i=0;i<SIZE-1;i++)
    {
       printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+SIZE-1));


	return 0;

}
void shift_element(int* arr, int i)
{
    i--;//2
    while(i>0)
    {
        *(arr+i)=*(arr+i-1);
        i--;
    }

}
void insertion_sort(int* arr , int len)
{
    int i=0;
    while(i<len)
    { 
        int j=i-1;
        int var=*(arr+i);
        while(j>=0)
        {
            if(var>=*(arr+j))//found the place to put it
                break;
            j--;
        }
    
        shift_element(arr+j+1, i-j);
        *(arr+j+1)=var; 
        i++;      
    }

}

    
#include <stdio.h>
#include <string.h>
#define SIZE 50
void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);

/*
 * The program receives 50 numbers from the user,
 * inserts them into a 50-size array,
 * sorts the array and prints the sorted array to the screen. 
 */
int main(int argc, char* argv[]) {
    int arr [SIZE];
	for(int i=0;i<SIZE;i++)
    {
       if(scanf("%d",arr+i)!=1)
       {
           return -1;
       }
    }
    //print before:
    // for(int i=0;i<SIZE-1;i++)
    // {
    //    printf("%d,",*(arr+i));
    // }
    // printf("%d\n",*(arr+SIZE-1));

    insertion_sort(arr,SIZE);
    for(int i=0;i<SIZE-1;i++)
    {
       printf("%d,",*(arr+i));
    }
    printf("%d\n",*(arr+SIZE-1));


	return 0;

}
/*
 * The function gets a pointer to an array and a number.
 * The function will move the i varables following in the array one cell to the right. 
 * assumes that there is memory for at least 1+i cells after the pointer to the array.
 */
void shift_element(int* arr, int i)
{
    i--;
    while(i>0)
    {
        *(arr+i)=*(arr+i-1);
        i--;
    }
}
/*
 * The function gets an array and its length,
 * And sorts it using the insertion sorting algorithm.
 */
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
        //move all the variable after the place to put var  one step right
        shift_element(arr+j+1, i-j);
        //put var in it's place. now the array up to var is sorted.
        *(arr+j+1)=var; 
        i++;      
    }

}

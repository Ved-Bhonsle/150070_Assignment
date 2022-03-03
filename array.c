/*
Search and Sequence
Consider an integer array ‘a’ of size 10, where the value of the array elements are
{1,5,4,8,9,2,0,6,11,7}. Write a program to
▪ Find whether the given element exists in an array or not. If the element exists in an
array, display YES else NO.
▪ To print a number following a sequence of elements in an array i.e., 15489206117.
*/

#include<stdio.h>

int main()
{
    int a[10]={1,5,4,8,9,2,0,6,11,7};
    int i,element,flag;
 
    printf("Enter the search element: ");
    scanf("%d",&element);
    flag = 0;
    for(i=0; i<10;i++)
    {
        if(a[i]==element)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        printf("YES");
    }
    else{
        printf("NO");
    }

    printf("\nElements in array is:");
    for(i=0; i<10;i++)
    {
        printf("%d",a[i]);
    }
	printf("\n");
    return 0;
}

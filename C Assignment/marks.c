/*
Write a function that receives marks received by a student in 3 subjects
and returns the total and percentage of these marks. Call this function from
main( ) and print the results in main( ).
*/

#include<stdio.h>

void func(int a,int b,int c,int *total,float *per)
{
    *total = a+b+c;
    *per = ((a+b+c)/300.0)*100;
}
void main()
{
    int m1,m2,m3,total;
    float per;
    
    printf("Enter the marks of  three subjects : ");
    scanf("%d %d %d",&m1,&m2,&m3);
    
    func(m1,m2,m3,&total,&per);
    
    printf("\nThe Average: %d",total);
    printf("\nThe Percentage: %.2f\n",per);
}


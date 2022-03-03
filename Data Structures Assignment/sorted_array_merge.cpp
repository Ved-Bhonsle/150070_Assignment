/*
In-place merge two sorted arrays.
Given two sorted arrays, X[ ] and Y[ ] of size m and n each, merge elements of X[ ] with elements of
array Y[ ] by maintaining the sorted order, i.e., fill X[ ] with the first m smallest elements and fill Y[ ]
with remaining elements.
For example,
Input:
X[] = { 1, 4, 7, 8, 10 }
Y[] = { 2, 3, 9 }
Output:
X[] = { 1, 2, 3, 4, 7 }
Y[] = { 8, 9, 10 }
*/

#include<iostream>
using namespace std;

void print_Array(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<< a[i] << " ";
    }
    cout<< endl;
}

void merge_Array(int X[],int Y[],int m,int n)
{
    for(int i=0; i<m; i++)
    {
        if(X[i]>Y[0])
        {
            swap(X[i],Y[0]);
            int first = Y[0];
            
            int k;
            for(k=1; k<n && Y[k]<first; k++)
            {
                Y[k-1] = Y[k];
            }
            Y[k-1] = first;
        }
    }
}

int main()
{
    	int X[] = {1,4,7,8,10};
    	int Y[] = {2,3,9};
    	int m = sizeof(X)/sizeof(X[0]);
    	int n = sizeof(Y)/sizeof(Y[0]);
    
	merge_Array(X,Y,m,n);

    	cout<<"X: ";
    	print_Array(X,m);
    	
	cout<<"Y: ";
   	print_Array(Y,n);

    	return 0;
}

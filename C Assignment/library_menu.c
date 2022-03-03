/*
Write a menu driven program that depicts the working of a library. The menu
options should be:
1. Add book information
2. Display book information
3. List all books of given author
4. List the title of specified book
5. List the count of books in the library
6. List the books in the order of accession number
7. Exit
Create a structure called library to hold accession number, title of the book, author
name, price of the book, and flag indicating whether the book is issued
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct library
{
    int an;                   //accession number
    char title[50];           //book title  
    char author[30];         //author name  
    int price;               //book price
    int bookis;             //flag for check book is issued or not if flag=1 :issued or flag=0: not issued
};

void sortBooksInOrderAccessionNumber(struct library mylibrary[],int size)
{
    int i,j,indexmin;
    struct library temp;
    for(i=0; i<size-1; i++)
     {
        indexmin = i;
        for(j=i+1; j<size; j++)
        if(mylibrary[j].an < mylibrary[indexmin].an)
        indexmin = j;
        temp = mylibrary[i];
        mylibrary[i] = mylibrary[indexmin];
        mylibrary[indexmin] = temp;
    }
}

int main(){
    struct library mylibrary[100];

    int totalBooks=0;
    int ch = -1;
    int index = -1;
    int i;
    int anTarget;
    char authorT[30];
    char titleT[50];
    
    while(1)
    {
        //display main menu
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. List the books in the order of accession number\n");
        printf("7. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        
        if(ch==1)                               // add book information
        {
           printf("Enter the book accession number: ");
           scanf("%d",&mylibrary[totalBooks].an);
           printf("Enter the book title: ");
           scanf("%s",mylibrary[totalBooks].title);
           printf("Enter the book author: ");
           scanf("%s",mylibrary[totalBooks].author);
           printf("Enter the book price: ");
           scanf("%d",&mylibrary[totalBooks].price);
           mylibrary[totalBooks].bookis=-1;
           
           while(mylibrary[totalBooks].bookis!=1 && mylibrary[totalBooks].bookis!=0)
           {
               printf("Is the book issued? 1- yes,0- no: ");
               scanf("%d",&mylibrary[totalBooks].bookis);
           }
           totalBooks++;
           printf("\n\nA new book has been added succesfully.\n\n");
        }
        
        else if(ch==2)                          //display book information
        {
            if(totalBooks==0){
                printf("\nThe library is empty.\n\n");
            }
            else{
                index = -1;
                printf("Enter the book accession number to display: ");
                scanf("%d",&anTarget);
                for(i=0; i<totalBooks; i++){
                    if(mylibrary[i].an==anTarget){
                        index = i;
                    }
                }
                if(index!=-1)
                {
                    printf("\n%-20s%-20s%-20s%-20s%-20s\n","Accession Number","Book title","Book Aurthor","Book Price","Book is issued");
             printf("%-20d%-20s%-20s%-20d%-20d\n\n",mylibrary[index].an,mylibrary[index].title,mylibrary[index].author,mylibrary[index].price,mylibrary[index].bookis);  
                }
                else{
                    printf("\nThe book does not exist.\n\n");
                   }
            }
        }
        
        else if(ch==3)                            //List all books of given author
        {
            if(totalBooks==0){
                printf("The library is empty.\n\n");
            }
            else{
                printf("Enter the book author to list: ");
                scanf("%s",authorT);
                index = -1;
                printf("\n\n%-20s%-20s%-20s%-20s%-20s\n", "Accession Number","Book title","Book Aurthor","Book Price","Book is issued");
                for(i=0; i<totalBooks; i++)
               {
                    if(strcmp(mylibrary[i].author,authorT)==0)
                    {
                        index = i;
               printf("%-20d%-20s%-20s%-20d%-20d\n\n",mylibrary[index].an,mylibrary[index].title,mylibrary[index].author,mylibrary[index].price,mylibrary[index].bookis);
                    }
                }
                if(index==-1){
                    printf("\nThe books do not exist.\n\n");
                }
            }
        }
        
        else if(ch==4)                             //list the title of specified books
        {
            if(totalBooks==0){
                printf("The library is empty.\n\n");
            }
            else{
                printf("Enter the book title to list: ");
                scanf("%s",titleT);
                index = -1;
                printf("\n\n%-20s%-20s%-20s%-20s%-20s\n", "Accession Number","Book title","Book Aurthor","Book Price","Book is issued");
                for(i=0; i<totalBooks; i++){
                    if(strcmp(mylibrary[i].title,titleT)==0)
                    {
                        index = i;
               printf("%-20d%-20s%-20s%-20d%-20d\n\n",mylibrary[index].an,mylibrary[index].title,mylibrary[index].author,mylibrary[index].price,mylibrary[index].bookis);
                    }
                }
                if(index==-1){
                    printf("\nThe books do not exist.\n\n");
                }
            }
        }
       
       else if(ch==5)                                //list the count of books in the library
       {
           if(totalBooks==0){
                printf("The library is empty.\n\n");
            }
            else{
                printf("The total number of books in the library: %d\n\n",totalBooks);
            }
       }
       
       else if(ch==6)                                //list the books in order of accession number
       {
           if(totalBooks==0){
                printf("The library is empty.\n\n");
            }
            else{
                sortBooksInOrderAccessionNumber(mylibrary,totalBooks);
                printf("\n\n%-20s%-20s%-20s%-20s%-20s\n", "Accession Number","Book title","Book Aurthor","Book Price","Book is issued");
                for(i=0; i<totalBooks; i++){
                        printf("%-20d%-20s%-20s%-20d%-20d\n\n",mylibrary[i].an,mylibrary[i].title,mylibrary[i].author,mylibrary[i].price,mylibrary[i].bookis);
                }
            }
       }
       
       else if(ch==7){
	break;
       }

	else if (ch != 1 || ch != 2 || ch != 3 || ch != 4 || ch != 5 || ch != 6 || ch != 7)
	{
	printf("Invalid Choice, enter proper choice\n\n");
	}
    }
    return 0;
}

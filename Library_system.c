// #Library Project#
#include "STD_TYPES.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
// Book Structure 
//typedef struct Book
struct book
{
	u8 title[100];
	u8 author[100];
	u16 page; 
	f32 price;
	u16 ID;
	struct book * nextptr;
};
u8 i; //global variabl for dynamic memory allocation
struct book * head=NULL;
struct book * tail=NULL;
struct book * IDsearch(u16 key);


 
 //ID SEARCH 
struct book * IDsearch(u16 key)
{
	struct book * ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr -> ID == key)
		{
			return ptr;
		}			
		ptr = ptr -> nextptr;
	}
	return NULL;
}
 
 
 
// function to add new book by ID

void addBook()
{
	struct book * ptr;
	u16 key;
	ptr=(struct book *)malloc(sizeof(struct book));
	system("cls");
	printf("\n******* Add New Book Detail ******");
	printf("\nPlease Enter The ID Number To Add New Book  : ");
	scanf(" %d", &key);
	fflush(stdin);
	system("cls");
	if (ptr != NULL)
	{
		if (IDsearch(key) == NULL)
		{
			ptr -> ID = key;
			printf("\nEnter Book Title :");
			gets(&(ptr -> title[i]));
			printf("\nEnter Book Author :");
			fflush(stdin);
			gets(&(ptr -> author[i]));
			printf("\nEnter Book Price :");
			scanf(" %d" ,&(ptr -> price));
			printf("\nEnter Book Page :");
			scanf(" %d" ,&(ptr -> page));
			//here i will think in reservation case 
			/*if (head == NULL)
			{
				head = ptr;
				tail = ptr;
				ptr -> nextptr = NULL;
			}
			else
			{
				tail -> nextptr = ptr;
				tail = ptr;
				tail -> nextptr =NULL;
			}*/
		}
		else if (IDsearch(key)!= NULL)
		{
			printf("This ID Is Already Exist -_- \n");
		}
	}
	
} 
// function for show all books
void showAllBook()
{
	struct book * ptr;
	u16 key;
	ptr=(struct book *)malloc(sizeof(struct book));
	system("cls");
	printf("\nBooks Details");
	printf("\nBOOK TITLE\t\tBOOK AUTHOR\t\tBOOK PRICE\t\tBOOK PAGE");
	printf("Book ID Is : %d\n " ,ptr -> ID);
	printf("Book Price Is : %d\n" ,ptr -> price);
	printf("Book Author Is : %c\n" ,ptr -> author);
	printf("Book Title is : %c\n" ,ptr -> title);
	printf("Book Pages is : %d\n" ,ptr -> page);
	
}
// function for search books by ID

void searchBook()
{
	struct book * ptr;
	u16 key;
	ptr=(struct book *)malloc(sizeof(struct book));
	system("cls");
	printf("To Search About Book please Enter the Book  ID : ");
	scanf(" %d" ,key);
	fflush(stdin);
	system("cls");
	if (IDsearch(key) != NULL)
	{
		ptr = IDsearch(key);
		printf("Book ID Is : %d\n " ,ptr -> ID);
		printf("Book Price Is : %d\n" ,ptr -> price);
		printf("Book Author Is : %c\n" ,ptr -> author);
		printf("Book Title is : %c\n" ,ptr -> title);
		printf("Book Pages is : %d\n" ,ptr -> page);
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Book Is Not Registered -_- \n");
		system("cls");
	}
	
}


void EdDis (u16 key)
{
	struct book * ptr;
	
	system("cls");
	printf("Book Old Data ");
	if (IDsearch(key) != NULL)
	{
		ptr = IDsearch(key);
		printf("Book ID Is : %d\n " ,ptr -> ID);
		printf("Book Price Is : %d\n" ,ptr -> price);
		printf("Book Author Is : %c\n" ,ptr -> author);
		printf("Book Title is : %c\n" ,ptr -> title);
		printf("Book Pages is : %d\n" ,ptr -> page);
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Book Is Not Registered -_- \n");
		system("cls");
	}
}


// function for Edit book by Id

void EditBook()
{
	struct book * ptr;
	u8 choice;
	u16 key;
	scanf(" %d" ,&key);
	fflush(stdin);
	if (IDsearch(key) != NULL)
	{
		//to display the old data
		EdDis(key);
		//to make ptr hold the user pointer
		ptr = IDsearch(key);
		printf("Book New Price : ");
		scanf(" %d" ,&(ptr -> price));
		fflush(stdin);
		printf("Book New Title : ");
		gets(&(ptr -> title[i]));
		fflush(stdin);
		printf("Book New Author : ");
		gets(&(ptr -> author[i]));
		fflush(stdin);
		printf("\n");
		printf("Book New Pages : ");
		scanf(" %d" ,&(ptr -> page));
		fflush(stdin);
		//CheckPrint();
		//scanf(" %d" ,&choice);
		//fflush(stdin);
		//CheckReserv(key);
		//Reservation(key,choice);
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Book Is Not Registered -_- \n");
		system("cls");
	}
}

void main()
{
	u32 choice;
	//printf("\nEnter Total no. of Books You Want To Add In Libaray  :");
	//scanf("%d",&size);
	//book = (Book*) malloc(sizeof(Book)*size);
	do
	{
		system("cls");
		printf("\n1.Add Book\n2.Show All Books\n3.Search Book\n4.Edit Book\n5.Exit\nEnter Your Choice :");
		scanf(" %d" ,&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				   addBook();
				   break;
			case 2:
				   showAllBook();
				   break;
			case 3:
				   searchBook();
				   break;	   	   
				   
			case 4:
				   EditBook();
				   break;	   
				   
			case 5:
				   return;
		}
		getch();
	}while(1);
}
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    char ISBN[10];
    int year;
    int copies;
    }Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book()
{
    if (book_count >= MAX_BOOKS) 
    {
        printf("Library is full!\n");
        return;
    }

    Book new_book;
    char title[100];
    char author[100];
    char ISBN[10];
    int year;
    int copies;

    printf("Enter the book title \n");
    fgets(title,sizeof(title),stdin);
    title[strcspn(title, "\n")] = '\0'; 
    strcpy(title,new_book.title);
    
    printf("Enter the name of author \n");
    fgets(author,sizeof(author),stdin);
    author[strcspn(author, "\n")] = '\0'; 
    strcpy(author,new_book.author);

    printf("Enter the ISBN \n");
    fgets(ISBN,sizeof(ISBN),stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0'; 
    strcpy(ISBN,new_book.ISBN);
    
    for (int i = 0; i < book_count; i++) 
    {
        if (strcmp(library[i].ISBN, new_book.ISBN) == 0) 
        {
            printf("A book with this ISBN already exists.\n");
            return;
        }
    }

    printf("Enter the publication year \n");
    getchar();
    scanf("%d",&year);
    new_book.year=year;
    

    printf("Enter the number of copies \n");
    getchar();
    scanf("%d",&copies);
    new_book.copies=copies;

    book_count++;

    printf("Book added successfully! \n");
    
}

void update_book()
{
    char title[100];
    char author[100];
    char ISBN[10];
    int year;
    int copies;
    printf("Enter the ISBN of the book to borrow \n");
    fgets(ISBN,strlen(ISBN),stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    for(int i=0;i<book_count;i++)
    {
        if(strcmp(library[i].ISBN,ISBN)==0)
        {
                printf("Enter new title \n");   
                fgets(title,sizeof(title),stdin);
                title[strcspn(title, "\n")] = '\0'; 
                strcpy(title,library[i].title);

                printf("Enter new author \n");   
                fgets(author,sizeof(author),stdin);
                author[strcspn(author, "\n")] = '\0'; 
                strcpy(author,library[i].author);

                printf("Enter the publication year \n");
                getchar();
                scanf("%d",&year);
                library[i].year=year;
    

                printf("Enter the number of copies \n");
                getchar();
                scanf("%d",&copies);
                library[i].copies=copies;

                return;


        }
        else
        {
            printf("Book with %s ISBN not found. Try again!\n", ISBN);
        }

        }

    }


void search_book()
{

    char query[100];
    int query_type;

    printf("Enter the query type: 1.by author \t 2.by title \n");
    scanf("%d",&query_type);
    getchar();

    printf("Enter search query \n");
    fgets(query,sizeof(query),stdin);
    query[strcspn(query, "\n")] = '\0';

    int found=0;
    for(int i=0;i<book_count;i++)
    {
        if((query_type == 1 && strstr(library[i].title, query)) || (query_type == 2 && strstr(library[i].author, query)))

      { 
        printf("Title: %s, Author: %s, ISBN: %s, Year: %d, Copies: %d\n",library[i].title, library[i].author, library[i].ISBN, library[i].year, library[i].copies);
        found++;
      }
    }
    if (!found) 
    {
        printf("No books found matching the query.\n");
    }
}


void list_books()
{
    char author[100];
    printf("Enter the author's name :\n");
    getchar();
    fgets(author,sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    int found=0;

    for(int i=0;i<book_count;i++)
    {
        if(strcmp(library[i].author,author)==0)
        {
            printf("Title: %s, \t ISBN: %d, \t year: %d, \t copies: %d, \t \n", library[i].title,library[i].ISBN,library[i].year,library[i].copies);
            found++;
        }
    } 
    if(!found)
    {
        printf("No books found by author %s \n",author);
    }
}

void display_books()
{
    int total =0;
    for(int i=0;i<book_count;i++)
    {
        total=total+library[i].copies;
    }
    printf("Total number of distinct books %d: \n", book_count );
    printf("Total number of books including copies %d\n", total);
}


void borrow_book()
{
    char ISBN[10];
    printf("Enter the ISBN of the book to borrow \n");
    fgets(ISBN,strlen(ISBN),stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    for(int i=0;i<book_count;i++)
    {
        if(strcmp(library[i].ISBN,ISBN)==0)
        {
            if(library[i].copies>0)
            {
                library[i].copies--;
                printf("Book borrowed successfully \n");   
            }
            else
            {
                printf("No copies available! Please try again later :(\n");
            }
            return;
        }
        else
        {
            printf("Book with ISBN %s not available \n", ISBN);
        }
    } 

}

void return_book()
{
    char ISBN[10];
    printf("Enter the ISBN of the book to return \n");
    fgets(ISBN,strlen(ISBN),stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    for(int i=0;i<book_count;i++)
    {
        if(strcmp(library[i].ISBN,ISBN)==0)
        {
                library[i].copies++;
                printf("Book returned successfully. Thank you! \n");
                return;
        }
        else
        {
            printf("Book with ISBN %s not available \n", ISBN);
        }
    } 
}

int main()
{
    int choice;
   
    printf("Welcome to the Digital Library System!\n 1. Add a new book\n 2. Update book details\n 3. Search for a book\n 4. List books by an author \n 5. Display total books\n 6. Borrow a book \n 7. Return a book \n 8. Exit \n") ;
    scanf("%d",&choice);
    getchar(); 
    printf("Your choice: %d \n",choice);

switch(choice)
{
    case 1:
    add_book();
    break;


    case 2:
    update_book();
    break;


    case 3:
    search_book();
    break;


    case 4:
    list_books();
    break;


    case 5:
    display_books();
    break;


    case 6:
    borrow_book();
    break;


    case 7:
    return_book();
    break;


    case 8:
    printf("Exited successully! \n");
    break;

    default:
    printf("Invalid choice! \n");
    break;

}

}


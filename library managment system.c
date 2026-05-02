/*
 * ============================================================
 *  LIBRARY MANAGEMENT SYSTEM
 *  Language  : C
 *  Syllabus  : GTU First-Year Engineering
 *  Concepts  : Structures, Functions, File Handling, Strings,
 *              Loops, Conditionals, Switch-Case
 * ============================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* -- Data Structure --------------------------------------- */
/* A structure to hold details of one book */
struct Book {
    int   id;
    char  name[50];
    char  author[50];
    float price;
};

/* -- File name constant ------------------------------------ */
#define FILE_NAME "books.txt"

/* -- Function Prototypes ----------------------------------- */
void addBook();
void displayBooks();
void searchByAuthor();
void countBooks();
void deleteBook();

/* ============================================================
 *  MAIN FUNCTION - shows the menu and calls other functions
 * ============================================================ */
int main() {
    int choice;   /* stores the user's menu selection */

    printf("\n========================================\n");
    printf("    WELCOME TO LIBRARY MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    /* Keep showing the menu until the user chooses to exit */
    do {
        printf("\n-------- MAIN MENU --------\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search by Author\n");
        printf("4. Count Total Books\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Call the matching function based on user choice */
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchByAuthor();
                break;
            case 4:
                countBooks();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                printf("\nThank you for using the Library System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number from 1 to 6.\n");
        }

    } while (choice != 6);   /* loop ends only when user picks 6 */

    return 0;
}

/* ============================================================
 *  FUNCTION: addBook
 *  PURPOSE : Read book details from user and save to file
 * ============================================================ */
void addBook() {
    struct Book b;   /* create a Book variable to hold input */
    FILE *fp;        /* file pointer */

    /* Take input from the user */
    printf("\n--- Add New Book ---\n");
    printf("Enter Book ID     : ");
    scanf("%d", &b.id);

    /* Clear leftover newline from buffer before reading strings */
    getchar();

    printf("Enter Book Name   : ");
    fgets(b.name, sizeof(b.name), stdin);
    /* Remove the newline character that fgets captures */
    b.name[strcspn(b.name, "\n")] = '\0';

    printf("Enter Author Name : ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Price       : ");
    scanf("%f", &b.price);

    /* Open the file in append mode so existing records are not lost */
    fp = fopen(FILE_NAME, "a");

    /* Check if file opened successfully */
    if (fp == NULL) {
        printf("\nError: Could not open file to save data.\n");
        return;
    }

    /* Write one book record per line, fields separated by '|' */
    fprintf(fp, "%d|%s|%s|%.2f\n", b.id, b.name, b.author, b.price);

    fclose(fp);   /* always close the file after use */

    printf("\nBook added successfully!\n");
}

/* ============================================================
 *  FUNCTION: displayBooks
 *  PURPOSE : Read all books from file and print them
 * ============================================================ */
void displayBooks() {
    struct Book b;   /* temporary variable to hold each record */
    FILE *fp;
    int found = 0;   /* flag: becomes 1 if at least one record exists */

    /* Open file in read mode */
    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("\nNo records found. The library is empty.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("  %-5s  %-25s  %-20s  %s\n", "ID", "Book Name", "Author", "Price");
    printf("============================================================\n");

    /* Read records one by one until end of file */
    while (fscanf(fp, "%d|%49[^|]|%49[^|]|%f\n",
                  &b.id, b.name, b.author, &b.price) == 4) {
        printf("  %-5d  %-25s  %-20s  Rs. %.2f\n",
               b.id, b.name, b.author, b.price);
        found = 1;
    }

    fclose(fp);

    if (found == 0) {
        printf("  No records found.\n");
    }

    printf("============================================================\n");
}

/* ============================================================
 *  FUNCTION: searchByAuthor
 *  PURPOSE : Find and display all books by a given author
 * ============================================================ */
void searchByAuthor() {
    struct Book b;
    FILE *fp;
    char searchName[50];   /* author name entered by user */
    int found = 0;

    /* Clear input buffer, then read the author name to search */
    getchar();
    printf("\n--- Search by Author ---\n");
    printf("Enter Author Name : ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';   /* remove newline */

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("\nNo records found. The library is empty.\n");
        return;
    }

    printf("\n--- Books by \"%s\" ---\n", searchName);

    /* Loop through every record in the file */
    while (fscanf(fp, "%d|%49[^|]|%49[^|]|%f\n",
                  &b.id, b.name, b.author, &b.price) == 4) {

        /* Compare author name (case-sensitive) */
        if (strcmp(b.author, searchName) == 0) {
            printf("  ID    : %d\n",       b.id);
            printf("  Name  : %s\n",       b.name);
            printf("  Price : Rs. %.2f\n", b.price);
            printf("  --------------------------\n");
            found = 1;
        }
    }

    fclose(fp);

    /* If no matching record was found, inform the user */
    if (found == 0) {
        printf("Author not found. No books by \"%s\" in the library.\n", searchName);
    }
}

/* ============================================================
 *  FUNCTION: countBooks
 *  PURPOSE : Count and display the total number of book records
 * ============================================================ */
void countBooks() {
    struct Book b;
    FILE *fp;
    int count = 0;   /* counter variable, starts at 0 */

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("\nNo records found. Total books: 0\n");
        return;
    }

    /* Read through every record and increment the counter */
    while (fscanf(fp, "%d|%49[^|]|%49[^|]|%f\n",
                  &b.id, b.name, b.author, &b.price) == 4) {
        count++;
    }

    fclose(fp);

    printf("\nTotal number of books in the library: %d\n", count);
}

/* ============================================================
 *  FUNCTION: deleteBook
 *  PURPOSE : Delete a book record by its ID
 *
 *  HOW IT WORKS:
 *  Step 1 - Read ALL records from file into an array
 *  Step 2 - Skip the record whose ID matches the delete ID
 *  Step 3 - Rewrite the remaining records back to the file
 * ============================================================ */
void deleteBook() {
    struct Book b;
    struct Book books[100];  /* temporary array to hold all records */
    FILE *fp;
    int deleteID;            /* ID the user wants to delete */
    int count = 0;           /* number of records kept (not deleted) */
    int found = 0;           /* flag: 1 if the ID was found */
    int i;

    printf("\n--- Delete Book ---\n");
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteID);

    /* -- Step 1: Read all records from file into array -- */
    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("\nNo records found. Nothing to delete.\n");
        return;
    }

    while (fscanf(fp, "%d|%49[^|]|%49[^|]|%f\n",
                  &b.id, b.name, b.author, &b.price) == 4) {

        if (b.id == deleteID) {
            found = 1;       /* found the book to delete - do NOT copy it */
        } else {
            books[count] = b;  /* keep all other books in the array */
            count++;
        }
    }

    fclose(fp);

    /* -- Step 2: If ID not found, stop here -- */
    if (found == 0) {
        printf("\nBook with ID %d not found.\n", deleteID);
        return;
    }

    /* -- Step 3: Rewrite the file with remaining records -- */
    fp = fopen(FILE_NAME, "w");   /* "w" mode clears the old file */

    if (fp == NULL) {
        printf("\nError: Could not open file to save changes.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%s|%.2f\n",
                books[i].id, books[i].name, books[i].author, books[i].price);
    }

    fclose(fp);

    printf("\nBook with ID %d deleted successfully!\n", deleteID);
}

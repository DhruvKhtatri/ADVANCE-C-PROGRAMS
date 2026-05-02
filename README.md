# ADVANCE-C-PROGRAMS
Library Management System in C is a simple console-based project for GTU students. It supports adding, displaying, searching, counting, and deleting books. The program uses basic concepts like structures, functions, file handling, loops, and strings, with clean and easy-to-understand code.
# 📚 Library Management System in C

A simple **console-based Library Management System** built in C language as part of the **GTU First-Year Engineering syllabus**. The program allows users to add, display, search, count, and delete book records — all stored in a local text file.

---

## 🖥️ Demo

```
========================================
    WELCOME TO LIBRARY MANAGEMENT SYSTEM
========================================

-------- MAIN MENU --------
1. Add Book
2. Display All Books
3. Search by Author
4. Count Total Books
5. Delete Book
6. Exit
---------------------------
Enter your choice:
```

---

## ✨ Features

| # | Feature | Description |
|---|---------|-------------|
| 1 | **Add Book** | Enter Book ID, Name, Author, and Price — saved to file |
| 2 | **Display All Books** | View all stored book records in a formatted table |
| 3 | **Search by Author** | Find all books written by a specific author |
| 4 | **Count Total Books** | Display the total number of books in the library |
| 5 | **Delete Book** | Remove a book record permanently using its ID |

---

## 📂 Project Structure

```
LibraryManagement/
│
├── library_management.c    # Main source code
├── books.txt               # Auto-created file where book data is stored
└── README.md               # Project documentation
```

---

## 🗄️ Data Storage

All book records are saved in **`books.txt`** in the same folder as the program.

Each line in the file stores one book in this format:

```
101|The C Programming Language|Brian Kernighan|450.00
102|Let Us C|Yashavant Kanetkar|350.00
103|Data Structures|Yashavant Kanetkar|500.00
```

> The file is created automatically when you add your first book. You can open it with any text editor like Notepad.

---

## 🛠️ C Concepts Used

This project strictly follows the **GTU First-Year Engineering syllabus** and demonstrates:

- `struct` — to define the Book data structure
- **Functions** — separate functions for each operation
- **File Handling** — `fopen`, `fclose`, `fprintf`, `fscanf`
- **Strings** — `strcmp`, `strcspn`, `fgets`
- **Loops** — `while`, `do-while`
- **Conditionals** — `if-else`, `switch-case`
- **Arrays** — used in delete function to hold records temporarily

---

## ⚙️ How to Compile and Run

### On Windows (using GCC / MinGW)

```bash
gcc library_management.c -o library_management
library_management.exe
```

### On Linux / Mac

```bash
gcc library_management.c -o library_management
./library_management
```

> **Requirement:** GCC compiler must be installed on your system.

---

## 📖 How to Use

**1. Add a Book**
- Choose option `1`
- Enter the Book ID, Book Name, Author Name, and Price
- Record is saved to `books.txt`

**2. Display All Books**
- Choose option `2`
- All saved books are shown in a table format

**3. Search by Author**
- Choose option `3`
- Enter the author's name (case-sensitive)
- All books by that author are displayed

**4. Count Total Books**
- Choose option `4`
- Shows the total number of books currently stored

**5. Delete a Book**
- Choose option `5`
- Enter the Book ID you want to delete
- That record is permanently removed from `books.txt`

**6. Exit**
- Choose option `6` to close the program

---

## 📋 Sample Output

**Adding a Book:**
```
--- Add New Book ---
Enter Book ID     : 101
Enter Book Name   : Let Us C
Enter Author Name : Yashavant Kanetkar
Enter Price       : 350

Book added successfully!
```

**Displaying All Books:**
```
============================================================
  ID     Book Name                  Author                Price
============================================================
  101    Let Us C                   Yashavant Kanetkar    Rs. 350.00
  102    The C Programming Language Brian Kernighan       Rs. 450.00
============================================================
```

**Deleting a Book:**
```
--- Delete Book ---
Enter Book ID to delete: 101

Book with ID 101 deleted successfully!
```

---

## ⚠️ Limitations

- Maximum **100 books** can be stored in the array during delete operation (can be changed by editing the array size in `deleteBook()`)
- Author name search is **case-sensitive** (e.g., `Kanetkar` ≠ `kanetkar`)
- Book IDs are not auto-generated — user must enter them manually
- No duplicate ID check is implemented

---

## 👨‍💻 Author

**Your Name**
- GitHub: [@yourusername](https://github.com/yourusername)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 🎓 Academic Info

| Field | Details |
|-------|---------|
| Language | C |
| Syllabus | GTU — First Year Engineering |
| Subject | Programming for Problem Solving (PPS) |
| Level | Beginner |

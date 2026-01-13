
# Library Management System

A Qt-based application for managing library items (books and magazines) with borrowing functionality.

## Features

- 📚 Manage both books and magazines
- 🔍 Search/filter items by title, author, or type
- 📝 Track borrowing status and borrower information
- 💾 Automatic saving/loading of library data
- 🖥️ User-friendly table interface

## Installation

1.  **Prerequisites**:
    - Qt 5.15+ or Qt 6.x
    - C++17 compatible compiler

2.  **Build Instructions**:
    ```bash
    qmake LibrarySystem.pro
    make
    # or for Windows:
    qmake LibrarySystem.pro -spec win32-msvc
    nmake
    ```

3.  **Run the Application**:
    ```bash
    ./LibrarySystem
    # or on Windows:
    LibrarySystem.exe
    ```

## Usage

### Adding Items
1.  Select item type (Book/Magazine) from dropdown
2.  Fill in title, author, and ID fields
3.  For books: enter genre
4.  For magazines: enter issue number
5.  Click "Add Item"

### Borrowing/Returning
1.  Select an item from the table
2.  Click "Borrow/Return" button
3.  For borrowing: enter borrower name
4.  For returning: confirm return

### Searching
- Type in the search box to filter items
- Search matches against title and author fields

### Data Management
- Data automatically saves when closing
- Data loads automatically on startup
- File saved as `library_data.txt` in application directory

## File Format
Data is stored in pipe-delimited format:
````

Type|Title|Author|ID|Extra|Borrowed|Borrower|BorrowDate

```
Example:
```

Book|The Great Gatsby|F. Scott Fitzgerald|101|Classic|John Smith|2023-06-15T14:30:00
Magazine|National Geographic|Various|201|456|0||

```

## Project Structure

```

LibraryManagementQT_AppFile/
├── Book.h/cpp          - Book item implementation
├── Magazine.h/cpp      - Magazine item implementation
├── LibraryItem.h/cpp   - Base library item class
├── MainWindow.h/cpp    - Main application UI
├── main.cpp            - Application entry point
└── library\_data.txt    - Data storage file (auto-generated)

```

## Dependencies

- Qt Core
- Qt GUI
- Qt Widgets

## License

MIT License

---

Developed by Tshepo Manyisa 
For questions or support, please contact: 68447353@mylife.unisa.ac.za

```

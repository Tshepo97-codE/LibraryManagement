# Console-Based Library Management System (COS2614)

## 📌 Project Overview

This repository contains a **console-based Library Management System** developed in **C++** as part of the **COS2614 Assignment 1**. The project demonstrates strong foundational knowledge of **Object-Oriented Programming (OOP)** concepts and basic **file handling**, presented in a clean, structured, and industry-readable way for future employers.

The system allows users to manage library items such as **books** and **magazines**, including adding items, searching, borrowing, returning, and persisting data using files.

---

## 🎯 Assignment Objective

The primary goal of this assignment is to reinforce understanding and practical application of **OOP principles in C++**, including:

* Encapsulation
* Inheritance
* Polymorphism
* Abstraction

This is achieved by building a functional, menu-driven library management system that runs entirely in the console.

---

## 🧩 System Description

The Library Management System enables users to:

* Add books and magazines to the library
* Search for library items
* Borrow and return items
* View available library items
* Persist data using file storage

All interactions are handled via a **menu-driven console interface**.

---

## 🛠️ Technical Requirements

### 1️⃣ Object-Oriented Design (40 Marks)

* A base class `LibraryItem` with the following attributes:

  * `title`
  * `author`
  * `id`
  * `isBorrowed`

* Derived classes:

  * `Book` → adds `genre`
  * `Magazine` → adds `issueNumber`

* Key OOP features implemented:

  * **Encapsulation**: Private member variables with getters and setters
  * **Inheritance**: `Book` and `Magazine` inherit from `LibraryItem`
  * **Polymorphism**: Virtual function `displayInfo()` overridden in derived classes

---

### 2️⃣ Console-Based User Interface (30 Marks)

* Menu-driven interaction

* Options to:

  * Add books or magazines
  * Search for items
  * Borrow items
  * Return items
  * Display all available items

* Output is formatted clearly for ease of use

---

### 3️⃣ File Handling & Data Persistence (20 Marks)

* Library data is stored in a text file (e.g., `library_data.txt`)
* Features include:

  * Loading data when the program starts
  * Saving new entries when items are added
  * Updating borrowing/returning status in the file

---

### 4️⃣ Borrowing & Returning Logic (20 Marks)

* Items can be marked as borrowed
* The system prevents borrowing an already borrowed item
* Borrowed items can be returned
* Item availability status is updated correctly

---

## 📂 Project Structure

```
Library-Management-System/
│
├── src/
│   ├── main.cpp
│   ├── LibraryItem.cpp
│   ├── Book.cpp
│   └── Magazine.cpp
│
├── include/
│   ├── LibraryItem.h
│   ├── Book.h
│   └── Magazine.h
│
├── data/
│   └── library_data.txt
│
├── README.md
└── .gitignore
```

*(Structure may vary slightly depending on implementation)*

---

## ▶️ How to Compile and Run

### Requirements

* C++ compiler (e.g. `g++`)
* Any standard C++ IDE or terminal

### Compile

```bash
g++ main.cpp LibraryItem.cpp Book.cpp Magazine.cpp -o library_system
```

### Run

```bash
./library_system
```

---

## 📑 Submission Requirements (Academic Context)

The original assignment required submission of:

* C++ source files (`.cpp`, `.h`)
* Any required resource files
* A README file with setup instructions
* Well-documented code
* A program that compiles and runs without errors

---

## 📊 Grading Breakdown

| Criteria                    | Marks   |
| --------------------------- | ------- |
| Class Design (OOP)          | 40      |
| Console Interface           | 30      |
| File Handling               | 20      |
| Borrow/Return Functionality | 20      |
| **Total**                   | **100** |

---

## 💡 Why This Project Matters (For Employers)

This project demonstrates:

* Strong understanding of **C++ and OOP fundamentals**
* Ability to design clean class hierarchies
* Experience with **file I/O and state persistence**
* Logical problem-solving and system design skills
* Writing maintainable and well-structured code

It serves as a solid foundational project showcasing readiness for **junior software development roles**.

---

## 👤 Author

**Tshepo Manyisa**
BSc Computer Science (UNISA)

---

## 📜 License

This project is for academic and portfolio purposes.

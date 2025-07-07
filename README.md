# 🏦 Bank Management System

## 📌 Overview

The **Bank Management System** is a multi-user console-based application that simulates the core functionalities of a bank. The system supports three main user roles: **Client**, **Employee**, and **Admin**, each with different permissions and responsibilities.

This project was developed collaboratively by a team of students as a part of a Course assignment, aiming to apply object-oriented programming, file handling, validation, and interface design in C++.

---

## 👥 Team Members

- Member 1: [ِAbdulrahman Saad]
- Member 2: [Rahma Ameen]
- Member 3: [Abdulaa]
---

## 🧩 System Modules

### 1️⃣ Client Module
- Each client has: `ID`, `Name`, `Password`, `Balance`
- Clients can:
  - Login to the system
  - Deposit and withdraw money
  - Transfer money to another client
  - Check their balance

### 2️⃣ Employee Module
- Each employee has: `ID`, `Name`, `Password`, `Salary`
- Employees can:
  - Login to the system
  - Add, edit, search, and list clients
  - View their own info

### 3️⃣ Admin Module
- Admin inherits from Employee with additional privileges:
  - Add, edit, search, and list employees
  - Manage both clients and employees

---

## 🏗️ System Structure

- ✅ **Inheritance Hierarchy**:  
  - `Person` → Base class (ID, Name, Password)  
  - `Client` & `Employee` inherit from `Person`  
  - `Admin` inherits from `Employee`

- ✅ **Validation Class**:  
  Centralized static validation functions for name, password, balance, and salary.

- ✅ **Data Persistence**:  
  Information is saved and retrieved from `.txt` files (`Clients.txt`, `Employees.txt`, `Admins.txt`).

- ✅ **Parser & FileManager**:  
  Responsible for reading from and writing to files, and converting string data to objects.

---

## 🔨 Application Phases

### 🚧 Phase 1: Core Classes
- Implement `Client`, `Employee`, `Admin` classes with validation
- Include deposit, withdraw, transfer, and display functions

### 💾 Phase 2: File Handling
- Implement `DataSourceInterface` and file operations
- Store all users' data in `.txt` files
- Develop `Parser`, `FilesHelper`, and `FileManager`

### 🧠 Phase 3: System Logic & UI
- Implement login, menus, and session management for:
  - `ClientManager`
  - `EmployeeManager`
  - `AdminManager`
  - `Screens` for UI flow and user interaction

---

## 🖥️ Technologies Used

- Programming Language: **C++**
- Concepts Applied:
  - OOP (Inheritance, Encapsulation)
  - File I/O operations
  - Abstract classes & interfaces
  - Static utility classes
  - Vectors & pointers

---

## ✅ Future Enhancements
- Add persistent login session
- GUI version with Qt or web interface
- Advanced error handling and logging

---

## 🧑‍💻 How to Run

1. Compile all `.cpp` files using any C++ compiler.
2. Run the program via terminal/console.
3. Use the on-screen menu to navigate as client, employee, or admin.

---

📬 *For any inquiries, suggestions, or collaboration, feel free to contact the project team.*


# Bancking_system
 💳 Bank System
🏦 Overview
A simple Bank System that allows Clients, Employees, and Admins to manage accounts, make transactions, and handle user data. The system includes three main modules:

Client Module: For individual clients to manage their accounts.

Employee Module: For employees to manage clients and perform basic tasks.

Admin Module: Admins manage employees and perform administrative tasks.

🔑 Features
1. Client Module
Login: Clients can log in using their ID and password.

Balance Management: Clients can check their account balance, deposit, or withdraw money.

Money Transfer: Clients can send money to other clients.

2. Employee Module
Login: Employees can log in using their credentials.

Add Clients: Employees can add new clients.

Manage Clients: Employees can search for clients, edit their details, and list all clients.

3. Admin Module
Employee Management: Admin can add, edit, or list employees.

Admin Privileges: Admins have the same rights as employees but with added privileges to manage employees.

🔧 How It Works
The Person class is the base for both Client and Employee.

Client inherits basic info from Person and adds functionality for transactions.

Employee inherits from Person and adds the ability to manage clients.

Admin inherits from Employee and adds the ability to manage employees.



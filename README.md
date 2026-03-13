# Inventory Management System (C++)

A **console-based Inventory Management System** built using C++.
This project simulates a real-world inventory system used in small stores or warehouses.

Designed as a portfolio project to demonstrate core programming and system design skills.

---

## Features

- Login System (Admin / Staff)
- Add Product
- View Inventory Table
- Search Product by ID
- Sell Product (with stock deduction)
- Delete Product
- Low Stock Alert
- Sales Report
- File-Based Data Storage
- Menu-Driven Interface

---

## Technologies Used

- C++ Programming Language
- Struct Data Structures
- Arrays
- File Handling (fstream)
- Console UI
- Basic Authentication Logic

---

## System Architecture

User

↓

Console Interface

↓

Inventory Logic

↓

File Storage

**Data Files Used**

products.txt — stores product inventory

sales.txt — stores sales transactions

---

## Product Data Format

Each product is stored in this format:

ID Name Stock Price

Example:

101 Coke 20 15

102 Bread 10 25

103 Milk 15 50

---

## Sales Data Format

Each sale record contains:

ProductName  Quantity  TotalPrice

Example:

Coke 2 30

Bread 1 25

---

## Login Credentials

Admin or Staff access:

Username: admin or staff

Password: 1234

---

## Example Menu

1 Add Product

2 View Products

3 Search Product

4 Sell Product

5 Delete Product

6 Low Stock Alert

7 Sales Report

8 Exit

---

## Learning Objectives

This project demonstrates:

• Struct-based data modeling

• Array storage in memory

• File persistence using text files

• Inventory management logic

• Menu-driven program design

• Basic authentication system

---

## Project Structure

Inventory-Management-System

│

├ main.cpp

├ products.txt

├ sales.txt

├ README.md

│

└ docs

├ login.png

├ menu.png

└ inventory.png

---

## Purpose of the Project

This system was developed as a portfolio project to demonstrate practical programming skills required for entry-level software development roles.

It simulates a simplified Point-of-Sale (POS) inventory backend.

---

## Author

**Geneva Bagona**

Aspiring Software Developer

Philippines 🇵🇭

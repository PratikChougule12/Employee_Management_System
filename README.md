# 🏢 Employee Management System

A console-based **Employee Management System** built in C++ for Windows. It provides a simple login/signup interface and full CRUD operations to manage employee records within a session.

---

## ✨ Features

- **Signup & Login** — Create a username/password at startup and authenticate before accessing the system
- **Add Employees** — Enter multiple employee records (up to 100) with ID, name, address, contact number, and salary
- **View All Records** — Display a formatted list of all stored employees
- **Search by ID** — Quickly look up a specific employee using their unique ID
- **Update Records** — Modify any employee's details by ID
- **Delete Records** — Remove a single record by ID or wipe all records at once
- **Input Validation** — Handles invalid salary input and enforces employee limits

---

## 🛠️ Tech Stack

- **Language:** C++
- **Platform:** Windows (uses `windows.h`, `conio.h`, `Sleep()`, `system("CLS")`)
- **Standard:** C++11 or later

---

## 🚀 Getting Started

### Prerequisites

- Windows OS
- A C++ compiler such as [MinGW (g++)](https://www.mingw-w64.org/) or MSVC

### Build & Run

```bash
# Using g++
g++ -o EmployeeMS main.cpp

# Run
./EmployeeMS
```

### Usage

1. On launch, **sign up** with a username and password.
2. **Log in** with those credentials.
3. Use the numbered menu to manage employee records:

```
1. Add New Employee Data
2. Show All Employee Data
3. Search Employee Data
4. Update Employee Data
5. Delete Employee Data
6. Logout
7. Exit Program
```

---
---

## 🔮 Possible Improvements

- [ ] Add file I/O to persist employee data between sessions
- [ ] Cross-platform support (Linux/macOS)
- [ ] Replace `goto` with a proper loop
- [ ] Add password hashing for security
- [ ] Support sorting and filtering of records

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

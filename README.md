# 🧾 Employee Management System (C++)

This is a console-based **Employee Management System** written in C++. It allows small organizations or teams to efficiently manage employee information, including salary calculations, department sorting, promotions, and more. The system also provides persistent data storage using a text file.

---

## 🚀 Features

- ➕ **Add New Employees**  
  Input employee details including ID, name, hours worked, salary per hour, title, and department.

- 📄 **Display Employees**  
  View all employees or filter them by department.

- 🔍 **Search Employees**  
  Search by employee name and department to quickly find specific entries.

- ✏️ **Update Employee Info**  
  Modify employee name, hours, salary, title, or department.

- 📈 **Promote Employees**  
  Change an employee’s title and/or salary.

- ❌ **Remove Employees**  
  Delete employee records using their ID.

- 🔄 **Move Between Departments**  
  Reassign employees to different departments.

- 💰 **Salary Calculator**  
  Automatically compute total salary based on hours worked and pay rate.

- 💾 **Data Persistence**  
  All changes are saved to `emp.txt` so data is retained between sessions.

---

## 🏷️ Departments

- 1: Human Resources  
- 2: Sales  
- 3: Customer Service  
- 4: Finance  

---

## 📁 Files

| File | Description |
|------|-------------|
| `finnal_employee.cpp` | Main C++ source code with all functionality |
| `emp.txt` | Output file storing employee data |

---

## 🛠️ How to Run

1. Compile the program:
   ```bash
   g++ -o employee_system finnal_employee.cpp

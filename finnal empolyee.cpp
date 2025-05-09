// finnal empolyee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;
const int MAX_EMPLOYEES = 100;
const int NUM_DEPARTMENTS = 4;
int num_employees = 0;
enum Department { HUMAN_RESOURCES = 1, SALES, CUSTOMER_SERVICE, FINANCE };
struct Employee {
    int id;
    string name;
    int hours_worked;
    double salary_per_hour;
    string title;
    Department department;
};
string departmentToString(Department dept) {
    switch (dept) {
    case HUMAN_RESOURCES: return "Human Resources";
    case SALES: return "Sales";
    case CUSTOMER_SERVICE: return "Customer Service";
    case FINANCE: return "Finance";
    default: return "Unknown";
    }
}
Employee employees[MAX_EMPLOYEES]; // Global employees array

void load_data(string filename) {
    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (line.find("Employee ID :") != string::npos) {
                employees[num_employees].id = stoi(line.substr(line.find(":") + 1));
            }
            else if (line.find("Employee Name :") != string::npos) {
                employees[num_employees].name = line.substr(line.find(":") + 2);
            }
            else if (line.find("Employee Hours Worked :") != string::npos) {
                employees[num_employees].hours_worked = stoi(line.substr(line.find(":") + 2));
            }
            else if (line.find("Employee Salary Per Hour :") != string::npos) {
                employees[num_employees].salary_per_hour = stod(line.substr(line.find(":") + 2));
            }
            else if (line.find("Employee Title :") != string::npos) {
                employees[num_employees].title = line.substr(line.find(":") + 2);
            }
            else if (line.find("Department:") != string::npos) {
                string dept = line.substr(line.find(":") + 2);
                if (dept == "HUMAN_RESOURCES") {
                    employees[num_employees].department = HUMAN_RESOURCES;
                }
                else if (dept == "SALES") {
                    employees[num_employees].department = SALES;
                }
                else if (dept == "CUSTOMER_SERVICE") {
                    employees[num_employees].department = CUSTOMER_SERVICE;
                }
                else if (dept == "FINANCE") {
                    employees[num_employees].department = FINANCE;
                }
                num_employees++;
            }
        }
        infile.close();
    }
}

void save_data(int num_of_employees_newly_added) {
    ofstream fileOut("emp.txt");
    if (!fileOut) {
        cerr << "Could not open the file for writing." << endl;
        return;
    }
    num_employees = num_employees + num_of_employees_newly_added;
    for (int i = 0; i < num_employees; i++) {
        fileOut << "---------------------------" << endl;
        fileOut << "Employee ID :" << employees[i].id << "\n";
        fileOut << "Employee Name : " << employees[i].name << "\n";
        fileOut << "Employee Hours Worked : " << employees[i].hours_worked << "\n";
        fileOut << "Employee Salary Per Hour : " << employees[i].salary_per_hour << "\n";
        fileOut << "Employee Title : " << employees[i].title << "\n";
        switch (employees[i].department) {
        case HUMAN_RESOURCES:
            fileOut << "Department: HUMAN_RESOURCES" << endl;
            break;
        case SALES:
            fileOut << "Department: SALES" << endl;
            break;
        case CUSTOMER_SERVICE:
            fileOut << "Department: CUSTOMER_SERVICE" << endl;
            break;
        case FINANCE:
            fileOut << "Department: FINANCE" << endl;
            break;
        default:
            fileOut << "Department: UNKNOWN" << endl;
            break;
        }
        fileOut << "--------------------------------" << endl;
    }
    fileOut.close();
    cout << "Data saved successfully.\n";
}

void add(int num_to_add_employees) {

    for (int i = (num_employees); i < (num_employees + num_to_add_employees); i++) {
        cout << "Enter ID : ";
        cin >> employees[i].id;
        cout << "Enter Employee name : ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "Enter Employee hours worked : ";
        cin >> employees[i].hours_worked;
        cout << "Enter Employee salary per hour : ";
        cin >> employees[i].salary_per_hour;
        cout << "Enter Employee Title : ";
        cin.ignore();
        getline(cin, employees[i].title);
        cout << "Enter department (1 for HUMAN_RESOURCES, 2 for SALES, 3 for CUSTOMER_SERVICE, 4 for FINANCE): ";
        int num;
        cin >> num;

        switch (num) {
        case 1:
            employees[i].department = HUMAN_RESOURCES;
            break;
        case 2:
            employees[i].department = SALES;
            break;
        case 3:
            employees[i].department = CUSTOMER_SERVICE;
            break;
        case 4:
            employees[i].department = FINANCE;
            break;
        default:
            cout << "---------------------------" << endl;
            cout << "Invalid department.\n";
            cout << "---------------------------" << endl;
            continue;
        }
    }
}



//1
void display_all_employees() {
    for (int i = 0; i < num_employees; i++) {
        cout << "---------------------------" << endl;
        cout << "ID: " << employees[i].id << endl;
        cout << "Name: " << employees[i].name << endl;
        cout << "Hours Worked: " << employees[i].hours_worked << endl;
        cout << "Salary per Hour: " << employees[i].salary_per_hour << endl;
        cout << "Title: " << employees[i].title << endl;
        cout << "Department: " << departmentToString(employees[i].department) << endl;
        cout << "---------------------------" << endl;
    }
}

//2
void display_choosen_department_employees(Department department) {
    bool found = false;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].department == department) {
            found = true;
            cout << "---------------------------" << endl;
            cout << "ID: " << employees[i].id << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Hours Worked: " << employees[i].hours_worked << endl;
            cout << "Salary Per Hour: " << employees[i].salary_per_hour << endl;
            cout << "Title: " << employees[i].title << endl;
            cout << "Department: " << departmentToString(employees[i].department) << endl;
            cout << "---------------------------" << endl;
        }
    }

    if (!found) {
        cout << "---------------------------" << endl;
        cout << "NO EMPLOYEES FOUND" << endl;
        cout << "---------------------------" << endl;
    }
}

//3
void search_employee(string name, Department department) {
    bool found = false;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].name == name && employees[i].department == department) {
            found = true;
            cout << "---------------------------" << endl;
            cout << "ID :" << employees[i].id << endl;
            cout << "hours worked :" << employees[i].hours_worked << endl;
            cout << "salary per hour :" << employees[i].salary_per_hour << endl;
            cout << "title :" << employees[i].title << endl;
            cout << "---------------------------" << endl;
        }

    }
    if (!found) {
        cout << "---------------------------" << endl;
        cout << "NO EMPLOYEES FOUND" << endl;
        cout << "---------------------------" << endl;
    }

}

void promote_employee(int id, double newSalary_per_hour, string newTitle) {
    bool promote = false;
    for (int i = 0; i < num_employees; i++) {

        if (employees[i].id == id) {
            promote = true;
            employees[i].title = newTitle;
            employees[i].salary_per_hour = newSalary_per_hour;
            // return;  
        }

    }
    if (!promote) {
        cout << "---------------------------" << endl;
        cout << "Employee NOT Found" << endl;
        cout << "---------------------------" << endl;

    }
    else
    {
        save_data(0);
        cout << "---------------------------" << endl;
        cout << "Employee info Promoted successfully" << endl;
        cout << "---------------------------" << endl;
    }
}

//6
void remove_employee(int id) {
    bool found = false;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            employees[i] = employees[num_employees - 1]; // Swap with the last employee
            num_employees--; // Decrease the count
            found = true;
            break;
        }
    }

    if (found) {
        ofstream outfile("emp.txt");
        for (int i = 0; i < num_employees; i++) {
            outfile << employees[i].id << endl;
            outfile << employees[i].name << endl;
            outfile << employees[i].hours_worked << endl;
            outfile << employees[i].salary_per_hour << endl;
            outfile << employees[i].title << endl;
            outfile << employees[i].department << endl;
        }
        outfile.close();

        cout << "---------------------------" << endl;
        cout << "Employee removed successfully.\n";
        cout << "---------------------------" << endl;
    }
    else {
        cout << "---------------------------" << endl;
        cout << "Employee NOT found\n";
        cout << "---------------------------" << endl;
    }
}
//7
void move_employee(int id, Department newDepartment) {
    bool move = false;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            move = true;
            employees[i].department = newDepartment;
        }
    }
    if (!move) {
        cout << "---------------------------" << endl;
        cout << "Employee NOT found" << endl;
        cout << "---------------------------" << endl;
    }
    else
        cout << "---------------------------" << endl;
    cout << "Employee Moved to the new department" << endl;
    cout << "---------------------------" << endl;
}
//8

void calculate_salary(int id) {
    bool found = false;
    double total_salary;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            found = true;
            total_salary = employees[i].hours_worked * employees[i].salary_per_hour;
            cout << "---------------------------" << endl;
            cout << "Employee ID: " << employees[i].id << endl;
            cout << "Employee Name: " << employees[i].name << endl;
            cout << "Total Salary: $" << total_salary << endl;
            cout << "---------------------------" << endl;
            break;
        }
    }
    if (!found) {
        cout << "---------------------------" << endl;
        cout << "Employee ID not found.\n";
        cout << "---------------------------" << endl;
    }
}



void update_employee(int id, string newName, int newHours_worked, double newSalary_per_hour, string newTitle, Department newDepartment) {
    bool found = false;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            employees[i].name = newName;
            employees[i].hours_worked = newHours_worked;
            employees[i].salary_per_hour = newSalary_per_hour;
            employees[i].title = newTitle;
            employees[i].department = newDepartment;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "---------------------------" << endl;
        cout << "Employee ID not found.\n";
        cout << "---------------------------" << endl;
    }
    else {
        save_data(0);
        cout << "---------------------------" << endl;
        cout << "Employee updated successfully.\n";
        cout << "---------------------------" << endl;
    }
}

int main() {
    load_data("emp.txt");
    int num_of_employees_to_add;
    Department department;
    int id, num;
    string name;
    string newName, newTitle;
    int newHours_worked;
    double newSalary_per_hour;
    Department newDepartment;
    string filename = "emp.txt";
    cout << "=================================" << endl;
    cout << "   Employee Management System" << endl;
    cout << "=================================" << endl;


    int choice;
    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Display all employees\n";
        cout << "2. Display department employees\n";
        cout << "3 Search for an employee\n";
        cout << "4. Update employee info\n";
        cout << "5. Promote an employee\n";
        cout << "6. Remove an employee\n";
        cout << "7. Move an employee to another department\n";
        cout << "8. Calculate salaries\n";
        cout << "9. Save data to file\n";
        cout << "10.Add Empolyee \n";
        cout << "11.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            display_all_employees();
            break;
        case 2:
            //chosen 
            cout << "Enter department (HR/Sales/CS/Finance): ";
            cin.ignore(); //*
            getline(cin, name);
            if (name == "HR" || name == "Human Resources") {
                department = HUMAN_RESOURCES;
            }
            else if (name == "Sales") {
                department = SALES;
            }
            else if (name == "CS" || name == "Customer Service") {
                department = CUSTOMER_SERVICE;
            }
            else if (name == "Finance") {
                department = FINANCE;
            }
            else {
                cout << "Invalid department\n";
                break;
            }
            display_choosen_department_employees(department);
            break;


        case 3:
           // search
            cout << "Enter employee name: ";
            cin.ignore(); //*
            getline(cin, name);
            cout << "Enter department (1 for HUMAN_RESOURCES, 2 for SALES, 3 for CUSTOMER_SERVICE, 4 for FINANCE): ";
            cin >> num;

            switch (num) {
            case 1:
                department = HUMAN_RESOURCES;
                break;
            case 2:
                department = SALES;
                break;
            case 3:
                department = CUSTOMER_SERVICE;
                break;
            case 4:
                department = FINANCE;
                break;
            default:
                cout << "Invalid department.\n";
                continue;
            }
            search_employee(name, department);
            break;

        case 4:
            //update
            cout << "Enter employee id: ";
            cin >> id;
            cout << "Enter new name : " << endl;
            cin.ignore(); //*
            getline(cin, newName);
            cout << "Enter new hours worked : " << endl;
            cin >> newHours_worked;
            cout << "Enter new Salarymper hour: " << endl;
            cin >> newSalary_per_hour;
            cout << "Enter new Title : " << endl;
            cin >> newTitle;
            cout << " Enter NEW department(1 for HUMAN_RESOURCES, 2 for SALES, 3 for CUSTOMER_SERVICE, 4 for FINANCE)  : " << endl;
            cin >> num;
            switch (num) {
            case 1:
                newDepartment = HUMAN_RESOURCES;
                break;
            case 2:
                newDepartment = SALES;
                break;
            case 3:
                newDepartment = CUSTOMER_SERVICE;
                break;
            case 4:
                newDepartment = FINANCE;
                break;
            }
            update_employee(id, newName, newHours_worked, newSalary_per_hour, newTitle, newDepartment);
            break;
        case 5:
            //promote
            cout << "Enter employee ID : ";
            cin >> id;
            cout << "promote employee TITLE: ";
            cin >> newTitle;
            cout << "Promote Employee SALARY: ";
            cin >> newSalary_per_hour;
            promote_employee(id, newSalary_per_hour, newTitle);
            break;
        case 6:
            //remove
            cout << "Enter employee id: ";
            cin >> id;
            remove_employee(id);
            save_data(0);
            break;
        case 7:
            //move
            cout << "Enter employee id: ";
            cin >> id;
            cout << "Enter new department (HR/Sales/CS/Finance): ";
            cin >> name;
            if (name == "HR" || name == "Human Resources") {
                newDepartment = HUMAN_RESOURCES;
            }
            else if (name == "Sales") {
                newDepartment = SALES;
            }
            else if (name == "CS" || name == "Customer Service") {
                newDepartment = CUSTOMER_SERVICE;
            }
            else if (name == "Finance") {
                newDepartment = FINANCE;
            }
            else {
                cout << "---------------------------" << endl;
                cout << "Invalid department\n";
                cout << "---------------------------" << endl;

            }
            move_employee(id, newDepartment);
            save_data(0);
            break;
        case 8:
            //calculate
            cout << "Enter Employee ID: " << endl;
            cin >> id;
            calculate_salary(id);
            break;
        case 9:
            save_data(0);
            break;
        case 10:
            //add
            cout << "enter number of employees: " << endl;
            cin >> num_of_employees_to_add;
            add(num_of_employees_to_add);
            save_data(num_of_employees_to_add);
            break;
        case 11:
            cout << "Exiting...\n";
            exit(0);
            cout << "---------------------------" << endl;
        default:
            cout << "Invalid choice\n";
            cout << "---------------------------" << endl;
        }
    } while (true);

}
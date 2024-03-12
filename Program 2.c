#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define CODE_LENGTH 9
#define NAME_LENGTH 21

struct Employee {
    char code[CODE_LENGTH];
    char name[NAME_LENGTH];
    double salary;
    double allowance;
};

// Function prototypes
void addEmployee(struct Employee employees[], int *count);
void findEmployeeByName(struct Employee employees[], int count);
void removeEmployeeByCode(struct Employee employees[], int *count);
void printDescendingOrder(struct Employee employees[], int count);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1- Add a new employee\n");
        printf("2- Find data about an employee by name\n");
        printf("3- Remove an employee by code\n");
        printf("4- Print the list in descending order based on salary + allowance\n");
        printf("5- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                findEmployeeByName(employees, count);
                break;
            case 3:
                removeEmployeeByCode(employees, &count);
                break;
            case 4:
                printDescendingOrder(employees, count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

void addEmployee(struct Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter employee code (8 characters): ");
    scanf("%s", employees[*count].code);

    printf("Enter employee name (up to 20 characters): ");
    scanf("%s", employees[*count].name);

    printf("Enter employee salary: ");
    scanf("%lf", &employees[*count].salary);

    printf("Enter employee allowance: ");
    scanf("%lf", &employees[*count].allowance);

    (*count)++;
    printf("Employee added successfully.\n");
}

void findEmployeeByName(struct Employee employees[], int count) {
    char name[NAME_LENGTH];
    int i;
    printf("Enter the name of the employee you want to find: ");
    scanf("%s", name);

    for (i = 0; i < count; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Employee found:\n");
            printf("Code: %s\n", employees[i].code);
            printf("Name: %s\n", employees[i].name);
            printf("Salary: %.2lf\n", employees[i].salary);
            printf("Allowance: %.2lf\n", employees[i].allowance);
            return;
        }
    }

    printf("Employee with name %s not found.\n", name);
}

void removeEmployeeByCode(struct Employee employees[], int *count) {
    char code[CODE_LENGTH];
    int i,j;
    printf("Enter the code of the employee you want to remove: ");
    scanf("%s", code);

    for (i = 0; i < *count; i++) {
        if (strcmp(employees[i].code, code) == 0) {
            for (j = i; j < *count - 1; j++) {
                strcpy(employees[j].code, employees[j + 1].code);
                strcpy(employees[j].name, employees[j + 1].name);
                employees[j].salary = employees[j + 1].salary;
                employees[j].allowance = employees[j + 1].allowance;
            }
            (*count)--;
            printf("Employee with code %s removed successfully.\n", code);
            return;
        }
    }

    printf("Employee with code %s not found.\n", code);
}

void printDescendingOrder(struct Employee employees[], int count) {
    // Bubble sort in descending order based on salary + allowance
    int i,j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            double currentIncome = employees[j].salary + employees[j].allowance;
            double nextIncome = employees[j + 1].salary + employees[j + 1].allowance;
            if (currentIncome < nextIncome) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("Employees in descending order based on salary + allowance:\n");
    for (i = 0; i < count; i++) {
        printf("Code: %s, Name: %s, Total Income: %.2lf\n", employees[i].code, employees[i].name, employees[i].salary + employees[i].allowance);
    }
}


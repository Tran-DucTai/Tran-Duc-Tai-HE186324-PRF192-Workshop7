#include <stdio.h>
#include <string.h>

#define MAX_DRINKS 100
#define MAX_NAME_LENGTH 20
#define MAX_MAKE_LENGTH 20

// Define structure for soft drink
struct SoftDrink {
    char name[MAX_NAME_LENGTH];
    char make[MAX_MAKE_LENGTH];
    int volume;
    int price;
    int duration;
};

// Function prototypes
void addSoftDrink(struct SoftDrink drinks[], int *count);
void printByMake(struct SoftDrink drinks[], int count, char make[]);
void printByVolumeRange(struct SoftDrink drinks[], int count, int v1, int v2);
void printAscendingOrder(struct SoftDrink drinks[], int count);

int main() {
    struct SoftDrink drinks[MAX_DRINKS];
    int count = 0;
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1- Add a new soft drink\n");
        printf("2- Print items by make\n");
        printf("3- Print items whose volumes are between v1 and v2\n");
        printf("4- Print the list in ascending order based on volumes then prices\n");
        printf("5- Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addSoftDrink(drinks, &count);
                break;
            case 2: {
                char make[MAX_MAKE_LENGTH];
                printf("Enter the make: ");
                scanf("%s", make);
                printByMake(drinks, count, make);
                break;
            }
            case 3: {
                int v1, v2;
                printf("Enter the range of volumes (v1 and v2): ");
                scanf("%d %d", &v1, &v2);
                printByVolumeRange(drinks, count, v1, v2);
                break;
            }
            case 4:
                printAscendingOrder(drinks, count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}

// Function to add a new soft drink
void addSoftDrink(struct SoftDrink drinks[], int *count) {
    if (*count >= MAX_DRINKS) {
        printf("Cannot add more soft drinks. Maximum capacity reached.\n");
        return;
    }
    
    printf("Enter name, make, volume, price, and duration (in days): ");
    scanf("%s %s %d %d %d", drinks[*count].name, drinks[*count].make,
                            &drinks[*count].volume, &drinks[*count].price,
                            &drinks[*count].duration);
    (*count)++;
    printf("Soft drink added successfully.\n");
}

// Function to print items by make
void printByMake(struct SoftDrink drinks[], int count, char make[]) {
	int i;
    printf("Items by make %s:\n", make);
    for (i = 0; i < count; i++) {
        if (strcmp(drinks[i].make, make) == 0) {
            printf("%s\t%s\t%dml\t$%d\t%d days\n", drinks[i].name, drinks[i].make,
                                                    drinks[i].volume, drinks[i].price,
                                                    drinks[i].duration);
        }
    }
}

// Function to print items whose volumes are between v1 and v2
void printByVolumeRange(struct SoftDrink drinks[], int count, int v1, int v2) {
    printf("Items whose volumes are between %dml and %dml:\n", v1, v2);
    int i;
	for (i = 0; i < count; i++) {
        if (drinks[i].volume >= v1 && drinks[i].volume <= v2) {
            printf("%s\t%s\t%dml\t$%d\t%d days\n", drinks[i].name, drinks[i].make,
                                                    drinks[i].volume, drinks[i].price,
                                                    drinks[i].duration);
        }
    }
}

// Function to print the list in ascending order based on volumes then prices
void printAscendingOrder(struct SoftDrink drinks[], int count) {
    // Bubble sort
    int i,j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (drinks[j].volume > drinks[j + 1].volume || 
               (drinks[j].volume == drinks[j + 1].volume && drinks[j].price > drinks[j + 1].price)) {
                // Swap
                struct SoftDrink temp = drinks[j];
                drinks[j] = drinks[j + 1];
                drinks[j + 1] = temp;
            }
        }
    }
    
    printf("List in ascending order based on volumes then prices:\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%s\t%dml\t$%d\t%d days\n", drinks[i].name, drinks[i].make,
                                                drinks[i].volume, drinks[i].price,
                                                drinks[i].duration);
    }
}


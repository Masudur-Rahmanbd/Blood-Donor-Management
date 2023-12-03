#include <stdio.h>
#include <string.h>

// Structure to store donor information
struct Donor {
    char name[50];
    int age;
    char bloodType[5];
};

// Function to add a new donor
void addDonor(struct Donor donors[], int *count) {
    printf("Enter donor name: ");
    scanf("%s", donors[*count].name);

    printf("Enter donor age: ");
    scanf("%d", &donors[*count].age);

    printf("Enter donor blood type: ");
    scanf("%s", donors[*count].bloodType);

    (*count)++; // Increment the donor count
}

// Function to display all donors
void displayDonors(struct Donor donors[], int count) {
    printf("\nDonor List:\n");
    printf("%-20s %-10s %-5s\n", "Name", "Age", "Blood Type");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-5s\n", donors[i].name, donors[i].age, donors[i].bloodType);
    }
}

// Function to search for donors based on blood type
void searchDonor(struct Donor donors[], int count, char bloodType[]) {
    printf("\nDonors with blood type %s:\n", bloodType);
    printf("%-20s %-10s %-5s\n", "Name", "Age", "Blood Type");

    for (int i = 0; i < count; i++) {
        if (strcmp(donors[i].bloodType, bloodType) == 0) {
            printf("%-20s %-10d %-5s\n", donors[i].name, donors[i].age, donors[i].bloodType);
        }
    }
}

int main() {
    struct Donor donors[100]; // Assuming a maximum of 100 donors
    int donorCount = 0;

    int choice;
    char searchBloodType[5];

    do {
        printf("\nBlood Donor Management System\n");
        printf("1. Add Donor\n");
        printf("2. Display Donors\n");
        printf("3. Search Donors by Blood Type\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDonor(donors, &donorCount);
                break;
            case 2:
                displayDonors(donors, donorCount);
                break;
            case 3:
                printf("Enter blood type to search: ");
                scanf("%s", searchBloodType);
                searchDonor(donors, donorCount, searchBloodType);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}



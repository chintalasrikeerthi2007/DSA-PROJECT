#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Queue variables
int queue[MAX];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int patient);
void dequeue();
void display();
void searchPatient();
void countPatients();
void clearQueue();
void header();
void menu();


// Function to print header
void header() {
    printf("\n=============================================\n");
    printf("         HOSPITAL QUEUE MANAGEMENT SYSTEM     \n");
    printf("=============================================\n");
}


// Add patient to the queue
void enqueue(int patient) {
    if (rear == MAX - 1) {
        printf("\nQueue is FULL! Cannot add more patients.\n");
    } else {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = patient;

        printf("\nPatient with ID %d has been ADDED to the queue.\n", patient);
    }
}


// Remove first patient from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nNo patients in the queue to serve.\n");
    } else {
        printf("\nPatient with ID %d has been SERVED.\n", queue[front]);
        front++;
    }
}


// Display all patients in queue
void display() {
    int i;

    if (front == -1 || front > rear) {
        printf("\nQueue is EMPTY. No patients waiting.\n");
    } else {
        printf("\nPatients currently in the queue:\n");

        for (i = front; i <= rear; i++)
            printf("Patient ID: %d\n", queue[i]);
    }
}


// Search for a patient ID
void searchPatient() {
    int id, i, found = 0;

    if (front == -1 || front > rear) {
        printf("\nQueue is EMPTY. Nothing to search.\n");
        return;
    }

    printf("\nEnter patient ID to search: ");
    scanf("%d", &id);

    for (i = front; i <= rear; i++) {
        if (queue[i] == id) {
            printf("\nPatient ID %d FOUND at position %d in the queue.\n", id, i - front + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nPatient ID %d NOT found in the queue.\n", id);
}


// Count total patients in the queue
void countPatients() {
    if (front == -1 || front > rear) {
        printf("\nNo patients in the queue.\n");
    } else {
        printf("\nTotal patients in the queue: %d\n", rear - front + 1);
    }
}


// Completely clear the queue
void clearQueue() {
    front = -1;
    rear = -1;
    printf("\nQueue has been CLEARED successfully!\n");
}


// Show menu
void menu() {
    printf("\n-------------------- MENU --------------------\n");
    printf("1. Add Patient (Enqueue)\n");
    printf("2. Serve Patient (Dequeue)\n");
    printf("3. Display Queue\n");
    printf("4. Search for a Patient\n");
    printf("5. Count Total Patients\n");
    printf("6. Clear Entire Queue\n");
    printf("7. Exit\n");
    printf("----------------------------------------------\n");
    printf("Enter your choice: ");
}


// Main program
int main() {
    int choice, patientID;

    while (1) {
        header();
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter patient ID to ADD: ");
                scanf("%d", &patientID);
                enqueue(patientID);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                searchPatient();
                break;

            case 5:
                countPatients();
                break;

            case 6:
                clearQueue();
                break;

            case 7:
                printf("\nExiting program... Thank you!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

        printf("\nPress ENTER to continue...");
        getchar();
        getchar();
        system("cls"); // Works in Dev-C++ / Windows
    }

    return 0;
}

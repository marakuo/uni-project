#include <stdio.h>

#define TOTAL_TABLES 5
#define TOTAL_ROOMS 4

// flag to be tested
int hasBooked = 0;

// showing available table
void showTables(int tables[]) {
    printf("\n=== Available Tables ===\n");
    for (int i = 0; i < TOTAL_TABLES; i++) {
        printf("Table %d: %s\n", i + 1, tables[i] == 0 ? "Available" : "Booked");
    }
}

// booking a table
int bookTable(int tables[]) {
    int tableChoice;
    showTables(tables);

    printf("\nPlease enter the number of the table you want to book (1 to %d): ", TOTAL_TABLES);
    scanf("%d", &tableChoice);

    if (tableChoice < 1 || tableChoice > TOTAL_TABLES) {
        printf("Sorry! That table number is out of range.\n");
        return 0;
    }

    if (tables[tableChoice - 1] == 0) {
        tables[tableChoice - 1] = 1;
        printf("Great! Table %d has been successfully booked for you.\n", tableChoice);
        return 1;
    } else {
        printf("Sorry, Table %d is already booked. Try another one.\n", tableChoice);
        return 0;
    }
}

// available rooms
void showRooms(int rooms[]) {
    printf("\n=== Available Rooms ===\n");
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i] == 0 ? "Available" : "Booked");
    }
}

// booking a room
int bookRoom(int rooms[]) {
    int roomChoice;
    showRooms(rooms);

    printf("\nPlease enter the number of the room you want to book (1 to %d): ", TOTAL_ROOMS);
    scanf("%d", &roomChoice);

    if (roomChoice < 1 || roomChoice > TOTAL_ROOMS) {
        printf("Oops! That room number is out of range.\n");
        return 0;
    }

    if (rooms[roomChoice - 1] == 0) {
        rooms[roomChoice - 1] = 1;
        printf("Awesome! Room %d has been successfully booked for you.\n", roomChoice);
        return 1;
    } else {
        printf("Sorry, Room %d is already booked. Please pick a different one.\n", roomChoice);
        return 0;
    }
}

void displaySubPlans() {
    printf("\n=== Workspace Subscription Plans ===\n");
    printf("1. 1 Hour - $1\n");
    printf("2. Whole Day - $5\n");
    printf("3. Weekly Plan - $25 (10%% off)\n");
    printf("4. Monthly Plan - $80 (20%% off)\n");
    printf("5. Student Pass (Monthly) - $60 (25%% off with ID)\n");
    printf("\nChoose a plan (1-5): ");
}

// Function to calculate the subscription plan cost
float calculateSubCost(int choice) {
    float cost = 0.0;
    switch (choice) {
        case 1:
            cost = 1.0;
            break;
        case 2:
            cost = 5.0;
            break;
        case 3:
            cost = 25.0 * 0.90;  // discount 10%
            break;
        case 4:
            cost = 80.0 * 0.80;  // discount 20%
            break;
        case 5:
            cost = 60.0 * 0.75;  // discount 25% for students
            break;
        default:
            printf("Invalid choice!\n");
            return -1.0; // Indicating an invalid choice
    }
    return cost;
}

// Function to display available Wi-Fi plans and get user selection
int selectWiFiPlan() {
    int wifiChoice;

    printf("\nAvailable Wi-Fi Plans:\n");
    printf("1. Free Wi-Fi (Basic Speed)\n");
    printf("2. Paid Wi-Fi (High Speed)\n");
    printf("3. Premium Wi-Fi (Ultra High Speed)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &wifiChoice);

    // Validate the user input
    while (wifiChoice < 1 || wifiChoice > 3) {
        printf("Invalid choice. Please select a valid Wi-Fi plan (1-3): ");
        scanf("%d", &wifiChoice);
    }

    return wifiChoice; // Return the user's selection
}

// Function to calculate Wi-Fi plan cost
float calculateWiFiCost(int choice) {
    float cost = 0.0;
    switch (choice) {
        case 1:
            cost = 0.0;  // Free Wi-Fi
            break;
        case 2:
            cost = 2.0;  // Paid Wi-Fi (High Speed)
            break;
        case 3:
            cost = 5.0;  // Premium Wi-Fi (Ultra High Speed)
            break;
        default:
            printf("Invalid Wi-Fi choice!\n");
            return -1.0; // Indicating an invalid choice
    }
    return cost;
}

int main() {
    int rooms[TOTAL_ROOMS] = {0};    // 0 = available, 1 = booked (both room and table)
    int tables[TOTAL_TABLES] = {0};
    int userChoice;

    printf("\" Welcome to the Smart Workspace Booking System \" \n");

    while (1) {
        printf("\n-----------------------------\n");
        printf("What would you like to do?\n");
        printf("1. View Subscription Plans\n");
        printf("2. View Wi-Fi Plan\n");
        printf("3. View Available Tables\n");
        printf("4. Book a Table\n");
        printf("5. View Available Rooms\n");
        printf("6. Book a Room\n");
        printf("8. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                int subChoice;
                float subTotalCost;

                displaySubPlans();
                scanf("%d", &subChoice);

                subTotalCost = calculateSubCost(subChoice);

                if (subTotalCost != -1.0) {
                    printf("\nYou have selected the Workspace Subscription Plan.\n");
                    printf("Plan: ");
                    switch (subChoice) {
                        case 1:
                            printf("1 Hour - $1\n");
                            break;
                        case 2:
                            printf("Whole Day - $5\n");
                            break;
                        case 3:
                            printf("Weekly Plan - $25 (10%% off)\n");
                            break;
                        case 4:
                            printf("Monthly Plan - $80 (20%% off)\n");
                            break;
                        case 5:
                            printf("Student Pass (Monthly) - $60 (25%% off with ID)\n");
                            break;
                        default:
                            printf("Invalid plan selection.\n");
                    }
                    printf("Cost: $%.2f\n", subTotalCost);
                } else {
                    printf("\nSubscription failed. Invalid choice.\n");
                }
                break;

            case 2:
                int wifiChoice;
                float wifiCost;

                wifiChoice = selectWiFiPlan();
                wifiCost = calculateWiFiCost(wifiChoice);

                if (wifiCost != -1.0) {
                    printf("\nYou have selected the Wi-Fi Plan.\n");
                    switch (wifiChoice) {
                        case 1:
                            printf("Free Wi-Fi (Basic Speed)\n");
                            break;
                        case 2:
                            printf("Paid Wi-Fi (High Speed)\n");
                            break;
                        case 3:
                            printf("Premium Wi-Fi (Ultra High Speed)\n");
                            break;
                        default:
                            printf("Invalid Wi-Fi plan selection.\n");
                    }
                    printf("Additional cost: $%.2f\n", wifiCost);
                } else {
                    printf("\nWi-Fi selection failed. Invalid choice.\n");
                }
                break;

            case 3:
                showTables(tables);
                break;

            case 4:
                if (bookTable(tables)) {
                    hasBooked = 1;
                }
                break;

            case 5:
                showRooms(rooms);
                break;

            case 6:
                if (bookRoom(rooms)) {
                    hasBooked = 1;
                }
                break;

            case 8:
                printf("\nThank you for using our system. Have a productive day!\n");
                return 0;

            default:
                printf("Invalid input. Please select a number from 1 to 8.\n");
        }
    }

    return 0;
}

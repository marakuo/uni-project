#include <stdio.h>

#define TOTAL_TABLES 5
#define TOTAL_ROOMS 4
#define WEEKLY_DISCOUNT 0.90
#define MONTHLY_DISCOUNT 0.80
#define STUDENT_DISCOUNT 0.75

// Showing available tables
void showTables(int tables[]) {
    printf("\n=== Available Tables ===\n");
    for (int i = 0; i < TOTAL_TABLES; i++) {
        printf("Table %d: %s\n", i + 1, tables[i] == 0 ? "Available" : "Booked");
    }
}

// Booking a table
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

// Showing available rooms
void showRooms(int rooms[]) {
    printf("\n=== Available Rooms ===\n");
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i] == 0 ? "Available" : "Booked");
    }
}

// Booking a room
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

// Display subscription plans
void displaySubPlans() {
    printf("\n=== Workspace Subscription Plans ===\n");
    printf("1. 1 Hour - $1\n");
    printf("2. Whole Day - $5\n");
    printf("3. Weekly Plan - $25 (10%% off)\n");
    printf("4. Monthly Plan - $80 (20%% off)\n");
    printf("5. Student Pass (Monthly) - $60 (25%% off with ID)\n");
    printf("\nChoose a plan (1-5): ");
}

// Calculate subscription plan cost
float calculateSubCost(int choice) {
    float cost = 0.0;
    switch (choice) {
        case 1: cost = 1.0; break;
        case 2: cost = 5.0; break;
        case 3: cost = 25.0 * WEEKLY_DISCOUNT; break;
        case 4: cost = 80.0 * MONTHLY_DISCOUNT; break;
        case 5: cost = 60.0 * STUDENT_DISCOUNT; break;
        default: printf("Invalid choice!\n"); return -1.0;
    }
    return cost;
}

// Display and select Wi-Fi plan
int selectWiFiPlan() {
    int wifiChoice;
    printf("\nAvailable Wi-Fi Plans:\n");
    printf("1. Free Wi-Fi (Basic Speed)\n");
    printf("2. Paid Wi-Fi (High Speed)\n");
    printf("3. Premium Wi-Fi (Ultra High Speed)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &wifiChoice);

    while (wifiChoice < 1 || wifiChoice > 3) {
        printf("Invalid choice. Please select a valid Wi-Fi plan (1-3): ");
        scanf("%d", &wifiChoice);
    }
    return wifiChoice;
}

// Calculate Wi-Fi plan cost
float calculateWiFiCost(int choice) {
    float cost = 0.0;
    switch (choice) {
        case 1: cost = 0.0; break;
        case 2: cost = 2.0; break;
        case 3: cost = 5.0; break;
        default: printf("Invalid Wi-Fi choice!\n"); return -1.0;
    }
    return cost;
}

// Display snacks menu
void snacks() {
    printf("\n--- (Snacks Menu) ---\n");
    printf("1. Donut - $9\n");
    printf("2. Toast - $6\n");
    printf("3. Brownie - $5\n");
    printf("4. Pancake - $6\n");
    printf("5. Cupcake - $5\n");
    printf("6. Ice Cream - $8\n");
    printf("7. Fresh Fruits - $5\n");
    printf("8. Apple Pie - $5\n");
    printf("9. Cookies - $5\n");
    printf("0. Done Ordering Snacks\n");
}

// Order snacks and calculate cost
float orderSnacks() {
    int choice;
    float totalCost = 0.0;
    do {
        snacks();
        printf("Enter your choice (0-9): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: totalCost += 9.0; printf("Added Donut ($9)\n"); break;
            case 2: totalCost += 6.0; printf("Added Toast ($6)\n"); break;
            case 3: totalCost += 5.0; printf("Added Brownie ($5)\n"); break;
            case 4: totalCost += 6.0; printf("Added Pancake ($6)\n"); break;
            case 5: totalCost += 5.0; printf("Added Cupcake ($5)\n"); break;
            case 6: totalCost += 8.0; printf("Added Ice Cream ($8)\n"); break;
            case 7: totalCost += 5.0; printf("Added Fresh Fruits ($5)\n"); break;
            case 8: totalCost += 5.0; printf("Added Apple Pie ($5)\n"); break;
            case 9: totalCost += 5.0; printf("Added Cookies ($5)\n"); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return totalCost;
}

// Display drinks menu
void drinks() {
    printf("\n--- (Drinks Menu) ---\n");
    printf("1. Coffee - $3\n");
    printf("2. Green Tea - $2\n");
    printf("3. Black Tea - $2\n");
    printf("4. Chamomile Tea - $3\n");
    printf("5. Lemon Juice - $2\n");
    printf("6. Strawberry Milk - $4\n");
    printf("7. Chocolate Milk - $4\n");
    printf("0. Done Ordering Drinks\n");
}

// Order drinks and calculate cost
float orderDrinks() {
    int choice;
    float totalCost = 0.0;
    do {
        drinks();
        printf("Enter your choice (0-7): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: totalCost += 3.0; printf("Added Coffee ($3)\n"); break;
            case 2: totalCost += 2.0; printf("Added Green Tea ($2)\n"); break;
            case 3: totalCost += 2.0; printf("Added Black Tea ($2)\n"); break;
            case 4: totalCost += 3.0; printf("Added Chamomile Tea ($3)\n"); break;
            case 5: totalCost += 2.0; printf("Added Lemon Juice ($2)\n"); break;
            case 6: totalCost += 4.0; printf("Added Strawberry Milk ($4)\n"); break;
            case 7: totalCost += 4.0; printf("Added Chocolate Milk ($4)\n"); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return totalCost;
}

// Display optional menu (snacks or drinks)
int optionalMenuDisplay() {
    int optionalchoice;
    printf("\n=== Choose either to Order a snack or a drink ===\n");
    printf("1. Snacks Menu\n");
    printf("2. Drinks Menu\n");
    printf("\nChoose an option (1-2): ");
    scanf("%d", &optionalchoice);
    while (optionalchoice < 1 || optionalchoice > 2) {
        printf("Invalid choice. Please select a valid option (1-2): ");
        scanf("%d", &optionalchoice);
    }
    return optionalchoice;
}

//  snack and drink ordering
float orderSnackMenu() {
    float totalCost = 0.0;
    int choice = optionalMenuDisplay();
    if (choice == 1) {
        totalCost = orderSnacks();
        if (totalCost > 0) printf("Total Snack Cost: $%.2f\n", totalCost);
    } else if (choice == 2) {
        totalCost = orderDrinks();
        if (totalCost > 0) printf("Total Drink Cost: $%.2f\n", totalCost);
    } else {
        printf("Invalid selection.\n");
    }
    return totalCost;
}

int main() {
    int rooms[TOTAL_ROOMS] = {0};    // 0 = available, 1 = booked
    int tables[TOTAL_TABLES] = {0};
    int userChoice;
    float totalCost = 0.0;           // track total cost
    int hasBooked = 0;               // track the booking process 

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
        printf("7. Order Snacks or Drinks %s\n", hasBooked ? "" : "(Requires Booking)");
        printf("8. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                int subChoice;
                float subCost;
                displaySubPlans();
                scanf("%d", &subChoice);
                subCost = calculateSubCost(subChoice);
                if (subCost != -1.0) {
                    printf("\nYou have selected the Workspace Subscription Plan.\n");
                    printf("Plan: ");
                    switch (subChoice) {
                        case 1: printf("1 Hour - $1\n"); break;
                        case 2: printf("Whole Day - $5\n"); break;
                        case 3: printf("Weekly Plan - $25 (10%% off)\n"); break;
                        case 4: printf("Monthly Plan - $80 (20%% off)\n"); break;
                        case 5: printf("Student Pass (Monthly) - $60 (25%% off with ID)\n"); break;
                        default: printf("Invalid plan selection.\n");
                    }
                    printf("Cost: $%.2f\n", subCost);
                    totalCost += subCost;
                } else {
                    printf("\nSubscription failed. Invalid choice.\n");
                }
                break;
            }

            case 2: {
                int wifiChoice;
                float wifiCost;
                wifiChoice = selectWiFiPlan();
                wifiCost = calculateWiFiCost(wifiChoice);
                if (wifiCost != -1.0) {
                    printf("\nYou have selected the Wi-Fi Plan.\n");
                    switch (wifiChoice) {
                        case 1: printf("Free Wi-Fi (Basic Speed)\n"); break;
                        case 2: printf("Paid Wi-Fi (High Speed)\n"); break;
                        case 3: printf("Premium Wi-Fi (Ultra High Speed)\n"); break;
                        default: printf("Invalid Wi-Fi plan selection.\n");
                    }
                    printf("Additional cost: $%.2f\n", wifiCost);
                    totalCost += wifiCost;
                } else {
                    printf("\nWi-Fi selection failed. Invalid choice.\n");
                }
                break;
            }

            case 3:
                showTables(tables);
                break;

            case 4: {
                if (bookTable(tables)) {
                    hasBooked = 1;
                    // asking to order snacks or drinks after booking
                    char order;
                    printf("\nWould you like to order a snack or drink? (y/n): ");
                    scanf(" %c", &order);
                    if (order == 'y' || order == 'Y') {
                        float snackDrinkCost = orderSnackMenu();
                        totalCost += snackDrinkCost;
                    } else if (order == 'n' || order == 'N') {
                        printf("No snack or drink selected.\n");
                    } else {
                        printf("Invalid selection.\n");
                    }
                }
                break;
            }

            case 5:
                showRooms(rooms);
                break;

            case 6: {
                if (bookRoom(rooms)) {
                    hasBooked = 1;
                    // Prompt for snacks/drinks immediately after booking
                    char order;
                    printf("\nWould you like to order a snack or drink? (y/n): ");
                    scanf(" %c", &order);
                    if (order == 'y' || order == 'Y') {
                        float snackDrinkCost = orderSnackMenu();
                        totalCost += snackDrinkCost;
                    } else if (order == 'n' || order == 'N') {
                        printf("No snack or drink selected.\n");
                    } else {
                        printf("Invalid selection.\n");
                    }
                }
                break;
            }

            case 7:
                if (!hasBooked) {
                    printf("\nYou must book a table or room before ordering snacks or drinks.\n");
                } else {
                    float snackDrinkCost = orderSnackMenu();
                    totalCost += snackDrinkCost;
                }
                break;

            case 8: {
                printf("\n=== Booking Details & Receipt ===\n");
                if (hasBooked) {
                    printf("Bookings:\n");
                    for (int i = 0; i < TOTAL_TABLES; i++) {
                        if (tables[i]) printf("=> Table %d\n", i + 1);
                    }
                    for (int i = 0; i < TOTAL_ROOMS; i++) {
                        if (rooms[i]) printf("=> Room %d\n", i + 1);
                    }
                } else {
                    printf("No bookings made.\n");
                }
                printf("Total Cost: $%.2f\n", totalCost);
                printf("\nThank you for using our system. Have a productive day!\n");
                return 0;
            }

            default:
                printf("Invalid input. Please select a number from 1 to 8.\n");
        }
    }

    return 0;
}


#include <stdio.h>

#define TOTAL_TABLES 5
#define TOTAL_ROOMS 4

// flag to be tested
int hasBooked = 0;

//  showing available table
void showTables(int tables[]) {
    printf("\n===  Available Tables ===\n");
    for (int i = 0; i < TOTAL_TABLES; i++) {
        printf("Table %d: %s\n", i + 1, tables[i] == 0 ? "Available" : "Booked");
    }
}

//  booking a table
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

//   available rooms
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

int main() {
    int rooms[TOTAL_ROOMS] = {0};    // 0 = Available, 1 = Booked
    int tables[TOTAL_TABLES] = {0};  // 0 = Available, 1 = Booked
    int userChoice;

    printf("\" Welcome to the Smart Workspace Booking System \" \n");

    while (1) {
        printf("\n-----------------------------\n");
        printf("What would you like to do?\n");
        printf("1. View Available Tables\n");
        printf("2. Book a Table\n");
        printf("3. View Available Rooms\n");
        printf("4. Book a Room\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                showTables(tables);
                break;
            case 2:
                if (bookTable(tables)) {
                    hasBooked = 1;
                }
                break;
            case 3:
                showRooms(rooms);
                break;
            case 4:
                if (bookRoom(rooms)) {
                    hasBooked = 1;
                }
                break;
            case 5:
                printf("\nThank you for using our system. have a productive day! \n");
                return 0;
            default:
                printf("Invalid input. Please select a number from 1 to 5.\n");
        }
    }


    return 0;
}

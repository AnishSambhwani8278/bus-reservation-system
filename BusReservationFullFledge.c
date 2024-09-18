#include <stdio.h>
#include <string.h>

struct bus
{
    int id;
    char name[50];
    char from[50];
    char to[50];
    int seats[20];
    int seatCount;
};

struct bus buses[10];
int busCount = 0;

void registerBus()
{
    if (busCount < 10)
    {
        printf("Enter Bus Name: ");
        scanf("%s", &buses[busCount].name);

        printf("Enter Bus Start: ");
        scanf("%s", &buses[busCount].from);

        printf("Enter Bus Destination: ");
        scanf("%s", &buses[busCount].to);

        // buses[busCount].seats[20] = {1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1};
        buses[busCount].seats[0] = 1;
        buses[busCount].seats[1] = 0;
        buses[busCount].seats[2] = 0;
        buses[busCount].seats[3] = 1;
        buses[busCount].seats[4] = 1;
        buses[busCount].seats[5] = 0;
        buses[busCount].seats[6] = 0;
        buses[busCount].seats[7] = 1;
        buses[busCount].seats[8] = 1;
        buses[busCount].seats[9] = 0;
        buses[busCount].seats[10] = 0;
        buses[busCount].seats[11] = 1;
        buses[busCount].seats[12] = 1;
        buses[busCount].seats[13] = 0;
        buses[busCount].seats[14] = 0;
        buses[busCount].seats[15] = 1;
        buses[busCount].seats[16] = 1;
        buses[busCount].seats[17] = 0;
        buses[busCount].seats[18] = 0;
        buses[busCount].seats[19] = 1;

        buses[busCount].id = busCount + 1;
        busCount++;
        return;
    }
    printf("No More Bus Registrations Allowed!\n");
}

void bookWindow(int busId)
{
    int seatIndex;
    int flag = 0;
    for (int i = 0; i < 20; i++)
    {
        if (buses[busId - 1].seats[i] == 1)
        {
            seatIndex = i;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("No Window Seat Available!\n");
    }
    else
    {
        buses[busId - 1].seats[seatIndex] = 2;
        printf("Window Seat %d: Booked\n", (seatIndex + 1));
    }
}

void bookNonWindow(int busId)
{
    int seatIndex;
    int flag = 0;
    for (int i = 0; i < 20; i++)
    {
        if (buses[busId - 1].seats[i] == 0)
        {
            seatIndex = i;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("No Seat Available!\n");
    }
    else
    {
        buses[busId - 1].seats[seatIndex] = 3;
        printf("Non-Window Seat %d: Booked\n", (seatIndex + 1));
    }
}

void bookTicket()
{
    if (busCount == 0)
    {
        printf("No Buses Registered!\n");
        return;
    }
    else
    {
        printf("Welcome To The Booking Window\n");
        printf("Enter The Bus ID: ");
        int busId;
        scanf("%d", &busId);

        printf("1. Want Window Seat?\n");
        printf("2. Want Non-Window Seat?\n");
        printf("3. Exit\n");

        int choice;
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bookWindow(busId);
            break;
        case 2:
            bookNonWindow(busId);
            break;
        case 3:
            printf("Exiting...\n");
            return;
        default:
            printf("Invalid!\n");
            return;
        }
    }
}

void cancelTicket()
{
    if (busCount == 0)
    {
        printf("No Buses Registered!\n");
        return;
    }

    int busId;
    printf("Enter Your Bus ID: ");
    scanf("%d", &busId);

    if (busId <= busCount && busId > 0)
    {
        int seatNumber;
        printf("Enter Your Seat Number: ");
        scanf("%d", &seatNumber);

        if (buses[busId - 1].seats[seatNumber - 1] == 2)
        {
            buses[busId - 1].seats[seatNumber - 1] = 1;
            printf("Seat %d: Cancelled Succesfully!\n", seatNumber);
        }
        else if (buses[busId - 1].seats[seatNumber - 1] == 3)
        {
            buses[busId - 1].seats[seatNumber - 1] = 0;
            printf("Seat %d: Cancelled Succesfully!\n", seatNumber);
        }
        else if (buses[busId - 1].seats[seatNumber - 1] == 0 || buses[busId - 1].seats[seatNumber - 1] == 1)
        {
            printf("This Seat Is Not Booked Yet!\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }

    else
    {
        printf("Not Valid Bus ID!\n");
    }
}

void checkSeats()
{
    if (busCount == 0)
    {
        printf("No Buses Registered!\n");
        return;
    }

    int id;
    printf("Enter Bus ID: ");
    scanf("%d", &id);

    if (id <= busCount && id > 0)
    {
        for (int i = 0; i < 20; i++)
        {
            if (buses[id - 1].seats[i] == 0 || buses[id - 1].seats[i] == 1)
            {
                printf("Seat %d: Available\n", i + 1);
            }
            else
            {
                printf("Seat %d: Reserved\n", i + 1);
            }
        }
    }

    else
    {
        printf("Not Valid Bus ID!\n");
    }
}

void checkBuses()
{
    if (busCount == 0)
    {
        printf("No Buses Registered!\n");
        return;
    }
    else
    {
        printf("Available Buses\n");
        for (int i = 0; i < busCount; i++)
        {
            if (busCount > 0)
            {
                printf("Bus ID: %d, Bus Name: %s, Bus Start: %s, Bus Destination: %s\n", buses[i].id, buses[i].name, buses[i].from, buses[i].to);
            }
            else
            {
                printf("No Buses Registered!\n");
            }
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Book Ticket\n2. Register Bus\n3. Check Buses\n4. Check Seats\n5. Cancel Ticket\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            bookTicket();
            break;
        case 2:
            registerBus();
            break;
        case 3:
            checkBuses();
            break;
        case 4:
            checkSeats();
            break;
        case 5:
            cancelTicket();
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
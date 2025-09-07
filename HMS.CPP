#include <iostream>
#include <stdlib.h>
using namespace std;
class HotelManagement {
private:
    // Quantities available in hotel
    int Qrooms, Qpasta, Qburger, Qnoodles, Qshake, Qchicken;

    // Quantities sold
    int Srooms, Spasta, Sburger, Snoodles, Sshake, Schicken;

    // Total collection
    int Total_rooms, Total_pasta, Total_burger, Total_noodles, Total_shake, Total_chicken;

public:
    HotelManagement() {
        Qrooms = Qpasta = Qburger = Qnoodles = Qshake = Qchicken = 0;
        Srooms = Spasta = Sburger = Snoodles = Sshake = Schicken = 0;
        Total_rooms = Total_pasta = Total_burger = Total_noodles = Total_shake = Total_chicken = 0;
    }

    void setrequirement() {
        cout << " Enter total number of Rooms available: ";
        cin >> Qrooms;
        cout << " Enter quantity of Pasta available: ";
        cin >> Qpasta;
        cout << " Enter quantity of Burgers available: ";
        cin >> Qburger;
        cout << " Enter quantity of Noodles available: ";
        cin >> Qnoodles;
        cout << " Enter quantity of Shakes available: ";
        cin >> Qshake;
        cout << " Enter quantity of Chicken-rolls available: ";
        cin >> Qchicken;
    }

    void displayMenu() {
        cout << "\n\n========== Hotel Management Menu ==========";
        cout << "\n1. Book Rooms";
        cout << "\n2. Order Pasta";
        cout << "\n3. Order Burger";
        cout << "\n4. Order Noodles";
        cout << "\n5. Order Shake";
        cout << "\n6. Order Chicken-roll";
        cout << "\n7. View Sales and Collection Report";
        cout << "\n8. Exit";
        cout << "\n===========================================";
        cout << "\n\nPlease enter your choice: ";
    }

    void processchoice(int choice) {
        int quant;
        switch (choice) {
            case 1:
                cout << "\nEnter the number of rooms you want: ";
                cin >> quant;
                if (Qrooms - Srooms >= quant) {
                    Srooms += quant;
                    Total_rooms += quant * 1200;
                    cout << "\n\t" << quant << " room(s) have been allotted to you!";
                } else {
                    cout << "\n\tOnly " << (Qrooms - Srooms) << " rooms remaining in hotel.";
                }
                break;

            case 2:
                cout << "\nEnter the pasta quantity: ";
                cin >> quant;
                if (Qpasta - Spasta >= quant) {
                    Spasta += quant;
                    Total_pasta += quant * 250;
                    cout << "\n\t" << quant << " pasta(s) ordered!";
                } else {
                    cout << "\n\tOnly " << (Qpasta - Spasta) << " pasta(s) remaining.";
                }
                break;

            case 3:
                cout << "\nEnter the burger quantity: ";
                cin >> quant;
                if (Qburger - Sburger >= quant) {
                    Sburger += quant;
                    Total_burger += quant * 180;
                    cout << "\n\t" << quant << " burger(s) ordered!";
                } else {
                    cout << "\n\tOnly " << (Qburger - Sburger) << " burger(s) remaining.";
                }
                break;

            case 4:
                cout << "\nEnter the noodles quantity: ";
                cin >> quant;
                if (Qnoodles - Snoodles >= quant) {
                    Snoodles += quant;
                    Total_noodles += quant * 210;
                    cout << "\n\t" << quant << " noodles ordered!";
                } else {
                    cout << "\n\tOnly " << (Qnoodles - Snoodles) << " noodles remaining.";
                }
                break;

            case 5:
                cout << "\nEnter the shakes quantity: ";
                cin >> quant;
                if (Qshake - Sshake >= quant) {
                    Sshake += quant;
                    Total_shake += quant * 100;
                    cout << "\n\t" << quant << " shake(s) ordered!";
                } else {
                    cout << "\n\tOnly " << (Qshake - Sshake) << " shake(s) remaining.";
                }
                break;

            case 6:
                cout << "\nEnter the Chicken-roll quantity: ";
                cin >> quant;
                if (Qchicken - Schicken >= quant) {
                    Schicken += quant;
                    Total_chicken += quant * 170;
                    cout << "\n\t" << quant << " chicken-roll(s) ordered!";
                } else {
                    cout << "\n\tOnly " << (Qchicken - Schicken) << " chicken-roll(s) remaining.";
                }
                break;

            case 7:
                displayreport();
                break;

            case 8:
                cout << "\nExiting... Thank you for using the system!\n";
                exit(0);

            default:
                cout << "\nInvalid choice! Please select a valid option.";
        }
    }

    void displayreport() {
        cout << "\n\n========== Sales and Collection Report ==========";
        cout << "\nRooms -> Had: " << Qrooms << " | Rented: " << Srooms << " | Remaining: " << (Qrooms - Srooms) << " | Collection: " << Total_rooms;
        cout << "\nPasta -> Had: " << Qpasta << " | Sold: " << Spasta << " | Remaining: " << (Qpasta - Spasta) << " | Collection: " << Total_pasta;
        cout << "\nBurger -> Had: " << Qburger << " | Sold: " << Sburger << " | Remaining: " << (Qburger - Sburger) << " | Collection: " << Total_burger;
        cout << "\nNoodles -> Had: " << Qnoodles << " | Sold: " << Snoodles << " | Remaining: " << (Qnoodles - Snoodles) << " | Collection: " << Total_noodles;
        cout << "\nShakes -> Had: " << Qshake << " | Sold: " << Sshake << " | Remaining: " << (Qshake - Sshake) << " | Collection: " << Total_shake;
        cout << "\nChicken-roll -> Had: " << Qchicken << " | Sold: " << Schicken << " | Remaining: " << (Qchicken - Schicken) << " | Collection: " << Total_chicken;
        cout << "\n=================================================";
    }
};

int main() {
    HotelManagement hotel;
    hotel.setrequirement();

    int choice;
    while (true) {
        hotel.displayMenu();
        cin >> choice;
        hotel.processchoice(choice);
    }

    return 0;
}


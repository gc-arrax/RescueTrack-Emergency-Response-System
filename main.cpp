
#include<bits/stdc++.h>
using namespace std;

// Function declarations

void findNearestFireStation();
void manageFireTrucks();
void searchEmergencyRecords();

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== SMART FIRE RESCUE SYSTEM =====\n";

        cout << "1. Find Nearest Fire Station\n";
        cout << "2. Manage Fire Trucks\n";
        cout << "3. Search Emergency Records\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            findNearestFireStation();
            break;

        case 2:
            manageFireTrucks();
            break;

        case 3:
            searchEmergencyRecords();
            break;

        case 4:
            cout << "\nThank you!\n";
            return 0;

        default:
            cout << "\nInvalid Choice!\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}


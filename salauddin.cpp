#include<bits/stdc++.h>
using namespace std;

void manageFireTrucks()
{
    vector<string> trucks =
    {
        "Fire Truck 1",
        "Fire Truck 2",
        "Fire Truck 3"
    };

    vector<string> status =
    {
        "Available",
        "Busy",
        "Available"
    };

    cout << "\n----- FIRE TRUCK STATUS -----\n";

    for (int i = 0; i < trucks.size(); i++)
    {
        cout << i + 1 << ". " << trucks[i]
             << " - " << status[i] << endl;
    }

    int choice;

    cout << "\nEnter truck number to book: ";
    cin >> choice;

    if (choice < 1 || choice > trucks.size())
    {
        cout << "Invalid truck number!\n";
        return;
    }

    if (status[choice - 1] == "Available")
    {
        status[choice - 1] = "Busy";

        cout << "\nBooking Successful!\n";
        cout << trucks[choice - 1] << " is now Busy.\n";
    }
    else
    {
        cout << "\nThis truck is already Busy!\n";
    }
}


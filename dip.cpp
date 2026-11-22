#include<bits/stdc++.h>
using namespace std;

void searchEmergencyRecords()
{
    vector<string> records =
    {
        "ID101 - Bornali - Building Fire",
        "ID102 - Laxmipur - Electrical Fire",
        "ID103 - Kazla - Factory Fire",
        "ID104 - Court - Road Accident",
        "ID105 - Railgate - Building Fire"
    };

    string keyword;

    cout << "\n----- EMERGENCY RECORD SEARCH -----\n";

    cout << "Enter location or emergency type: ";
    getline(cin >> ws, keyword);

    bool found = false;

    for (int i = 0; i < records.size(); i++)
    {
        if (records[i].find(keyword) != string::npos)
        {
            cout << records[i] << endl;
            found = true;
        }
    }

    if (found == false)
    {
        cout << "No record found\n";
    }
}


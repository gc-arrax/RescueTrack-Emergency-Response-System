#include<bits/stdc++.h>
using namespace std;

void findNearestFireStation()
{
    map<string, vector<pair<string, int>>> graph;

    // Road connections

    graph["Court"] = {{"Bornali", 4}, {"Rajpara", 5}};
    graph["Bornali"] = {{"Court", 4}, {"Laxmipur", 2}};
    graph["Rajpara"] = {{"Court", 5}, {"Laxmipur", 3}};
    graph["Laxmipur"] = {{"Bornali", 2}, {"Rajpara", 3}, {"Zero Point", 4}};

    graph["Zero Point"] = {{"Laxmipur", 4}, {"Railgate", 3}};
    graph["Railgate"] = {{"Zero Point", 3}, {"Talaimari", 5}};
    graph["Talaimari"] = {{"Railgate", 5}, {"Kazla", 3}};
    graph["Kazla"] = {{"Talaimari", 3}};

    // Fire Station locations

    map<string, string> stations;

    stations["Fire Station 1"] = "Court";
    stations["Fire Station 2"] = "Laxmipur";
    stations["Fire Station 3"] = "Talaimari";

    vector<string> locations =
    {
        "Court", "Bornali", "Rajpara", "Laxmipur",
        "Zero Point", "Railgate", "Talaimari", "Kazla"
    };

    cout << "\n===== AVAILABLE LOCATIONS =====\n";

    for (int i = 0; i < locations.size(); i++)
    {
        cout << i + 1 << ". " << locations[i] << endl;
    }

    int choice;

    cout << "\nEnter your location number: ";
    cin >> choice;

    if (choice < 1 || choice > locations.size())
    {
        cout << "Invalid location!\n";
        return;
    }

    string start = locations[choice - 1];

    map<string, int> distance;
    map<string, string> previous;

    for (auto node : graph)
    {
        distance[node.first] = INT_MAX;
    }

    distance[start] = 0;

    priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>> pq;

    pq.push({0, start});

    // Dijkstra Algorithm

    while (!pq.empty())
    {
        string current = pq.top().second;
        int currentDistance = pq.top().first;

        pq.pop();

        if (currentDistance > distance[current])
            continue;

        for (auto neighbor : graph[current])
        {
            string next = neighbor.first;
            int newDistance = currentDistance + neighbor.second;

            if (newDistance < distance[next])
            {
                distance[next] = newDistance;
                previous[next] = current;

                pq.push({newDistance, next});
            }
        }
    }

    // Find nearest station

    string nearestStation;
    string stationLocation;

    int minimumDistance = INT_MAX;

    for (auto station : stations)
    {
        string name = station.first;
        string location = station.second;

        if (distance[location] < minimumDistance)
        {
            minimumDistance = distance[location];
            nearestStation = name;
            stationLocation = location;
        }
    }

    cout << "\n----- RESCUE ROUTE RESULT -----\n";

    cout << "Your Location: " << start << endl;
    cout << "Nearest Fire Station: " << nearestStation << endl;
    cout << "Station Location: " << stationLocation << endl;
    cout << "Shortest Distance: " << minimumDistance << " km\n";

    // Print shortest route

    vector<string> path;

    string current = stationLocation;

    while (current != start)
    {
        path.push_back(current);
        current = previous[current];
    }

    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << "Shortest Route: ";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;
}


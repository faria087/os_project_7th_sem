#include <bits/stdc++.h>
using namespace std;

// Function to implement FIFO Scheduling
void fifo(vector<int> requests, int head)
{
    cout << "Execution Order: " << head << " -> ";
    int cost = 0;
    int newHead = head;
    for (int i = 0; i < requests.size(); i++)
    {
        cout << requests[i];
        if (i < requests.size() - 1)
            cout << " -> ";
        cost += abs(newHead - requests[i]);
        newHead = requests[i];
    }
    cout << endl;
    cout << "Total head movements = " << cost << endl;
    cout << "Average head movements = " << (double)cost / requests.size() << endl;
}

// Function to implement SJF Scheduling
void sjf(vector<int> requests, int head)
{
    sort(requests.begin(), requests.end());
    cout << "Execution Order: " << head << " -> ";
    int cost = 0;
    int newHead = head;
    for (int i = 0; i < requests.size(); i++)
    {
        cout << requests[i];
        if (i < requests.size() - 1)
            cout << " -> ";
        cost += abs(newHead - requests[i]);
        newHead = requests[i];
    }
    cout << endl;
    cout << "Total head movements = " << cost << endl;
    cout << "Average head movements = " << (double)cost / requests.size() << endl;
}

// Function to implement RR Scheduling
void rr(vector<int> requests, int head, int quantum)
{
    queue<int> rq;
    for (int req : requests)
        rq.push(req);

    cout << "Execution Order: " << head << " -> ";
    int cost = 0;
    int newHead = head;
    while (!rq.empty())
    {
        int current = rq.front();
        rq.pop();
        cout << current;
        if (!rq.empty())
            cout << " -> ";
        cost += abs(newHead - current);
        newHead = current;
    }
    cout << endl;
    cout << "Total head movements = " << cost << endl;
    cout << "Average head movements = " << (double)cost / requests.size() << endl;
}

int main()
{
    int n, size;
    cout << "Please enter the size of the disk: ";
    cin >> size;
    cout << "Please enter the number of requests: ";
    cin >> n;
    cout << "Please enter the requests: ";
    vector<int> requests;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        requests.push_back(temp);
    }
    int head;
    cout << "Please enter the initial head position: ";
    cin >> head;

    cout << endl
         << "FIFO Scheduling" << endl;
    fifo(requests, head);

    cout << endl
         << "SJF Scheduling" << endl;
    sjf(requests, head);

    int quantum;
    cout << endl
         << "Please enter time quantum for Round Robin: ";
    cin >> quantum;
    cout << "Round Robin Scheduling" << endl;
    rr(requests, head, quantum);

    return 0;
}

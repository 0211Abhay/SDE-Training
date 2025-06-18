#include <bits/stdc++.h>
using namespace std;

// Function to apply bookings using prefix sum technique
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res(n);
    for (auto &v : bookings) {
        res[v[0] - 1] += v[2];
        if (v[1] < n) res[v[1]] -= v[2];
    }
    for (int i = 1; i < n; ++i) res[i] += res[i - 1];
    return res;
}

// Main function
int main() {
    int m, n;
    cout << "Enter number of bookings: ";
    cin >> m;
    cout << "Enter number of flights: ";
    cin >> n;

    vector<vector<int>> bookings(m, vector<int>(3));
    cout << "Enter bookings (start end seats):\n";
    for (int i = 0; i < m; ++i) {
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }

    vector<int> result = corpFlightBookings(bookings, n);

    cout << "Final seat bookings for each flight:\n";
    for (int seats : result) {
        cout << seats << " ";
    }
    cout << endl;

    return 0;
}

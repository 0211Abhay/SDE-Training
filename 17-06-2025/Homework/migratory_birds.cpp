#include <bits/stdc++.h>
using namespace std;

int migratoryBirds(vector<int> arr) {
    unordered_map<int, int> BirdSight;
    for (int i : arr) {
        BirdSight[i]++;
    }

    int maxCount = 0, bird_type = INT_MAX;
    for (auto &entry : BirdSight) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            bird_type = entry.first;
        } else if (entry.second == maxCount && entry.first < bird_type) {
            bird_type = entry.first;
        }
    }
    return bird_type;
}

int main() {
    int n;
    cout << "Enter number of bird sightings: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter bird sighting IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = migratoryBirds(arr);
    cout << "Most frequently sighted bird type: " << result << endl;

    return 0;
}

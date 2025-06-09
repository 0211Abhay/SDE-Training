#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> freqMap;

    for (int num : arr) {
        freqMap[num]++;
    }

    set<int> freq_set;
    for (auto entry : freqMap) {
        if (freq_set.find(entry.second) != freq_set.end()) {
            return false;
        }
        freq_set.insert(entry.second);
    }

    return true;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bool result = uniqueOccurrences(arr);
    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}

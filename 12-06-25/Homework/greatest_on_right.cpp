#include <bits/stdc++.h>
using namespace std;

// Function to replace each element with the greatest element to its right
vector<int> replaceElements(vector<int>& arr) {
    int rep = -1;
    for (int i = arr.size() - 1; i >= 0; --i) {
        int num = arr[i];
        arr[i] = rep;
        rep = max(rep, num);
    }
    return arr;
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = replaceElements(arr);

    cout << "Array after replacement: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

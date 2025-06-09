#include <bits/stdc++.h>
using namespace std;

string balancedSums(vector<int> arr) {
    int ls = 0, rs = accumulate(arr.begin(), arr.end(), 0);
    for (int i = 0; i < arr.size(); i++) {
        rs -= arr[i];
        if (i != 0) ls += arr[i - 1];
        if (ls == rs) return "YES";
    }
    return "NO";
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

    string result = balancedSums(arr);
    cout << "Output: " << result << endl;

    return 0;
}

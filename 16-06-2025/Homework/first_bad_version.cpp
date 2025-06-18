#include <bits/stdc++.h>
using namespace std;

// Mocked bad version (you can change this value for testing)
int bad_version = 4;

// Mock API function
bool isBadVersion(int version) {
    return version >= bad_version;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n; // Versions are typically 1-based
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isBadVersion(mid)) h = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {
    int n;
    cout << "Enter total number of versions: ";
    cin >> n;

    cout << "Enter the first bad version: ";
    cin >> bad_version;

    Solution sol;
    int result = sol.firstBadVersion(n);

    cout << "First bad version is: " << result << endl;

    return 0;
}

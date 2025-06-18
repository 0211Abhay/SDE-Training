#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long hours = 0;
            for (int p : piles)
                hours += (p + mid - 1) / mid; // Ceiling division

            if (hours <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile sizes:\n";
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }

    cout << "Enter number of hours (h): ";
    cin >> h;

    Solution sol;
    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}

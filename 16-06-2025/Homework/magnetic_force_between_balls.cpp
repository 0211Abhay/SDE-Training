#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position[0];
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int lastPosition = position[0], balls = 1;
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - lastPosition >= mid) {
                    lastPosition = position[i];
                    balls++;
                }
            }
            if (balls >= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, m;
    cout << "Enter number of positions: ";
    cin >> n;

    vector<int> position(n);
    cout << "Enter the positions:\n";
    for (int i = 0; i < n; ++i) {
        cin >> position[i];
    }

    cout << "Enter number of balls: ";
    cin >> m;

    Solution sol;
    int result = sol.maxDistance(position, m);

    cout << "Maximum minimum distance to place the balls: " << result << endl;

    return 0;
}

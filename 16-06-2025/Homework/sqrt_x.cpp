#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int start = 1;
        int end = x;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            long long square = static_cast<long long>(mid) * mid;

            if (square == x)
                return mid;
            else if (square < x)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return end; 
    }
};

int main() {
    int x;
    cout << "Enter a number to find its integer square root: ";
    cin >> x;

    Solution sol;
    int result = sol.mySqrt(x);

    cout << "Integer square root of " << x << " is: " << result << endl;

    return 0;
}

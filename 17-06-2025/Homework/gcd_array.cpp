#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if(b == 0){
            cout << a << " " << b << "\n";  // Debug print
            return a;
        }
        cout << a << " " << b << "\n";  // Debug print
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int maxVal = nums[0];
        int minVal = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > maxVal) maxVal = nums[i];
            if(nums[i] < minVal) minVal = nums[i];
        }

        return gcd(maxVal, minVal);
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.findGCD(nums);
    cout << "GCD of largest and smallest element: " << result << endl;

    return 0;
}

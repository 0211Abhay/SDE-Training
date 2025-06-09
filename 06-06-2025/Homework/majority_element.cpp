#include <bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
    int candidate, count = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (count == 0) candidate = nums[i];
        if (nums[i] == candidate) count++;
        else count--;
    }
    return candidate;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = majorityElement(nums);
    cout << "Majority Element: " << result << endl;

    return 0;
}

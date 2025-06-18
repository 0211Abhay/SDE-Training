#include <bits/stdc++.h>
using namespace std;

// Function to compute running sum
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = runningSum(nums);

    cout << "Running Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

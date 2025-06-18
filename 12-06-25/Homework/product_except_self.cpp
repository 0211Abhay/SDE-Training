#include <bits/stdc++.h>
using namespace std;

// Function to compute product of array except self
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n);
    output[0] = 1;

    // Prefix products
    for (int i = 1; i < n; i++) {
        output[i] = output[i - 1] * nums[i - 1];
    }

    // Suffix product
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= right;
        right *= nums[i];
    }

    return output;
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

    vector<int> result = productExceptSelf(nums);

    cout << "Output array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

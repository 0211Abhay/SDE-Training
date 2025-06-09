#include <bits/stdc++.h>
using namespace std;


void moveZeroes(vector<int>& nums) {
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != 0) {
            swap(nums[right], nums[left]);
            left++;
        }
    }
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

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

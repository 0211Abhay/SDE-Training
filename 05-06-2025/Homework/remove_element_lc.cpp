#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val) {
        int start = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!= val){
                nums[start] = nums[i];
                start+=1;
            }
        }
        return start;
    }
int main() {
    int n, val;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter value to remove: ";
    cin >> val;

    int k = removeElement(nums, val);

    cout << "Output: " << k << ", nums = [";
    for (int i = 0; i < k; ++i) {
        cout << nums[i];
        if (i != k - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
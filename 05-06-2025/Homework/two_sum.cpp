#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
       

        unordered_map<int,int> mymap;
        for(int i = 0; i<nums.size();i++){
            if(mymap.count(target-nums[i]))
            {
                return{i,mymap[target-nums[i]]};
            }
            mymap[nums[i]] = i;
        }
        return {};
    }



int main() {
    int n, target;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
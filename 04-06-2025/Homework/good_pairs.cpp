#include<bits/stdc++.h>
using namespace std;
int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
        } 
        return count;   
    }

int main(){
        cout << "Enter size of nums"<<"\n";
    int n;
    cin >> n;
    vector<int> nums(n);


    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    int result = numIdenticalPairs(nums);
    cout << result;
}
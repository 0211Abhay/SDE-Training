#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for (int n : nums) {
            if (n == 0) zero++;
            else if (n == 1) one++;
            else two++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (zero > 0) {
                nums[i] = 0;
                zero--;
            } else if (one > 0) {
                nums[i] = 1;
                one--;
            } else {
                nums[i] = 2;
                two--;
            }
        }
    }

int main(){
    cout << "Enter size of nums"<<"\n";
    int n;
    cin >> n;
    vector<int> nums(n);


    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    sortColors(nums);
    
    for(int i=0;i<n;i++){
        cout <<  nums[i] << " ";
    }
    cout<<endl;
}
int maxSubArray(vector<int>& nums) {
    int sum=0;
    int max=nums[0];
    
    int i=0;

    while (i<nums.size()) {
        sum+=nums[i++];
        if (sum>max) {
            max=sum;
        }
        if (sum<0) {
            sum=0;
        }
        
    }
    return max;
    }
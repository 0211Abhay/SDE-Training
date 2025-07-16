int findPeakElement(vector<int>& nums) {
        int maxe = 0;
        for(int i = 1 ; i<nums.size();i++){
           if(nums[maxe]< nums[i]){
            maxe = i;
           }
        }
        return maxe;
    }
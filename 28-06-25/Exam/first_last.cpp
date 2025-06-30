vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;
        for(int i=0 ;i< nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        if(ans.size()>1){
            return {ans[0],ans[ans.size()-1]};
        }else if(ans.size()==1){
            ans.push_back(ans[0]);
            return ans;
        }
        return {-1,-1};
    }
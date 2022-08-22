class Solution {
public:
    void fun(int ind,vector<int>nums,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        //recursive case
        for(int i = ind;i<nums.size();i++){
            // imp condn
            if(nums[i]==nums[ind]&&i!=ind) continue;
            swap(nums[i],nums[ind]);
            fun(ind+1,nums,ans);
            //we will not backtrack because of repetation
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        fun(0,nums,ans);
            return ans;
    }
};

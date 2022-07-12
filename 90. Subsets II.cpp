class Solution {
public:
    set<vector<int>>s;
    void fun(vector<int>& nums,int i,vector<int>temp){
        if(i==nums.size()){
            s.insert(temp);
            return;
        }
        //recursive case
        temp.push_back(nums[i]);
        fun(nums,i+1,temp); //take
        temp.pop_back();
        fun(nums,i+1,temp); //skip
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        fun(nums,0,temp);
        vector<vector<int>>ans;
        for(auto x:  s)
            ans.push_back(x);
        return ans;
    }
};

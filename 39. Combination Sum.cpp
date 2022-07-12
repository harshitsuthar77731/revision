//combination sum
class Solution {
public:
    vector<vector<int>>v;
    void fun(vector<int>& can,int ind, int target,int sum,vector<int>&temp){
        
        if(ind<=can.size()&&sum==target){
            v.push_back(temp);
            return;
        }
        
        if(ind==can.size())
            return;
        
        if(sum>target)
            return;
        
        temp.push_back(can[ind]);
        fun(can,ind,target,sum+can[ind],temp);
        temp.pop_back();
        //skip
        fun(can,ind+1,target,sum,temp);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        fun(candidates,0,target,0,temp);
        return v;
    }
};

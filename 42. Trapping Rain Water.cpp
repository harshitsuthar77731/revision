class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int sum = 0;
        int lmax = INT_MIN;
        int rmax = INT_MIN;
        while(i<j){
            lmax = max(lmax,height[i]);
            rmax = max(rmax,height[j]);
            if(lmax<rmax){
                sum+=lmax-height[i++];
            }else{
                sum+=rmax-height[j--];
            }
        }
        return sum;
        
    }
};

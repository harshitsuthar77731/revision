class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int maxm = INT_MIN;
        int minm = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            maxm = max(maxm,matrix[i][matrix[i].size()-1]);
            minm = min(minm,matrix[i][0]);
        }
        while(minm<=maxm){
            int mid = minm + (maxm-minm)/2;
            int place = 0;
            for(int i=0;i<matrix.size();i++){
                place+= upper_bound(matrix[i].begin(),matrix[i].begin()+matrix[i].size(),mid)-matrix[i].begin();
            }
            
            if(place<k)
                minm = mid+1;
            else
                maxm = mid-1;
        }
        return minm;
    }
};

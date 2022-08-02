class Solution {
public:
    int fun(int minm,int maxm,int k,vector<int>& nums1, vector<int>& nums2){
        while(minm<=maxm){
            int mid = minm + (maxm-minm)/2;
            int place = 0;
            place+=upper_bound(nums1.begin(),nums1.begin()+nums1.size(),mid)-nums1.begin();
            place+=upper_bound(nums2.begin(),nums2.begin()+nums2.size(),mid)-nums2.begin();
            
            if(place<k)
                minm = mid+1;
            else
                maxm = mid-1;
        }
        return minm;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int maxm = INT_MIN;
        int minm = INT_MAX;
        if(nums1.size()>0&&nums2.size()>0){
            minm = min(nums1[0],nums2[0]);
            maxm = max(nums1[nums1.size()-1],nums2[nums2.size()-1]);
        }else if(nums1.size()>0){
            minm = nums1[0];
            maxm = nums1[nums1.size()-1];
        }else
        {
            minm = nums2[0];
            maxm = nums2[nums2.size()-1];
        }
        
        int k = (nums1.size()+nums2.size())/2;
         // k=k;
        int ind  =-1;
        if((nums1.size()+nums2.size())%2==0){
            int t1 = fun(minm,maxm,k,nums1,nums2);
            int t2 = fun(minm,maxm,k+1,nums1,nums2);
            double ans = ((double)t1+(double)t2)/2;
            return ans;
        }else{
            return (double)fun(minm,maxm,k+1,nums1,nums2);
        }
        return -1;
    }
};

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
       int ans = arr[n-1]-arr[0];
         for(int i=0;i<n-1;i++){
             if(arr[i+1]<k)
                continue;
            int mx = max(arr[i]+k,arr[n-1]-k);
            int mn = min(arr[i+1]-k,arr[0]+k);
            ans= min(ans,mx-mn);
         }
        return ans;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m=nums.size();
        int keep=0;
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            while(j<m && nums[j]-nums[i]<n){
                j++;
            }
            keep=j-i;
            ans=min(ans, n-keep);
        }
        return ans;
    }
};
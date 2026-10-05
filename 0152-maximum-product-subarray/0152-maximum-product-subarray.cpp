class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxans=nums[0];
        int minans=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int premax=maxans;
            int premin=minans;
            maxans=max(nums[i], max(premax*nums[i], premin*nums[i]));
            minans=min(nums[i], min(premin*nums[i], premax*nums[i]));
            ans=max(ans, maxans);
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int leftmax=0;
        int rightmax=0;
        long long ans=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=leftmax){
                    leftmax=height[left];
                }
                else{
                    ans+=(leftmax-height[left]);
                }
                left++;
            }
            else{
                if(height[right]>=rightmax){
                    rightmax=height[right];
                }
                else{
                    ans+=(rightmax-height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};
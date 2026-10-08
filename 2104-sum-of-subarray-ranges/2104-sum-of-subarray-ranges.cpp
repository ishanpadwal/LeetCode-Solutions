class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return summax(nums)-summin(nums);
    }
    long long summin(vector<int> &nums){
        int n=nums.size();
        long long total=0;
        vector<int> nse=findnse(nums);
        vector<int> pse=findpse(nums);
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=total+(left*right*1LL*nums[i]);
        }
        return total;
    }
    vector<int> findnse(vector<int> &nums){
        stack<int> st;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?nums.size():st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int> &nums){
        stack<int> st;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    long long summax(vector<int> &nums){
        int n=nums.size();
        long long total=0;
        vector<int> nge=findnge(nums);
        vector<int> pge=findpge(nums);
        for(int i=0;i<n;i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            total=total+(left*right*1LL*nums[i]);
        }
        return total;
    }
    vector<int> findnge(vector<int> &nums){
        stack<int> st;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?nums.size():st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpge(vector<int> &nums){
        stack<int> st;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
};
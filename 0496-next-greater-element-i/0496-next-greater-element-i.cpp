class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        unordered_map<int, int> ump;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            ump[nums2[i]]=st.empty()?-1: st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(ump[nums1[i]]);
        }
        return ans;
    }
};
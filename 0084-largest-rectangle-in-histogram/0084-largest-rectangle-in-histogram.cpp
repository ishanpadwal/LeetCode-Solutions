class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=heights[st.top()];
                int nse=i;
                st.pop();
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi, el*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=heights[st.top()];
            int nse=n;
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi, el*(nse-pse-1));
        }
        return maxi;
    }
};
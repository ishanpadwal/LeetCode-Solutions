class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=heights[st.top()];
                st.pop();
                int pse=st.empty()?-1: st.top();
                maxarea=max(maxarea, el*(i-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,el*(nse-pse-1));
        }
        return maxarea;
    }
};
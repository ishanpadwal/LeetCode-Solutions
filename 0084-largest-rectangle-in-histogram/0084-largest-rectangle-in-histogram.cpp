class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> pse=findpse(heights);
        vector<int> nse=findnse(heights);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
    vector<int> findpse(vector<int>& heights){
        int n=heights.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> findnse(vector<int>& heights){
        int n=heights.size();
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
};
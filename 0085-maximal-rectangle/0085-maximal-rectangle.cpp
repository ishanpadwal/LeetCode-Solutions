class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
        vector<vector<int>> presum(n,vector<int> (m));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                presum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxarea=max(maxarea, findmax(presum[i]));
        }
        return maxarea;
    }
    int findmax(vector<int> nums){
        stack<int> st;
        int n=nums.size();
        int maxans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                int el=nums[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxans=max(maxans, el*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=nums[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxans=max(maxans, el*(nse-pse-1));
        }
        return maxans;
    }
};
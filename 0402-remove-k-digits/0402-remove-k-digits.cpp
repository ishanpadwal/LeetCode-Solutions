class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.length();
        if(k==n) return "0";
        for(int i=0;i<num.length();i++){
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
    string s="";
    while(!st.empty()){
        char ch=st.top();
        s+=ch;
        st.pop();
    }
    while(s.length()!=0 && s.back()=='0'){
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    return s.empty()?"0":s;
    }
};
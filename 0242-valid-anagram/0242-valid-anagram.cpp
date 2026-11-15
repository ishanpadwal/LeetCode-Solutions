class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length(), m=t.length();
        if(n!=m) return false;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']+=1;
            freq[t[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};
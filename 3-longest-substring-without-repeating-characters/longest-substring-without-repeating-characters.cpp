class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int left = 0;
        int res = 0;
        for(int i=0; i<s.size(); i++){
            while(st.count(s[i])){
                st.erase(s[left]);
                left++;
            }
            
                st.insert(s[i]);
              res = max(res, i-left+1);
        }
        return res;
    }
};

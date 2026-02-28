class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1e9 + 7;
        long long ans = 0;
        int length = 0;
        
        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0) length++;
            ans = ((ans << length) % mod + i) % mod;
        }
        
        return ans;
    }
};
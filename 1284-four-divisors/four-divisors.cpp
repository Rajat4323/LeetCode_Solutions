class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int sum = 0;
            bool ok = false;

            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    int e = x / d;
                    if (d != e && isPrime(d) && isPrime(e)) {
                        sum = 1 + d + e + x;
                        ok = true;
                    }
                    break;
                }
            }

            if (!ok) {
                int p = round(cbrt(x));
                if (1LL * p * p * p == x && isPrime(p)) {
                    sum = 1 + p + p * p + x;
                    ok = true;
                }
            }

            if (ok) ans += sum;
        }
        return ans;
    }
};

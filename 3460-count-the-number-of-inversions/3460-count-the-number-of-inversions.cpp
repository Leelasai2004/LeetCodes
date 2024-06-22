class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& reqs) {
        unordered_map<int, int> r;
        for (auto& q : reqs) {
            r[q[0] + 1] = q[1];
        }

        vector<vector<long long>> p(n + 1, vector<long long>(401));
        p[0][0] = 1;
        vector<int> fact(n + 1, 1);
        vector<int> invfact(n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            fact[i] = (fact[i - 1] * 1LL * i) % MOD;
        }
        auto modInverse = [&](int a, int mod) {
            int b = mod - 2;
            int res = 1;
            while (b > 0) {
                if (b % 2 == 1)
                    res = (res * 1LL * a) % mod;
                a = (a * 1LL * a) % mod;
                b /= 2;
            }
            return res;
        };

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= 400; i++) {
                for (int j = 0; j < l; j++) {
                    int v = i - j;
                    if (v >= 0) {
                        p[l][i] = (p[l][i] + p[l - 1][v]) % MOD;
                    }
                }
            }
            invfact[n] = modInverse(fact[n], MOD);
            for (int i = n - 1; i > 0; --i) {
                invfact[i] = (invfact[i + 1] * 1LL * (i + 1)) % MOD;
            }
            auto nCk = [&](int n, int k, int mod) -> long long {
                if (k > n)
                    return 0;
                return (fact[n] * 1LL * invfact[k] % mod) * 1LL *
                       invfact[n - k] % mod;
            };
            if (r.find(l) != r.end()) {
                int t = r[l];
                for (int i = 0; i <= 400; i++) {
                    if (i != t) {
                        p[l][i] = 0;
                    }
                }
            }
        }

        long long res = 0;
        for (int i = 0; i <= 400; i++) {
            res = (res + p[n][i]) % MOD;
        }

        return int(res);
    }
};

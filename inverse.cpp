#include <bits/stdc++.h>

using namespace std;

namespace INV { 
    vector<int> getInv(int n, int mod) {
        vector<int> inv(n + 1);
        inv[0] = inv[1] = 1; 
        for (int i = 2; i <= n; ++i) {
            inv[i] = (mod - mod / i) * inv[mod % i] % mod; 
        }
        return inv; 
    }
}
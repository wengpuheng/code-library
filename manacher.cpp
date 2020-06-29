#include <bits/stdc++.h>

using namespace std; 

namespace manacher {
 
    vector<int> getp(string s) {
        int n = s.length(); 
        int id = 0, mx=0;
        vector<int> p(n, 0); 
        for (int i = 0; i < n; ++i) {
            if (i < mx) {
                p[i] = min(p[id + id - i], mx - i);
            }   else {
                p[i] = 1;
            }
            while(s[i - p[i]] == s[i + p[i]]) {
                ++p[i]; 
            }
            if (mx < i + p[i] - 1) {
                id = i;
                mx = i + p[i] - 1;
            }
        } 
        return p; 
    }
    
}
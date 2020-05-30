#include <bits/stdc++.h>

using namespace std;

namespace ACA {
    const int T = 40005 * 30; 
    const int C = 2; 
    // ...
    int sz; 
    int t[T][C]; 
    int fail[T]; 
    int mark[T]; 
    // ...
    void init() {
        sz = 0; 
        for (int i = 0; i < C; ++i) {
            t[0][i] = 0; 
        }
        fail[0] = mark[0] = 0; 
    }
    void add(const string &str) {
        int u = 0; 
        for (int i = 0; i < (int)str.size(); ++i) {
            int c = str[i] - '0'; 
            // ...
            int &v = t[u][c]; 
            if (!v) {
                v = ++sz; 
                for (int j = 0; j < C; ++j) {
                    t[v][j] = 0; 
                }
                fail[v] = mark[v] = 0; 
            }
            u = v; 
        }
        mark[u] = 1; 
    }
    void getfail() {
        queue<int> q; 
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); 
            for (int i = 0; i < C; ++i) {
                int &v = t[u][i];
                if (v) {
                    fail[v] = (u != 0) * t[fail[u]][i];
                    q.push(v);
                    mark[v] |= mark[fail[v]]; 
                }   else {
                    v  = t[fail[u]][i]; 
                }
            }
            q.pop(); 
        }
    }
}; 
#include <bits/stdc++.h>

using namespace std;

namespace T{
    const int N = 100005; 
    //...
    int dfn[N], low[N], belong[N], sta[N], cnt, tot, id; 
    bool insta[N]; 
    vector<int> e[N]; 
    void init() {
        //...
        // dfn low = -1
        // insta belong = 0
    }
    void dfs(int u) {
        dfn[u] = low[x] = ++id;
        insta[u] = 1; sta[++cnt] = u; 
        for(auto v: e[u]) { 
            if(dfn[v] == -1) {
                dfs(v); 
                low[u] = min(low[u], low[v]); 
            }
            else if(insta[v]) low[u] = min(low[u], dfn[v]); 
        }
        if(dfn[u] == low[u]) {
            ++tot 
            int x;  
            do {
                x = sta[cnt--]; 
                insta[x] = 0; 
                belong[x] = tot; 
            } while(x != u); 
        }
    }
}
#include <bits/stdc++.h>

using namespace std; 

namespace MaxFlow {
    const int N = 205; 
    //...
    struct edge {
        int v, c, opp; 
        edge() {}
        edge(int _v, int _c, int _opp) {
            v = _v; 
            c = _c; 
            opp = _opp; 
        }
    }; 
    vector<edge> e[N]; 
    queue<int> q;
    int h[N]; 
    int s, t; 
    void init(int _s, int _t) {
        s = _s; 
        t = _t; 
        for (int i = s; i <= t; ++i) {
            e[i].clear(); 
        }
    }
    void addedge(int u, int v, int c) {
        e[u].push_back(edge(v, c, e[v].size())); 
        e[v].push_back(edge(u, 0, e[u].size() - 1)); //directed edge
    }
    bool bfs() { 
        for (int i = s; i <= t; ++i) {
            h[i] = -1; 
        }
        h[s] = 0; 
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            for (auto &it: e[u]) { 
                if (it.c > 0 && h[it.v] == -1) {
                    h[it.v] = h[u] + 1; 
                    q.push(it.v); 
                }
            }
            q.pop(); 
        }
        return h[t] != -1; 
    }
    int dfs(int u, int flow) {
        if (u == t) return flow; 
        int delta, mn; 
        delta = 0; 
        for (auto &it: e[u]) { 
            if (h[it.v] == h[u] + 1 && it.c > 0 && delta < flow) {
                mn = dfs(it.v, min(it.c, flow - delta)); 
                it.c -= mn; 
                e[it.v][it.opp].c += mn; 
                delta += mn; 
            }
        } 
        if (!delta) h[u] = -1; 
        return delta; 
    }
    int maxFlow() {
        int ret = 0; 
        while (bfs()) {
            ret += dfs(s, INT_MAX); 
        }
        return ret; 
    }
}
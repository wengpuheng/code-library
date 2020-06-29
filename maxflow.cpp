#include <bits/stdc++.h>

using namespace std; 

namespace MaxFlow {
    const int N = 205; 
    const int M = 50005; 
    //...
    int s, t; 
    struct edge {
        int v, c, nxt; 
    }e[M]; 
    int adj[N], tail; 
    void init(int ns, int nt) {
        s = ns;
        t = nt; 
        tail = 0; 
        for (int i = s; i <= t; ++i) {
            adj[i] = -1; 
        } 
    }
    void addedge(int u, int v, int c) {
        e[tail].v = v; e[tail].c = c; 
        e[tail].nxt = adj[u]; adj[u] = tail; ++tail; 
        e[tail].v = u; e[tail].c = 0; 
        e[tail].nxt = adj[v]; adj[v] = tail; ++tail;  
    }
    int d[N]; 
    bool bfs() {
        queue<int> q; 
        for (int i = s; i <= t; ++i) {
            d[i] = -1; 
        }
        d[s] = 0; 
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            for (int k = adj[u]; k != -1; k = e[k].nxt) {
                int v = e[k].v; 
                if (e[k].c > 0 && d[v] == -1) {
                    d[v] = d[u] + 1; 
                    q.push(v); 
                }
            }
            q.pop(); 
        }
        return d[t] != -1; 
    }
    int dfs(int u, int flow) {
        if (u == t) return flow; 
        int delta, mn; 
        delta = 0; 
        for (int k = adj[u]; k != -1; k = e[k].nxt) {
            int v = e[k].v; 
            if (d[v] == d[u] + 1 && e[k].c > 0 && delta < flow) {
                mn = dfs(v, min(e[k].c, flow - delta)); 
                e[k].c -= mn; 
                e[k ^ 1].c += mn; 
                delta += mn; 
            }
        } 
        if (!delta) d[u] = -1; 
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
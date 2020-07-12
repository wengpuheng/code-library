#include <bits/stdc++.h>

using namespace std;

namespace EK {
    const int N = 505; 
	struct edge {
		int v, c, d, opp; 
		edge() {}
		edge(int _v, int _c, int _d, int _opp) {
			v = _v; 
			c = _c; 
			d = _d; 	
			opp = _opp; 
		} 
	}; 
	queue<int> q; 
	vector<edge> e[N]; 
	bool inq[N]; 
	int pos[N], pre[N], d[N]; 
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			e[i].clear(); 
		}
	}
	void addedge(int u, int v, int c, int d) {
		e[u].push_back(edge(v, c, d, e[v].size())); 
		e[v].push_back(edge(u, 0, -d, e[u].size() - 1)); 
	}
	bool spfa(int s, int t) {
		for (int i = s; i <= t; ++i) {
			inq[i] = 0; 
			d[i] = INT_MAX; 
			pos[i] = -1; 
			pre[i] = -1; 
		}
		inq[s] = 1; 
		d[s] = 0; 
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); 
			for (int k = 0; k < e[u].size(); ++k) {
				edge &it = e[u][k]; 
				if (it.c > 0 && d[it.v] > d[u] + it.d) {
					pre[it.v] = k;
					pos[it.v] = u; 
					d[it.v] = d[u] + it.d; 
					if (!inq[it.v]) {
						inq[it.v] = 1; 
						q.push(it.v); 
					} 
				}
			}
			inq[u] = 0; 
			q.pop(); 
		}
		return d[t] < INT_MAX; 
	}
    int cost(int s, int t) {
        int cost = 0; 
        while (!spfa(s, t)) {
            int minc = INT_MAX;
            for (int i = t; i != s; i = pos[i]) {
                edge &it = e[pos[i]][pre[i]];
                minc = min(minc, it.c); 
            }
            cost += minc * d[t]; 
            for (int i = t; i != s; i = pos[i]) {
                edge &it = e[pos[i]][pre[i]];
                it.c -= minc; 
                e[i][it.opp].c += minc; 
            }
        }
        return cost; 
    }
}
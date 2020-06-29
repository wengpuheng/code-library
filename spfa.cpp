#include <bits/stdc++.h>

using namespace std;

namespace SPFA {
	const int N = 100005;
	//... 
	struct edge {
	    int v, d;
	    edge(int v, int d) : v(v), d(d){
	    }
	};
	vector<edge> e[N]; 
	int d[N];
	bool inq[N];  

	void init() {
		//...
		// e -> clear
	}

	void addedge(int u, int v, int d) {
	    e[u].push_back(edge(v, d)); 
	    e[v].push_back(edge(u, d)); 
	}

	int dis(int s, int t) {
	    for (int i = s; i <= t; ++i) d[i] = INT_MAX, inq[i] = 0; 
	    queue<int> q;
	    d[s] = 0; 
	    inq[s] = 1; 
	    q.push(s);
	    while (!q.empty()) {
	        int u = q.front(); 
	        for (auto it: e[u]) {
	            if (d[it.v] > d[u] + it.d) {
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
	    return d[t]; 
	}
}
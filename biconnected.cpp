#include <bits/stdc++.h>

using namespace std; 

namespace T{
	const int N = 100005; 
	//...
	int dfn[N], low[N], id; 
	int sta[N], cnt, root; 
	int cut[N]; 
	vector<int> BCC[N]; int BCC_size; 
	vector<int> e[N]; 

	void addedge(int u,  int v) {
		e[u].push_back(v);
		e[v].push_back(u); 
	}

	void init() {	
		//...
		// dfn low  = -1
		// cut = 0
	}

	void dfs(int u) {
		int c = 0; 
		dfn[u] = low[u] = ++id; 
		sta[++cnt] = u; 
		for(auto v: e[u]) { 
			if(dfn[v] == -1) {
				c++; 
				dfs(v); 
				if(low[v] < low[u]) low[u] = low[v]; 
				if(low[v] >= dfn[u]) {
					if(u != root || c > 1) cut[u] = 1; 
					int o; BCC_size++; 
					do {
						o = sta[cnt];
						sta[cnt] = 0; 
						cnt--; 
						BCC[BCC_size].push_back(o); 
					}while(o != v); 
					BCC[BCC_size].push_back(u); 
				}
			} else {
				if(dfn[v] < low[u]) low[u] = dfn[v]; 
			}
		}
	}

}

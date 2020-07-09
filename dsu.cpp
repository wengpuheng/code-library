#include <bits/stdc++.h>

using namespace std; 

namespace F {
	const int N = 100005; 
	int fa[N], val[N];
	void init(int n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i; 
			val[i] = 0; 
		}
	}
	int findFa(int u) {
		if (fa[u] != u) {
			int f = fa[u]; 
			fa[u] = findFa(fa[u]);
			val[u] += val[f]; 
		}
		return fa[u]; 
	} 
	void connect(int u, int v) {
		//...
		//w val
		int fu = findFa(u); 
		int fv = findFa(v);
		if (fu != fv) {
			//...
			//w val
		}
	}
}
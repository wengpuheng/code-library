#include <bits/stdc++.h>

using namespace std;

namespace kmp {
	vector<int> getp(string s) {
		int n = (int)s.length();
		vector<int> p(n, 0);
		for (int i = 1; i < n; i++) {
			int j = p[i - 1];
			while (j > 0 && s[i] != s[j]) j = p[j - 1];
			if (s[i] == s[j]) j++;
			p[i] = j;
		}
		return p;
	}
};
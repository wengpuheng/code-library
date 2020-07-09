#include <bits/stdc++.h>

using namespace std;

namespace LB {
	void upd(int xr) {
		for (int i = 30; i >= 0; --i) {
			if (xr >> i) {
				if (!bs[i]) {
					bs[i] = xr; 
					break; 
				}
				xr ^= bs[i]; 
			}
		}
	} 
}
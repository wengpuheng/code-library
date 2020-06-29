#include <bits/stdc++.h>

using namespace std; 

namespace FFT {

	struct Z{
		double real, i; 
		Z(){}
		Z(double _real, double _i){real = _real; i = _i;}
		Z friend operator + (Z a, Z b){return Z(a.real + b.real, a.i + b.i);}
		Z friend operator - (Z a, Z b){return Z(a.real - b.real, a.i - b.i);}
		Z friend operator * (Z a, Z b){return Z(a.real * b.real - a.i * b.i, a.real * b.i + b.real * a.i);}
	}; 

	const int N = 4 * 60005; 
	//...
	
	const double Pi = acos(-1);

	int n, r[N]; 

	void dft(Z *a, int sig){
		for(int i = 0; i < n; ++i) if(i < r[i]) swap(a[i], a[r[i]]); 
		for(int d = 2; d <= n; d <<= 1){
			Z wn = Z(cos(2 * Pi * sig / d), sin(2 * Pi * sig / d));
			for(int i = 0; i < n; i += d){
				Z w = Z(1, 0); 
				for(int j = 0; j < d/2; ++j){
					Z u = a[i + j];
					Z v = w * a[i + j + d / 2];
					a[i + j] = u + v; 
					a[i + j + d / 2] = u - v; 
					w = w * wn; 
				}
			}
		}
		if(sig == -1) for(int i = 0; i < n; ++i) a[i].real /= (double)n; 
	}

	void fft(Z *a, Z *b, int na, int nb){
		for( n = 1; n <= na + nb; n <<= 1); 
		r[0] = 0; 
		for(int i = 1; i <= n - 1; ++i) r[i] = r[i - (i & (-i))] | (n / 2 / (i & (-i))); 
		// notice init
		dft(a, 1); 
		dft(b, 1); 
		for(int i = 0; i < n; ++i) a[i] = a[i] * b[i]; 
		dft(a, -1); 
	}
}; 

// fft

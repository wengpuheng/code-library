#include <bits/stdc++.h>

using namespace std; 

struct node {
    int x, y;
    int a[25][25]; 
    //...
    node() {
        x = y = 0; 
        memset(a, 0, sizeof a); 
    }
    friend node operator* (node A, node B) {
        node C; 
        C.x = A.x; 
        C.y = B.y; 
        for (int i = 0; i < C.x; ++i) {
            for (int j = 0; j < C.y; ++j) {
                for (int k = 0; k < A.y; ++k) {
                    C.a[i][j] += A.a[i][k] * B.a[k][j]; 
                    //... mod
                }
            }
        }
        return C; 
    }
    friend node operator+ (node A, node B) {
        node C; 
        C.x = A.x; 
        C.y = A.y; 
        for (int i = 0; i < C.x; ++i) {
            for (int j = 0; j < C.y; ++j) {
                C.a[i][j] = A.a[i][j] + B.a[i][j]; 
            }
        }
        return C; 
    }
}; 
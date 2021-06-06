#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

const int MAX_N = 131072;
int n;
int dat[MAX_N*2-1]; //MAX_N*4

//初期化
void init(){
    rep(i,2*n-1) dat[i] = INT_MAX;
}

//更新
void update(int i, int x){
    i += n-1; // n+i-1
    dat[i] = x;
    while(i>0){
        i = (i-1)/2;
        dat[i] = min(dat[i*2+1],dat[i*2+2]); 
    }
}

//最小値を知りたい
int query(int a, int b, int k, int l, int r){
    if(r<=a || b<=l) return INT_MAX;
    if(a<=l && r<=b) return dat[k];
    else{
        int vl = query(a,b,k*2+1,l,(l+r)/2);
        int vr = query(a,b,k*2+1,(l+r)/2,r);
        return min(vl,vr);
    }
}
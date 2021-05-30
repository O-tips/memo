#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

//引用したよ！

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    REP(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    REP(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};

/*
graph g(n);
と書けばn頂点のグラフが作成され、

g.add_edge(a,b,cost);
とすれば頂点aから頂点bへのコストcostの辺が張られます。そして

g.dijkstra(s);
とすれば頂点sから各頂点への最短経路をダイクストラ法で探索できます。探索結果は

int dist = g.d[i]:
と呼び出して使うことができます。
*/

int main(){
    graph g(6); //n頂点のグラフを作成する
    g.add_edge(1, 3, 1);
    g.add_edge(1, 4, 1);
    g.add_edge(4, 1, 1);
    g.add_edge(4, 2, 1);
    g.add_edge(5, 3, 1);

    g.dijkstra(1); //1からの距離を求める

    for(int i = 1;i <= 5;i++){
        int dist = g.d[i];
        cout << i << "から1までの距離は : ";
        cout << dist << endl; //-1だったら到達できないぞ！
    }

  return 0;
}
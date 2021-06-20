//必要なサイズをとってね！
//main関数でpar[i]=iの初期化を忘れない！
vector <long long> par(100000);

int root(int x){

//実引数は根を求めたいノード
if(par[x]==x){
	//親が自分自身ならそのノードは根
	//根を返す
	return x;
}else{
	//親が自分自身でないなら親ノードの根を求める
	return par[x]=root(par[x]);
}

}

bool same(int x,int y){

//ノードとノードが実引数

//xの根とyの根が同じかどうかを確認してbool値を返す
return root(x) == root(y);

}


void unite(int x,int y){

//ノードとノードが実引数

x = root(x);
y = root(y);

//根が同じなら併合の必要なし
if(x==y) return;

//根が同じでないならxの親をyにする
par[x] = y;

}

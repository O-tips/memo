#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[1050];
int main() {
    graph[3].push_back(5);//町3から町5へ
    graph[3].push_back(2);//町3から町2へ
    graph[3].push_back(8);//町3から町8へ
    int a = 3;
    for (int i = 0; i < graph[a].size(); i++) {
        //頂点aに連結しているすべての頂点を最小回数で洗い出せる
        cout << graph[a][i] << ' ';//5 2 8
    }
}
#include <iostream>
#include <vector>
using namespace std;

//graph[3] = {4, 5, 1}
vector<int> graph[1050];
/*
graph[1] = {3, 4}
graph[2] = {}
graph[3] = {}
graph[4] = {1}
graph[5] = {3}
*/

int main() {
    graph[1].push_back(4);//町1から町4への道が存在
    graph[1].push_back(3);//町1から町3へ
    graph[4].push_back(1);//町4から町1へ
    graph[5].push_back(3);//町3から町8へ
    int a = 1;
    for (int i = 0; i < graph[a].size(); i++) {
        //頂点aに連結しているすべての頂点を最小回数で洗い出せる
        cout << graph[a][i] << ' ';//5 2 8
    }
}
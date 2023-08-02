#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M; // 문제의 수, 정보의 개수
vector <int> edge[100001]; //간선 
int inDegree[100001]; // 진입차수


void TopoLogicalSort(){
    priority_queue<int, vector<int>, greater<int>> pq; 

    for (int i=1; i<=N; i++){
        if (inDegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty()){
        int cur = pq.top();
        cout << cur << " ";
        pq.pop();

        for (int j=0; j<edge[cur].size(); j++){
            int next = edge[cur][j];
            if(--inDegree[next] == 0) pq.push(next);
 
        }
    }

}




int main(){

    cin >> N >> M;
    for (int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;
        edge[A].push_back(B);
        inDegree[B]++;
    }

    TopoLogicalSort();

}
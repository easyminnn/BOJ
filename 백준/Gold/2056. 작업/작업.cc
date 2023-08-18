#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <array>

using namespace std;

int N; // 작업의 개수
vector <int> edge[1000001]; //간선 
int TopologyDegree[10001]; // i번 노드는 처음부터 TopologyDegree[i]번째 노드 방문.
int inDegree[1000001]; // 진입차수
int T[10001];
int TotalTime[10001];

void TopoLogicalSort(){
    priority_queue<int,vector<int>,greater<int>> pq; 
    for (int i=1; i<=N; i++){
        if (inDegree[i] == 0){
            pq.push(i);
        }
        TotalTime[i] = T[i];
    }
  
    while (!pq.empty()){
        
        int cur = pq.top();
        
        pq.pop();

        for (int j=0; j<edge[cur].size(); j++){
            int next = edge[cur][j];
            TotalTime[next] = max(TotalTime[next], TotalTime[cur]+T[next]);
            if(--inDegree[next] == 0) {
                pq.push(next);
            }
        }
    }

}




int main(){

    cin >> N;
    for (int i=1; i<=N; i++){
        int lineNum; //i번 작업에서 걸리는 시간 T[i]와 연결된 linNum개의 작업들
        cin >> T[i] >> lineNum;
        for (int j=0; j<lineNum; j++){
            int B; // 이전노드
            cin >> B;
            edge[B].push_back(i);
            inDegree[i]++;
        }
        
    }

    TopoLogicalSort();
    
    int ans = -1;
    for(int i=1; i<=N; i++){
        ans = max(ans, TotalTime[i]);
    }

    cout << ans;

}
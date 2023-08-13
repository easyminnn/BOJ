#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

int minCost[20001]; //최소비용
vector<pair<int, int>> a[20001]; // 간선
// a[i] ={j, k} 일 때, i->j로 가는 가중치가 k. 
int V, E;


void dijkstra(int start){

    minCost[start] = 0;
    priority_queue<pair<int,int>> pq;
    //pq[i] = {j, k} 시, i-> k의 가중치는 j.
    pq.push({0, start});

    while(!pq.empty()){
        int current = pq.top().second; //현재 노드의 인덱스
        int distance = -pq.top().first; 
       //cout << "현재노드 : " << pq.top().first << " " << -pq.top().second << "\n";
        /*
        원래 pq는 내림차순 정렬(최대 힙)인데, 우리는 최소 힙을 구해야 하므로 push할때 음수로 push한다. */
        pq.pop();
        
        if(minCost[current] < distance) continue;
        for (int i=0; i<a[current].size(); i++){ //current와 연결돼있는 간선
            //선택노드의 인접노드들
            int next = a[current][i].second;
            int nextDistance = distance + a[current][i].first;
            //기존의 최소 비용보다 더 저렴하면 교체. 
            if (nextDistance < minCost[next]){
                
                minCost[next] = nextDistance;
                pq.push({-nextDistance, next});
                
            }
        }
        //cout << "다음 값: " << pq.top().first << " " << pq.top().second << "\n";
    }


}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i=1; i<=V; i++){
        minCost[i] = INF;
    }

    int k;
    cin >> k;

    for (int i=0; i< E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w,v});
    }

    dijkstra(k);

    for (int i=1; i<=V; i++){
        if (minCost[i] == INF) cout << "INF\n";
        else cout << minCost[i] << "\n";
    }


}



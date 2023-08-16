#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

int minCost[2][20001]; //최소비용
vector<pair<int, int>> a[2][20001]; // 간선

// a[i] ={j, k} 일 때, i->k로 가는 가중치가 j. 

int N, M, X; // 마을 수, 간선 수, 파티장소

void dijkstra(int k){
    minCost[k][X] = 0; //X는 출발장소 
    priority_queue<pair<int,int>> pq;
    //pq[i] = {j, k} 시, i-> k의 가중치는 j.
    pq.push({0, X});

    while(!pq.empty()){
        int current = pq.top().second; //현재 노드의 인덱스
        int distance = -pq.top().first; 
        pq.pop();
        
        if(minCost[k][current] < distance) continue;
        for (int i=0; i<a[k][current].size(); i++){ //current와 연결돼있는 간선
            //선택노드의 인접노드들
            int next = a[k][current][i].second;
            int nextDistance = distance + a[k][current][i].first;
            //기존의 최소 비용보다 더 저렴하면 교체. 
            if (nextDistance < minCost[k][next]){
                
                minCost[k][next] = nextDistance;
                pq.push({-nextDistance, next});
                
            }
        }
        
    }



}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;

    for (int i=1; i<=N; i++){
        minCost[0][i] = INF; //초기화 
        minCost[1][i] = INF; //초기화 
    }

    for (int i=0; i< M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[0][u].push_back({w,v}); //정방향 : 파티 장소에서 각 노드까지 가는 모든 최단거리 구하기. 
        a[1][v].push_back({w,u}); //역방향 : 노드에서 파티 장소까지 가는 모든 최단거리 구하기. 
    }

    dijkstra(0); //정방향 : 파티 장소에서 각 노드까지 가는 모든 최단거리 구하기.
       
    dijkstra(1); //역방향 : 노드에서 파티 장소까지 가는 모든 최단거리 구하기.

    int maxtime = 0;
    for (int i=1; i<=N; i++){
        if(minCost[0][i] + minCost[1][i] > maxtime) 
        maxtime = minCost[0][i] + minCost[1][i];
    }

    cout << maxtime;


}

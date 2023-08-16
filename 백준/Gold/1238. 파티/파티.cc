#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

int minCost[20001]; //최소비용
vector<pair<int, int>> a[20001]; // 간선
// a[i] ={j, k} 일 때, i->k로 가는 가중치가 j. 

int N, M, X; // 마을 수, 간선 수, 파티장소
int MinMap[1001][1001]; // start-> end로 갈 떄의 최단거리. 

void dijkstra(int start, int end){

    minCost[start] = 0;
    priority_queue<pair<int,int>> pq;
    //pq[i] = {j, k} 시, i-> k의 가중치는 j.
    pq.push({0, start});

    while(!pq.empty()){
        int current = pq.top().second; //현재 노드의 인덱스
        int distance = -pq.top().first; 
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
        
    }

    MinMap[start][end] = minCost[end];

}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;

    for (int i=1; i<=N; i++){
        minCost[i] = INF; //초기화 
    }

    for (int i=0; i< M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w,v});
    }

    for (int start=1; start<=N; start++){
        dijkstra(start, X);
        for (int i=1; i<=N; i++){
        minCost[i] = INF; //초기화 
        } 
    }
    dijkstra(X, 1);
    for (int i=1; i<=N; i++){
        MinMap[X][i] = minCost[i];
    }
    
    int maxtime = 0;
    for (int i=1; i<=N; i++){
        if(MinMap[i][X] + MinMap[X][i] > maxtime) 
        maxtime = MinMap[i][X] + MinMap[X][i];
    }

    cout << maxtime;


}

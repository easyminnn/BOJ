#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int T, N, K; // 테스트 개수, 건물개수, 규칙의 개수
int BuildingTime[1001]; 
int CanBuildMap[1001][1001];
int BuildEndTime[1001]; // 각 건물까지 건설하는 데에 걸리는 시간(dp)
int W;
int inDegree[1001];

void TopoLogicalSort()
{
    queue<int> q;
    for (int i=1; i<=N; i++){
        if(inDegree[i] == 0){
            q.push(i);
            BuildEndTime[i] = BuildingTime[i];
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int j=1; j<=N; j++){
            if (CanBuildMap[cur][j])
            {
                CanBuildMap[cur][j] = 0;
                BuildEndTime[j] = max(BuildEndTime[j], BuildEndTime[cur] + BuildingTime[j]);
                if(--inDegree[j] == 0) q.push(j);
            }
            
        }

    }

    cout << BuildEndTime[W] << "\n";
}
int main()
{
    int X , Y;

    cin >> T;
    while(T--)
    {
        cin >> N >> K;

        for (int i=1; i<=N; i++) cin >> BuildingTime[i]; // 각 건물을 짓는 데 걸리는 시간 

        for (int i=0; i<K; i++)
        {
            cin >> X >> Y;
            CanBuildMap[X][Y] = 1; // 간선 
            inDegree[Y]++; // Y로 들어오는 간선
        }
        
        cin >> W; // 목표 노드 
  
        TopoLogicalSort();
        

        for (int j=0; j<=N; j++){
            inDegree[j] = 0;
            BuildingTime[j] = 0;
            BuildEndTime[j] = 0;

        }


    }
}
    

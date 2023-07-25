#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N; // 건물 수 
int inDegree[501]; // 간선 수 
int time[501]; //각 건물을 짓는 데 걸리는 시간
int buildingTime[501]; // 그 건물을 짓기까지 걸리는 총시간
vector <int> edge[501]; 

void topologicalSort(){
    queue <int> q;

    for (int i=1; i<=N; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
            buildingTime[i] = time[i];
        }
    }    

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (int j=0; j<edge[cur].size(); j++)
        {
            int next = edge[cur][j];
            buildingTime[next] = max(buildingTime[cur] + time[next], buildingTime[next]); 
            if(--inDegree[next] == 0)
                q.push(next);
        }

    }


    for (int i=1; i<=N; i++)
        cout << buildingTime[i] << "\n";

    


}


int main(){

    cin >> N;
    for (int i=1; i<=N; i++)
    {
        int x;
        cin >> time[i];
        cin >> x;
        while(x != -1)
        {
            edge[x].push_back(i);
            inDegree[i]++;
            cin >> x;
        }
    }

    topologicalSort();
}
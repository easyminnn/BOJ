#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int K;
int V, E;
vector <int> graph[20001];
int visited[20001] = {0,}; //미방문은 0, 빨간색(초깃값)은 1, 파란색은 -1
int judge = 1;

void dfs(int start){

    for (int i=0; i<graph[start].size(); i++){
        int next = graph[start][i];
        //cout << start << "의 색:" << visited[start] << " " << next << "의 색 :" << 
        //visited[next] << "\n";
        if((visited[next] * visited[start]) > 0){
            judge = 0; // 0은 이분그래프가 아님. 
            return ;
        }
        else if (visited[next]*visited[start] == 0){
                visited[next] = -visited[start];
                dfs(next);
        }
    }

}


int main(){
    cin >> K;
    while(K--){
        cin >> V >> E;

        for (int i=0; i<E; i++){
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for (int i=1; i<=V; i++){
            if(visited[i] == 0){ // 방문하지 않았다면
                visited[i] = 1;
                dfs(i);
            }
        }

        if (judge == 0)
            cout << "NO\n";
        else
            cout << "YES\n";


        //초기화
        judge = 1;
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));



    }


}
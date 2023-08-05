#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int graph[1001][1001] = {0,};
queue<int> q;
int visit[1001];
int N;

int reset(){
    for (int i=0; i<=1000; i++)
    {
        visit[i] = 0;
    }
    return 0;
}


void dfs(int start){
    visit[start] = true;//현재 점과 연결돼있고 방문되지 않았으면 visit 하기. 그리고 재귀 !
    cout << start << " ";
    
    for (int i=1; i<=N; i++)
    {
        if(graph[start][i] == 1 && !visit[i])
            dfs(i);
    }
    
}


void bfs(int start){
    q.push(start);
    visit[start] = true;
    cout << start << " ";
    while (!q.empty()){
        //큐에 값이 있을 경우 반복 실행.
        // 큐에 값이 있다는 것은? 아직 방문하지 않은 노드가 있다! 
        int x = q.front();
        q.pop();
        
        
        for (int i=1; i<= N; i++) // 현재의 점과 연결돼있고 방문되지 않은 노드면 push
        {
            if(graph[x][i] && !visit[i])
            {
                q.push(i);
                visit[i] = true;
                cout << i << " ";
            }
        }
        
    }
}


int main(){
    int  M, V, A, B;
    cin >> N >> M >> V;
    
    for (int i=0; i<M; i++)
    {
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }
    
    reset();
    dfs(V);
    cout << "\n";
    reset();
    bfs(V);
    
    
}
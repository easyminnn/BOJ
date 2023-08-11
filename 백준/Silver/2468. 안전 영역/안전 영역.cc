#include <vector>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N;
int area[101][101];
bool visited[101][101];

int cnt = 0; // 영역의 개수 카운트
int dr[4] = {-1,0,1,0}; //시계방향 탐색
int dc[4] = {0,1,0,-1};
int max_cnt = 0; //최대 영역 개수 카운트

queue <pair<int, int>> q;

void bfs(){

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (visited[nr][nc] == true ) continue;
            if (area[nr][nc]>=1)
            {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

}


void solve(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (area[i][j] >= 1 && visited[i][j] == false){
                cnt ++; 
                q.push({i, j});
                visited[i][j] = true;
                bfs();
            }
        }
    }

}

int main(){

    cin >> N;
    int max = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> area[i][j];
            if (max < area[i][j]) max = area[i][j];
        }
    }

    for (int m=0; m< max; m++){
        for(int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (area[i][j] - m <= 0 ) area[i][j] = 0;
                else area[i][j] -=m;
            }
        }
        
        solve();
        if (max_cnt < cnt) max_cnt = cnt;

        //초기화
        cnt = 0;
        memset(visited, false, sizeof(visited));
        while(!q.empty()){
            q.pop();
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                area[i][j]+=m;
            } 
        }

    }

    cout << max_cnt;
}



#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, M, N, K;
int area[51][51]= {0,};
bool visited[51][51] = {false,};
int dx[4] = {-1,0,1,0}; //시계방향 탐색
int dy[4] = {0,1,0,-1};
int cnt = 0;


void dfs(int y, int x){
    visited[y][x] = true;

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >=0 && nx < M && ny >= 0 && ny < N){
            if(area[ny][nx] == 1){   //배추가 있다면 
                if(!visited[ny][nx]){   //지나치지 않았다면 
                    dfs(ny, nx); 
                }
            }
        }

        else continue;



    }
    

}


int main(){
    cin >> T;
    while(T--){
        cin >> M >> N >> K;

        for (int i=0; i<K; i++){
            int x, y;
            cin >> x >> y;
            area[y][x] = 1;
        } 

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                //cout << i << " " << j << " " <<  visited[i][j]<<"\n";
                if (area[i][j] == 1 && (!visited[i][j])){
                    cnt++; 
                    dfs(i, j);
                    
                }
            }
        }


        cout << cnt << "\n";

        cnt = 0;
        memset(area, 0, sizeof(area));
        memset(visited, false, sizeof(visited));



        

    }

}
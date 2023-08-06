#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int w, h; 
int map[51][51];
bool visited[51][51] = {false,};
int dx[8] = {-1,0,1,0,1, 1, -1,-1}; //시계방향 탐색(대각선까지 탐색)
int dy[8] = {0,1,0,-1,-1,1,1,-1};

void dfs(int y, int x){   //x축, y축
    visited[y][x] = true;

    for (int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >=0 && nx < w && ny >= 0 && ny < h){
            if(map[ny][nx] == 1){   //땅이 있다면 
                if(!visited[ny][nx]){   //지나치지 않았다면 
                    dfs(ny, nx); 
                }
            }
        }

        else continue;
    }
}


int main(){
    while(1){
        int cnt = 0;
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                cin >> map[i][j];
            }
        }

        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

    }



}
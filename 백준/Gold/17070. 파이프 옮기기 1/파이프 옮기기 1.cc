#include <iostream>

using namespace std;

int N;
int ans = 0;
int room[16][16];

void input(){
    cin >> N;
    
   
    for (int r=0; r<N; r++)
    {
        for (int c=0; c<N; c++)
        {
            cin >> room[r][c];
        }
    }

}

void movePipe(int state, int r, int c) // 가로:0, 세로:1, 대각선:2
{
   
    if (r==N-1 && c==N-1) 
    {
        ans++;
        return;
    }

    bool CanMoveH = c + 1 < N && room[r][c+1] == 0;
    bool CanMoveV = r + 1 < N && room[r+1][c] == 0;
    

    if (CanMoveH && state != 1) movePipe(0, r, c+1);
    
    if (CanMoveV && state != 0) movePipe(1, r+1, c);
    
    if (CanMoveV && CanMoveH && room[r+1][c+1] == 0) 
        movePipe(2, r+1, c+1);
    

}

void output(){
    cout << ans;
}

int main(){
    input();

    movePipe(0, 0, 1);

    output();

}
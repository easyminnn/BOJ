#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int pSum[301][301];

int main()
{
    cin >> N >> M;

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
            cin >> pSum[i][j];
            pSum[i][j] += pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1];
        }
    }

    cin >> K;
    
    int a, b, x, y;
    for (int i=0; i<K; i++){
        cin >> a >> b >> x >> y;

        cout << pSum[x][y] - pSum[x][b-1] - pSum[a-1][y] + pSum[a-1][b-1] << "\n";
    }

}
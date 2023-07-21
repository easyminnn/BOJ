#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int summap[1001][1001];
int map[1001][1001];

int main(){
    cin >> n >> m;

    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            summap[i][j] = max(summap[i-1][j], max(summap[i][j-1], summap[i-1][j-1])) + map[i][j];
        }
    }


    cout << summap[n][m];

}
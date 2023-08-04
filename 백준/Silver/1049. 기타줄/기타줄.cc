#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int N, M;

int main(){
    cin.tie(NULL);

    cin >> N >> M;  

    int minx, miny = 1001;
    for (int i= 0; i<M; i++)
    {
        int x, y;
        cin >> x >> y;
        
        if (minx > x) minx = x; //팩
        if (miny > y) miny = y; //낱개
    }
    
    int cost = N * miny; 
    int pack = N / 6;
    int left = N % 6; 
    
    if (left == 0 ) cost = min(cost, pack * minx);
    else cost = min (cost, min((pack+1) * minx, pack * minx + left * miny));

    cout << cost ;
}
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rope[100001];
int MaxWeight[100001];
int maxnum = 0;

void input(){
    cin >> N;
    
    for (int i=0; i<N; i++)
    {
        cin >> rope[i];
    }

}

void RopeSort(){
    sort(rope, rope+N);
    
    for (int i=0; i<N; i++)
    {
        MaxWeight[i] = rope[i] * (N-i);
        if (maxnum < MaxWeight[i]) maxnum = MaxWeight[i];
    }
    
    
}

void output(){
    cout << maxnum;
}

int main(){
    input();

    RopeSort();

    output();

}
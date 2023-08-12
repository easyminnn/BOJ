#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CaseSit[41];
int N, M;  //N은 좌석의 개수, M은 고정석의 개수 
int Sitting[41] = {0,};
vector <int> emptyseat;

int main(){
    cin >> N;
    cin >> M;
    for (int i=0; i<M; i++){
        int x;
        cin >> x;
        Sitting[x] = 1;
    }
    Sitting[N+1] = 1;

    CaseSit[0] = 1;
    CaseSit[1] = 1;
    CaseSit[2] = 2;
    for (int i=3; i<41; i++){
        CaseSit[i] = CaseSit[i-1] + CaseSit[i-2];
    }

    int cnt =  0;
    for (int i=1; i<=N+1; i++){
        if(Sitting[i] == 0 ){
            cnt ++; 
        }
        else{
            emptyseat.push_back(cnt);
            cnt = 0;
        }
    }

    long long result = 1;
    

    for (int i=0; i<emptyseat.size(); i++){
        result *= CaseSit[emptyseat[i]];
        
    }

    cout << result;


}
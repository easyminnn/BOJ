#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> v;
int N,k;

void Msort(int people, int level){

    //기저 
    if (people== k) return ;

    else{
        
        for (int i=0; i<N; i+=level)
        {
            sort(v.begin()+i, v.begin()+i+level);
        }


        Msort(people/2, level * 2);
    }

}


int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    Msort(N, 2);
    for (int i=0; i<N; i++)
    {
        cout << v[i] << " ";
    }
    
}
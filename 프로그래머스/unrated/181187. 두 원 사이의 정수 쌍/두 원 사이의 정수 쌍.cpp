#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define ll long long 

using namespace std;

long long solution(int r1, int r2) {
    ll answer = 0;
    
    for (ll y = 1; y<=r2; y++){
        ll x1 = (ll)(sqrt((ll)pow(r2, 2) - (ll)pow(y, 2)));
        answer += 4 *(x1+1);


    }
    for (ll y=1; y<=r1; y++){
        ll x2 = (long long int)(sqrt((ll)r1*r1 - (ll)y*y));
        if((ll)x2*x2 - (ll)r1*r1 == (ll)-y*y) answer+=4;
        answer -= 4 *(x2+1);

    }
    
  
    
    return answer;
}
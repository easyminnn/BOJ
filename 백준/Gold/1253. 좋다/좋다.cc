#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N; 
vector <int> num;

bool CheckIf(int a, int index){
    num.erase(num.begin() + index);

    int l = 0;
    int r = N-2;

    while(l<r){
        if(num[l]+num[r] == a){
            num.insert(num.begin() + index, a);
            return true;
        }
        else if(num[l]+num[r] < a){
            l++;
        }
        else{
            r--;
        }
            
    }

    num.insert(num.begin() + index, a);
    return false;

}



int main(){
    cin >> N;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }

    sort(num.begin(), num.end());
    int count =0;

    for (int i=0; i<N; i++){
        if (CheckIf(num[i], i)){
            count ++;
        }
    }

    cout << count;
}
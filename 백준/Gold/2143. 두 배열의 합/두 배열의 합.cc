#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int n, m;
long long T;
int Asum[1001];
int Bsum[1001];
vector <long long> Asumcase;
vector <long long> Bsumcase;

int main(){
    long long ans = 0;
    cin >> T;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> Asum[i];
        Asum[i] += Asum[i-1];
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        cin >> Bsum[i];
        Bsum[i] += Bsum[i-1];
    }

    for (int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            Asumcase.push_back(Asum[j]-Asum[i-1]);
        }
    }

    for (int i=1; i<=m; i++){
        for(int j=i; j<=m; j++){
            Bsumcase.push_back(Bsum[j]-Bsum[i-1]);
        }
    }

    sort(Asumcase.begin(), Asumcase.end());
    sort(Bsumcase.begin(), Bsumcase.end());

    


    for (int i=0; i<Asumcase.size(); i++){
        int low = lower_bound(Bsumcase.begin(), Bsumcase.end(), T-Asumcase[i]) - Bsumcase.begin();
        int high = upper_bound(Bsumcase.begin(), Bsumcase.end(), T-Asumcase[i])- Bsumcase.begin();

        ans += high - low;
    }

    cout << ans << "\n" ;


    


}
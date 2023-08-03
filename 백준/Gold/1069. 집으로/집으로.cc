#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int X, Y, D, T;



int main(){

    cin >> X >> Y >> D >> T;

    double distance = sqrt(X*X + Y*Y);
    cout << fixed;
    cout.precision(9);
    if (D <= T ){
        cout << distance << "\n";
        return 0; 
    }

    int jump = distance / D;
    double result = distance;
    double left = distance - jump * D;

    if (jump == 0) result = min(distance,min(2.0*T, T + D - left));
    else result = min(result, min(jump * T + left , (jump + 1.0) * T));

    cout << result ;

}

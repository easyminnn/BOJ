#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double x, y, c;

double cal(double mid){

    double h1 = sqrt(pow(x,2) - pow(mid, 2));
    double h2 = sqrt(pow(y,2) - pow(mid, 2));
    return (h1*h2) / (h1+h2);
}

int main(){

    cin >> x >> y >> c;

    double low = 0;
    double high = min(x,y);
    double result = 0;


    while (high-low > 0.000001){
        
        double mid = (high+low) / 2.0;


        if (cal(mid) >= c)
        {
            result = mid ;
            low = mid;
        }   
        else 
            high = mid;

    }

    cout << fixed;
    cout.precision(3);
    cout << result ;


}


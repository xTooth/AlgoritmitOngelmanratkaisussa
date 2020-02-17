#include <bits/stdc++.h>

using namespace std;

vector<long long> planets;

long f(long k)
{
    long d = 0;
    for (int i = 0; i < planets.size(); i++)
    {
        if(d + planets[i] < 0) return 0;
        if(d + planets[i] <= k){
            d += planets[i];
        }else{
            d = k;
        }
    }
    return 1;
    
}
int main()
{
    long nrp;
    cin >> nrp;
    long x;
    long long sum = 0;
    long long negsum = 0;
    for (int i = 0; i < nrp; i++)
    {
        cin >> x;
        planets.push_back(x);
        sum += x;
        if(x < 0){
            negsum += x;
        }
        if(sum < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    negsum = -negsum; 
    long k = -1;

    for (long b = negsum; b >= 1; b /= 2)
    {
        while (f(k + b) == 0)
            k += b;
    }
    long ans = k + 1;
    cout << ans << endl;
}
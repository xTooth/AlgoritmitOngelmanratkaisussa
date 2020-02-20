#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll i, l, M;
    M = 1000000007;
    unordered_map<ll, ll> f, ff;
    cin >> i >> l;
    f[0] = 2;
    ff[0] = 2;

    for (long x = 1; x <= i; x++)
    {
        long long a = 0;
        for(long i = 1; i<l;i++)
             a = ( a + f[x - i]) % M;
        f[x] = a;
    }
        
    for (long c = 1; c <= i; c++)
    {
        ff[c] = (2 * ff[c - 1]) %M;
    }
    long long r = ff[i-1] - f[i];
    if(r<0){
        r +=M;
    }
    cout <<  r << endl;

    return 0;
}
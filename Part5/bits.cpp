#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll r(ll a, ll i, ll l, ll ones, ll zeros)
{
    if (ones > l || zeros > l)
    {
        return 0;
    }
    if (a == i)
    {
        return 1;
    }
    a++;
    return r(a, i, l, ones + 1, 0) + r(a, i, l, 0, zeros + 1);
}

int main()
{
    ll i, l, M;
    M = 1000000007;
    unordered_map<ll, ll> f;
    cin >> i >> l;
    if (l == 1)
    {
        cout << 2 << endl;
        return 0;
    }
    for (long x = 1; x <= 10; x++)
    {
        f[x] = (r(1, x, l, 1, 0) * 2 )%M;
    }
    for (long x = 11; x <= i; x++)
    {
        long long a = 0;
        for(long i = 1; i<=l;i++)
             a = ( a + f[x - i]) % M;
        f[x] = a;
    }

    cout << f[i] << endl;

    return 0;
}
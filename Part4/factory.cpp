#include <bits/stdc++.h>

using namespace std;

vector<int> machines;
long w;

long f(long k)
{
    long d = 0;
    for (int i = 0; i < machines.size(); i++)
    {
        d += k / machines[i];
    }
    if (d < w)
    {
        return 0;
    }
    return 1;
    
}

int main()
{
    long m, x;
    cin >> m >> w;

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        machines.push_back(x);
    }

    sort(machines.begin(), machines.end());
    long max = machines[0] * w;
    long k = -1;

    for (long b = max; b >= 1; b /= 2)
    {
        while (f(k + b) == 0)
            k += b;
    }
    long ans = k + 1;
    cout << ans << endl;
}
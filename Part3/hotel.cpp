#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<long> r;
    int m, q, w, a = 0;
    vector<long> g;

    cin >> q >> w;
    for (int i = 0; i < q; i++)
    {
        cin >> a;
        r.insert(a);
        if (a > m)
        {
            m = a;
        }
    }

    for (int i = 0; i < w; i++)
    {
        cin >> a;
        bool f = false;

        if (a > m)
        {
            g.push_back(-1);
            continue;
        }
        auto j = r.find(*r.lower_bound(a));
        while (j != r.end())
        {
            if(a <= *j){
                g.push_back(*j);
                r.erase(r.find(*j));
                f = true;
                break;
            }
            j++;
        }
        if (!f)
        {
            g.push_back(-1);
        }
    }
    for (int i; i < g.size(); i++)
    {
        cout << g[i] << ' ';
    }
    cout << endl;
}
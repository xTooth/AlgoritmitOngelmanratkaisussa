#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> m;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    for (unsigned i = 0; i < s.size(); i++)
    {
        m[s[i]] = m[s[i]] + 1;
    }
    string a = "";
    vector<char> chrs;
    for (auto const &c : m)
    {
        chrs.push_back(c.first);
    }
}
#include <bits/stdc++.h>

using namespace std;

string srtS(string &s){
    sort(s.begin(), s.end());
    return s;
}

int main(){
    int t;
    cin >> t;
    map<string, int> m;
    for (int i = 0; i < t; i++)
    {
        string x;
        cin >> x;
        x = srtS(x);
        m[x] = 1;
    }
    cout << m.size();
}
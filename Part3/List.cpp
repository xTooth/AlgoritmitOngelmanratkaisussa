#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<long ,vector<long>, std::greater<long>> q;
    long n;
    long k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        q.push(k);    
    }
    while(q.size() > 1){
        n = q.top();
        q.pop();
        k = n + q.top();
        cout << k << ' ';
        q.pop();
        q.push(k);
    }
}
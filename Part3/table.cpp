#include <bits/stdc++.h>
 
using namespace std;
 
long o(long x){
    long ans = 0;
    for(long i = 0; i<=x; i++){
        ans = ans + i;
    }
    return ans;
}
 
int main()
{
    long i, k, p = 0;
    vector<long> n;
    map<long,long> r;
    cin >> i;
 
    for (long j = 0; j < i; j++)
    {
        cin >> k;
        n.push_back(k);
    }
 
    k = 0;
    unsigned x = 0;
    while( x < n.size())
    {
        
        if(r.count(n[x]) > 0){
            long h = x - (r[n[x]] +1);
            //cout << "h:" << h << " p: " << p << " rnx: " << r[n[x]] << endl;
            //cout << "item at h: " << n[h] << endl;
            k = k + o(p) - o(h);    
            p = 0;
            x = r[n[x]];
            r.clear();
        } else {  
            r[n[x]] = (long) x;
            p++;
        }
        if( x == (n.size() -1)){
            k = k + o(p);
            break;
        }
        x++;
        
    }
    cout << k << endl;
}
// 80 69 91 47 74 75 94 22 100 43 50 82 47 40 51 90 27 98 85 47
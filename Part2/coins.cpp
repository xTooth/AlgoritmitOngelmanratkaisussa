#include <bits/stdc++.h>
using namespace std;

void fS(vector<long> &a, long &n){
    long r = 1;
    for (long i = 0; i < n && a[i] <= r; i++)
        r = r + a[i];
    cout << r << endl;
}

int main(){
    long i;
    vector<long> v;
    cin >> i;
    for (long j = 0; j < i; j++){
        long k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    long n = v.size();
    fS(v, n);   
}
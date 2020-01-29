#include <bits/stdc++.h>

using namespace std;

int main(){

    long posts;
    long input;
    long output = 0;
    vector<long> amounts;
    cin >> posts;
    
    for(long i = 0; i< posts; i++){
        cin >>input;
        amounts.push_back(input);
    }
    sort(amounts.rbegin(),amounts.rend()); 
    for( long i : amounts){
        if (i >= output + 1){
            output++;
        } else {
            break;
        }
    }
    cout << output << '\n';
}

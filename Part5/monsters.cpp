#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int t[2500]={0};
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size();j++){
            if(i > 0 && j > 0){
                if(s[j] == '*'){
                    t[j] = min(t[j-1], t[j]) +1;
                }else{
                    t[j] = min(t[j-1], t[j]);
                }
            }else if(i > 0){
                if(s[j] == '*'){
                    t[j] = t[j] + 1;
                }
            }else if(j > 0){
                if(s[j] == '*'){
                    t[j] = t[j-1] + 1;
                }else{
                    t[j] = t[j-1];
                }
            }else{
                if(s[j] == '*'){
                    t[j] = 1;
                }else{
                    t[j] = 0;
                }
            }
        }
    }
    cout << t[n-1] << endl;
    return 0;
}
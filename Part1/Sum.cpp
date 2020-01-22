# include <iostream>

using namespace std;

int main(){
    int i;
    cin >> i;
    long a = 0;
    for(int x = 1; x <= i; x++){
        a += x;
    }
    cout << a << "\n";

}
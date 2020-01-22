#include <iostream>

using namespace std;

int main(){
    int i;
    cin >> i;
    if( i == 2 || i == 3 ) {
        cout << "NO SOLUTION\n";
    } else {
    
        for (int x = 1; x <= i ; x++) {
            if ( x % 2 == 0) {
                cout << x << " ";
            }
        }
        for (int x = 1; x <= i ; x++) {
            if ( x % 2 != 0) {
                cout << x << " ";
        
            }
        }
        cout << "\n";
    }
}
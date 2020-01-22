#include <iostream>

using namespace std;

int main() {
    long tests;
    cin >> tests;
    long x,y;
    for( int i = 0; i< tests; i++){
        cin >> x >> y;
        if( x == y && x == 0){
            cout << "YES";
        }else if((x == 0 && y != 0) || (y==0 && x != 0)){
            cout << "NO";
        }else if( (x + y) % 3 != 0){
            cout << "NO";
        }else{
            if( x > y){
                double half = (double) y / x;
                
                if ( half < 0.5){
                    cout << "NO";
                } else{ 
                    cout << "YES";
                }
            }else if( y > x){
                double half = (double) x / y;
                if ( half < 0.5){
                    cout << "NO";
                } else{ 
                    cout << "YES";
                }
            }else {
                cout << "YES";
            }
        }
        cout << "\n";
    }

}
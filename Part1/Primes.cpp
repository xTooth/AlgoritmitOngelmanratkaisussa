#include <iostream>
#include <stack>

using namespace std;

bool isPrime(int number){

    for (int a = 2; a*a <= number; a++) {
        if (number % a == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    stack <int> primes;
    int n;
    cin >> n;
    stack <int> descending;
    stack <int> pairs;
    int lowestUsed = n + 1;
    int highestAllowed = n;
//generate primes
    for (int currentNum = 2; currentNum <= n * 2 ; currentNum++) {
        if (isPrime(currentNum)) {
            primes.push(currentNum);
        }
    }
//combine pairs
    while (!primes.empty() && n > 0) {

        if(n + highestAllowed < primes.top()){
            highestAllowed = lowestUsed -1;
            while(n+highestAllowed < primes.top()){
                primes.pop();
            }
            
        }

        for(int i = highestAllowed; i + n >= primes.top(); i-- ) {
            if ( i + n == primes.top()){
                descending.push(n);
                pairs.push(i);
                if(i < lowestUsed){
                    lowestUsed = i;
                }
            }
        }

        n--;
    } 

//printing the lists
    while (!descending.empty()) { 
        cout << ' ' << descending.top(); 
        descending.pop(); 
    } 
    cout << '\n';
    while (!pairs.empty()) { 
        cout << ' ' << pairs.top(); 
        pairs.pop(); 
    } 
    cout << '\n';
}
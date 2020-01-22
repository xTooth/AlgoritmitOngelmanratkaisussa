#include <iostream>

using namespace std;
// array for characters
int chars[256] = {0};


bool isPalindromable(string x){
    // count for chars that appear an odd amount of times.
    int odds = 0;
    
    // count appearences of chars
    for(int i = 0; x[i]; i++) {
        chars[x[i]]++;
    }

    //count amount of odd occurances, if more than 1 odd, cant be palindrome
    for (int i = 0; i<256; i++){
        
        if(chars[i] % 2 != 0) {
            odds++;
        } 
        if (odds > 1) {
            return false;
        }
    }
    return true;
}

string buildPalindrome(string x){
    int min = 0;
    int max = x.size() -1;
    int word[1000001] = {0};
    int center = 0;
    int cam= 0;
    
    for(int i = 0; i<256; i++){
        if(chars[i] % 2 == 0){
            int amount = chars[i] / 2;
            for(int e = 0; e < amount ; e++){
                word[max] = i;
                max--;
                word[min] = i;
                min++;
            }
        }
        if(chars[i] % 2 != 0){
            cam = chars[i];
            center = i;
        }
    }
    for(int i = 0; i<cam;i++){
        word[min] = center;
        min++;
    }
    string ans = "";
    for(int i = 0; word[i]; i++){
        ans += (char) word[i];
    }
    return ans;  
}

int main(){
    string x;
    cin >> x;
    if (isPalindromable(x)) {
        cout << buildPalindrome(x) << "\n";  
    } else {
        cout << "NO SOLUTION\n";
    }
}



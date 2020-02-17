#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, mid;
    cin >> n;
    long long min = 1;
    long long max = n * n;
    
    while (min <= max)
    {
        mid = (min + max) / 2;
        long long sum = 0;
        for (int i = 1; i <= n; i++){
            if(mid / i > n ){
                sum += n;
            } else {
                sum += mid / i ;
            }
        }

        sum--;
        if (sum < (n * n) / 2){
            min = mid + 1;
        } else if (sum > (n * n) / 2){
            max = mid - 1;
        } else {
            break;
        }
    }

    if(mid > min){
        cout << mid << endl;
    } else {
        cout << min << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> inputNumbers;
    int input, size, x;
    cin >> input >> size;
    //used for finding numbers in table
    map<int, int> amounts;
    //used for "scorekeepimg with negative integer amounts for nice sorting"
    set<pair<int, int>> amountAndOfWhat;
    int minValorMaxAmount = 0;
    
    for (int i = 0; i < input; i++)
    {
        cin >> x;
        inputNumbers.push_back(x);
    }
    for (int i = 0; i < size; i++)
    {
        amounts[inputNumbers[i]]++;
    }
    auto i = amounts.begin();
    while ( i != amounts.end())
    {
        amountAndOfWhat.insert({-(i->second), i->first});
        i++;
    }
    minValorMaxAmount = amountAndOfWhat.begin()->second;
    for (int i = size; i <= inputNumbers.size(); i++)
    {
        //print ans.
        cout << minValorMaxAmount << " ";
        if (amounts[inputNumbers[i]] == 0)
        {
            amountAndOfWhat.insert({0, inputNumbers[i]});
        }
        // remove old val at i-size  so if pointer is at 5 and size of table is 3, it points to beginning of table. 
        amountAndOfWhat.erase(amountAndOfWhat.find(pair<int, int>(-amounts[inputNumbers[i - size]], inputNumbers[i - size])));
        amounts[inputNumbers[i - size]]--;
        amountAndOfWhat.insert({-amounts[inputNumbers[i - size]], inputNumbers[i - size]});
        // insert new val
        amountAndOfWhat.erase(amountAndOfWhat.find(pair<int, int>(-amounts[inputNumbers[i]], inputNumbers[i])));
        amounts[inputNumbers[i]]++;
        amountAndOfWhat.insert({-amounts[inputNumbers[i]], inputNumbers[i]});
        minValorMaxAmount = amountAndOfWhat.begin()->second;
    }
    cout << endl;
}
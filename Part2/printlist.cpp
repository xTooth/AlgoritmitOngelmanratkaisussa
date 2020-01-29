#include <bits/stdc++.h>

using namespace std;

bool comparer(std::pair<int, string> &lhs, std::pair<int, string> &rhs) {
    if (lhs.first > rhs.first) {
        return true;
    }
    else if (lhs.first == rhs.first && lhs.second < rhs.second) {
        return true;
    }
    else {
        return false;
    }
}


int main(){
    string name;
    int points;
    long entries;
    cin >> entries;
    vector< pair<int, string> > list;
    for(int i = 0; i<entries; i++){
        cin >> name >> points;
        list.push_back(pair<int,string> (points,name));
    }
    sort(list.begin(),list.end(),comparer);

    for(int i = 0; i<list.size(); i++) {
        cout << list[i].second << " " << list[i].first << "\n";
    }

}
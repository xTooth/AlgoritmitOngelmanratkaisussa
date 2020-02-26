#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    pair<string, int> t[2500];

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if( i == 0 && j == 0){
                if(s[j] == '*'){
                    cout << -1 << endl;
                    return 0;
                }else{
                    t[j] = {"dr",0};
                }
            }
            else if (s[j] == '*')
            {
                t[j] = {"w", -1};
            }
            else if (i > 0 && j > 0)
            {
                if ((t[j].first == "d" && t[j - 1].first == "r")
                || (t[j].first == "dr" && t[j - 1].first == "dr")
                || (t[j].first == "dr" && t[j - 1].first == "r") 
                || (t[j].first == "d" && t[j - 1].first == "dr"))
                {
                    if (t[j].second == t[j - 1].second)
                    {
                        t[j] = {"dr", t[j].second};
                    }
                    else if (t[j].second > t[j - 1].second)
                    {
                        t[j] = {"r", t[j - 1].second};
                    }
                    else
                    {
                        t[j] = {"d", t[j].second};
                    }
                }
                else if ((t[j].first == "d" && t[j - 1].first == "d") 
                        || (t[j].first == "dr" && t[j - 1].first == "d"))
                {
                    if (t[j].second == t[j - 1].second + 1)
                    {
                        t[j] = {"dr", t[j].second};
                    }
                    else if (t[j].second < t[j - 1].second + 1)
                    {
                        t[j] = {"d", t[j].second};
                    }
                    else
                    {
                        t[j] = {"r", t[j - 1].second + 1};
                    }
                }
                else if ((t[j].first == "r" && t[j - 1].first == "r")
                        || (t[j].first == "r" && t[j - 1].first == "dr"))
                {
                    if (t[j].second + 1 == t[j - 1].second)
                    {
                        t[j] = {"dr", t[j].second + 1};
                    }
                    else if (t[j].second + 1 < t[j - 1].second)
                    {
                        t[j] = {"d", t[j].second + 1};
                    }
                    else
                    {
                        t[j] = {"r", t[j - 1].second};
                    }
                }
                else if (t[j].first == "w" && t[j - 1].first != "w")
                {
                    if (t[j - 1].first == "d" )
                    {
                        t[j] = {"r", t[j - 1].second + 1};
                    }
                    else
                    {
                        t[j] = {"r", t[j - 1].second};
                    }
                }
                else if (t[j].first != "w" && t[j - 1].first == "w")
                {
                    if (t[j].first == "d" || t[j].first == "dr")
                    {
                        t[j] = {"d", t[j].second};
                    }
                    else
                    {
                        t[j] = {"d", t[j].second + 1};
                    }
                }else if(t[j].first == "r" && t[j-1].first == "d"){
                    if(t[j].second == t[j-1].second){
                        t[j] = {"dr",t[j].second +1};
                    }
                    else if(t[j].second > t[j-1].second){
                        t[j] = {"r", t[j-1].second +1};
                    }else{
                        t[j] = {"d", t[j].second +1};
                    }

                }
                else
                {
                    t[j] = {"w", -1};
                }
            }
            else if (i > 0)
            {
                if(t[j].first == "w"){
                    t[j] = {"w",-1};
                }
               else if (t[j].first == "d" || t[j].first == "dr")
                    {
                        t[j] = {"d", t[j].second};
                    }
                    else
                    {
                        t[j] = {"d", t[j].second + 1};
                    } 
            }
            else
            {
                if(t[j-1].first == "w"){
                    t[j] = {"w",-1};
                    continue;
                }
                if (t[j - 1].first == "d" )
                    {
                        t[j] = {"r", t[j - 1].second + 1};
                    }
                    else
                    {
                        t[j] = {"r", t[j - 1].second};
                    }
            }

            // cout << "at i:" << i << " j:"<< j << " s[j]:" << s[j] << " turns now: " << t[j].second  << "directon: " << t[j].first << endl;
        }
    }

    cout << t[n - 1].second << endl;
    return 0;
}
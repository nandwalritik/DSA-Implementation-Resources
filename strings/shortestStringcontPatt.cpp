#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    map<char, int> mp1, mp2;
    for (auto x : s2)
        mp2[x]++;
    int rmct = 0, mct = 0;
    for (auto x : mp2)
    {
        rmct += x.second;
    }
    int left = 0, right = 0;
    string ans = "";
    while (true)
    {
        bool f1 = false, f2 = false;
        // cout << "Aquiring\n";
        while (right < n && mct < rmct)
        {
            mp1[s1[right]]++;
            if (mp1[s1[right]] <= mp2[s1[right]])
            {
                mct++;
            }
            string temp = s1.substr(left, right - left + 1);
            cout << temp << endl;
            right++;
            f1 = true;
        }

        // cout<<"Releasing\n";
        while (left < right && mct == rmct)
        {
            string temp = s1.substr(left, right - 1 - left + 1);
            cout << temp << endl;
            if (ans.size() == 0 || ans.size() > temp.size())
            {
                ans = temp;
            }

            if (mp1[s1[left]] == 1)
            {
                mp1.erase(s1[left]);
            }
            else
            {
                mp1[s1[left]]--;
            }
            if (mp1[s1[left]] < mp2[s1[left]])
            {
                mct--;
            }
            left++;
            f2 = true;
        }
        if (!f1 && !f2)
            break;
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    cout << "Inside solve" << endl;
    vector<int> v{-5, -2, 5, 2, 4, 7, -8,13,14,-15,-17,-19,-10,-57,-56};
    int n = v.size();

    /*----------------O(n^2) approach-------------*/

    // for (int i = 1; i < n; i++)
    // {
    //     if (v[i] * v[i - 1] < 0)
    //         continue;
    //     else
    //     {
    //         int j;
    //         for (j = i + 1; j < n; j++)
    //         {
    //             if (v[i] * v[j] < 0)
    //             {
    //                 swap(v[i], v[j]);
    //                 break;
    //             }
    //         }
    //         if (j == n)
    //             break;
    //     }
    // }

    /*-------------------------------------------*/


    /*----------------O(nlogn) approach-------------*/

    // sort(v.begin(), v.end());

    /*-------------------------------------------*/

    /*----------------O(n) approach-------------*/
    int left=0,right=n-1;
    while(left < right){
        while(left < n && v[left] < 0)
            left++;
        while(right >= 0 && v[right] >= 0)
            right--;
        if(left<right)
            swap(v[left],v[right]);
    }
    /*-------------------------------------------*/
    int negEnd, pos = 0, neg = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
            continue;
        else
        {
            negEnd = i - 1;
            break;
        }
    }
    for (auto x : v)
        cout << x << " ";
    cout<<endl;
    int posStart = negEnd + 1, posEnd = n - 1;
    int i;
    for (i = 1; i < n && posStart < n; i++)
    {   
        if(v[i] * v[i-1] <= 0)
            continue;
        else{
            swap(v[i],v[posStart]);
            posStart++;
        }
    }


    for (auto x : v)
        cout << x << " ";
    cout<<endl;
}

int main(){
    solve();
    return 0;
}
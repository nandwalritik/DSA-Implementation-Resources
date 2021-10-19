/*Easy logic just find nsl and nsr and then compute the area*/
#include <bits/stdc++.h>
using namespace std;
long long getMaxArea(long long arr[], int n)
{
    // Your code here
    vector<int> nsl(n), nsr(n);
    stack<pair<int, int>> st, st1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nsr[i] = n;
        }
        else
        {
            nsr[i] = st.top().second;
        }
        st.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        while (!st1.empty() && st1.top().first >= arr[i])
        {
            st1.pop();
        }
        if (st1.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = st1.top().second;
        }
        st1.push({arr[i], i});
    }
    long long int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (nsr[i] - nsl[i] + 1 - 2));
        // cout<<arr[i]*(nsr[i]-nsl[i]+1-2)<<" ";
    }
    // cout<<endl;
    return ans;
}
int main()
{
}
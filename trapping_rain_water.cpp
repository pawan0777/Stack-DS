#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = v.size();
    int ans = 0, left = 0, right = n - 1, maxleft = 0, maxright = 0;
    while (left <= right)
    {
        if (v[left] <= v[right])
        {
            maxleft = max(maxleft, v[left]);
            ans += maxleft - v[left];
            left++;
        }
        else
        {
            maxright = max(maxright, v[right]);
            ans += maxright - v[right];
            right--;
        }
    }
    cout << ans;
    return 0;
}
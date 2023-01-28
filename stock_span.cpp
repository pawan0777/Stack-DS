#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    vector<int> v = {100, 80, 60, 70, 60, 75, 85}, res(n);
    stack<pair<int,int>> st;
    for (int i = 0; i < n; i++){
        if (st.empty()){
            res[i] = -1;
        }
        else if (st.size() > 0 and st.top().first > v[i]){
            res[i] = st.top().second;
        }
        else if (st.size() > 0 and st.top().first <= v[i]){
            while (st.size() > 0 and st.top().first <= v[i]){
                st.pop();
            }
            if (st.size() == 0){
                res[i] = -1;
            }
            else{
                res[i] = st.top().second;
            }
        }
        st.push({v[i],i});
    }
    for (int i = 0; i < res.size(); i++){
        res[i] = i - res[i];
        cout<<res[i]<<" ";
    }
    return 0;
}
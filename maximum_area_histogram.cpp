#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {6,2,5,4,5,1,6};
    int n = v.size();
    vector<int> nsl(n),nsr(n),res(n);
    stack<pair<int,int>> st;
    for (int i = 0; i < n; i++){
        if (st.empty()){
            nsl[i] = -1;
        }
        else if (st.size() > 0 and st.top().first < v[i]){
            nsl[i] = st.top().second;
        }
        else if (st.size() > 0 and st.top().first >= v[i]){
            while (st.size() > 0 and st.top().first >= v[i]){
                st.pop();
            }
            if (st.size() == 0){
                nsl[i] = -1;
            }
            else{
                nsl[i] = st.top().second;
            }
        }
        st.push({v[i],i});
    }
    while(!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--){
        if (st.empty()){
            nsr[i] = n;
        }
        else if (st.size() > 0 and st.top().first < v[i]){
            nsr[i] = st.top().second;
        }
        else if (st.size() > 0 and st.top().first >= v[i]){
            while (st.size() > 0 and st.top().first >= v[i]){
                st.pop();
            }
            if (st.size() == 0){
                nsr[i] = n;
            }
            else{
                nsr[i] = st.top().second;
            }
        }
        st.push({v[i],i});
    }
    for (int i = 0; i < n; i++){
        res[i] = nsr[i] - nsl[i] - 1;
    }
    int ct = -1;
    for (int i = 0; i < n; i++)
    {
        ct = max(ct,res[i]*v[i]);
    }
    cout<<ct;
    return 0;
}
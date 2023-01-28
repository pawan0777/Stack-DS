#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int> v = {1, 3, 2, 4, 1}, res(n);
    stack<int> st;
    for (int i = 0; i < n; i++){
        if (st.empty()){
            res[i] = -1;
        }
        else if (st.size() > 0 and st.top() < v[i]){
            res[i] = st.top();
        }
        else if (st.size() > 0 and st.top() >= v[i]){
            while (st.size() > 0 and st.top() >= v[i]){
                st.pop();
            }
            if (st.size() == 0){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
        }
        st.push(v[i]);
    }
    for (auto it : res){
        cout << it << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string> 
#include <stack>
#define ll long long
#define pb push_back
#define bp pop_back
#define mod 1000000007
#define faster ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    faster;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int res[n];
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && a[i] >= a[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = i - st.top();
            }
            else res[i] = i + 1;
            st.push(i);

        }
        for(int i = 0; i < n; i++) cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}
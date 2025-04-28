#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n+1, 0);
        for(ll i = 1;i<=n;i++){
            cin>>arr[i];
        }
        if(arr[n] == 0){
            for(ll i = 1;i<=n+1;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(arr[1] == 1){
            cout<<n+1<<" ";
            for(ll i = 1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            bool flag = false;
            for(ll i = 1;i<n;i++){
                if(arr[i] == 0 && arr[i+1] == 1){
                    for(ll j = 1;j<=i;j++){
                        cout<<j<<" ";
                    }
                    cout<<n+1<<" ";
                    for(ll j = i+1;j<=n;j++){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}
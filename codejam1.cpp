#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<int> arr;
		ll ele;
		ll index=-1,flag=0;
		ll max=INT_MAX;
		arr.push_back(max);
		for(ll i=0;i<n;i++)
			{cin>>ele;
			arr.push_back(ele);
			}
		arr.push_back(max);
		for(ll i=1;i<n+1;i++){
			if(arr[i-1]<arr[i]&&arr[i+1]<arr[i]){
				index=i-1;
			}
		}
		cout<<index;
		if(t>0)
			cout<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long int
ll highestPowerOf2(ll n) 
{ 
    return (n & (~(n - 1))); 
} 
ll Noofcounts(ll n){
	//cout<<"in=";
	ll answer=0;
	ll count=highestPowerOf2(n);
//cout<<"cpunt="<<count;
for(int i=2;i<=n;i++){
	ll r=highestPowerOf2(i);
	if(r>count)
		{
			//cout<<"i="<<i<<endl;
			answer++;
		}
}
return answer;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<Noofcounts(n);
		if(t>0)
			cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long int
ll highestPowerOf2(ll n) 
{ 
    return (n & (~(n - 1))); 
} 
ll Noofcounts(ll n){
	//cout<<"in=";
	if(n%2==0)
		{
			//cout<<"innnnnnn";
			ll count=highestPowerOf2(n);
			//cout<<" c="<<count<<endl;
			if(count==n)
				return 0;
			else
				{
					ll answer=(n/(2*count));
					return answer;
				}
		}
	else
	{
		ll total=(n/2);
		return total;
	}
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

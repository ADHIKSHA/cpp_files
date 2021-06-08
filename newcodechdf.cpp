#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll smallEven(vector<ll> digits){
    ll index=-1,min=INT_MAX;
    ll size=digits.size();
    for(ll i=0;i<size;i++){
        if(digits[i]<min && digits[i]%2==0){
            min=digits[i];
            index=i; 
            break;
        }
    }
    //cout<<index<<endl;
    if(index==-1)
    	return -1;
    return index;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
		vector<ll> digits;
		int dig;
		for(ll i=0;i<n.length();i++){
			dig=n[i]-'0';
			digits.push_back(dig);
		}
		sort(digits.begin(),digits.end());
		int smallest=smallEven(digits);
		std::stringstream ret;
		string answer="";
		if(smallest==-1)
			cout<<"-1";
		else{
			for(ll i=digits.size()-1;i>=0;i--){
				if(i!=smallest){
					ret<<digits[i];
				}
			}
			ret<<digits[smallest];
    		ret>>answer;
    		cout<<answer;
		}
		
    if(t>0)
    	cout<<endl;
	}
}

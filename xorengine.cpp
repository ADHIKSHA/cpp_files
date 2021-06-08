#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool ismatched(ll k,ll num,ll arr[]){
    if(__gcd(arr[k],num)==1)
        return 1;
    else
        return 0;
}
vector <vector<ll> > addprimes(ll n) 
{ 
    vector <vector<ll> > vr;
    vector<ll> vs,vt;
    vs.push_back(1);
	    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
           for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (ll p=2; p<=n; p++) 
      { if (prime[p]) 
          vs.push_back(p);
    	else
    		vt.push_back(p);
            }
    vr.push_back(vs);
    vr.push_back(vt);
return vr;
} 

int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        vector<vector<ll> > vr;
		vector<vector<ll> > v =addprimes(n);
        vr.push_back(v[0]);
        ll size=0;
        ll arr[n];
        arr[0]=1;
        memset(arr,1,sizeof(arr));
        for(ll cntr=0;cntr<v[1].size();cntr++){
        	ll j= v[1][cntr];
			ll k=1;
            ll flag=0;
            while(k<=size){
                if(ismatched(k,j,arr))
                {vr[k].push_back(j);
                arr[k]*=j;
                //cout<<arr[k]<<" ";
                    flag=1;
                    break;
                }
                k++;
                //flag=1;
            }
            if(flag==0)
            {
                //cout<<"value="<<j<<endl;
            vector<ll> lm;
            lm.push_back(j);
            arr[++size]=j;
            vr.push_back(lm);
            }
                				
        }
        cout<<vr.size()<<endl;
        for(ll x=0;x<vr.size();x++){
            cout<<vr[x].size()<<" ";
            for(ll p=0;p<vr[x].size();p++){
                cout<<vr[x][p];
                if(p<vr[x].size()-1)
                    cout<<" ";
            }
            if(x<vr.size()-1)
            cout<<endl;
        }
    if(i<t-1)
    cout<<endl;
    }
    
}

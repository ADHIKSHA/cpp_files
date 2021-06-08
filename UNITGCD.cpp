#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std;
#define ll  long long int
  

bool ismatched(ll k,ll num,int128_t arr[]){
    if(__gcd((ll)arr[k],num)==1)
        return 1;
    else
        return 0;
}
vector <vector<ll> > addprimes(ll n) 
{ 
    vector <vector<ll> > vr;
    vector<ll> vs,vt,vz;
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
    	else if(p%2==0)
    		vt.push_back(p);
        else
			vz.push_back(p);    
			}
    vr.push_back(vs);
    vr.push_back(vt);
    vr.push_back(vz);
return vr;
} 

int main(){
	
    ll t;
    cin>>t;
    //sieve();
    for(ll i=0;i<t;i++){
    
        ll n;
        cin>>n;
        vector<vector<ll> > vr;
		vector<vector<ll> > v =addprimes(n);
        vr.push_back(v[0]);
        ll size=0;
        int128_t arr[n];
        arr[0]=1;
        ll length1=v[0].size();
        ll length2=v[1].size();
        ll length3=v[2].size();
        //int maxim[n][length1];
		
        for(ll x=0;x<n;x++)
        	{
        		arr[x]=1;
			}
      
        for(ll cntr=0;cntr<length2;cntr++){
        	vector<ll> vll;
        	vll.push_back(v[1][cntr]);//cout<<v[1][cntr]<<endl;
        	vr.push_back(vll);
        	arr[++size]*=v[1][cntr];
        	//maxim[++size][2]=1;
		}
	int got=0;
	if(length3>10000)
		got=1;
        for(ll cntr=0;cntr<length3;cntr++){
        	ll j= v[2][cntr];
        	
			ll k= 1;
			if(got==1)
				k=j/3+1;
            ll flag=0;
            while(k<=size){
            	
				if(arr[k]<0)
					k++;
				else{	

                if(ismatched(k,j,arr))
                {
				vr[k].push_back(j);
                	arr[k]*=j;
                
                    flag=1;
                    break;
                }
                k++;}
                //flag=1;
            }/*
            if(flag==0)
            {
                //cout<<"value="<<j<<endl;
            vector<ll> lm;
            lm.push_back(j);
            arr[++size]=j;
            vr.push_back(lm);
            }*/
                				
        }
        printf("%lld\n",n/2);
		//printf("%lld\n",vr.size());
        for(ll x=0;x<n/2;x++){
            printf("%lld ",vr[x].size());
            std::copy(vr[x].begin(),vr[x].end(),std::ostream_iterator<ll>(std::cout, " "));
			if(x<vr.size()-1)
			printf("\n");
        }  
    if(i<t-1)
   	printf("\n");
    }
    
}

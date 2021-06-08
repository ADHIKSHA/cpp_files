#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int muls(int a,int b){
	long long int pro=1;
	for(int i=0;i<b;i++){
		pro=(pro*a)%MOD;
	}
	return pro%MOD;
}
int permutation(int n, int r) 
{ 
  
     long long p = 1, k = 1; 
  
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p = (p*n)%MOD; 
            k = (k*r)%MOD; 
  
            long long m = __gcd(p, k)%MOD; 
  			p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
  
    else
        p = 1; 
  
    // if our approach is correct p = ans and k =1 
    return p%MOD;
} 

int func(int a,int b,int k){
	int odd=0,even=0;
	for(int i=a;i<=b;i++){
		if(i%2==0)
			even++;
		else
			odd++;
	}
//	cout<<odd<<" "<<even<<endl;
	long long int count=0,temp1,temp2;
	for(int i=0;i<=k;i+=2){
		temp1=(muls(odd,i)*muls(even,(k-i)))%MOD;
		//cout<<"temp1"<<temp1<<endl;
		temp2=(temp1*permutation(k,i))%MOD;
		//cout<<"perm="<<temp2<<endl;
		count=(count+temp2)%MOD;
	}
	return count%MOD;
}
int main(){
	int a,b,k;
	cin>>a>>b>>k;
	int ans=func(a,b,k);
	cout<<ans<<endl;
}

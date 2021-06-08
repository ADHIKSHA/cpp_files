#include<bits/stdc++.h>
using namespace std;
int factors(int n)  
{  
	int count=0;
    while (n % 2 == 0)  
    {  
        count++;
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
           count++;
            n = n/i;  
        }  
    }  
    if (n > 2)  
        count++;
        
    return count;
}  
  
int func(int a,int b){
	if(a==b)
		return 0;
	int gc=__gcd(a,b);
	if(gc==1){
		return (factors(a)+factors(b));
	}
	if(gc!=1){
		return func(a/gc,b/gc);
	}
	return factors(a)+factors(b);
}
int main(){
	int a,b;
	cin>>a>>b;
	int ans=func(a,b);
	cout<<ans;
}

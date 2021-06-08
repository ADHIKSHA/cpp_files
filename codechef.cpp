#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k,x,y;
		cin>>n>>k>>x>>y;
		int x1,y1,x2,y2;
		if(x==y){
			cout<<n<<" "<<n;
		}
		else{
			if(x>y){
				int val= n-x;
				x1=n;y1=y+val;
				x2=0;y2=abs(x1-y1);
			}
			if(x<y){
				int val= n-y;
				x1=x+val;y1=n;
				x2=abs(x1-y1);y2=0;
			}
			if((k-1)%4 == 0){ 
				cout<<x1<<" "<<y1;
			}
			if((k-1)%4 == 1){
				cout<<y1<<" "<<x1;
			}
			if((k-1)%4 == 2){
				cout<<x2<<" "<<y2;
			}
			if((k-1)%4 == 3){
				cout<<y2<<" "<<x2;
			}
		}
		if(i<t-1)
			cout<<"\n";
	}
}

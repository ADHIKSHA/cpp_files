#include<bits/stdc++.h>
//12564444444444444444411111
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	string n;
	cin>>n;
	//int temp;
	string answer="";
	int len=n.length();
	len=len-1;
	char stemp;
	for(int i=len;i>=0;i--){
			//stemp="";
		stemp=n[i];
		answer+=stemp;
	}
	cout<<answer;
	if(t>0)
		cout<<endl;
	}
}

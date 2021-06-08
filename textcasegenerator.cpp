#include<bits/stdc++.h>
using namespace std;

int main(){
	int y;
	cin>>y;
	long long int a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<long long int>  t;
	t.push_back(a);
	t.push_back(b);
	t.push_back(c);
	t.push_back(d);
	sort(t.begin(),t.end());
	long long int sum=(t[1]-t[0])+(t[2]-t[0])+(t[3]-t[0]);
	cout<<sum<<" ";
	long long int area = (t[0]*t[0])%1000000000;
	cout<<area;
}

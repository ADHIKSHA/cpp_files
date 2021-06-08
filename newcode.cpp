#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<double> movingTiles(int l, int s1, int s2, vector<int> queries) {
    /*
     * Write your code here.
     
     */
    vector<double> times;
    double diagonal=l*sqrt(2);
    ll q=queries.size();
    
    double area,qdiag,dist,time=0.00000;
    
    for(ll i=0;i<q;i++){
        area=queries[i];
        qdiag=sqrtl(area*2);
        dist=diagonal-qdiag;
        time=dist/abs(s2-s1);
        times.push_back(time);
    }
return times;
}
int main(){
	int l,s1,s2;
	cin>>l>>s1>>s2;
	int q;
	cin>>q;
	int c;
	vector<int> times;
	vector <double>timing;
	for(int i=0;i<q;i++){
		cin>>c;
		times.push_back(c);
	}
	timing=movingTiles(l,s1,s2,times);
	for(int i=0;i<q;i++){
		cout<<timing[i]<<endl;
	}
}

















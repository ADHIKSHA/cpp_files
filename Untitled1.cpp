#include<bits/stdc++.h>
using namespace std;
struct nodes{
	int start,end;
};
/*
bool Possible(vector<nodes> Val,int st,int end){
	int flag=1;
	for(int i=0;i<Val.size();i++){
		if(Val[i].start<st&&Val[i].end>end||Val[i].start<st&&Val[i].end>st||Val[i].start>st&&Val[i].start<end)
			{
				flag=0;
				break;
			}
	}
	return flag;
}
*/
bool sortbysec(const pair<nodes,int> &a, 
              const pair<nodes,int> &b) 
{ 
    return (a.first.end < b.first.end); 
} 
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector <pair<nodes,int>> inputs;
		int a1,b1;
		nodes p1;
		pair<nodes,int> p2;
		for(int j=0;j<n;j++)
		{
			cin>>a1>>b1;
			p1.start=a1;
			p1.end=b1;
			p2=make_pair(p1,j);
			inputs.push_back(p2);
		}
	//	before=inputs;
		sort(inputs.begin(),inputs.end(),sortbysec);
		int Cam=0,Jam=0;
		vector<char> Ans;
		int IMP=0;
		for(int j=0;j<n;j++){
			if(Cam<=inputs[j].first.start)
				{
					
					Cam=inputs[j].first.end;
					//cout<<Cam;
					Ans.push_back('C');
				}
			else if(Jam<=inputs[j].first.start){
					Jam=inputs[j].first.end;
					//cout<<Cam;
					Ans.push_back('J');
			}
			else{
				IMP=1;
				break;
			}
		}
	//	std::copy(Ans.begin(),Ans.end(),std::ostream_iterator<char>(std::cout, ""));
		//cout<<endl;
		cout<<"Case #"<<i+1<<": ";
		if(IMP==0)
		{
			int index;
			vector<char> final(n);
			for(int j=0;j<n;j++){
				index=inputs[j].second;
			//	cout<<index<<" ";
				final[index]=Ans[j];
			}
			std::copy(final.begin(),final.end(),std::ostream_iterator<char>(std::cout, ""));
		}
		else
		cout<<"IMPOSSIBLE";
		if(i<t-1)
		cout<<endl;
	}
}

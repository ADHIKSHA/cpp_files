#include<bits/stdc++.h>
using namespace std;
struct strt{
	int b,e;
	int l;
};
struct cars{

	std::vector<string> path;
};
int main(){
	//map<int,set<string>> All;
	int d,inter,s,v,f;
	cin>>d>>inter>>s>>v>>f;
	map<string,strt> street;
	cars car[v];
	string sname;int b,e,l;
	map<int,int> arrivaltime;

	for(int i=0;i<s;i++){
		cin>>b>>e>>sname>>l;
		street[sname].b=b;street[sname].e=e;street[sname].l=l;
	}
	for(int i=0;i<v;i++){
		int n;
		cin>>n;string strtn;
		for(int j=0;j<n;j++){cin>>strtn;
		    car[i].path.push_back(strtn);}
	}
	//cout<<"input done";
	map<int,set<string>> inters;
	for(int i=0;i<inter-1;i++){
		set<string> j;
		inters[i]=j;
	}
	for(int i=0;i<v;i++){
	    int end,prev=0;string p;
	     for(int j=0;j<car[i].path.size()-1;j++){
	     	p = car[i].path[j];
	     	end= street[p].e;
	     	set<string> s = inters[end];
	     	s.insert(p);
	        inters[end]= s;
	        int x=prev+street[p].l;
	        if(arrivaltime[end]==0)
	                 arrivaltime[end]=x;
	        else if(arrivaltime[end]>x)
	            arrivaltime[end]=x;
	            
	        prev= x;
	    }
	}
/*	for(map<int,set<string>>::iterator it = inters.begin();it!=inters.end();it++){
		cout<<it->first<<endl;
		for(set<string>::iterator iter = it->second.begin();iter!= it->second.end();iter++){
			cout<<*iter<<" ";
		}
		cout<<endl;
	}*/
	
//	cout<<"here";
	map<int,map<string,int>> ans;
	map<int,set<string>>::iterator it;
	for(int i=0;i<v;i++){
	for(it = inters.begin();it!=inters.end();it++){
	         int l = it->second.size();
	         map<string,int> vals;
	         set<string>::iterator iter=it->second.begin();
	         if(l==1){
	             vals[(*iter)]=1;
	             ans[it->first]=vals;
	         }
	         else{
	             for(iter=it->second.begin();iter!=it->second.end();iter++){
	                 vals[(*iter)]=arrivaltime[it->first];
	             }
	             ans[it->first]=vals;
	         }
	}

}
int n;
	map<int,map<string,int>>::iterator itert;
for(itert = ans.begin();itert!=ans.end();itert++){
	if(itert->second.size()==0)
		continue;
	n++;
}
	cout<<n<<endl;
	for(itert=ans.begin();itert!=ans.end();itert++){
		if(itert->second.size()==0)
			continue;
	    cout<<itert->first<<endl;
	    int leng = itert->second.size();
	    cout<<leng<<endl;
	    map<string,int> temp = itert->second;
	    int cnt =0;
	    for(map<string,int>::iterator iter = temp.begin();iter!=temp.end();iter++){
	        cout<<iter->first<<" "<<iter->second<<endl;
	       cnt++;
	    }
	}
}

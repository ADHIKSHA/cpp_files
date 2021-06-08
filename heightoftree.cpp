#include<bits/stdc++.h>
using namespace std;
void calcheight(vector <string> nums,int len,int nodepos,int &height)
{
	cout<<"nodepos="<<nodepos<<"height="<<height<<"val="<<nums[nodepos]<<endl;
//	int f=1;
	if(2*nodepos>len||2*nodepos+1>len)
		{return;}
	string left=nums[2*nodepos];
	string right=nums[2*nodepos+1];
	
	if(left!="N"||right!="N")
		height++;
		
	if(left!="N"){
	//	height++;
		//f=0;
		if(2*nodepos<=len)
		calcheight(nums,len,2*nodepos,height);
	}
	if(right!="N"){
		if(2*nodepos+1<=len)
		calcheight(nums,len,2*nodepos+1,height);
	}

}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//
	//	cout<<i<<endl;
		string input;
		vector <string> numbers;
		numbers.push_back("null");
		//memset(numbers,0,sizeof(numbers));
		int len;
		int l=0;
cin.ignore();
	getline(cin,input);
	len=input.length();
	//cout<<input;
	string buff="";
	for(int j=0;j<len;j++){
		
		if(input[j]==' '||j==len-1)
			{
				if(j==len-1)
					buff+=input[j];
				cout<<buff<<endl;
				numbers.push_back(buff);
				l++;
				buff="";
				//continue;
			}
		else if(input[j]!=' ')
			buff+=input[j];
	}
  
	int height=1;
	calcheight(numbers,l,1,height);
	cout<<height;
	}
}

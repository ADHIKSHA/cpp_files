#include<bits/stdc++.h>
using namespace std;
int main(){
	char arr[9][20],an[9][20],temp[9][20];
	int count=0,total=0;
	string s;
	for(int i=0;i<=8;i++){
		cin>>s;
		for(int j=0;j<20;j++){
			an[i][j]=s[j];
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<20;j++){
			arr[i][j]=an[8-i][j];
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<20;j++){
			if(arr[i][j]=='a'||arr[i][j]=='c')
				{
				total++;
				}
			temp[i][j]=arr[i][j];
		}
	}
	
	int bound=0,i=1,j=1,direc=1;
	cout<<"0 0"<<endl;
	int flag=0;
	while(bound<=1&&flag<1000)
	{
		flag++;
		cout<<i<<" "<<j<<endl;
		if(arr[j][i]=='*'&&bound==1){
				break;
			}
			if(arr[j][i]=='*'){
				if(i==0&&j==8||i==20&&j==8||i==20&&j==0){
					break;
				}
			}
			if(arr[j][i]=='*'&&bound==0){
			//	cout<<"here"<<direc;
				bound++;
				if(i==0&&j!=8&&j!=0){
				//	cout<<"a";
					if(direc==2)
						{
							direc=1;
							i++;j++;
						}
					else if(direc==4){
						direc=3;j--;i++;
					}
				}
				else if(i==20&&j!=0&&j!=8){
				//	cout<<"b";
					if(direc==1){
						direc=2;i--;j++;
					}
					else if(direc==3){
						direc=4;i--;j--;
					}
				}
				else if(j==8&&i!=0&&i!=20){
				//	cout<<"c";
					if(direc==2){
						direc=4;i--;j--;
					}
					else if(direc==1){
						direc=3;j--;i++;
					}
				}
				else if(j==0&&i!=0&&i!=20){
				//	cout<<"here";
					if(direc==4)
						{
						direc=2;i--;j++;
						}
					else if(direc==3)
						{
						direc=1;
						i++;j++;
						}
				}
				continue;
			}
			
			if(arr[j][i]=='c'){
				temp[j][i]='-';
				
				if(direc==1)
					{direc=3;	j--;i++;}
					
				else if(direc==2)
					{direc=1;i++;j++;}
				else if(direc==3)
					{direc=4;i--;j--;}
				else if(direc==4)
					{direc=2;i--;j++;}
				count++;
				continue;
			}
			if(arr[j][i]=='a'){
				temp[j][i]='-';
				
				if(direc==1)
					{direc=2;
					i--;j++;}
				else if(direc==2)
					{
					direc=4;i--;j--;}
				else if(direc==3)
					{
					direc=1;i++;j++;}
				else if(direc==4)
				{
					direc=3;j--;i++;}
				count++;
				continue;
			}
		if(arr[j][i]=='.'){
			if(direc==1)
				{
				i++;j++;
				}
			else if(direc==2)
				{
					i--;j++;
				}
			else if(direc==3){
				j--;i++;
			}
			else if(direc==4){
				i--;j--;
			}
			continue;
		}	
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<20;j++){
			cout<<temp[8-i][j];
		}
		cout<<endl;
	}
	cout<<"safe="<<(total-count)<<endl;
	cout<<"infected="<<(count)<<endl;
	return 0;
}

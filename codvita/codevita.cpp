#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char arr[n][n],trans[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			trans[j][i]=arr[i][j];
		}
	}
	int count[n],count1[n];
	memset(count,0,sizeof(count));
	memset(count1,0,sizeof(count1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[j][i]=='D'){
				count[i]++;
			}
			if(trans[j][i]=='D'){
				count1[i]++;
			}
		}
	}
	int ch[n][n],trans1[n][n],subs[n][n],subs1[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j-count[i]>0){
				ch[j][i]=0;
				count[i]--;
			}
			else{
				ch[j][i]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j-count1[i]>0){
				trans1[j][i]=0;
				count1[i]--;
			}
			else{
				trans1[j][i]=1;
			}
		}
	}


	for(int i=0;i<n;i++){
		subs[i][0]=ch[i][0];
		subs1[i][0]=trans1[i][0];
	}
	for(int i=0;i<n;i++){
		subs[0][i]=ch[0][i];
		subs1[0][i]=trans1[0][i];
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(ch[i][j]==1){
				subs[i][j]=min(subs[i][j-1],min(subs[i-1][j],subs[i-1][j-1]))+1;
			}
			else
				{subs[i][j]=0;}
			
			if(trans1[i][j]==1){
				subs1[i][j]=min(subs1[i][j-1],min(subs1[i-1][j],subs1[i-1][j-1]))+1;
			}
			else
				{subs1[i][j]=0;}
		}
	}
			
	int max=0,max1=0,final;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(max1<subs1[i][j])
				max1=subs1[i][j];
			if(max<subs[i][j])
				max=subs[i][j];
		}
	}
	if(max>max1)
		final=max;
	else
		final=max1;

	cout<<final;

}

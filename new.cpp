#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
bool vowel(char a){
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		return 1;
	else
		return 0;
}
string findSubstring(string s, int k) {
int j=0;
int len=s.length();
int count=0;
int max=INT_MIN;
string ret;
int flag=0;
for(int i=0;i<len-k+1;i++){
	count=0;
	j=i;
	string answer;
	while(j<i+k){
		answer+=s[j];
		if(vowel(s[j])==1){
			count++;
			flag=1;
		}
		j++;
	}
	if(count>max)
		{max=count;
		ret=answer;
		}
	if(count==k)
		break;
}
if(flag==0)
	return "Not Found!";
else 
return ret;
}

int main(){
	string s;
	int k;
	cin>>s>>k;
	cout<<findSubstring(s,k);
	
}

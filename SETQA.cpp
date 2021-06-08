#include<bits/stdc++.h>
using namespace std;
int CheckPrime(int n){         //return 1 if prime else returns 0
	int flag=1;
	for(int i=2;i<=pow(n,0.5);i++)    //the loop will only run till sqrt(n) because the factos only lie in that range.
	{
		if(n%i==0)					//factor is found
			flag=0;
	}
	return flag;
}
int CheckAms(int n){          //return 1 if amstrong else returns 0
	int flag=0;
	int sum=0,temp=n,temp2=n,noofdigits=0;
	while(temp2>0)				//loop to get number of digits in the number
	{
		noofdigits++;
		temp2=temp2/10;
	}
	
	while(n>0)				//loop until number of digits in the number
	{
		sum+=pow(n%10,noofdigits); // cubing and adding them to the sum
		n=n/10;
	}
	if(temp==sum)    		// if sum is equal to the number return 1
		flag=1;
	else
		flag=0;
		
	return flag;
		
}
int main(){
	cout<<"\n Enter the Number=";
	int n;
	A:
	 cin>>n;
	//Check the number for prime and Amstrong using function calls
	// 1 for true and 0 for false
	if(n>pow(10,9)||n<0)
	{
		cout<<"\n This number is out of the range(0 - 10^9).\n Please Enter the number again:-";
		 cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto A;
	}
	if(!cin)
	{
		cout<<"\n This input is not valid.\n Please Enter the number again:-";
		 cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto A;
	}
	if(n==0||n==1){
		cout<<"\n Number is neither Prime nor Composite";
		cout<<"\n Number is not amstrong";
	}
	else{
	if(CheckPrime(n)==1)
		cout<<"\n Number is Prime";	
	else
		cout<<"\n Number is not Prime/Composite";
	if(CheckAms(n)==1)
		cout<<"\n Number is Amstrong";
	else
		cout<<"\n Number is not Amstrong";
	}
		
}

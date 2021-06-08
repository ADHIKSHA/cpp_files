#include<iostream>
 
using namespace std;
 
int main() {
    int bitdata[10];
    int bitdatatrec[10],c,c1,c2,c3,i;
 
    cout<<"Enter 4 bits of bitdata one by one\n";
    cin>>bitdata[0];
    cin>>bitdata[1];
    cin>>bitdata[2];
    cin>>bitdata[4];
 
    //Calculation of even parity
    bitdata[6]=bitdata[0]^bitdata[2]^bitdata[4];
	bitdata[5]=bitdata[0]^bitdata[1]^bitdata[4];
	bitdata[3]=bitdata[0]^bitdata[1]^bitdata[2];
 
	cout<<"\nEncoded bitdata is\n";
	for(i=0;i<7;i++)
        cout<<bitdata[i];
    
	cout<<"\n\nEnter received bitdata bits one by one\n";
    for(i=0;i<7;i++)
        cin>>bitdatatrec[i];
 
    c1=bitdatatrec[6]^bitdatatrec[4]^bitdatatrec[2]^bitdatatrec[0];
	c2=bitdatatrec[5]^bitdatatrec[4]^bitdatatrec[1]^bitdatatrec[0];
	c3=bitdatatrec[3]^bitdatatrec[2]^bitdatatrec[1]^bitdatatrec[0];
	c=c3*4+c2*2+c1 ;
 
    if(c==0) {
		cout<<"\nNo error while transmission of bitdata\n";
    }
	else {
		cout<<"\nError on position "<<c;
		
		cout<<"\nbitdata sent : ";
		for(i=0;i<7;i++)
        	cout<<bitdata[i];
        
		cout<<"\nbitdata received : ";
        for(i=0;i<7;i++)
        	cout<<bitdatatrec[i];
        
		cout<<"\nCorrect message is\n";
        
		//if errorneous bit is 0 we complement it else vice versa
		if(bitdatatrec[7-c]==0)
			bitdatatrec[7-c]=1;
        else
		 	bitdatatrec[7-c]=0;
		for (i=0;i<7;i++) {
			cout<<bitdatatrec[i];
		}
	}
	
	return 0;
}



/*OUTPUT:-
Enter 4 bits of bitdata one by one
1 0 0 1

Encoded bitdata is
1001100

Enter received bitdata bits one by one
1 0 0 0 1 0 0

Error on position 4
bitdata sent : 1001100
bitdata received : 1000100
Correct message is
1001100

*/

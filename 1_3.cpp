#include<iostream>
#include<string.h>
using namespace std;
int main(){
	const char* p="abc";
	cout<<p<<endl;
	const char* q=new char[5]{'d','e','f',0,0};
	char* m=(char*)q;
	cout<<q<<" "<<strlen(q)+2<<endl;
	char n;
	cin>>n;
	for(int i=0;i<4;i++){
		if(i!=3){
			*(m+i)=*(p+i);
		}
		else{
			*(m+i)=n;
		}
		
	}
	cout<<q;
	delete[] q;
	return 0;
}
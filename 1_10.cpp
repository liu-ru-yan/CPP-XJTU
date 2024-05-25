#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1<<8],point=0;
	while(1){
		int n;
		cin>>n;
		if(n==-1){
			break;
		}
		else{
			a[point++]=n;
		}
	}
	int *p1=a,*p2=a;
	for(int i=0;i<point;i++,p2++){
		if(*p2!=0){
			int t=*p2;
			*p2=*p1;
			*p1=t;
			p1++;
		}
		else{
			continue;
		}
	}
	for(int i=0;i<point;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
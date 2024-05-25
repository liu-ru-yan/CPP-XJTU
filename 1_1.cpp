#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *p[n];
	int ans=0;
	for(int i=0;i<n;i++){
		p[i]=NULL;
		int t;
		cin>>t;
		p[i]=new int;
		if(p[i]){
			*p[i]=t;
			ans=ans+*p[i];
		}
		if(p[i]){
			delete p[i];
		}
	}
	cout<<ans;
	return 0;
}
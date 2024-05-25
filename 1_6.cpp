#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[5],b[6];
	cin>>a>>b;
	for(int i=0;i<4;i++){
		if(a[i]==b[i]){
			continue;
		}
		else{
			if(a[i]>=b[i]){
				cout<<a;
				break;
			}
			else{
				cout<<b;
				break;
			}
		}
	}
	return 0;
}
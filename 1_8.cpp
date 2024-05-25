#include<bits/stdc++.h>
using namespace std;
int main(){
	int r=0;
	for(int i=2;i<=30;i++){
		r=0;
		if(i==2||i==3){
			cout<<i<<" ";
			continue;
		}
		else{
			for(int j=2;j<=sqrt(i);j++){
				if(i%j==0){
					r=1;
					break;
				}
			}
			if(r==0){
				if(i==29){
					cout<<i;
				}
				else{
					cout<<i<<" ";
				}
			}
			else{
				continue;
			}
		}
	}
	return 0;
}
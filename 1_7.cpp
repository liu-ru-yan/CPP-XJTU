#include<bits/stdc++.h>
using namespace std;
void swap(int a[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<i;j++){
			int t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
}

int main(){
	int a[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}

	}

	swap(a);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(j!=2){
				cout<<a[i][j]<<" ";
			}
			else{
				cout<<a[i][j]<<endl;
			}
		}
		
	}
	return 0;
}
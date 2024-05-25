#include<iostream>
using namespace std;
void exchange(int &x,int &y,int &z){
	int a[3];
	if(x<=y&&x<=z){
		a[0]=x;
		if(y<=z){
			a[1]=y;
			a[2]=z;
		}
		else{
			a[1]=z;
			a[2]=y;
		}
	}
	else if(y<=x&&y<=z){
		a[0]=y;
		if(x<=z){
			a[1]=x;
			a[2]=z;
		}
		else{
			a[1]=z;
			a[2]=x;
		}

	}
	else{
		a[0]=z;
		if(x<=y){
			a[1]=x;
			a[2]=y;

		}
		else{
			a[1]=y;
			a[2]=x;
		}
	}
	x=a[0];
	y=a[1];
	z=a[2];
}
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	exchange(x,y,z);
	cout<<x<<" "<<y<<" "<<z;
	return 0;
}
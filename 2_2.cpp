#include<bits/stdc++.h>
using namespace std;
class Rectangle{
	int position[4];
public:
	void init_rect(int x1,int y1,int x2,int y2){
		position[0]=x1;
		position[1]=y1;
		position[2]=x2;
		position[3]=y2;
	}
	void show_sumline(){
		int line=2*abs(position[0]-position[2])+2*abs(position[1]-position[3]);
		cout<<line<<endl;
	}
	void show_sumerea(){
		int erea=abs(position[0]-position[2])*abs(position[1]-position[3]);
		cout<<erea<<endl;
	}

	
};
int main(){
	Rectangle r;
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	r.init_rect(x1,y1,x2,y2);
	r.show_sumline();
	r.show_sumerea();
	return 0;
}
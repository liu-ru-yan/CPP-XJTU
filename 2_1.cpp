#include<bits/stdc++.h>
using namespace std;
struct Stu{
	char number[1<<8];
	char name[1<<8];
	double score;
	
};
int main(){
	int n;
	cin>>n;
	Stu s[n];
	double ans=0;
	for(int i=0;i<n;i++){
		cin>>s[i].number>>s[i].name>>s[i].score;
		ans=ans+s[i].score;
		cout<<s[i].number<<" "<<s[i].name<<" "<<s[i].score<<endl;
	}
	ans=ans/n;
	printf("%.2lf",ans);
	return 0;
}
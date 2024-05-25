#include<bits/stdc++.h>
using namespace std;
struct Stu{
	char number[1<<8];
	char name[1<<8];
	double score;
};
void max(struct Stu *p,int n){
	double m=p->score;
	Stu *pn=p;
	p++;
	for(int i=1;i<n;i++,p++){
		if(m<p->score){
			m=p->score;
			pn=p;
		}
		else{
			continue;
		}
	}
	cout<<pn->number<<" "<<pn->name<<" "<<pn->score<<endl;
}
int main(){
	int n;
	cin>>n;
	Stu s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].number>>s[i].name>>s[i].score;
	}
	max(s,n);
	return 0;
}
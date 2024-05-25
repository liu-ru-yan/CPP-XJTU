#include<bits/stdc++.h>
using namespace std;
class Person{
	char *idperson;
	char *name;
	char *sex;
	char *Birthday;
	char *homeadd;
public:
	void initperson(char *id,char *na,char *s,char *bir, char *ho){
		idperson=new char[1<<8];
		strcpy(idperson,id);
		name=new char[1<<8];
		strcpy(name,na);
		sex=new char[1<<8];
		strcpy(sex,s);
		Birthday=new char[1<<8];
		strcpy(Birthday,bir);
		homeadd=new char[1<<8];
		strcpy(homeadd,ho);
	}
	void show(){
		cout<<idperson<<" "<<name<<" "<<sex<<" "<<Birthday<<" "<<homeadd<<endl;
	}
};
int main(){
	char id1[1<<8],id2[1<<8];
	char na1[1<<8],na2[1<<8];
	char s1[10],s2[10];
	char Bir1[1<<8],Bir2[1<<8];
	char ho1[1<<8],ho2[1<<8];
	cin>>id1>>na1>>s1>>Bir1>>ho1>>id2>>na2>>s2>>Bir2>>ho2;
	Person p1,p2;
	p1.initperson(id1,na1,s1,Bir1,ho1);
	p2.initperson(id2,na2,s2,Bir2,ho2);
	p1.show();
	p2.show();
	return 0;
}
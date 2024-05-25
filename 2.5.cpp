#include<iostream>
#include<string.h>
using namespace std;
class Student{
private:
	char* name;
	float g1,g2;
public:
	Student(char* n,float gg1,float gg2){
		name=new char[strlen(n)+1];
		strcpy(name,n);
		g1=gg1;
		g2=gg2;
		cout<<"construct "<<this->name<<endl;
	}
	~Student(){
		cout<<"destruct "<<this->name<<endl;
		delete[] name;
	}
	Student(const Student&s){
		name=new char[4];
		strcpy(name,"liu");
		this->g1=s.g1-10.0;
		this->g2=s.g2-10.0;
		cout<<"copy "<<name<<endl;
	}	
	float get_g1(){
		return g1;
	}
	float get_g2(){
		return g2;
	}
	Student* const getaddress(){
		return this;
	}

};

int main(){
	Student a("li",90.0,80.0);
	Student *st=new Student[2]{Student("zhang",80.0,70.0),Student("wang",90.0,80.0)};
	float avg1=(st[0].get_g1()+st[0].get_g2())/2.0;
	float avg2=(st[1].get_g1()+st[1].get_g2())/2.0;
	cout<<avg1<<" "<<avg2<<endl;
	delete[] st;
	Student b(a);
	Student* const b_add=&b;
	Student* const b_add_inclass=b.getaddress();
	cout<<b_add-b_add_inclass<<endl;

	return 0;
}
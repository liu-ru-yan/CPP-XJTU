#include<iostream>
#include<cstring>
#include<typeinfo>

using namespace std;

class Base{
private:
    char* pname;
    int age;
public:
    Base(char* name,int age);
    ~Base();
    virtual void show();
};
Base::Base(char* name,int age){
    pname=new char[strlen(name)+1];
    strcpy(pname,name);
    this->age=age;
    cout<<"Base constructor"<<endl;
}
void Base::show(){
    cout<<pname<<" "<<age;
}
Base::~Base(){
    if(pname){
        delete[] pname;
    }
    cout<<"Base destructor"<<endl;
}
class Leader : virtual public Base{
private:
    char duty[10];
public:
    Leader(char* name,int age,char* duty);
    ~Leader();//
    void show();
};
Leader::Leader(char* name,int age,char* duty): Base(name,age){
    for(int i=0;i<strlen(duty)+1;i++){
        this->duty[i]=*(duty+i);
    }
    cout<<"Leader constructor"<<endl;
}
void Leader::show(){
    if(typeid(this)==typeid(Leader)){
        Base::show();
    }
    cout<<" "<<duty;
}
Leader::~Leader(){
    cout<<"Leader destructor"<<endl;
}

class Engineer : virtual public Base{
private:
    char major[10];
public:
    Engineer(char *name,int age,char* major);
    ~Engineer();
    void show();
};

Engineer::Engineer(char *name,int age,char* major):Base(name,age){
    for(int i=0;i<strlen(major)+1;i++){
        this->major[i]=*(major+i);
    } 
    cout<<"Engineer constructor"<<endl;
}
void Engineer::show(){
    if(typeid(this)==typeid(Engineer)){
        Base::show();
    }
    cout<<" "<<major;
}
Engineer::~Engineer(){
    cout<<"Engineer destructor"<<endl;
}
class Chairman : public Leader,public Engineer{
public:
    Chairman(char* name,char* duty,char* major,int age);
    void show();
    ~Chairman();

};
Chairman::Chairman(char* name,char* duty,char* major,int age):Base(name,age),Leader(name,age,duty),Engineer(name,age,major){
    cout<<"Chairman constructor"<<endl;
}
void Chairman::show(){
    Base::show();
    Leader::show();
    Engineer::show();
    cout<<endl;
}
Chairman::~Chairman(){
    cout<<"Chairman destructor"<<endl;
}




int main(){
    Chairman a("Li","chair","computer",20);
    a.show();

    return 0;
}

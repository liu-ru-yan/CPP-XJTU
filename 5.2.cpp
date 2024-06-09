#include <iostream>
#include<cstring>
using namespace std;

int L;

class Manage;
class A{
private:
    char* name;
public:
    virtual void show(){
        cout<<name<<endl;
    }
    A(const char* n){
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }
    virtual ~A(){
        cout<<"destructor A"<<endl;
        delete[] name;
    }
    virtual void print()=0;
};

class B:public A{
private:
    int age;

public:
    void print(){
        cout<<"B:";
        show();
        cout<<age<<endl;
    }
    B(const char* n,int a):A(n),age(a){}

    ~B(){
        cout<<"destructor B"<<endl;
    }
};

class C:public A{
private:
    char sex;
public:
    void print(){
        cout<<"C:";
        show();
        cout<<sex<<endl;
    }
    C(const char* n,char s): A(n),sex(s){}
    ~C(){
        cout<<"destructor C"<<endl;
    }
};


class manager{
private:
    A** array;
    int len;
public:
    manager(int x){
        array=new A*[x];
        L=x;
        len=0;
    }
    ~manager(){
        for(int i=0;i<L;i++){
            if(array[i]){
                delete array[i];
            }
        }
        delete[] array;
    }
    void add(int index,char* name,int param_b){
        len++;
        array[index]=new B(name,param_b);
    }
    void add(int index,char* name,char param_c){
        len++;
        array[index]=new C(name,param_c);
    }
    void display(){
        for(int i=0;i<L;i++){
            if(array[i]){
                array[i]->print();
            }
        }
    }
};

int main(){
    manager m(4);
    m.add(0,"zhang",18);
    
    m.add(1,"wang",'F');
    m.add(3,"liu",'M');
    m.display();
    return 0;


}

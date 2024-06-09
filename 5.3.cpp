#include<iostream>
using namespace std;

class A{
private:
    int a;
public:
    A(int x=0){
        a=x;
    }
    virtual A& operator+(int x){
        a=a+x;
        return *this;
    }
    virtual void show(){
        cout<<"a="<<a<<endl;
    }
};
class B:virtual public A{
private:
    int b;
public:
    B(int x,int y):A(x),b(y){}
    B& operator+(int x){
        b=b+x;
        return *this;
    }
    void show(){
        A::show();
        cout<<"b="<<b<<endl;
    }

};
void add(A& AB,int x){
    AB=AB+x;
}

int main(){

    A myA,*p;
    B myB(2,3);
    add(myA,3);p=&myA;p->show();
    add(myB,3);p=&myB;p->show();
}
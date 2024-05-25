#include<iostream>
using namespace std;

class Base{
private:
    int x;
public:
    Base(int x);
    void show();
};
Base::Base(int x){
    this->x=x;
}
void Base::show(){
    cout<<"x="<<this->x<<endl;
}


class derived : public Base{
private:
    int y;
public:
    derived(int x,int y);
    void show(){
        Base::show();
        cout<<"y="<<this->y<<endl;
    }


};
derived::derived(int x,int y):Base(x){
    this->y=y;
}

void func1(Base &obj){
    obj.show();
}
void func2(derived &obj){
    obj.show();
}


int main(){
    derived a(10,20);
    a.show();
    Base* p_base_a=&a;
    derived* p_derived_a=&a;
    p_base_a->show();
    p_derived_a->show();
    func1(a);
    func2(a);


    return 0;
}

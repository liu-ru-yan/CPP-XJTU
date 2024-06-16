#include<iostream>
#include<cstring>
using namespace std;
/*定义A类，A类内部有：
    静态成员变量num_Aclass（代表已经创建的A类对象的个数）,
    构造函数A(double value1,float value2_1,float value2_2,int value3,char* name);
    析构函数~A();
    静态成员函数：void set_num_Aclass(int num)；
    静态成员函数：void set_new()；
    成员函数：void set_data_double(double num)；

    同时在A内部声明友元函数show(A &a);

*/
class A{
private:
    static int num_Aclass;
    double* data_double=NULL;
    float* data_float=NULL;
    int data_int=NULL;
    char* pname=NULL;
    int& reference=num_Aclass;
public:
    friend void show(A &a);
    A(double value1,float value2_1,float value2_2,int value3,char* name);
    ~A();
    static void set_num_Aclass(int num){
        num_Aclass=num;
    }
    static void set_new(){
        num_Aclass++;
    }
    void set_data_double(double num){
	*(data_double)=num;
    }

};
int A::num_Aclass=0;//先给静态成员赋值；
//定义A的构造函数；
A::A(double value1,float value2_1,float value2_2,int value3,char* name){
    data_double=new double(value1);
    data_float=new float[2]{value2_1,value2_2};
    data_int=value3;
    pname=new char[strlen(name)+1];
    strcpy(pname,name);
    set_new();
}
//定义A的析构函数；
A::~A(){
    if(data_double){
        delete data_double;
    }
    if(data_float){
        delete [] data_float;
    }
    if(pname){
        delete pname;
    }

}
//外部函数show，用来展示地址
//输出格式为：
/*
num_Aclass,num_Aclass的引用，a.data_double，a.data_float的指向的数据，a.data_int的值，a.pname的指向的数据
num_Aclass的地址,num_Aclass的引用的地址，a.data_double，a.data_float的指针值，a.data_int的的地址,a.pname的指针值
对象所占存储空间的大小
静态成员函数的地址
非静态成员函数的地址

*/
void show(A &a){
    cout<<"values:"<<endl;
    cout<<a.num_Aclass<<" "<<a.reference<<" "<<*(a.data_double)<<" "<<a.data_float[0]<<" "<<a.data_float[1]<<" "<<a.data_int<<" ";
    if(a.pname){
	    cout<<a.pname;
    }
    cout<<endl;
    cout<<"addresses:"<<endl;
    cout<<&a.num_Aclass<<" "<<&a.reference<<" "<<a.data_double<<" "<<&a.data_float[0]<<" "<<&a.data_float[1]<<" "<<&a.data_int<<" ";
    if(a.pname){
	cout<<(void*)a.pname;
    }
    cout<<endl;
    cout<<sizeof(a)<<endl;
    cout<<endl;
    cout<<"addresses of static_functions:"<<endl;
    void(*set_num_Aclass)()=set_num_Aclass;
    cout<<&set_num_Aclass<<endl;
    void(*set_new)()=set_new;
    cout<<&set_new<<endl;
    cout<<"addresses of member_functions:"<<endl;
    void(*set_data_double)()=set_data_double;
    cout<<&set_data_double<<endl;
    
}



void func(){
    //在外部函数中创建的局部对象
    A funcjubu1(5.0,5.1,5.2,5,"funcjubu1");
    cout<<"address of funcjubu1: "<<&funcjubu1<<endl;
    show(funcjubu1);
    A funcjubu2(6.0,6.1,6.2,6,"funcjubu2");
    cout<<"address of funcjubu2: "<<&funcjubu2<<endl;
    show(funcjubu2);
}

//定义全局对象
A quanju1(1.0,1.1,1.2,1,"quanju1");
A quanju2(2.0,2.1,2.2,2,"quanju2");
int main(){
    cout<<"address of quanju1: "<<&quanju1<<endl;
    show(quanju1);
    cout<<"address of quanju2: "<<&quanju2<<endl;
    show(quanju2);
    func();
    //定义main函数中的局部对象
    A jubu1(3.0,3.1,3.2,3,"jubu1");
    A jubu2(4.0,4.1,4.2,4,"jubu2");
    cout<<"address of jubu1: "<<&jubu1<<endl;
    show(jubu1);
    cout<<"address of jubu2: "<<&jubu2<<endl;
    show(jubu2);
    //main函数中的动态创建对象
    A* dongtai=new A[2]{A(7.0,7.1,7.2,7,"dongtai[0]"),A(8.0,8.1,8.2,8,"dongtai[1]")};
    cout<<"address of dongtai[0]: "<<&dongtai[0]<<endl;
    show(dongtai[0]);
    cout<<"address of dongtai[1]: "<<&dongtai[1]<<endl;
    show(dongtai[1]);
    A* dongtai2=new A[2]{A(9.0,9.1,9.2,9,"dongtai2[0]"),A(10.0,10.1,10.2,10,"dongtai2[1]")};
    cout<<"address of dongtai2[0]: "<<&dongtai2[0]<<endl;
    show(dongtai2[0]);
    cout<<"address of dongtai2[1]: "<<&dongtai2[1]<<endl;
    show(dongtai2[1]);
    cout<<"addresses of func:"<<endl;
    void(*show)()=show;
    cout<<&show<<endl;
    cout<<"addresses of main:"<<endl;
    int(*main)()=main;
    cout<<&main<<endl;
    return 0;
}

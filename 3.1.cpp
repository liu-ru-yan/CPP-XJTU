#include<iostream>
using namespace std;
class Student;
class Teacher;
class Teacher{
private:
    Student* pStu;
public:
    Teacher(int size);
    void assign(int index,int ps2,int qm2);
    void show(int index);
};
class Student{
private:
    int ps,qm;
    static float bl;
public:
    friend void Teacher::assign(int index,int ps2,int qm2);
    friend void Teacher::show(int index);
    static void setProp(float bl1){
        bl=bl1;
    }
    float comScore(){
        float ans,ps1,qm1;
        ps1=(float)ps;
        qm1=(float)qm;
        ans=ps1*bl+(1-bl)*qm1;
        return ans;
    }
};
Teacher::Teacher(int size){
    pStu=new Student[size];
}
void Teacher::assign(int index,int ps2,int qm2){
    pStu[index].ps=ps2;
    pStu[index].qm=qm2;
}
void Teacher::show(int index){
    float ans=pStu[index].comScore();
    cout<<ans;
}
float Student::bl=0.5;
int main(){
    float bl;cin>>bl;
    Student::setProp(bl);
    int size;cin>>size;
    Teacher t(size);
    for(int i=0;i<size;i++){
        int ps,qm;cin>>ps>>qm;
        t.assign(i,ps,qm);
    }
    for(int i=0;i<size;i++){
        t.show(i);
        if(i!=size-1){
            cout<<" ";
        }
    }
    return 0;

}


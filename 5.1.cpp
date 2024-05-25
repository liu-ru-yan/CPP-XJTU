#include<iostream>
#include<cstring>
using namespace std;

class String{
private:
    char* array;

public:
    String(const char* p){
        array=new char[strlen(p)+1];
        strcpy(array,p);
    }
    ~String(){
        delete[] array;
    }

    friend ostream& operator<<(ostream& os,const String& s){
        os<<s.array;
        return os;
    }

    char& operator[](int index){
        if(index>=0&&index<strlen(array)){
            return array[index];
        } 
        else {
            cout<<"Index out of range."<<endl;
            static char o='\0'; 
            return o;
        }
    }

    String& operator+(const String& s){
        char* temp;
        temp=new char[strlen(array)+strlen(s.array)+1];
        strcpy(temp,array);
        strcat(temp,s.array);
        delete[] array;
        array=temp;
        return *this;
    }
    String operator+(const char* p){
        char* newStr=new char[strlen(array)+strlen(p)+1];
        strcpy(newStr,array);
        strcat(newStr,p);
        String temp(newStr);
        delete [] newStr;
        return temp;
    }

    operator int(){
        return strlen(array);
    }
};

int main(){
    String string1("mystring"),string2("yourstring"),string3("herstring");
    cout<<string1<<endl;
    string1[7]='n';
    cout<<string1<<endl;
    string1[8]='n';
    cout<<string1+string2+string3<<endl;
    cout<<string1<<endl;
    cout<<string2+"ab"<<endl;
    cout<<string2<<endl;
    cout<<string3+3<<endl;
    cout<<string3<<endl;
    return 0;
}
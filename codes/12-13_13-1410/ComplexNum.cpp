#include<iostream>
#include<cstring>
using namespace std;

class ComplexNum {
private:
    int rp,ip;

public:
    ComplexNum(){
        ip=0;rp=0;
    }
    void set_rp(int a){
        rp=a;
    }
    void set_ip(int a){
        ip=a;
    }
    int get_rp(){
        return rp;
    }
    int get_ip(){
        return ip;
    }
    void Print(){
        cout<<rp;
        if (ip>=0) cout<<'+';
        cout<<ip<<'i'<<endl;
    }
    void Print(ostream &os){
        os<<rp;
        if (ip>=0) os<<'+';
        os<<ip<<'i'<<endl;
    }
    ComplexNum Add(ComplexNum c1, ComplexNum c2){
        ComplexNum temp;
        temp.rp=c1.rp+c2.rp;
        temp.ip=c1.ip+c2.ip;
        return temp;
    }
    void Add(ComplexNum c){
        rp=rp+c.rp;
        ip=ip+c.ip;
    }
    ComplexNum operator+(ComplexNum c){
        ComplexNum temp;
        temp.rp=rp+c.rp;
        temp.ip=ip+c.ip;
        return temp;
    }
    friend ostream &operator<<(ostream &os, ComplexNum &c);
    friend istream &operator>>(istream &is, ComplexNum &c);
};

ostream &operator<<(ostream &os, ComplexNum &c){
    ///c.Print(os);
        os<<"My out:"<<c.rp;
        if (c.ip>=0) os<<'+';
        os<<c.ip<<'i'<<endl;

    ///return os;
}

istream &operator>>(istream &is, ComplexNum &c){

    is>>c.rp>>c.ip;
    ///return is;
}

int main(){
    ComplexNum c1,c2;
    /*c1.rp=1;
    c1.ip=2;
    c2.rp=3;
    c2.ip=4;*/
    c1.set_rp(1);
    c1.set_ip(2);
    c2.set_rp(3);
    c2.set_ip(-4);
    c1.Print();
    c2.Print();
    ComplexNum cs;
    cs=c1.Add(c1,c2);
    cs.Print();
    c1.Add(c2);
    c1.Print();
    cs=c1+c2;
    cs.Print();
    cout<<"cout working:"<<endl;
    cin>>cs>>c1;
    cout<<cs<<c1;
}

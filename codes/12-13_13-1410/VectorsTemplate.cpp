#include<iostream>
using namespace std;

template <class myclass>
class Vector{
private:
    myclass * arr;
    int count;
    int size;
public:
    Vector (int s=4){
        count=0;
        size=s;
        arr= new myclass[size];
    }
    ~Vector (){
        delete [] arr;
    }
    void push(myclass n){
        if (count==size){
            ///resize the array
            cout<<"resize the array"<<endl;
            size*=2;
            myclass * temp=arr;
            arr= new myclass [size];
            for (int i=0;i<count;i++) arr[i]=temp[i];
            delete [] temp;temp=NULL;
        }
        arr[count++]=n;
    }
    void Print(){
        for (int i=0;i<count;i++) cout<<arr[i]<<" "; cout<<endl;
    }
    myclass top (){
        ///if (count==0) return -1;
        return arr[count-1];
    }
    void pop(){
        count--;
        ///check if count<=size/4 then half the array
    }
    myclass ValueAt(int ind){
        ///if (ind>=count) return -1;
        return arr[ind];
    }
    myclass &operator[](int ind){
        ///if (ind>=count) return -1;
        return arr[ind];
    }
    template <class myclass1>
    friend ostream &operator<<(ostream &os, Vector<myclass1> &V);
};

template <class myclass>
ostream &operator<<(ostream &os, Vector<myclass> &V){
    for (int i=0;i<V.count;i++) os<<V.arr[i]<<" "; os<<endl;
    return os;
}

int main(){
    Vector<int> V(3), V1;
    V.push(1);
    V.push(2);
    V.push(3);
    V.push(4);
    V.Print();
    cout<<V;
    cout<<V.top();
    V.pop();
    V.push(5);
    cout<<V;
    cout<<V.ValueAt(2)<<endl;
    V[1]=7;
    cout<<V[1]<<endl;
    Vector<char> vch(3);
    vch.push('a');
    vch.push('b');
    vch.push('c');
    vch.push('d');
    cout<<vch;
    vch.pop();
    vch.push('e');
    cout<<vch;
}

#include<iostream>
using namespace std;

int main(){
    char arr[4]={'A','A','A','A'};
    int *p=(int*)arr;
    cout<<*p<<endl;
    *p=1094927169;

    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;

    int a=1094927169;
    char* chp=(char*)&a;
    cout<<chp[1]<<endl;
   cout<<chp[0]<<endl;

    /*cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<(int*)&arr[1]<<endl;
    char *p=arr;

    cout<<&p<<endl;*/
}

/*int main(){


    int arr[10]={10,20,30,40,50,60,70,80,90,100};

    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;
    int *p=arr, *q;
    cout<<&p<<endl;
    cout<<&p[0]<<endl;
    cout<<arr<<endl;
    return 0;
    cout<<arr<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*arr<<endl;
    cout<<p[5]<<endl;
    cout<<*p+1<<endl;
    cout<<*(p+5)<<endl;

    cout<<sizeof(p)<<endl;
    int b=1000;
    p=&b;
    cout<<*p<<endl;

    /*int a=10;
    int * b=&a;
    int &c=a;

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<*b<<endl;
    *b=20;
    cout<<a<<endl;

    char ch='a';
    char *chp=&ch;
    cout<<*chp<<endl;
    cout<<chp<<endl;

}*/

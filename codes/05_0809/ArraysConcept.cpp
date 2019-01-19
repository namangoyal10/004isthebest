#include<iostream>
using namespace std;

int main(){
    int n;///cin>>n;
    int arr[10]={1,2,3};

    for (int i=0;i<10;i++) cout<<arr[i]<<" ";
    cout<<endl;

    ///arr={1,2,3,4,5,6,7,8,9,0};

    char charr[100];

    for (int i=0;i<26;i++){
        charr[i]='A'+i;
    }
    for (int i=0;i<26;i++) cout<<charr[i]<<" ";
    cout<<endl;

    char ch1[5]={'a','e','i','o','u'};
    for (int i=0;i<5;i++) cout<<(int)ch1[i]<<" ";
    cout<<endl;

    cout<<arr<<endl;
    cout<<charr<<endl;
    cout<<ch1<<endl;

    char ch2[10]="Rajesh";
    cout<<ch2<<endl;
    for (int i=0;i<10;i++) cout<<(int)ch2[i]<<" ";
    cout<<endl;

    cout<<'\n';

    ///char ch='\'';

}

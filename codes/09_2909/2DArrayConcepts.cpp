#include<iostream>
using namespace std;

int main()
{
    int arr[3][4]= {{1,2,3,10},
        {4,5,6,11},
        {1,8,9,12}};

    cout<<arr<<endl;
    int *ptr=(int*)arr;
    cout<<ptr[10]<<endl;
    cout<<arr[0][1]<<endl;
    cout<<**(arr+1)<<endl;
    return 0;
    cout<<*arr<<endl;
    int**p2=(int**)arr;
}

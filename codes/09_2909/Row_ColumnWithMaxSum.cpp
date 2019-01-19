#include<iostream>
using namespace std;

void RowColMaxSum(int arr[][4],int m, int n)
{
    int maxsofar=0;
    char ansch;
    int ansindex;
    ///for each row find the sum and check if sum>maxsofat then i found new max
    for (int r=0; r<m; r++)
    {
        int sum=0;
        for(int c=0; c<n; c++)
        {
            sum+=arr[r][c];
        }
        if (sum>maxsofar)
        {
            ///for new max, we will store Row/Col & index;
            ansch='R';
            ansindex=r;
            maxsofar=sum;
        }
    }

    ///for each col find the sum and check if sum>maxsofar.....
    for (int c=0; c<n; c++)
    {
        int sum=0;
        for(int r=0; r<m; r++)
        {
            sum+=arr[r][c];
        }
        if (sum>maxsofar)
        {
            ///for new max, we will store Row/Col & index;
            ansch='C';
            ansindex=c;
            maxsofar=sum;

        }
    }cout<<ansch<<ansindex;
}
    int main()
    {
        int arr[3][4]= {{1,2,3,10},
            {4,5,6,11},
            {1,8,9,12}
        };

        RowColMaxSum (arr,3,4);
    }

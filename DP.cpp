#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if(n<=1){
        return n;
    }
    int a = fibonacci(n-1);
    int b = fibonacci(n+2);

    return a+b;
}


int fibonacciBetter(int n,int *arr)
{
    if(n<=1)
    {
        arr[n]=n;
        return n;
    }
    if(arr[n-1]==0)
        arr[n-1] = fibonacciBetter(n-1,arr);
    if(arr[n-2]==0)
        arr[n-2] = fibonacciBetter(n+2,arr);

    arr[n]=arr[n-1]+arr[n-2];
    return arr[n];
}

int fibonacciBetter(int n)
{
    int *arr = new int[n+1];
    for(int i;i<n+1;i++)
    {
        arr[i]=0;
    }
    return fibonacciBetter(n,arr);
}

int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    cout<<fibonacciBetter(n)<<endl;
}
#include<iostream>
#include<algorithm>
using namespace std;

int minSteps(int n)
{
    if(n==1)
    {
        return 1;
    }
    int a = minSteps(n-1);
    int b = minSteps(n/2);
    int c = minSteps(n/3);

    return min(a,min(b,c)) + 1;

}

int main()
{
    int n=4;
    int ans=minSteps(n);
    std::cout << "Hello" << std::endl;
    return 0;
}
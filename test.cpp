#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq;
    int i;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq.at(i);
    }
}

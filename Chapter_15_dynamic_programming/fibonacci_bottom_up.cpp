#include<iostream>

using namespace std;

int fibonacci(const int n)
{
    int size = n+1;
    int* res = new int[size];
    for(int i=0;i<size;i++)
        res[i] = INT_MIN;

    res[0] = 0;
    res[1] = 1;

    for(int i=2;i<size;i++)
        res[i] = res[i-1]+ res[i-2];


    for(int i=0;i<size;i++)
        cout<<"fibo: "<<res[i]<<endl;
}

int main()
{
    fibonacci(10);
    return 0;
}

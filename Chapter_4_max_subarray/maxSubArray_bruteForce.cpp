#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using std::endl;
using std::cout;

int max(int& a,int& b)  { return (a>b?a:b); }

int maxSubArray(int* start, int size);
int sum(const int*, const int*);

int main(int argc, char *argv[])
{
    const int arraySize = 8;
    int array[arraySize];
    srand(time(0));
    for(auto i=0;i<arraySize;i++)
      {
        int prefix = 0;
        if(i%2)
            prefix = 1;
        else prefix=-1;
        array[i] = prefix*(rand()%10);
      }

    for(auto i=0;i<arraySize;i++)
        cout<<i<<"te element: "<<array[i]<<endl;

    cout<<"max sub array: "<<maxSubArray(array,arraySize);

}

int maxSubArray(int* start, int size)
{
    int tmp = *start;
    for(int* i = start;i < start+size;i++)
    {
        for(int* j = i;j<start+size;j++ )
        {
            if(sum(i,j)>tmp)
                tmp = sum(i,j);
        }
    }
    return tmp;
}
int sum(const int *a, const int *b)
{
    int tmp = 0;
    while(a<=b)
    {
        tmp += *a;
        a++;
    }
    return tmp;
}





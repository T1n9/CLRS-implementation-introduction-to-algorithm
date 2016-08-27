#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using std::endl;
using std::cout;

int maxSubArray(int* start, int size);

int main(int argc, char *argv[])
{
    const int arraySize = 10;
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
int maxSubArray(int *start, int size)
{
    int tmp = 0;
    int sum = start[0];
    for(size_t i=0;i<size;i++)
    {
        tmp += start[i];
        if(sum < tmp)   sum = tmp;
        if(tmp<0)       tmp = 0;
    }
    return sum;

}






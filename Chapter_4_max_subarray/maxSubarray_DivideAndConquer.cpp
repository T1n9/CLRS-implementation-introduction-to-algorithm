#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using std::endl;
using std::cout;

int sumBackward(int*,int*);
int sumForward(int*,int*);
int maxCrossArray(int*start, int aSize);
int maxSubArray(int* start, int aSize);
int max(const int&,const int&,const int&);

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


    cout<<"max cross array:"<<maxCrossArray(array,arraySize)<<endl;
    cout<<"max subarray: "<<maxSubArray(array,arraySize);

}
int maxSubArray(int *start, int aSize)
{
    if(aSize==2)
        return max(*start,*(start+1), *start + *(start+1));

    int leftSubArray = maxSubArray(start, aSize/2);
    int rightSubArray = maxSubArray(start+ aSize/2, aSize/2);

    int crossArray = maxCrossArray(start,aSize);

    return max(leftSubArray,rightSubArray,crossArray);
}
int max(const int& left,const  int& right,const int& cross)
{
    int tmp = (left>right?left:right);
    return (tmp>cross?tmp:cross);
}

int maxCrossArray(int* start, int aSize)
{
    size_t mid = aSize/2-1;
    int maxBefore = *(start+mid);
    int maxAfter = *(start+mid+1);
    for(auto i = start+mid; i>=start; i--)
    {
        if(maxBefore < sumBackward(start+mid,i))
         maxBefore = sumBackward(start+mid,i);
    }
        for(auto i= start+mid+1;i<start+aSize;i++)
        {
         if(maxAfter < sumForward(start+mid+1, i))
            maxAfter = sumForward(start+mid+1,i);
        }
    return maxBefore+maxAfter;
}

int sumBackward (int* start, int* end)
{
    int tmp = *start;

    while(start>end)
    {
        start--;
        tmp += *start;
    }
    return tmp;
}
int sumForward(int *start, int *end)
{
    int tmp = *start;
    while(start<end)
    {
        start++;
        tmp += *start;
    }
    return tmp;
}

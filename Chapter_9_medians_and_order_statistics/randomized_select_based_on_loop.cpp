#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define DEBUG

using std::cout;
using std::endl;
typedef std::vector<int> vInt;

#ifdef DEBUG
#define msg(fmt, args...)    puts(fmt ## args)
#else
#define msg(fmt, args...)
#endif

vInt uniqArray()
{
    srand(time(0));
    int size;
    vInt tmp;
    cout<<"enter the size of the array"<<endl;
    std::cin>>size;
    for(auto i=0;i<size;i++)
    {
        int randValue = 0;
        while((std::find(tmp.begin(),tmp.end(), randValue = rand()%(size*3)))!=tmp.end())
            ;
         tmp.push_back(randValue);
    }
    return tmp;
}
void display(const vInt& array)
{
    for(const auto& i: array)
        cout<<i<<" , ";
    cout<<endl;
}
int randomizedPartition(vInt& array, int begin, int end)
{
    int pick = 0;
    while((pick <begin)||(pick > end))
    {
        pick = rand()%array.size();
    }
    return pick;
}
void exchange(vInt& array, int pos1, int pos2)
{
    int tmp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = tmp;
}
void findPos(vInt& array, int& frontIter, int& backIter, int currentPos)
{
    int pos = randomizedPartition(array,frontIter,backIter);
    int end = backIter;
    exchange(array,pos,backIter);
    int pivot = array.at(backIter);
    --backIter;

    while(frontIter <=backIter)
    {

        if(array.at(frontIter)>=pivot)
        {
            exchange(array,frontIter,backIter);
            --backIter;
        }
        else
            ++frontIter;
    }
    exchange(array,frontIter,end);
#ifdef DEBUG
     cout<<"pivot:"<<pivot<<endl;
    //cout<<"frontIter:"<<frontIter<<endl;
    //cout<<"backiter:"<<backIter<<endl;
    display(array);
#endif



}

vInt whichSmallest( vInt& array,int aim)
{
    --aim;
    int backIter = array.size()-1;
    int frontIter=0;
    int currentPos = 0;
         while(currentPos!=aim)
        {
             cout<<"f iter:"<<frontIter<<endl<<"b iter:"<<backIter<<endl;

             int begin = frontIter;
             int end = backIter;


             findPos(array,frontIter,backIter,currentPos);
             currentPos = frontIter+1;

             if(currentPos>aim)
             {
             msg("goes left");
             backIter = frontIter - 1;
             frontIter = begin;
             }
             else if(currentPos<aim)
             {
              msg("goes right");
               frontIter = frontIter +1;
               backIter = end;
             }
             else
             {
                 display(array);
                 cout<<"found"<<endl;
                 cout<<"the "<<aim+1<<"th smallest number:"<<array.at(currentPos)<<endl;
             }


       }

}


int main()
{
    vInt array = uniqArray();
    display(array);
    whichSmallest(array,5);
    display(array);

}


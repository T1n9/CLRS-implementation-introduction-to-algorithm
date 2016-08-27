#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define noDebug

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

void exchange(vInt& array, const int& a, const int& b)
{
    int tmp = array.at(a);
    array[a] = array[b];
    array[b] = tmp;
}
int medianByInsertSort(vInt& array,const int& start,const int& end)
{
    for(int i= start+1;i<=end;i++)
    {
        int tmpIter = i;
        for(int j=i-1;j>=start;j--)
        {
            if(array.at(j)>array.at(tmpIter))
            {
                exchange(array,tmpIter,j);
                --tmpIter;
            }
            else break;
        }
    }
    int size = end-start+1;
    if((size==1)||(size==2))
        return array.at(start);
    else if((size==3)||(size==4))
        return array.at(start+1);
    else
        return array.at(start+2);
}

vInt createMedians( vInt& array)
{
    vInt medians;
    for(int i=0;i<array.size();i+=5)
    {
        int end=(i+4 <= array.size()-1)?(i+4):(array.size()-1);
        int median = medianByInsertSort(array,i,end);
#ifdef DEBUG
        cout<<"median:"<<median<<endl;
#endif
        medians.push_back(median);
    }
    return medians;
}

//this recursion is ugly, I think with loop is in most cases
int linearSelectWorstCase(vInt& array)
{
    vInt medians;
    static int res=0;

    if(array.size()<=5)
        res = medianByInsertSort(array,0,array.size()-1);
    else
    {
        vInt medians = createMedians(array);
        linearSelectWorstCase(medians);
    }
    return res;
}

void findPos(vInt& array, int& frontIter, int& backIter, int currentPos)
{
    vInt& copy = array;
    int median = linearSelectWorstCase(copy);
    int pos = 0;
    for(int i=0;i<array.size();i++)
       if(array.at(i) == median)
           pos = i;

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
#ifdef DEBUG
             cout<<"f iter:"<<frontIter<<endl<<"b iter:"<<backIter<<endl;
#endif
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
                 cout<<"showing the result array:"<<endl;
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
    whichSmallest(array,3);


}


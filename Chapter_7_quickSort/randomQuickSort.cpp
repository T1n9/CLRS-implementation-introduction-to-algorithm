
#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cstdio>
#include<algorithm>

using std::cout;
using std::endl;
typedef std::vector<int> vInt;

vInt createArray()
{
    srand(time(0));
    int size;
    vInt tmp;
    cout<<"enter the size of the array"<<endl;
    std::cin>>size;
    for(auto i=0;i<size;i++)
    {
        int randValue = rand()%(size*3);
        while(std::find(tmp.begin(),tmp.end(),randValue) !=tmp.end())
            randValue = rand()%(size*3);
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
void exchange(vInt& array,int a,int b)
{
    int tmp = 0;
    tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}
void toBack(vInt& array,int a,int b)
{
    array.insert(array.begin()+b+1,array[a]);
    array.erase(array.begin()+a);
}

void qSort(vInt& array,int start, int end)
{
    int pivotNo = start + rand()%(end-start);//this two lines are the mark that make this a random sort
    toBack(array,pivotNo,end);

    int pivot = array[end];

    int i = start;
    int iter =0;
    while(iter< end-start)
    {
        if(pivot<=array[i])
        {
            toBack(array,i,end);
              --i;
        }
         ++i;
        ++iter;
    }

     int halfEnd = --i;
    int halfStart = ++i;

    if((halfEnd-start)>1)
    qSort(array,start,halfEnd);
    if((end-halfStart)>1)
    qSort(array,halfStart,end);

}

int main()
{
    vInt array = createArray();
    display(array);
    qSort(array,0,array.size()-1);
    display(array);

}


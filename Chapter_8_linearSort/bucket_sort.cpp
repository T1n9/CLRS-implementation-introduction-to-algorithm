
#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<cmath>

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
        int randValue = rand()%(size*10);
       // while((randValue = rand()%(size*1000))>999)
         //  ;
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
void insertSort(vInt & array)
{

}

vInt bucketSort( vInt& array)
{
    auto maxIter = std::max_element(array.begin(),array.end());
    int maxElement = *maxIter;

    vInt buckets[10];
    for(const auto & j:array)
    {
        int iter = static_cast<int>(j/(static_cast<float>(maxElement+1)/10));
        buckets[iter].push_back(j);
        sort(buckets[iter].begin(),buckets[iter].end());
    }

    cout<<"the elements in buckets are:"<<endl;
    for(const auto & a:buckets)
    {
        if(a.size()>0)
        display(a);
    }
    cout<<endl;
    vInt out;
    out.reserve(10*buckets[0].size());
    for(auto i=0;i<10;i++)
        out.insert(out.end(),buckets[i].begin(),buckets[i].end());
    return out;
}


int main()
{
    vInt array = createArray();
     display(array);
    vInt res = bucketSort(array);
    display(res);

}


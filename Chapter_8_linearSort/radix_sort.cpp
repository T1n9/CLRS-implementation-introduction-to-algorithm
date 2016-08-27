
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
        int randValue;
        while((randValue = rand()%(size*1000))>999)
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

void exchange(vInt& array, int a,int b)
{
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}
int getPosValue(const int& a, int pos)
{
    if(pos==1)
        return a%10;
    else
        return a%static_cast<int>((pow(10,pos)))/static_cast<int>(pow(10,pos-1));
}

vInt radixSort( vInt& array)
{
    for(auto m=1;m<4;m++)
    {
#ifdef DEBUG
        cout<<endl<<"new pos"<<endl;
#endif
        for(auto i=1;i<array.size();i++)
        {
            for(auto j=i-1;j>=0;j--)
            {
#ifdef DEBUG
                cout<<"pos value:"<<getPosValue(array[i],m)<<" and "<<getPosValue(array[j],m)<<endl;
#endif
                if(getPosValue(array[i],m) < getPosValue(array[j],m))
                {
#ifdef DEBUG
                    cout<<"execute exchange"<<endl;
#endif
                    exchange(array,i,j);
                    i = j;
                 }
                else
                {
#ifdef DEBUG
                    cout<<"break"<<endl;
#endif
                    break;
                }
            }
        }
     }
    return array;
}


int main()
{
    vInt array = createArray();
     display(array);
    vInt res = radixSort(array);
    display(res);

}


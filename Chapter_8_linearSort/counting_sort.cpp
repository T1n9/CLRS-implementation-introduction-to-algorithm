
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
        int randValue = rand()%(size*2);
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


vInt linearSort( vInt& array)
{
    auto max = std::max_element(std::begin(array),std::end(array));
    int sizeMax = *max;
    vInt counter(sizeMax+1,0);
    for(const auto & i: array)
        ++counter[i];
     for(auto i=1;i<counter.size();i++)
        counter[i] += counter[i-1];
#ifdef DEBUG
    display(counter);
#endif
    vInt out(array.size()+1,0);

    while(array.size()>0)
    {
#ifdef DEBUG
        cout<<"to push:"<<array.back()<<" on pos:"<<counter[array.back()]<<endl;
#endif
        out[counter[array.back()]] = array.back();
        --counter[array.back()];
        array.pop_back();
#ifdef DEBUG
        cout<<"in output stream:";
        for(auto & i: out)
            cout<<i<<",";
        cout<<endl;
#endif
    }
    out.erase(out.begin());

    return out;
}

int main()
{
    vInt array = createArray();
     display(array);
    vInt res = linearSort(array);
    display(res);

}


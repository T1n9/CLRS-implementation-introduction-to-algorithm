#include"pQueue.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
using std::endl;
using std::cout;

int main(int argc, char *argv[])
{
    srand(time(0));
    int size = 15;
    pQueue pQ;
    for(auto i=0;i<size;i++)
        pQ.insert(rand()%size);
    pQ.display();
    cout<<"max in this queue:"<<pQ.max()<<endl;
    pQ.extractMax();
    pQ.display();
    pQ.increaseKey(10,100);
    pQ.display();


 }


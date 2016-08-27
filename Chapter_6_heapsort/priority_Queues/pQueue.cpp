#include<pQueue.h>
#include<cmath>
#include<iostream>

using std::cout;
using std::endl;
typedef unsigned int uint;

pQueue::pQueue()
{}
pQueue::~pQueue()
{
 }
void pQueue::insert(const int &value)
{
    queues.push_back(value);
    maxHeapify();
}
void pQueue::display()
{
    int tmp = queues.size()+2;
   double lines = log(tmp)/log(2);
   if(static_cast<int>(lines)!=lines)
       ++lines;
   double spaces = pow(2,lines);
   bool newLine = true;

   for(auto i=0;i<queues.size();i++)
   {
       if(newLine)
       {
           for(auto j=0;j<spaces/2 - i;j++)
               cout<<" ";
       }
       newLine = false;
       cout<<queues[i]<<"_";
       int tmp = i+2;
       double lineEnd = log(tmp)/log(2);
       if((static_cast<int>(lineEnd)-lineEnd)==0)
       {
           cout<<endl;
           newLine = true;
       }
   }
   cout<<endl;
}
void pQueue::maxHeapify()
{

        uint size = queues.size();
        for(int start = size/2;start>=0;start--)
        {
             int count = start;

            while(count<=size)
            {
                  int bigger = 0;
                int toReplace = 0;
                 if(count*2 <= size)
                {
                    bigger = queues[count*2-1];
                    toReplace = count*2;

                 }
                    else break;
                if(count*2+1 <= size)
                {

                    if(queues[count*2]>bigger)
                    {
                        bigger = queues[count*2];
                         toReplace = count*2 +1;
                     }
                }
                if(bigger > queues[count-1])
                {
                    swap(count,toReplace);

                    count = toReplace;
                }
                else
                    break;



            }
        }



}
void pQueue::swap(const int& a, const int& b)
{
    int tmp = 0;
    tmp = queues[b-1];
    queues[b-1] = queues[a-1];
    queues[a-1] = tmp;
}

int pQueue::max()
{
    return queues.front();
}
void pQueue::extractMax()
{
    queues[0] = queues.back();
    queues.pop_back();
    maxHeapify();
}
void pQueue::increaseKey(const int &pos, const int &value)
{
    if(pos>queues.size())
    {
        cout<<"error, the pos you entered is bigger than the array size";
        return;
    }
    if(value < queues[pos])
    {
        cout<<"the new value is not bigger than the old one";
        return;
    }
    queues[pos] = value;
    maxHeapify();
}

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<cstdio>

using std::cout;
using std::cin;
using std::endl;
typedef std::vector<int> vec;
using uint = unsigned int;

vec createHeap();
void displayHeap(const vec& heap);
void maxHeapify(vec& heap);
int findMax(const int& a,const int& b)
{
    return a>b?a:b;
}
void swap(vec &heap, const int&a, const int& b);
vec sort(vec & heap);

int main()
{
    srand(time(0));
    vec heap = createHeap();
    displayHeap(heap);
    maxHeapify(heap);
    cout<<endl<<"the new heap:"<<endl;
    displayHeap(heap);
    vec result = sort(heap);
    for(const auto& i: result)
        cout<<i<<endl;


 
}
vec sort(vec& heap)
{
    vec tmp;
    while(heap.size()!=0)
    {
        tmp.push_back(heap.front());
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(heap);
    }
    return tmp;
}

void maxHeapify(vec& heap)
{
    uint size = heap.size();
    for(int start = size/2;start>=0;start--)
    {
         int count = start;

        while(count<=size)
        {
              int bigger = 0;
            int toReplace = 0;
             if(count*2 <= size)
            {
                bigger = heap[count*2-1];
                toReplace = count*2;
#ifdef DEBUG
                cout<<"left child:"<<bigger<<endl;
#endif
             }
                else break;
            if(count*2+1 <= size)
            {
#ifdef DEBUG
                cout<<"right child:"<<heap[count*2]<<endl;
#endif
                if(heap[count*2]>bigger)
                {
                    bigger = heap[count*2];
                     toReplace = count*2 +1;
                 }
            }
            if(bigger > heap[count-1])
            {
                swap(heap,count,toReplace);
#ifdef DEBUG
                if(toReplace == count*2)
                     cout<<"swap left"<<endl;
                else if(toReplace == count*2+1)
                     cout<<"swap right"<<endl;
                else cout<<"no swap";
                cout<<endl;
                getchar();
#endif
                count = toReplace;
            }
            else
                break;



        }
    }

}
void swap(vec& heap,const int& a,const int & b)
{
    int tmp = 0;
    tmp = heap[b-1];
    heap[b-1] = heap[a-1];
    heap[a-1] = tmp;
}

vec createHeap()
{
    uint size=0;
    cout<<"enter the size of the heap: ";
    cin>>size;
    vec tmp;
    for(auto i=0;i<size;i++)
        tmp.push_back(rand()%size);
    return tmp;
}
void displayHeap(const vec& heap)
{
     int tmp = heap.size()+2;
    double lines = log(tmp)/log(2);
    if(static_cast<int>(lines)!=lines)
        ++lines;
    double spaces = pow(2,lines);
    bool newLine = true;

    for(auto i=0;i<heap.size();i++)
    {
        if(newLine)
        {
            for(auto j=0;j<spaces/2 - i;j++)
                cout<<" ";
        }
        newLine = false;
        cout<<heap[i]<<"_";
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

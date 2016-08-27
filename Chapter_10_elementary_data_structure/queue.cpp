#include<iostream>
#include<cstring>

using std::cout;
using std::endl;


class queueExp
{
public:
    queueExp();
    ~queueExp();

    void push(const int&);
    void pop();
    int size();
    int top();
    void allEl();

private:
    int* pnt;
    int pos;
    unsigned int capacity;
    int begin;
};
queueExp::queueExp():
    pnt(new int[10]()),
  pos(0),
  capacity(10),
  begin(0)
{
}
queueExp::~queueExp()
{
    delete pnt;
}

void queueExp::push(const int & value)
{
    if(pos == capacity)
    {
        cout<<"trying to resize stack";
        int* tmp = new int[capacity*2];
        memcpy(tmp,pnt,capacity*sizeof(int));
        capacity *= 2;
        delete pnt;
        pnt = tmp;
    }

    pnt[pos] = value;
    ++pos;
}
int queueExp::size(){   return pos;     }
void queueExp::pop()
{
    if(!(pos-begin))
        cout<<"error: stack is empty"<<endl;
    else    ++begin;
}
int queueExp::top()
{
    if(!(pos - begin))
        cout<<"error: stack is empty"<<endl;
    else
    return pnt[begin];
}
void queueExp::allEl()
{
    if(!pos)
        cout<<"error: stack is empty"<<endl;
    else
    {
    for(auto i=begin;i<pos;i++)
        cout<<pnt[i]<<",";
    cout<<endl;
    }
}

int main()
{
    queueExp queue;
    for(int i=0;i<10;i++)
        queue.push(i);
    cout<<"tp:"<<queue.top()<<endl;
    queue.allEl();
    queue.push(123);
    cout<<endl<<queue.top()<<endl;
    queue.pop();
    cout<<"tp:"<<queue.top();

}











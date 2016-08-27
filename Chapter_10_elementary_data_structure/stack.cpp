#include<iostream>
#include<cstring>

using std::cout;
using std::endl;


class stackExp
{
public:
    stackExp();
    ~stackExp();

    void push(const int&);
    void pop();
    int size();
    int top();
    void allEl();

private:
    int* pnt;
    int pos;
    unsigned int capacity;
};
stackExp::stackExp():
    pnt(new int[10]()),
  pos(0),
  capacity(10)
{
}
stackExp::~stackExp()
{
    delete pnt;
}

void stackExp::push(const int & value)
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
int stackExp::size(){   return pos;     }
void stackExp::pop()
{
    if(!pos)
        cout<<"error: stack is empty"<<endl;
    else    --pos;
}
int stackExp::top()
{
    if(!pos)
        cout<<"error: stack is empty"<<endl;
    else
    return pnt[pos-1];
}
void stackExp::allEl()
{
    if(!pos)
        cout<<"error: stack is empty"<<endl;
    else
    {
    for(auto i=0;i<pos;i++)
        cout<<pnt[i]<<",";
    cout<<endl;
    }
}

int main()
{
    stackExp stack;
    for(int i=0;i<10;i++)
        stack.push(i);
    cout<<"tp:"<<stack.top()<<endl;
    stack.allEl();
    stack.push(123);
    cout<<stack.top()<<endl;


}











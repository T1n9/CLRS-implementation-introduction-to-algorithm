#include<iostream>
#include<cstring>

using std::cout;
using std::endl;


class dequeue
{
public:
    dequeue();
    ~dequeue();

    void pushFront(const int&);
    void pushBack(const int &);
    void showError();

    void popFront();
    void popBack();
    int size();
    int front();
    int back();

    void allEl();
    void Resize();

private:
    int* pnt;
    int posFront;
    int posBack;
    unsigned int capacity;
    int begin;
};
dequeue::dequeue():
    pnt(new int[10]()),
  posFront(0),
  capacity(10),
  posBack(9),

  begin(0)
{
}
dequeue::~dequeue()
{
    delete pnt;
}
void dequeue::showError(){  cout<<"error: dequeue is empty"<<endl ; }

void dequeue::pushBack(const int & value)
{
    if(posFront == posBack)
    {
        Resize();
        posBack += (capacity/2);
    }
    pnt[posBack] = value;
    --posBack;

}
void dequeue::pushFront(const int & value)
{
    if(posFront == posBack)
        Resize();

    pnt[posFront] = value;
    ++posFront;
}
void dequeue::Resize()
{
    cout<<"trying to resize stack";
    int* tmp = new int[capacity*2];
    memcpy(tmp,pnt,posFront*sizeof(int));
    memcpy(tmp+posFront+capacity+1,pnt+posFront+1,(capacity - posFront - 1)*sizeof(int));
    capacity *= 2;
    delete pnt;
    pnt = tmp;
}
int dequeue::size(){   return posFront + (capacity - posBack);     }
void dequeue::popFront()
{
    if(!(posFront-begin))
        showError();
        else    --posFront;
}
void dequeue::popBack()
{
    if(posBack == capacity-1)
        showError();
    else ++posBack;
}
int dequeue::front()
{
    if(!(posFront - begin))
        showError();
        else
    return pnt[posFront-1];
}
int dequeue::back()
{
    if(posBack == capacity -1)
        showError();
    else
        return pnt[posBack+1];
}
void dequeue::allEl()
{
    if(!posFront && (posBack == capacity -1))
        cout<<"error: stack is empty"<<endl;
    else
    {
    for(auto i=posFront-1;i>=begin;i--)
        cout<<pnt[i]<<",";
    for(auto i=capacity-1;i>posBack;i--)
        cout<<pnt[i]<<",";
    cout<<endl;
    }
}

int main()
{
    dequeue queue;
    for(int i=0;i<5;i++)
        queue.pushFront(i);
    for(int i=0;i<5;i++)
        queue.pushBack(5);
    queue.allEl();
    queue.pushBack(123);
    queue.allEl();
    cout<<"front:"<<queue.front()<<endl<<"back:"<<queue.back()<<endl;
    queue.back();
    queue.pushFront(321);
    queue.allEl();
    queue.popFront();
    queue.popBack();
    queue.allEl();

}











#include<iostream>
#include<stack>

using namespace std;


//you can optimize this class by pushing only n-1 elements into the temperary stack, so next time you want to pop something out
//or you want to find the front value, just need to pop the last value of the temperaty stack, therefore no need to push all
//elements from stackIn

//I am too lazy tonight for that.

class queueWithStack
{
public:
    queueWithStack();
    ~queueWithStack();

    void push(const int&);
    void pop();
    int top();


private:
    stack<int> stackIn;
    stack<int> stackOut;
};
queueWithStack::queueWithStack()
{}
queueWithStack::~queueWithStack()
{}

void queueWithStack::push(const int& value)
{
    stackIn.push(value);
}
void queueWithStack::pop()
{
    while(!stackIn.empty())
    {
        stackOut.push(stackIn.top());
        stackIn.pop();
    }
    stackOut.pop();
    while (!stackOut.empty())
    {
        stackIn.push(stackOut.top());
        stackOut.pop();
    }
}
int queueWithStack::top()
{
    while(!stackIn.empty())
    {
        stackOut.push(stackIn.top());
        stackIn.pop();
    }
    int value = stackOut.top();
    while (!stackOut.empty())
    {
        stackIn.push(stackOut.top());
        stackOut.pop();
    }

    return value;
}

int main()
{
    queueWithStack queue;
    for(int i=0;i<10;i++)
    queue.push(i);
    cout<<"top:"<<queue.top()<<endl;
    for(int i=0;i<5;i++)
    queue.pop();
    cout<<"top:"<<queue.top()<<endl;
}

#include<iostream>
#include<climits>

using std::cout;
using std::endl;

struct node
{
    node():
        nodeValue(0),
        previous(NULL),
        next(NULL)
    {}
    int nodeValue;
    node* previous;
    node* next;
};

class double_linked_list
{
public:
    double_linked_list();
    ~double_linked_list();
    void insertNode(const int&);
    void showList();
    void deleteNode(const int&);
     node* find(const int&);

private:
    node* sentinel;
    node* tail;
};

double_linked_list::double_linked_list():
    sentinel(new node)
{
    sentinel->next = sentinel->previous;
    sentinel->nodeValue = INT_MIN;
    tail = sentinel;
}
double_linked_list::~double_linked_list()
{
    node* tmp = sentinel->next;
    node* next = tmp->next;
    while(tmp->nodeValue!=INT_MIN)
    {
        delete tmp;
        tmp = next;
        next = next->next;
    }
    delete sentinel;

}
void double_linked_list::deleteNode(const int & value)
{
    node* tmp = find(value);
    if(!tmp)
        cout<<value<<" not in the list"<<endl;
    else
    {
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        delete tmp;
    }
}
void double_linked_list::showList()
{
    node* tmp = sentinel->next;
    while(tmp->nodeValue!=INT_MIN)
    {
        cout<<tmp->nodeValue<<",";
        tmp = tmp->next;
    }
    cout<<endl;
}
void double_linked_list::insertNode(const int & value)
{
    node* tmp = new node;
    tmp->nodeValue = value;

    tail->next = tmp;
    tmp->previous = tail;
    tmp->next = sentinel;
    sentinel->previous = tmp;

    tail = tmp;
}
node* double_linked_list::find(const int& value)
{
    node* tmp = sentinel->next;
    while(tmp->nodeValue != value && tmp->nodeValue!=INT_MIN)
    {
        tmp = tmp->next;
    }
    if(tmp->nodeValue == INT_MIN)
        return NULL;
    else
    return tmp;
}

int main()
{
    double_linked_list list;
    for(auto i=0;i<10;i++)
        list.insertNode(i);
    list.showList();
    list.deleteNode(22);
    for(int i=4;i<9;i++)
        list.deleteNode(i);
    list.showList();

}

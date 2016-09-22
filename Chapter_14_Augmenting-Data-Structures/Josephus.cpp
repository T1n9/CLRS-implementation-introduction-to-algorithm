//I mainly copyed the idea from https://github.com/gzc/CLRS
#include<iostream>

using namespace std;

struct node
{
    int value;
    node* next;
    node(int no):value(no){}
};

int main()
{
    int n = 11;
    int m = 5;
    node* walk = NULL;
    node* last = NULL;
    node* first = NULL;
    for(int i=1;i<n;i++)
    {
        if(i == 1)
        {
            walk = new node(i);
            last = walk;
            first = walk;
        }
        walk = new node(i);
        last->next = walk;
        last = walk;
    }
    walk->next = first;
    walk = first;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++,walk = walk->next);
        cout<<walk->value<<", ";
        walk->value = walk->next->value;
        walk->next = walk->next->next;
    }
}

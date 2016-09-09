#include<iostream>
#include<vector>
#include<deque>

// if the data is other types, e.g. string or char*. A comparison logic should also be applied to arrange
// the order of the bi-tree

//in the show() func, I assume the bi_tree is a perfect tree, but it is not always the case...
using namespace std;

struct node
{
    node* left = NULL;
    node* right = NULL;
    int data = 0;
};
struct bi_pair
{
    node** parent;
    node** child;
};
typedef node*& node_ref;

class bi_tree
{
public:
    bi_tree();
    ~bi_tree();
    void delete_tree();
    void insert(const int &data );
    void insert_recursive(node_ref Node, const int&);
    void show();
    node_ref get_root(){   return root;    }
    bi_pair search(const int&);
    const int& max();
    void delete_node(const int&);

private:
    node* root;
};
bi_tree::bi_tree():    root(NULL)  {}
bi_tree::~bi_tree() {      }

void bi_tree::delete_node(const int & data)
{
    bi_pair tmp = search(data);
    node** child = tmp.child;

    if(child == NULL)
    {
        cout<<"cannot delete "<<data<<". Not in bi_tree"<<endl;
        return;
    }
    node* walk;
    if((*child)->left == NULL)
    {
        walk = *child;
        *child = (*child)->right;
    }
    else if((*child)->right == NULL)
    {
        walk = *child;
        *child = (*child)->left;
    }
    else
    {
        walk = *child;
        node** left_min  = &((*child)->left);
        while(*left_min)
        {
            left_min = &((*left_min)->right);
        }
        *left_min = (*walk).right;
        *child = (*child)->left;
     }

    delete walk;
}


const int& bi_tree::max()
{
    node* walk = root;
    while(walk->right)
        walk = walk->right;
    return walk->data;
}
void bi_tree::insert(const int& data)
{
    node** walk = &root;
    while(*walk)
    {
        if(data <= (*walk)->data)
            walk = &((*walk)->left);
        else walk = &((*walk)->right);
    }
    *walk = new node;
    (*walk)->data = data;
    (*walk)->left = NULL;
    (*walk)->right = NULL;
}
void bi_tree::insert_recursive(node_ref Node, const int& data)
{
    if(!Node)
    {
        Node = new node;
        Node->data = data;
        Node->right = NULL;
        Node->left = NULL;
    }
    else
    {
    if(data <= Node->data)
        insert_recursive(Node->left,data);
    else    insert_recursive(Node->right,data);
    }
}
void bi_tree::show()
{
    if(!root)
        return;
    deque<node*> nVec;
    nVec.push_back(root);
    int layer = 1;
    while(nVec.size())
    {
        node* walk = nVec.front();
        nVec.pop_front();
        cout<<walk->data<<" ";

        if((layer==1)||(layer==3)||(layer == 7))
            cout<<endl;
        ++layer;

        if(walk->left)
        nVec.push_back(walk->left);
        if(walk->right)
        nVec.push_back(walk->right);
    }
}
bi_pair bi_tree::search(const int & data)
{
    bi_pair res;
    node** parent = NULL;
    node** walk = &root;
    while(*walk)
    {
        if(data == (*walk)->data)
        {
            cout<<data <<" found in the tree !!!"<<endl;
            res.parent = parent;
            res.child = walk;
            return res;
        }
        else if(data < (*walk)->data)
        {
            parent = walk;
            walk = &((*walk)->left);
        }
            else
        {
            parent = walk;
            walk = &((*walk)->right);
        }
    }
    res.child = NULL;
    res.parent = NULL;
    cout<<data<<" not in bi_tree"<<endl;
    return res;
}






int main()
{
    bi_tree tree;
    int data1[4] = {10,23,12,33};
    int data2[3] = {3,2,5};
    for(const auto& i: data1)
        tree.insert_recursive(tree.get_root(),i);
    for(const auto& i: data2)
        tree.insert(i);
    tree.show();
    for(int i=1;i<6;i++)
        tree.search(i);
    cout<<"max for the tree: "<<tree.max()<<endl;
    tree.delete_node(100);
    tree.delete_node(2);
    tree.delete_node(3);
    tree.show();
    cout<<endl;
    tree.insert(1);
    tree.insert(4);
    tree.show();
}

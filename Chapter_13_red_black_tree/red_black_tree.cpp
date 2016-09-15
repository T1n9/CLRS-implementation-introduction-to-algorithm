//delete part is not finished yet
#include<iostream>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>

using namespace std;
enum _color {black, red};

struct node
{
    node* left = NULL;
    node* right = NULL;
    node* parent = NULL;
    int data = 0;
    _color color = red;
};

class rb_tree
{
public:
    rb_tree();
    ~rb_tree();
    bool insert(const int&);
    void show(node * NODE = root);
    void save_route(node* NODE = root);
    void verify_rb();
    void left_rotate(node *pNode);
    void right_rotate(node *pNode);
    void rb_insert_fix(node *pNode);
     void create_node(node** pNode, node* parent, _color color, const int& value);
    void delete_data(const int& );
    node* search_data(const int& );
    void delete_node(node* );

private:
    static node* root;
    node* NIL;
    vector<int> path;
    vector<int> black_no;
    int cnt;
};
node* rb_tree::root = NULL;
rb_tree::rb_tree():
    cnt(0),
    black_no(0),
    path(10000)
{
    NIL = new node;
    NIL->color = black;
    NIL->data = INT_MIN;
    NIL->left = NULL;
    NIL->right = NULL;
    NIL->parent = NULL;
}
rb_tree::~rb_tree()
{
}
void rb_tree::delete_node(node * walk)
{

}
void rb_tree::delete_data(const int & data)
{
    node * walk = search_data(data);
    if(walk == NIL)
        cout<<"data not found in rb_tree"<<endl;
    else    delete_node(walk);
}
node* rb_tree::search_data(const int & data)
{
    node* walk = root;
    while(walk != NIL)
    {
        if(data == walk->data)
            break;
        else if(data > walk->data)
            walk = walk->right;
        else walk = walk->left;
    }
    return walk;
}
void rb_tree::left_rotate(node *pNode)
{
    node* x_node = pNode;
    node* y_node = pNode->right;
    node* beta = y_node->left;
    node* grandpa = x_node->parent;

    x_node->right = beta;
    beta->parent = x_node;
    y_node->left = x_node;
    x_node->parent = y_node;
    if(grandpa == NULL)
    {
        root = y_node;
        y_node->parent = NULL;
    }
    else
    {
        if(grandpa->left == x_node)
        {
            grandpa->left = y_node;
            y_node->parent = grandpa;
        }
        else
        {
            grandpa->right = y_node;
            y_node->parent = grandpa;
        }
    }
}
void rb_tree::right_rotate(node *pNode)
{

    cout<<"rotate right"<<endl;
    node* y_node = pNode;
    node* x_node = y_node->left;

    cout<<"x:"<<x_node->data<<endl;

    node* beta = x_node->right;
    node* grandpa = y_node->parent;

    y_node->left = beta;
    beta->parent = y_node;
    x_node->right = y_node;
    y_node->parent = x_node;

    if(grandpa == NULL)
    {
        root = x_node;
        x_node->parent = NULL;
    }
    else
    {
        if(grandpa->left == y_node)
        {
            grandpa->left = x_node;
            x_node->parent = grandpa;
        }
        else
        {
            grandpa->right = x_node;
            x_node->parent = grandpa;
        }
    }
}
void rb_tree::show(node* NODE)
{
    if(NODE!=NIL)
    {
    cout<<NODE->data<<endl;
    show(NODE->left);
    show(NODE->right);
    }
}
void rb_tree::create_node(node **pNode, node *parent, _color color, const int &value)
{
    *pNode = new node;
    if(!*pNode)
        cout<<"cannot create space for pNode"<<endl;
    (*pNode)->parent = parent;
    (*pNode)->color = color;
    (*pNode)->data = value;
    (*pNode)->left = NIL;
    (*pNode)->right = NIL;
}
bool rb_tree::insert(const int & value)
{
    cout<<"insert:"<<value<<endl;
    node** walk = &root;
    node* parent = NULL;
    _color color_for_root = black;
    _color color_for_new = red;
    if(!(*walk))
    {
        create_node(walk,NULL,color_for_root,value);
        return true;
    }
    while((*walk)!=NIL)
    {
        parent = *walk;
        if(value <= (*walk)->data)
            walk = &((*walk)->left);
        else walk = &((*walk)->right);
    }
    create_node(walk,parent,color_for_new,value);
    rb_insert_fix(*walk);
    return true;
}


void rb_tree::rb_insert_fix(node* pNode)
{

    if(pNode->parent == NULL)
    {
        pNode->color = black;
        return;
    }
    else if(pNode->parent->color == black)
        return;
    else if(pNode->parent->color == red)
    {
        node* toRemove = pNode;
        node* father = toRemove->parent;
        node* grandpa = father->parent;
        node* uncle = NULL;
        if(father == grandpa->left)
            uncle = grandpa->right;
        else uncle = grandpa->left;

        if( uncle->color==red)
        {
            father->color = black;
            uncle->color = black;
            grandpa->color = red;
            rb_insert_fix(grandpa);
        }
        else if(uncle->color==black)
        {
            if(father==grandpa->left)
            {
                if(toRemove == father->right)
                {
                    toRemove->color = black;
                    grandpa->color = red;
                    left_rotate(father);
                    right_rotate(grandpa);

                }
                    else
                {
                    father->color = black;
                    grandpa->color = red;
                    right_rotate(grandpa);
                }
            }
            else
            {
                if(toRemove==father->left)
                {
                    toRemove->color = black;
                    grandpa->color = red;
                    right_rotate(father);
                    left_rotate(grandpa);

                }
                else
                {
                    father->color = black;
                    grandpa->color = red;
                    left_rotate(grandpa);

                }


            }
        }
    }

}

void rb_tree::verify_rb()
{
    save_route();
    if(path[0]!=1)
    {
        cout<<"not a valid red-black tree, root is not black"<<endl;
        return;
    }
    int black = black_no.back();
    bool if_rb = true;
    for(const auto & i:black_no)
    {
        if(black!=i)
        {
            cout<<"not a red-black tree, different route has different number of black nodes"<<endl;
            if_rb = false;
            break;
        }
    }
    if(if_rb)
        cout<<"it is a valid red-black tree"<<endl;
}
void rb_tree::save_route(node* NODE)
{
    if (NODE == NULL)
        return;
    if (NODE == NIL)
    {
        int b_no = 0;
        for (int i = 0; i < cnt; ++i)
        {
            cout<<path.at(i);
            if(path.at(i))
                ++ b_no;
        }
        cout<<endl;
        black_no.push_back(b_no);
        return;
    }
    if(NODE->color == black)
        path[cnt++] = 1;
    else path[cnt++] = 0;

    save_route(NODE->left);
    save_route(NODE->right);
    --cnt;
}

//it is a func to create unique array so should not be part of the class
vector<int> create_uniq()
{
    vector<int> uniq;
    srand(time(0));
    for(int i=0;i<20;i++)
    {
        int value = rand()%30;
        auto tmp = std::find(uniq.begin(),uniq.end(),value);
        while(tmp != uniq.end())
        {
            value = rand()%20+1;
            tmp = std::find(uniq.begin(),uniq.end(),value);
        }
        uniq.push_back(value);
    }
    return uniq;
}
int main()
{
    rb_tree rb;
    vector<int> uniq = create_uniq();

    srand(time(0));


    for(int i=0;i<uniq.size();i++)
    {
        if(!rb.insert(uniq.at(i)))
            cout<<"something went wrong"<<endl;
    }

    cout<<"showing red-black tree"<<endl;
    rb.show();
    rb.verify_rb();
    rb.delete_data(40);

}

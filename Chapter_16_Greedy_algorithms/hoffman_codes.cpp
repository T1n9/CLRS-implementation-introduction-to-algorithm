#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class hoffman_node
{
public:
    char element;
    int frequence;
    hoffman_node* left = NULL;
    hoffman_node* right = NULL;
    hoffman_node* parent = NULL;
    hoffman_node(){}
    hoffman_node(char ele, int fre):
        element(ele),
        frequence(fre)
    {
    }
};


void show(vector<hoffman_node>& hoffman)
{
    for(const auto & i:hoffman)
        cout<<i.element<<":"<<i.frequence<<endl;
}

hoffman_node* build_branch(hoffman_node& node1, hoffman_node& node2)
{
    hoffman_node* node1_pt = new hoffman_node;
    hoffman_node* node2_pt = new hoffman_node;
    *node1_pt = node1;
    *node2_pt = node2;

    hoffman_node* tmp = new hoffman_node;
    tmp->frequence = node1.frequence + node2.frequence;
    tmp->left = node1_pt;
    tmp->right = node2_pt;
    node1_pt->parent = tmp;
    node2_pt->parent = tmp;
    tmp->parent = NULL;
    return tmp;
}

bool less_fre(const hoffman_node& node1, const hoffman_node& node2)
{
    return node1.frequence<node2.frequence;
}
void print_path(vector<int>& path)
{
    for(const auto& i: path)
        cout<<i<<", ";
    cout<<endl;
}
void print(const hoffman_node* root, vector<int>& path)
{
    if(root->parent !=NULL)
    {
        if(root == root->parent->left)
            path.push_back(0);
        else
            path.push_back(1);
    }

    if(root->left ==NULL)
    {
        cout<<"found leaf"<<endl;

        cout<<"code for "<<root->element<<endl;
        print_path(path);
        path.pop_back();
        return;
    }


    print(root->left, path);
    print(root->right, path);
    path.pop_back();
}


void hoffman_tree(vector<hoffman_node>& hoffman)
{
    sort(hoffman.begin(),hoffman.end(),less_fre);

#ifdef DEBUG
    show(hoffman);
#endif

    while(hoffman.size()!=1)
    {
        hoffman_node* tmp = build_branch(hoffman.at(0),hoffman.at(1));
        hoffman.erase(hoffman.begin(),hoffman.begin()+2);
        hoffman.push_back(*tmp);
        sort(hoffman.begin(),hoffman.end(),less_fre);
#ifdef DEBUG
        cout<<endl;
        show(hoffman);
        getchar();
#endif
    }
    hoffman_node* root = &(hoffman.back());
    vector<int> path;

    print(root, path);

}

int main()
{
    vector<hoffman_node> hoffman;
    hoffman.emplace_back('a',1);
    hoffman.emplace_back('b',1);
    hoffman.emplace_back('c',2);
    hoffman.emplace_back('d',3);
    hoffman.emplace_back('e',5);
    hoffman.emplace_back('f',8);
    hoffman.emplace_back('g',13);
    hoffman.emplace_back('h',21);


    hoffman_tree(hoffman);


}

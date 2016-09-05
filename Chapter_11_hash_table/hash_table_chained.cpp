#include<iostream>
#include<list>

using namespace std;
typedef int keyType;


class element
{
public:
    element():info(""),key(0){}
    element(string name, keyType keyValue):info(name),key(keyValue){}

    string info;
    keyType key;
};

class hash_table
{
public:
    hash_table();
    ~hash_table();
    void insert(const element& );
    int hash_value(const int &keyValue);
    void show_table();
    void search(const int &keyValue);

private:
    list<element>* elem[10];
};
hash_table::hash_table()
{
    for(auto & i: elem)
        i = NULL;
}
hash_table::~hash_table(){}
void hash_table::insert(const element & element_to_add)
{
    int result = hash_value(element_to_add.key);
    if(elem[result]==NULL)
    {
        list<element>* head = new list<element>;
        elem[result] = head;
        head->push_back(element_to_add);
    }
    else
        elem[result]->push_back(element_to_add);

}
//this can be replaced by multiplication method and universal method
int hash_table::hash_value(const int& keyValue){    return keyValue%10;    }
void hash_table::show_table()
{
    for(int i=0;i<10;i++)
    {
        cout<<"slot"<<i<<endl;
        if(!elem[i])
            cout<<"no element in this slot"<<endl;
        else
        {
            for(auto j = elem[i]->cbegin();j!=elem[i]->cend();j++)
                cout<<"info:"<<j->info<<" key:"<<j->key<<",";
                      cout<<endl;
        }
    }
}
void hash_table::search(const int & keyValue)
{
    int result = hash_value(keyValue);
    bool found = false;
    for(auto i=elem[result]->cbegin();i!=elem[result]->cend();i++)
    {
        if(keyValue==i->key)
        {
            cout<<"key found"<<endl;
            cout<<"the info for this key:"<<i->info<<endl;
            found = true;
            break;
        }
    }
    if(!found)
        cout<<"key  "<< keyValue <<" does not exist in the hash table"<<endl;

}


int main()
{
    element ele[8];
    ele[0] = element("zhang",1);
     ele[1]  = element("james",2);
     ele[2] = element("william",1321);
     ele[3] = element("jax",321);
     ele[4] = element("irelia",3);
     ele[5]  =element("garen",4);
     ele[6]= element("fire",5);
     ele[7]= element("ice",12);
    hash_table table;
     for(const auto & i:ele)
    table.insert(i);
    table.show_table();
    table.search(22);
    table.search(12);

}

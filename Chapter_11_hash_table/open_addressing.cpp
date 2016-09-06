// I am not sure what should be the being searched information, but if the information/key is desired to be searched, it can 
//be modified very easily
#include<iostream>

typedef int key_type;
using std::string;
using std::cout;
using std::endl;

struct table_node
{
    string info;
    key_type key;
    int number_in_table;
    table_node():key(0),number_in_table(0){}
    table_node( string name,key_type key_value):key(key_value),info(name){}
};

class hash_table
{
public:
    hash_table();
    ~hash_table();
    void insert( table_node& node);
     int able_to_push(table_node&);
    void resize();
    void push_into_slot(const int & pos,const table_node& node);
    void show_table();
    void search(const int& );

private:
    //if bigger table size is desired, a prime number generator is necessary
    int table_size_array[6] = {11, 23, 37, 53, 73, 97};
    table_node* table_head;
    int table_size;
    int size_no;
};
hash_table::hash_table():
    size_no(0)
{
    table_size = table_size_array[size_no];
    table_head = new table_node[table_size];
}
hash_table::~hash_table()   {   delete[]table_head;  }

void hash_table::insert( table_node &node)
{
    int result = 0;
    while((result = able_to_push(node)) < 0)
    {
        cout<<"have to resize hash table";
        resize();
    }
    push_into_slot(result, node);
}

int hash_table::able_to_push(table_node & node)
{
    int iter = 0;
    int i = 0;
    int h1 = node.key%table_size;
    int h2 = 1+ (node.key%(table_size-2));
    bool found = false;
    for(int i=0;i<table_size;i++)
    {
        iter = (h1 + i*h2)%table_size ;

        if(table_head[iter].info.size())
            continue;
        else
        {
            found = true;
            break;
        }
    }
    if(!found)
         iter  = -1;
    else node.number_in_table = iter;

    return iter;
}
void hash_table::push_into_slot(const int &pos, const table_node &node)
{
    table_head[pos].info = node.info;
    table_head[pos].key = node.key;
}
void hash_table::resize()
{
    ++size_no;
    int new_table_size = table_size_array[size_no];
    table_node* tmp = new table_node[new_table_size];
    for(int i=0;i<table_size;i++)
        tmp[i] = table_head[i];
    delete[] table_head;
    table_head = tmp;

    table_size = table_size_array[size_no];
}
void hash_table::show_table()
{
    for(int i=0;i<table_size;i++)
    {
        if(table_head[i].info.size())
            cout<<"info for slot "<<i<<" : "<<table_head[i].info<<endl;
        else
            cout<<"no msg stored in slot "<<i<<endl;
    }
}
void hash_table::search(const int & no)
{
    if(no >= table_size)
    {
        cout<<"no msg stored for this slot"<<endl;
        return;
    }
    string result = table_head[no].info;
    if(result.size())
    {
        cout<<"msg in this slot: "<<result<<endl;
        return;
    }
    else
    cout<<"no msg stored for this slot"<<endl;
}

int main()
{
    hash_table table;
    table_node node[13];
    node[0] = {"jax",0};
    node[1] = {"irelia",1};
    node[2] = {"garen",2};
    node[3] = {"velkoz",3};
    node[4] = {"thresh",333};
    node[5] = {"jinh",13};
    node[6] = {"pikaq",21};
    node[7] = {"arri",321};
    node[8] = {"jix", 4};
    node[9] = {"alex", 5};
    node[10] = {"lmao",6};
    node[11] = {"hi",7};
    node[12] = {"more", 8};
    for( auto& i:node)
        table.insert(i);
    table.show_table();
   table.search(node[12].number_in_table);
    table.search(100);

}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define a_size 11

struct event_time
{
    int start;
    int end;
    event_time(int _start, int _end):
        start(_start),
        end(_end)
    {}
};
void show_all(const vector<event_time>& e_time)
{
    for(auto& i: e_time)
        cout<<i.start<<","<<i.end<<endl;
}


bool less_sec(const event_time& e_time1, const event_time& e_time2)
{
    return e_time1.end<e_time2.end;
}
vector<event_time> greed_algorithm_class_room(vector<event_time>& e_time,int size)
{
    sort(e_time.begin(), e_time.end(),less_sec);
    vector<event_time> tmp;
    tmp.push_back(e_time.front());
    e_time.erase(e_time.begin());


    for(auto& i:e_time)
    {
        event_time e_tmp = tmp.back();
        if(i.start>= e_tmp.end)
            tmp.push_back(i);
    }
    return tmp;
}

int main()
{
    vector<event_time> e_time;
    e_time.push_back(event_time(6,10));
    e_time.push_back(event_time(8,11));
    e_time.push_back(event_time(8,12));
    e_time.push_back(event_time(2,14));
    e_time.push_back(event_time(12,16));
    e_time.push_back(event_time(1,4));
    e_time.push_back(event_time(3,5));
    e_time.push_back(event_time( 0,6));
    e_time.push_back(event_time(5,7));
    e_time.push_back(event_time(3,9));
    e_time.push_back(event_time(5,9));



    vector<event_time>res = greed_algorithm_class_room(e_time, a_size);
    show_all(res);
}

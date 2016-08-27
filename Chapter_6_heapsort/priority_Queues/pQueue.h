#ifndef PQUEUE_H
#define PQUEUE_H

#include<vector>

class pQueue
{
public:
    pQueue();
     ~pQueue();

    void insert(const int& value);
    void extractMax();
    int max();
    void increaseKey(const int& pos, const int& value);
    void display();

private:
    std::vector<int> queues;
    void maxHeapify();
    void swap(const int& a, const int& b);

};

#endif // PQUEUE_H


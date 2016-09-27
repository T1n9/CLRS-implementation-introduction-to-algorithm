#include<iostream>
#include<climits>

using namespace std;

//you can also pass a struct in the functions, but I am too lazy so I will use static variable
static int cutting_length[11] = {0};

int max(const int& value1, const int& value2){    return (value1>value2)?value1:value2; }


int memoized_aux(const int* price, const int& n, int* result, int& iter_no)
{
    ++iter_no;
    int q = 0;
    int res = 0;
    if(result[n]>0)
    {
        --iter_no;
        return result[n];
    }
    if(n == 0)
        q = 0;
    else
    {
        q = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            int tmp = price[i] + memoized_aux(price, n-i, result, iter_no);
            if(q < tmp)
            {
                res = i;
                q = tmp;
            }
        }
    }
    cutting_length[n] = res;

    result[n] = q;
    --iter_no;
    return q;
}

pair<int*, int> memoized_cut_rod(const int* p, const int& n)
{
    pair<int*, int> to_return;
    int *result = new int[n+1];
    to_return.first = result;
    for(int i=0;i<n+1;i++)
        result[i] = INT_MIN;
    int iter = 0;
    to_return.second =  memoized_aux(p , n, result, iter);
    return to_return;
}


int main()
{


    int price[11] = {0};

    price[1] = 1;
    price[2] = 5;
    price[3] = 8;
    price[4] = 9;
    price[5] = 10;
    price[6] = 17;
    price[7] = 17;
    price[8] = 20;
    price[9] = 24;
    price[10] = 30;

    int to_investigate = 8;

    pair<int* , int> hello = memoized_cut_rod(price,to_investigate);
    cout<<hello.second<<endl;
    cout<<"optimal profit for different length:"<<endl;
    for(int i=0;i<9;i++)
        cout<<hello.first[i]<<endl;
    cout<<endl;
    for(int i=0;i<to_investigate+1;i++)
        cout<<cutting_length[i]<<endl;
}

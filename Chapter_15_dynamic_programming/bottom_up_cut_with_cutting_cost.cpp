#include<iostream>
#include<climits>

using namespace std;

int max(const int& val1, const int& val2){    return (val1>val2)?val1:val2;     }

int* bottom_up_cut(int* price, int n, const int& single_cost)
{
    int cutting_times = 0;
    int* result = new int[n+1];
    result[0] = 0;
    int cut_times[n+1] = {0};
    for(int i=1;i<=n;i++)
    {
        int q = INT_MIN;
        for(int j=1; j<=i;j++)
        {
            int tmp = price[j] + result[i-j];
            if(q < tmp)
            {
                q = tmp;
                cut_times[i] = j;
            }
        }
        result[i] = q;
    }

    int cut_tmp = n;
    while(cut_tmp >0 )
    {
        cout<<"cut "<<cut_times[cut_tmp]<<endl;
        cut_tmp -= cut_times[cut_tmp];
        ++ cutting_times;
    }
    cout<<"cost: "<<result[n] - cutting_times*single_cost;

    return result;
}

int main()
{
    int single_cut_cost = 3;

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

    int to_investigate = 5;
    int* res = bottom_up_cut(price,to_investigate, single_cut_cost);
  //  for(int i=0;i<=to_investigate;i++)
    //    cout<<res[i]<<endl;

}

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void matrix_chain_order(int * p, int size, int m[7][7], int s[7][7])
{
    int n = size;
    for(int l = 2; l<= n; ++l)
        for(int i=1; i<= n-l+1; i++)
        {
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<=j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
}
void print_order(int s[7][7], int i, int j)
{
    if(i == j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_order(s, i, s[i][j]);
        print_order(s,s[i][j]+1, j);
        cout<<")";
    }
}



int main()
{
    const int size = 7;
    int p[size] = {5, 10, 3, 12, 5, 50, 6};
    int m[size][size] = {0};
    int s[size][size] = {0};

    for(auto& i: p)
        cout<<i<<endl;
    matrix_chain_order(p,size,m,s);
    print_order(s, 1, size);

}

#include<iostream>
using namespace std;
#define size_a 9
#define size_b 10

void least_common_subsequence(int* X, int* Y, int b[size_a][size_b], int c[size_a][size_b])
{
    for(int i=1;i<size_a;i++)
        for(int j=1;j<size_b;j++)
        {
            if(X[i] == Y[j])
            {
                c[i][j] = 1+ c[i-1][j-1];
                b[i][j] = 5;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 0;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 10;
            }
        }
}
void print_lcs(int b[size_a][size_b], int* X, int i, int j)
{
    if(i == 0 || j ==0)
        return;
    if(b[i][j] == 5)
    {
        print_lcs(b, X, i-1, j-1);
        //cout<<X[i]<<",";
        cout<<"X"<<i<<":"<<X[i]<<",";
    }
    else if(b[i][j] == 0)
        print_lcs(b, X, i-1,j);
    else print_lcs(b, X, i, j-1);
}
int main()
{
    int X[size_a] = {INT_MIN, 1,0,0,1,0,1,0,1};
    int Y[size_b] = {INT_MIN, 0,1,0,1,1,0,1,1,0};
    int b[size_a][size_b]={0};
    int c[size_a][size_b] = {0};
    least_common_subsequence(X,Y, b, c);

    print_lcs(b, X, size_a-1, size_b-1);
}

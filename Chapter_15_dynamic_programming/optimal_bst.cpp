#include<iostream>
#include<climits>

#define array_size 8
using namespace std;

optimal_bst(float* pi, float* qi, int n, int root[array_size][array_size])
{
    float e[n+1][n] = {0};
    float w[n+1][n] = {0};
    for(int i=1;i<n+1;i++)
    {
        e[i][i-1] = qi[i-1];
        w[i][i-1] = qi[i-1];
    }
    for(int l = 1;l<n;l++)
        for(int i=1;i<n-l+1;i++)
        {
            int j = i+l-1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j-1]+ pi[j] + qi[j];
#ifdef DEBUG
            cout<<"i:"<<i<<". "<<"j:"<<j<<". ";
            cout<<w[i][j]<<endl;
            getchar();
#endif
            for(int r=i;r<=j;r++)
            {
                float t = e[i][r-1] + e[r+1][j] + w[i][j];
                if(t<e[i][j])
                {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }

}

int main()
{
    float pi[array_size] = {INT_MIN, 0.04, 0.06, 0.08, 0.02, 0.1, 0.12, 0.14 };
    float qi[array_size] = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};

    int root[array_size][array_size] = {0};
    optimal_bst(pi,qi, array_size, root);

    cout<<"result:"<<endl;
    cout<<root[1][array_size-1];

}

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<time.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef vector<vector<int>> mat;
mat createMatrix();
void displayMatrix(const mat&array);
mat normalMultiply(const mat&, const mat&);

int main(int argc, char *argv[])
{

    vector<vector<int>> array0 = createMatrix();
    vector<vector<int>> array1 = createMatrix();
    cout<<"displaying array:"<<endl;
    displayMatrix(array0);
    cout<<"another array:"<<endl;
    displayMatrix(array1);
    cout<<"the result of the matrix multiplication:"<<endl;
    mat result = normalMultiply(array0,array1);

    displayMatrix(result);



}
mat normalMultiply(const mat & mat1, const mat & mat2)
{
    mat matTmp;

    for(auto i = 0;i<mat1.size();i++)
    {
        vector<int> tmpVec;
        for(auto j=0 ; j<mat1.size();j++)
        {
            int tmp = 0;
            for( auto m=0; m<mat1.size(); m++)
            tmp += mat1[i][m]*mat2[m][j];

            tmpVec.push_back(tmp);
        }
        matTmp.push_back(tmpVec);
    }

    return matTmp;
}

void displayMatrix(const mat &array)
{
    for(auto i=array.begin();i!=array.end();i++)
    {
        for(auto j=i->begin();j!= i->end();j++)
            cout<<(*j)<<"   ";
        cout<<endl;
    }
}

mat createMatrix()
{
    mat array;
    srand(time(0));
    int size = 0;
    cout<<"enter size, it will create a squre matrix:";
    cin>>size;

    for(auto i=0;i<size;i++)
    {
        vector<int> tmp;
        for(auto j=0;j<size;j++)
            tmp.push_back(rand()%10);

        array.push_back(tmp);
    }

     return array;
}


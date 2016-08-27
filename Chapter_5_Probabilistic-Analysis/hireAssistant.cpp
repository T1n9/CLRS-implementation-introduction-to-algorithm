#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>

typedef std::vector<int> vecInt;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    const int hireCost = 1;
    int totalCost = 0;
    const int candidateSize = 100;
    const int testSize = 1000;
    int hired = 1;
    vecInt candidateList;
    vecInt expectation;
    int max = -1;
    for(auto i=0;i<testSize;i++)
    {
        if(candidateList.size())
            cout<<"something is wrong, the candidate list is not empty before inserting";
        for(auto j=0;j<candidateSize;j++)
            candidateList.push_back(rand()%candidateSize);

        max = candidateList.front();
        for(auto m=1;m<candidateList.size();m++)
           {
            if(max<candidateList[m])
               {
                max = candidateList[m];
                ++ hired;
                }
            }
        totalCost = hired*hireCost;
        expectation.push_back(totalCost);

        totalCost = 0;
        hired = 1;
        max = -1;
        candidateList.clear();
    }

    int expectationSum = 0;
    for(const auto & i: expectation)
        expectationSum += i;

    cout<<"expectation from calculation: "<<(static_cast<float>(expectationSum)/expectation.size())<<endl;
    cout<<"expectation using equation from book: "<<hireCost*log(candidateSize);
 
}






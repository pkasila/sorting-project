#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
    long long i,n,j,t,t1,t2;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin>>n;
    cout<<n<<endl;
    vector<long long>S(n);
    for(i=0; i<n; i++)
    {
        cin>>S[i];
    }
    t1=clock();
    for(i=1; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(S[j]>S[j+1])
            {
                swap(S[j],S[j+1]);
            }
        }
    }
    t2=clock();
    t=t2-t1;
    cout<<t<<" ms"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<S[i]<<' ';
    }
    return 0;
}

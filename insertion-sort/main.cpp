#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n;

    vector<int> v(n);
    fin >> n;
    for(int i = 0; i < n; i++)
        fin >> v[i];

    int t1 = clock();
    for(int i=1;i<n;i++)
        for(int j=i;j>0 && v[j-1]>v[j];j--) // пока j>0 и элемент j-1 > j, x-массив int
			swap(v[j-1],v[j]);
    int t2 = clock();

    for(int i = 0; i < n; i++)
        fout << v[i] << endl;

    cout << t2-t1 << endl;

    return 0;
}

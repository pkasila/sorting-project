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
    for (int i = 0; i < n; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[smallestIndex])
				smallestIndex = j;
		}
		std::swap(v[i], v[smallestIndex]);
	}
	int t2 = clock();

    for(int i = 0; i < n; i++)
        fout << v[i] << endl;

    cout << t2-t1 << endl;
    return 0;
}

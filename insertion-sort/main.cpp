#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

static int find_keyword(int argc, char *argv[], const char *keyword) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], keyword) == 0) return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    const int inIndex = find_keyword(argc, argv, "-in");
    if (inIndex < 0) {
        printf("No -in keyword found!  Exiting!\n");
        exit(10);
    }

    const int outIndex = find_keyword(argc, argv, "-out");
    if (outIndex < 0) {
        printf("No -out keyword found!  Exiting!\n");
        exit(10);
    }

    ifstream fin(argv[inIndex + 1]);
    ofstream fout(argv[outIndex + 1]);
    int n;

    fin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        fin >> v[i];

    int t1 = clock();
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && v[j - 1] > v[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
            swap(v[j - 1], v[j]);
    int t2 = clock();

    fout << t2 - t1 << endl;

    for (int i = 0; i < n; i++)
        fout << v[i] << endl;

    return 0;
}

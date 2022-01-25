#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

void merge_intervals(vector<int> &v, int s, int m, int e) {
    vector<int> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {
        if (v[i] <= v[j]) {
            temp.push_back(v[i]);
            ++i;
        } else {
            temp.push_back(v[j]);
            ++j;
        }
    }

    while (i <= m) {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(v[j]);
        ++j;
    }

    for (i = s; i <= e; ++i)
        v[i] = temp[i - s];
}

void merge_sort(vector<int> &v, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        merge_sort(v, s, m);
        merge_sort(v, m + 1, e);
        merge_intervals(v, s, m, e);
    }
}

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
    vector<int> v;

    fin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        fin >> v[i];
    }

    int t1 = clock();
    merge_sort(v, 0, n - 1);
    int t2 = clock();

    fout << t2 - t1 << std::endl;
    for (auto i: v)
        fout << i << ' ';

}
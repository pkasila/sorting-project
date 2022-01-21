#include <iostream>
#include <vector>
#include <fstream>

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

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("merge-sort.txt");

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
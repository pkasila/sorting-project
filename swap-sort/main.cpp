#include <iostream>
#include <fstream>
#include <vector>
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

    std::ifstream fin(argv[inIndex + 1]);
    std::ofstream fout(argv[outIndex + 1]);
    long long i, n, j, t, t1, t2;
    fin >> n;
    fout << n << endl;
    vector<long long> S(n);
    for (i = 0; i < n; i++) {
        fin >> S[i];
    }
    t1 = clock();
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (S[j] > S[j + 1]) {
                swap(S[j], S[j + 1]);
            }
        }
    }
    t2 = clock();
    t = t2 - t1;
    fout << t << " ms" << endl;
    for (i = 0; i < n; i++) {
        fout << S[i] << ' ';
    }
    return 0;
}

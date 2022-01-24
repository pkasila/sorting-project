#include <iostream>
#include <fstream>
#include <vector>

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

    int n;
    std::vector<int> v;

    fin >> n;
    v = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        fin >> v[i];
    }

    int t1 = clock();
    std::sort(v.begin(), v.end());
    int t2 = clock();

    fout << t2 - t1 << std::endl;
    for (auto i: v)
        fout << i << ' ';
}
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
    fin >> n;
    std::vector<int> v;

    while(!fin.eof()) {
        int i;
        fin >> i;
        v.emplace_back(i);
    }

    v.pop_back();

    std::reverse(v.begin(), v.end());

    fout << v.size() << std::endl;
    for (auto i: v)
        fout << i << ' ';
}
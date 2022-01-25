#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

static int find_keyword(int argc, char *argv[], const char *keyword) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], keyword) == 0) return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    const int nIndex = find_keyword(argc, argv, "-n");
    if (nIndex < 0) {
        printf("No -n keyword found!  Exiting!\n");
        exit(10);
    }

    const int minIndex = find_keyword(argc, argv, "-min");
    if (minIndex < 0) {
        printf("No -min keyword found!  Exiting!\n");
        exit(10);
    }

    const int maxIndex = find_keyword(argc, argv, "-max");
    if (maxIndex < 0) {
        printf("No -max keyword found!  Exiting!\n");
        exit(10);
    }

    const int outIndex = find_keyword(argc, argv, "-out");
    if (maxIndex < 0) {
        printf("No -out keyword found!  Exiting!\n");
        exit(10);
    }

    long long n = stol(argv[nIndex + 1]),
            min = stol(argv[minIndex + 1]), max = stol(argv[maxIndex + 1]), x, i;
    ofstream fout(argv[outIndex + 1]);
    fout << n << endl;
    for (i = 0; i < n; i++) {
        x = rand() % (max - min) + min;
        fout << x << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

void quicksort(std::vector<int> &mas, int first, int last) {
    int mid;
    int f = first;
    int l = last;
    mid = mas[(f + l) / 2];
    do {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        if (f <= l) {
            int temp = mas[f];
            mas[f] = mas[l];
            mas[l] = temp;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
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

    std::ifstream fin(argv[inIndex + 1]);
    std::ofstream fout(argv[outIndex + 1]);

    int numbers;
    fin >> numbers;
    std::vector<int> Massive(numbers);
    for (int i = 0; i < numbers; i++)
        fin >> Massive[i];
    int t1 = clock();
    quicksort(Massive, 0, numbers - 1);
    int t2 = clock();
    fout << t2 - t1 << std::endl;
    for (auto i: Massive)
        fout << i << ' ';
    return 0;
}
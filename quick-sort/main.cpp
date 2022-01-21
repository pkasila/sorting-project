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

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("quick-sort.txt");
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
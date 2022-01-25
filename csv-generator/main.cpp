#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void gen(std::string file, std::vector<std::string> sorts, std::vector<std::string> sources) {

    std::ofstream fout(file);

    for (auto sort: sorts) {
        fout << "SORT:" << sort << std::endl;
        for (auto source: sources) {
            fout << source << ',';
        }
        fout << std::endl;
        for (int i = 1; i <= 10; i++) {
            fout << i << ',';

            for (auto source: sources) {
                std::stringstream ss;
                ss << "data/runs/" << i << "/out/" << sort << "-" << source << ".txt";
                std::ifstream fin(ss.str());
                int n;
                fin >> n;
                fout << n << ',';
                fin.close();
            }
            fout << std::endl;
        }
    }

    for (auto sort: sorts) {
        fout << "SORT:" << sort << "_inversed" << std::endl;
        for (auto source: sources) {
            fout << source << ',';
        }
        fout << std::endl;
        for (int i = 1; i <= 10; i++) {
            fout << i << ',';

            for (auto source: sources) {
                std::stringstream ss;
                ss << "data/runs/" << i << "/inversed/out/" << sort << "-" << source << ".txt";
                std::ifstream fin(ss.str());
                int n;
                fin >> n;
                fout << n << ',';
                fin.close();
            }
            fout << std::endl;
        }
    }
}

int main() {
    gen("data/out/result_task1.csv", {
            "selection-sort",
            "swap-sort",
            "insertion-sort",
    }, {
            "20k_100",
            "20k_10000",
            "40k_100",
            "40k_10000",
    });

    gen("data/out/result_task2.csv", {
            "std-sort",
            "quick-sort",
            "merge-sort",
    }, {
            "1m_100",
            "1m_10000",
            "2m_100",
            "2m_10000",
    });
}
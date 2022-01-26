#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

int isSorted(int *arr, int n) {
   while ( --n >= 1 ) {
      if ( arr[n] < arr[n-1] ) {
         return 0;
      }
   }
   return 1;
}
void shuffle(int *arr, int n) {
   int temp, r;
   for(int i=0; i < n; i++) {
      temp = arr[i];
      r = rand() % n;
      arr[i] = arr[r];
      arr[r] = temp;
   }
}
void bogosort(int *arr, int n) {
   while ( !isSorted(arr, n) ) {
      shuffle(arr, n);
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

    std::cout << "started" << std::endl;
    std::ifstream fin(argv[inIndex + 1]);
    std::ofstream fout(argv[outIndex + 1]);
    int n;
    fin >> n;
    int v[n];

    for(int i = 0; i < n; i++)
        fin >> v[i];

    int t1 = clock();
    bogosort(v, n);
    int t2 = clock();
    fout << t2-t1 << endl;

    for(int i = 0; i < n; i++)
        fout << v[i] << ' ';
    return 0;
}

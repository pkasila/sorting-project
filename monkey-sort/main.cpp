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
int main()
{
    cout << "started" << endl;
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n;
    fin >> n;
    int v[n];

    for(int i = 0; i < n; i++)
        fin >> v[i];

    int t1 = clock();
    cout << "t1 = " << t1 << endl;
    bogosort(v, n);
    for(int i = 0; i < n; i++)
        fout << v[i] << endl;

    int t2 = clock();
    cout << t2-t1 << endl;
    return 0;
}

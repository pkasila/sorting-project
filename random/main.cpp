#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));
    long long n, d, x, i;
    cin >> n >> d;
    ofstream cout("input.txt");
    //Числа генерируются в диапазоне от -d до d включительно.
    cout << n << endl;
    for (i = 0; i < n; i++) {
        x = rand() % (2 * d + 1) - d;
        cout << x << endl;
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    int Size;
    cout << "Max number> ";
    cin >> Size;
    bool* primes = new bool[Size-1];
    fill_n(primes, Size-1, true);
    for(int i = 0; pow(i,2) < (Size-1); i++){
        if(primes[i]){
            int x = i + 2;
            for(int j = x*2; j < (Size-1)+2; j += x){
                primes[j-2] = false;
            }
        }
    }
    ofstream file;
    file.open("prime.txt");
    if(Size > 1){
        file << 2;
        for(int i = 1; i < (Size-1); i++){
            if(primes[i]){
                file << endl
                     << i + 2;
            }
        }
    }
    file.close();
    return 0;
}

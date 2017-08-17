#include <iostream>
#include <windows.h>
#include <time.h>

#define NUM_PRIMES 50000

using namespace std;

int main()
{
    int array[NUM_PRIMES];
    clock_t start, interval;
    bool isPrime;
    LARGE_INTEGER frequency, t1, t2;
    double elapsedTime;

    //get ticks per second
    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&t1);
    for (int idx = 0, i = 2; idx < NUM_PRIMES; ++i) {
        isPrime = true;
        for (int y = 0; y < idx; ++y) {
            if(i % array[y] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            array[idx] = i;
            idx++;
        }
    }
    QueryPerformanceCounter(&t2);
    elapsedTime = (double)(t2.QuadPart - t1.QuadPart) * 1000 / frequency.QuadPart;
    cout << "Finished. array values:" << endl;
    for (int x = 0; x < 1000; ++x) {
        cout << array[x] << "\t";
    }
    cout << fixed << "\n\nTime needed for process: " << elapsedTime << " milliseconds." << endl;
    cout << t2.QuadPart << "\t" << t1.QuadPart << "\t" << t2.QuadPart - t1.QuadPart << "\tFreq: " << frequency.QuadPart << endl;
    system("pause");
    return 0;

}

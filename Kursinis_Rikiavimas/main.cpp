#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

struct Stats {
    long long comparisons = 0;
    long long swaps = 0;
};

void insertionSort(vector<int>& arr, Stats& stat) {

    for(int i = 1; i < arr.size(); i++) {

        int key = arr[i];
        int j = i - 1;

        while(j >= 0) {

            stat.comparisons++;

            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                stat.swaps++;
                j--;
            }
            else {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

int main() {

    vector<int> numbers;
    Stats stat;
    int size = 5000;

    srand(time(0));

    for(int i = 0; i < size; i++) {
        numbers.push_back(rand() % 100);
    }

    cout << "Nesurikiuotas masyvas:\n";

    for(int num : numbers) {
        cout << num << " ";
    }

    cout << endl;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(numbers,stat  );
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


    cout << "\nSurikiuotas masyvas:\n";

    for(int num : numbers) {
        cout << num << " ";
    }

    cout << endl;
    cout << "\nPalyginimai: " << stat.comparisons << endl;
    cout << "Perkelimai: " << stat.swaps << endl;
    cout << "Laikas mikrosekundemis: " << duration.count() << endl;
    return 0;
}
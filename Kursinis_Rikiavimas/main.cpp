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

void merge(vector<int>& arr, int left, int mid, int right, Stats& stat) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right) {

        stat.comparisons++;

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }

        stat.swaps++;
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
        stat.swaps++;
    }

    while(j <= right) {
        temp.push_back(arr[j]);
        j++;
        stat.swaps++;
    }

    for(int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right, Stats& stat) {

    if(left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, stat);
    mergeSort(arr, mid + 1, right, stat);

    merge(arr, left, mid, right, stat);
}

int main() {

    vector<int> numbers;
    Stats stat;

    int size = 5000;

    srand(time(0));

    for(int i = 0; i < size; i++) {
        numbers.push_back(rand() % 100);
    }

    auto start = chrono::high_resolution_clock::now();

    insertionSort(numbers, stat);

    auto end = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Palyginimai: " << stat.comparisons << endl;
    cout << "Perkelimai: " << stat.swaps << endl;
    cout << "Laikas mikrosekundemis: "
         << duration.count() << endl;

    return 0;
}
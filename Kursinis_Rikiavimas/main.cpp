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

void runTest(vector<int> data) {

    vector<int> insertionData = data;
    vector<int> mergeData = data;

    Stats insertionStat;
    Stats mergeStat;

    auto startInsertion = chrono::high_resolution_clock::now();
    insertionSort(insertionData, insertionStat);
    auto endInsertion = chrono::high_resolution_clock::now();

    auto insertionTime =
        chrono::duration_cast<chrono::microseconds>(
            endInsertion - startInsertion);

    auto startMerge = chrono::high_resolution_clock::now();
    mergeSort(mergeData, 0, mergeData.size() - 1, mergeStat);
    auto endMerge = chrono::high_resolution_clock::now();

    auto mergeTime =
        chrono::duration_cast<chrono::microseconds>(
            endMerge - startMerge);

    cout << "\nINSERTION SORT\n";
    cout << "Palyginimai: " << insertionStat.comparisons << endl;
    cout << "Perkelimai: " << insertionStat.swaps << endl;
    cout << "Laikas: " << insertionTime.count() << " mikrosek." << endl;

    cout << "\nMERGE SORT\n";
    cout << "Palyginimai: " << mergeStat.comparisons << endl;
    cout << "Perkelimai: " << mergeStat.swaps << endl;
    cout << "Laikas: " << mergeTime.count() << " mikrosek." << endl;
}

int main() {

    srand(time(0));

    vector<int> sizes = {5000, 10000, 50000};

    for(int size : sizes) {

        cout << "\n\n";
        cout << "DUOMENU KIEKIS: " << size << endl;

        vector<int> randomData;

        for(int i = 0; i < size; i++) {
            randomData.push_back(rand() % 100000);
        }

        cout << "\n RANDOM DATA \n";
        runTest(randomData);

        vector<int> sortedData;

        for(int i = 0; i < size; i++) {
            sortedData.push_back(i);
        }

        cout << "\n SORTED DATA \n";
        runTest(sortedData);

        vector<int> reversedData;

        for(int i = size; i > 0; i--) {
            reversedData.push_back(i);
        }

        cout << "\nREVERSED DATA \n";
        runTest(reversedData);
    }

    return 0;
}
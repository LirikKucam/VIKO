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

vector<int> generateRandomData(int size) {

    vector<int> data;

    for(int i = 0; i < size; i++) {
        data.push_back(rand() % 100000);
    }

    return data;
}

vector<int> generateSortedData(int size) {

    vector<int> data;

    for(int i = 0; i < size; i++) {
        data.push_back(i);
    }

    return data;
}

vector<int> generateReversedData(int size) {

    vector<int> data;

    for(int i = size; i > 0; i--) {
        data.push_back(i);
    }

    return data;
}

void runTest(vector<int> data) {

    const int repeats = 5;

    long long insertionTimeSum = 0;
    long long insertionComparisonsSum = 0;
    long long insertionSwapsSum = 0;

    long long mergeTimeSum = 0;
    long long mergeComparisonsSum = 0;
    long long mergeSwapsSum = 0;

    for(int i = 0; i < repeats; i++) {

        vector<int> insertionData = data;
        Stats insertionStat;

        auto startInsertion = chrono::high_resolution_clock::now();

        insertionSort(insertionData, insertionStat);

        auto endInsertion = chrono::high_resolution_clock::now();

        auto insertionTime =
            chrono::duration_cast<chrono::microseconds>(
                endInsertion - startInsertion);

        insertionTimeSum += insertionTime.count();
        insertionComparisonsSum += insertionStat.comparisons;
        insertionSwapsSum += insertionStat.swaps;

        vector<int> mergeData = data;
        Stats mergeStat;

        auto startMerge = chrono::high_resolution_clock::now();

        mergeSort(mergeData, 0, mergeData.size() - 1, mergeStat);

        auto endMerge = chrono::high_resolution_clock::now();

        auto mergeTime =
            chrono::duration_cast<chrono::microseconds>(
                endMerge - startMerge);

        mergeTimeSum += mergeTime.count();
        mergeComparisonsSum += mergeStat.comparisons;
        mergeSwapsSum += mergeStat.swaps;
    }

    cout << "\nINSERTION SORT" << endl;
    cout << "Palyginimai: "
         << insertionComparisonsSum / repeats << endl;
    cout << "Perkelimai: "
         << insertionSwapsSum / repeats << endl;
    cout << "Laikas: "
         << insertionTimeSum / repeats
         << " mikrosek." << endl;

    cout << "\nMERGE SORT" << endl;
    cout << "Palyginimai: "
         << mergeComparisonsSum / repeats << endl;
    cout << "Perkelimai: "
         << mergeSwapsSum / repeats << endl;
    cout << "Laikas: "
         << mergeTimeSum / repeats
         << " mikrosek." << endl;
}

int main() {

    srand(time(0));

    vector<int> sizes = {5000, 10000, 50000};

    for(int size : sizes) {

        cout << "\nDUOMENU KIEKIS: "
             << size << endl;

        cout << "\nRANDOM DATA" << endl;
        runTest(generateRandomData(size));

        cout << "\nSORTED DATA" << endl;
        runTest(generateSortedData(size));

        cout << "\nREVERSED DATA" << endl;
        runTest(generateReversedData(size));
    }

    return 0;
}
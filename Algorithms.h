/*
 * FCAI - Data Structure
 * Author: Sara Tamer Mohamed Bihery - 20210155
 * Program: Sorting Algorithms
 * Date: 19/3/2023
 *
 */
#ifndef SORTING_ALGORITHMS_ALGORITHMS_H
#define SORTING_ALGORITHMS_ALGORITHMS_H

using namespace std;

#define ll long long

namespace sortlib {
    template<class T>
    class SortingAlgorithms {
    private:
        T *ans;
        int size;
    public:
        SortingAlgorithms() { size = 0; }

        void insertionSort(T arr[], ll n);

        void selectionSort(T *arr, ll n);

        void bubbleSort(T arr[], ll n);

        void countSort(T arr[], ll n);

        void merge(T *arr, ll l, ll m, ll r);

        void mergeSort(T *arr, ll l, ll r);

        ll partitioning(T *arr, ll l, ll r);

        void quickSort(T *arr, ll l, ll r);

        void shellSort(T *arr, ll n);

        void printArray(T *arr, ll n);
    };

}
#endif //SORTING_ALGORITHMS_ALGORITHMS_H

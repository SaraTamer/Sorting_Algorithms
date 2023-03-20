/*
 * FCAI - Data Structure
 * Author: Sara Tamer Mohamed Bihery - 20210155
 * Program: Sorting Algorithms
 * Date: 19/3/2023
 *
 */
#include "Algorithms.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace sortlib;

template <class T>
void SortingAlgorithms<T>::insertionSort(T arr[] , ll n)
{
    for (ll i = 1; i < n; ++i)
    {
        ll key = arr[i];
        ll j = i-1;
        for(; j >= 0; j--)
        {
            if(key < arr[j])
            {
                arr[j+1] = arr[j];
            }
            else
                break;
        }
        arr[j+1] = key;
    }
}
template <class T>
void SortingAlgorithms<T>::selectionSort(T* arr , ll n)
{
    ll mnm;
    for(ll i = 0 ; i < n - 1; i++)
    {
        mnm = i;
        for (ll j = i + 1 ; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                mnm = j;
                swap(arr[i] , arr[mnm]);
            }
        }
    }
}
template <class T>
void SortingAlgorithms<T>::bubbleSort(T arr[] , ll n)
{
    bool flag = false;
    for(ll i = 0 ; i < n; i++)
    {
        for(ll j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                flag = true;
            }
        }
        if(!flag){
            cout << "The data is sorted!\n";
            break;
        }
    }
}
template <class T>
void SortingAlgorithms<T>::countSort(T arr[] , ll n)
{
    vector<T> comFreq(100000);
    for(ll i = 0; i < n; i++)
    {
        comFreq[arr[i]]++;
    }
    for(ll i = 1 ; i < comFreq.size(); i++)
    {
        comFreq[i] += comFreq[i-1];
    }
    T ansArr[n];

    for(ll i = n - 1; i >= 0; i--)
    {
        ansArr[comFreq[arr[i]]-1] = arr[i];
    }
    for(ll i = 0; i < n; i++)
    {
        arr[i] = ansArr[i];
    }
}
template <class T>
void SortingAlgorithms<T>::merge(T* arr , ll l, ll m, ll r)
{
    ll sz1 = m - l + 1;
    ll sz2 = r - m;

    T* leftSub = new T[sz1];
    T* rightSub = new T[sz2];

    for(ll i = 0; i < sz1; i++)
    {
        leftSub[i] = arr[l + i];
    }
    for(ll i = 0; i < sz2; i++)
    {
        rightSub[i] = arr[m + 1 + i];
    }
    ll k = l;
    while(sz1 && sz2)
    {
        if(leftSub[0] <= rightSub[0])
        {
            arr[k] = leftSub[0];
            leftSub++;
            sz1--;
        }
        else
        {
            arr[k] = rightSub[0];
            rightSub++;
            sz2--;
        }
        k++;
    }
    while(sz1)
    {
        arr[k] = leftSub[0];
        leftSub++;
        sz1--;
        k++;
    }
    while(sz2)
    {
        arr[k] = rightSub[0];
        rightSub++;
        sz2--;
        k++;
    }
}
template <class T>
void SortingAlgorithms<T>:: mergeSort(T* arr, ll l, ll r)
{
    if(l >= r)
        return;

    ll m = (l + r) / 2;

    mergeSort(arr , l , m);
    mergeSort(arr , m + 1 , r);

    merge(arr , l , m , r);

}
template <class T>
ll SortingAlgorithms<T>::partitioning(T* arr , ll l, ll r)
{
    ll i = l + 1;
    ll j = l + 1;
    ll pivot = l;
    while(j <= r)
    {
        if(arr[j] < arr[pivot])
        {
            swap(arr[j] , arr[i]);
            if(i <= r)
                i++;
        }
        j++;
    }
    if(pivot != i - 1) {
        swap(arr[pivot] , arr[i-1]);
        pivot = i ;
        return pivot;
    }
    else
    {
        return pivot + 1;
    }
}
template <class T>
void SortingAlgorithms<T>::quickSort(T *arr, ll l, ll r)
{
    if(l >= r)
    {
        return;
    }
    ll pivot = partitioning(arr , l , r);
    quickSort(arr , l , pivot - 1);
    quickSort(arr , pivot, r);
}
template <class T>
void SortingAlgorithms<T>::shellSort(T *arr, ll n)
{
    for(ll gap = n/2 ; gap > 0; gap /= 2)
    {
        for (ll i = gap; i < n; ++i)
        {
            ll j = i;
            for(; j >= gap; j -= gap)
            {
                if(arr[j-gap] > arr[j])
                {
                    swap(arr[j-gap] , arr[j]);
                }
            }
        }
    }
}
template <class T>
void SortingAlgorithms<T>::printArray(T* arr , ll n)
{
    for(ll i = 0 ; i < n; i++)
    {
        cout << arr[i] << ' ' ;
    }
    cout << '\n';
}


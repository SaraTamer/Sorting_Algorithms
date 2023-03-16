#include <iostream>
#include <vector>
using namespace std;

#define ll long long

namespace sortlib{
    template <class T>
    class SortingAlgorithms{
    private:
        T* ans;
        int size;
    public:
        SortingAlgorithms() {size = 0;}

        void insertionSort(T arr[] , ll n);
        void selectionSort(T* arr , ll n);
        void bubbleSort(T arr[] , ll n);
        void countSort(T arr[] , ll n);
        void merge(T* arr , ll l, ll m, ll r);
        void mergeSort(T* arr, ll l, ll r);

        void printArray(T* arr , ll n);
    };

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
                }
                swap(arr[i] , arr[mnm]);
            }
        }
    }
    template <class T>
    void SortingAlgorithms<T>::bubbleSort(T arr[] , ll n)
    {
        bool flag = false;
        for(ll i = 0 ; i < n; i++)
        {
            for(ll j = 0; j < n - i; j++)
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
        vector<T> comFreq(100);
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
        delete[] leftSub;
        delete[] rightSub;
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
    void SortingAlgorithms<T>::printArray(T* arr , ll n)
    {
        for(ll i = 0 ; i < n; i++)
        {
            cout << arr[i] << ' ' ;
        }
        cout << '\n';
    }
}

int main() {
    sortlib::SortingAlgorithms<int> insert;
    int array[7] = {4,3,1,8,5,7,2};
//    insert.insertionSort(array , 7);
//    insert.selectionSort(array , 7);
//    insert.bubbleSort(array , 7);
//    insert.countSort(array, 7);
//    insert.mergeSort(array , 0 , 6);
    insert.printArray(array , 7);

    return 0;
}

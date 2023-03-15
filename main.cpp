#include <iostream>
#include <vector>
using namespace std;

namespace sortlib{
    template <class T>
    class SortingAlgorithms{
    private:
        T* ans;
        int size;
    public:
        SortingAlgorithms() {size = 0;}
        void insertionSort(T arr[] , int n)
        {
            for (int i = 1; i < n; ++i)
            {
                int key = arr[i];
                int j = i-1;
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
        void selectionSort(T* arr , int n)
        {
            int mnm;
            for(int i = 0 ; i < n - 1; i++)
            {
                mnm = i;
                for (int j = i + 1 ; j < n; j++)
                {
                    if(arr[i] > arr[j])
                    {
                        mnm = j;
                    }
                    swap(arr[i] , arr[mnm]);
                }
            }
        }
        void bubbleSort(T arr[] , int n)
        {
            bool flag = false;
            for(int i = 0 ; i < n; i++)
            {
                for(int j = 0; j < n - i; j++)
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
        void countSort(T arr[] , int n)
        {
            vector<T> comFreq(100);
            for(int i = 0; i < n; i++)
            {
                comFreq[arr[i]]++;
            }
            for(int i = 1 ; i < comFreq.size(); i++)
            {
                comFreq[i] += comFreq[i-1];
            }
            T ansArr[n];

            for(int i = n - 1; i >= 0; i--)
            {
                ansArr[comFreq[arr[i]]-1] = arr[i];
            }
            for(int i = 0; i < n; i++)
            {
                arr[i] = ansArr[i];
            }
        }
        void printArray(T* arr , int n)
        {
            for(int i = 0 ; i < n; i++)
            {
                cout << arr[i] << ' ' ;
            }
            cout << '\n';
        }
    };

}

int main() {
    sortlib::SortingAlgorithms<int> insert;
    int array[7] = {4,3,1,8,5,7,2};
//    insert.insertionSort(array , 7);
//    insert.selectionSort(array , 7);
//    insert.bubbleSort(array , 7);
//    insert.countSort(array, 7);

    return 0;
}

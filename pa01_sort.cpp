#include <iostream>

using namespace std;

int cnt = 0;

template<class T>
void printAll(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;;
    }
}

template<class T>
void printAll_debug(T arr[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << " ]" << endl;
}

template<class T>
void copy_arr(T src[], T tar[], int size)
{
    for(int i = 0; i < size; i++)
    {
        tar[i] = src[i];
    }
}

template<class T>
int insertionSort(T arr[], const int size, int k)
{
    int i, j, k_cnt = 0;
    T key;

    for (j = 1; j <= k; j++)
    {
        key = arr[j];
        i = j - 1;
        
        while (i >= 0 && ++k_cnt && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = key;
    }
    return k_cnt;
}

template<class T>
void selectionSort(T arr[], const int size, int k)
{
    int i, j, smallest_idx;
    T smallest;

    for (i = 0; i < size; i++)
    {
        smallest = arr[i];
        smallest_idx = i;

        for (j = i + 1; j < size; j++)
        {
            if (smallest > arr[j])
            {
                smallest = arr[j];
                smallest_idx = j;
            }
        }
        if(smallest_idx != i) swap(arr[smallest_idx], arr[i]);

        if(i == k - 1)
            printAll(arr, size);
    }
}

template<class T>
void adjust_heap(T arr[], const int size, const int root)
{
    T e = arr[root - 1];
    int j;
    for(j = 2*root; j <= size; j = 2 * j)
    {
        if(j < size && arr[j - 1] > arr[j]) j++;
        if(e <= arr[j - 1]) break;
        arr[j / 2 - 1] = arr[j - 1];
    }
    arr[j / 2 - 1] = e;
}

template<class T>
void heapSort(T arr[], const int size, int k)
{
    int cnt = 0;
    for(int i = size / 2; i >= 1 ; i--)
        adjust_heap(arr, size, i);

    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        adjust_heap(arr, i, 1);

        if(k == cnt + 1)
        {
           for (int i = 0; i <= size - k - cnt; i++)
           {
                cout << arr[i] << endl;
           }
        }
        cnt++;
    }
}

template <class T>
int partition(T arr[], int low, int high)
{
    int left, right;
    left = low + 1;
    right = high;
    T pivot_item = arr[low];

    while (left <= right)
    {
        while (arr[left] < pivot_item) left++;
        while (arr[right] > pivot_item) right--;

        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else
        {
            break;
        }
    }
    swap(arr[low], arr[right]);

    return right;
}

template<class T>
T* quickSort(T arr[], T answer[], int low, int high, int size, const int arr_k, int k, T pivot_arr[])
{
    T pivot = low;

    //cout << cnt << "'s\t pivot : " << pivot << "\t arr[pivot] : " << arr[pivot] << "\t";
    pivot_arr[cnt] = arr[pivot];
    //printAll_debug(arr, size);
    //cout << "\t\t\t\t\t\t";
    //printAll_debug(pivot_arr, size);
    
    if (cnt <= k) copy_arr(arr, answer, size);


    if (high > low)
    {
        pivot = partition(arr, low, high);
        cnt++;

        answer = quickSort(arr, answer, low, pivot - 1, size, arr_k, k, pivot_arr);
        answer = quickSort(arr, answer, pivot + 1, high, size, arr_k, k, pivot_arr);

    }
    return answer;
}

int main()
{

    int selectSort;
    int k;
    int size;

    int out;

    cin >> selectSort >> k;
    cin >> size;

    int *arr = new int[size];
    int *answer = new int[size];
    int *pivot_arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        answer[i] = 0;
    }

    switch (selectSort)
    {
    case 1:
        out = insertionSort(arr, size, k);
        cout << out;
        break;
    
    case 2:
        selectionSort(arr, size, k);
        break;

    case 3:
        heapSort(arr, size, k);
        break;
    
    case 4:
        answer = quickSort(arr, answer, 0, size - 1, size, arr[k - 1], k, pivot_arr);
        //cout << "-----" << endl;
        //printAll(arr, size);
        //cout << "-----" << endl;
        printAll(answer, size);
        break;
    }
    delete[] arr;
    delete[] answer;

    return 0;
}
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

const int ARR_SIZE = 10;
const int BIG_SIZE = 1000;

//task 1 functions

template <typename T, typename T2> //show array
void showArr(T arr[], T2 size)
{
    for (T2 i = 0; i < size; i++)
        cout << arr[i] << endl;
    cout << endl;
}
void sortArr(long long arr[], int); //sort array
void menu(long long* arr, long long* arr2, int size); // menu for show and sort arrays

//task 2, 4 function
template<typename T1, typename T2>
T2 sortTask2(T1* arr, T2);

int sortTask4(int* arr, int);

//task 3 function
void sortTask3(double* arr, int start, int size);

//task 4 functions

void makingArray(int* arr, int size);

int main()
{
    setlocale(LC_ALL, "");
    //task 1
    long long mobArr[ARR_SIZE]
    {
        89214574356,
        89923419873,
        89349832137,
        89315679873,
        89815438765,
        89115439876,
        89113459832,
        89215679876,
        89215692387,
        89113874562
    };
    long long homeArr[ARR_SIZE]
    {
        658205,
        234512,
        210098,
        239853,
        290989,
        285808,
        275891,
        534891,
        285476,
        295431
    };

    menu(mobArr, homeArr, ARR_SIZE);

    //task 2
    sortTask2(mobArr, ARR_SIZE);

    //task 3
    
    int ol;
    double radOl[ARR_SIZE]
    {
        13.2, 10.1, 12.4, 13.2, 11.9, 10.1, 13.4, 12.5, 13.1, 10.4
    };
    cout << "Под какую оладью вставим лопатку?\n";
    cin >> ol;
    ol--;
    sortTask3(radOl, ol, ARR_SIZE);
    showArr(radOl, ARR_SIZE);
    
    
    //task 4
    
    int task_two_sort = 0;
    int task_four_sort = 0;
    //создаем 10 массивов с рандомными номерами от 0 до 1000
    for (int i = 0; i < 10; i++)
    {
        int* arr1 = new int[BIG_SIZE];
        int* arr2 = new int[BIG_SIZE];
        makingArray(arr1, BIG_SIZE);
        makingArray(arr2, BIG_SIZE);
        task_two_sort += sortTask2(arr1, BIG_SIZE);
        task_four_sort += sortTask4(arr2, BIG_SIZE);
        delete[] arr1;
        delete[] arr2;
    }
    cout << "Среднее количество перестановок усовершенствованным методом пузырька из второго задания: " << (double)task_two_sort / 10 << endl;
    cout << "Среднее количество перестановок методом выбора: " << (double)task_four_sort / 10 << endl;
}

//task 1 functions

void sortArr(long long arr[], int size)
{
    long long temp;
    int j, i;
    for (i = 0; i < size-1; i++)
    {
        for (j = 0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void menu(long long* arrMob, long long* arrHome, int size)
{
    int choise;
    do 
    {
        cout << "Menu:\n\n";
        cout << "1. Show mobile phones\n";
        cout << "2. Show home phones\n";
        cout << "3. Sort mobile phones\n";
        cout << "4. Sort home phones\n";
        cout << "-1. Exit\n";
        cin >> choise;
        system("CLS");
        switch (choise)
        {
        case 1:
            showArr(arrMob, size);
            break;
        case 2:
            showArr(arrHome, size);
            break;
        case 3:
            sortArr(arrMob, size);
        case 4:
            sortArr(arrHome, size);
        default:
            break;
        }
    } while (choise != -1);
    
}

//task 2, 4 functions
template<typename T1, typename T2>
T2 sortTask2(T1* arr, T2 size)
{
    T1 temp;
    int j, i, count;
    for (i = 0; i < size - 1; i++)
    {
        count = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
            
        }
        if (count == 0)
        {
            cout << "Sorting stoped at " << i << " step!\n";
            return i;
        }
    }
}

int sortTask4(int* arr, int size)
{
    int i, j, k, count = 0;
    int x;

    for (i = 0; i < size; i++)
    {
        k = i;
        x = arr[i];
        for (j = i + 1; j < size; j++) 
        {
            if (arr[j] < x) 
            {
                k = j; // k - индекс наименьшего элемента
                x = arr[j];
            }
        }
        if (k != i) 
        {
            arr[k] = arr[i];
            arr[i] = x;
            count++;
        }
    }
    return count;
}

//task 3 functions
void sortTask3(double* arr, int start, int size)
{
    double temp;
    int i, j;
    for (i = start; i < size - 1; i++)
    {
        for (j = start; j < size - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void makingArray(int* arr, int size)
{
    srand(time(NULL));
    Sleep(1500); // задержка чтобы значение в массивах отличались
    for (int i = 0; i < BIG_SIZE; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

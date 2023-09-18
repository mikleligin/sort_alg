#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
using namespace std;
const int range_of_numbers = 100000;
int GetRandom(int min, int max)
{
    //srand(time(NULL));
    return min + rand() % (max - min + 1);
}
ofstream out;
void arr_out(int a[])
{
    
    out.open("out.txt", ios_base::out);
    clock_t start = clock();
    cout << "Time!" << endl;
    for (size_t i = 0; i < range_of_numbers; i++)
    {
        cout << a[i] << ", ";
        out << a[i]<<",";
    }
    out << '\n';
    cout << endl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    out << "The time: " << seconds;
}
int bouble(int a[])
{
    cout << "Bouble" << endl;
    for (size_t i = 0; i < range_of_numbers; i++)
    {
        for (size_t j = 0; j < range_of_numbers - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    arr_out(a);
    return 0;
}
int DraftSort(int a[])
{
    cout << "DraftSort" << endl;
    for (size_t i = 0; i < range_of_numbers; i++)
    {
       if(i<range_of_numbers)
       {    
           for (size_t j = 0; j < range_of_numbers; j++)
           {
               if (a[i + 1] < a[i])
               {
                   swap(a[i + 1], a[i]);
                   i = i - 1;
               }
           }
       }
    }
    arr_out(a);
    return 0;
}
int fastSort(int a[])
{
    cout << "fastSort" << endl;
    int b[100000]{};
    for (size_t i = 0; i < range_of_numbers; i++)
    {
        b[i] = 0;
    }
    for (size_t i = 0; i < range_of_numbers; i++)
    {
        b[a[i]]++;
        
    }
    int count = 0;
    int i = 0;

    for (size_t i = 0; i < range_of_numbers+1; i++)
    {
        for (size_t j = 0; j < b[i]; j++)
        {
            a[count] = i;
            count++;
        }
    }
   arr_out(a);
   return 0;
}
int qsortRecursive(int mas[], int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];
    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
    arr_out(mas);
    return 0;
}
typedef int(*func) (int[]);
int main()
{
    clock_t start = clock();
    func mass[4]{ bouble, DraftSort, fastSort };
    SetConsoleOutputCP(1251);
    int a[100000]{};
    cout << "[";
    for (size_t i = 0; i < range_of_numbers; i++)
    {
        a[i] = GetRandom(0, range_of_numbers);
        //cout << a[i] << ", ";
    }
    
    double time = 0 ;
    cout << "]" << '\n';
    for (size_t i = 0; i < 3; i++)
    {
        mass[i](a);
    }
    out.close();
}
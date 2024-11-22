#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int array[15];
    for (int i = 0; i < 15; ++i) 
    {
        array[i] = rand() % 41 - 20;
    }
    cout << "Початковий масив: ";
    for (int i = 0; i < 15; ++i) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < 15; ++i) 
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] < key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
    cout << "Відсортований масив (за спаданням): ";
    for (int i = 0; i < 15; ++i) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
    int target;
    cout << "Введіть значення для пошуку: ";
    cin >> target;
    int left = 0, right = 14;
    int firstIndex = -1, lastIndex = -1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            firstIndex = mid;
            right = mid - 1;
        }
        else if (array[mid] < target)
        {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    left = 0, right = 14;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) 
        {
            lastIndex = mid;
            left = mid + 1;
        }
        else if (array[mid] < target) 
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    if (firstIndex == -1) 
    {
        cout << "Число " << target << " відсутнє у масиві" << endl;
    }
    else 
    {
        cout << "Індекси числа " << target << ": ";
        for (int i = firstIndex; i <= lastIndex; ++i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

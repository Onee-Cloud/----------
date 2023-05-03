#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <list>

using namespace std;

/*
    Завдання:
    Структури даних: масив, список, черга, стек.
    6.1. Створення структури даних у пам'яті та видалення;
    6.2. Додавання елемента до структури даних;
    6.3. Вилучення елемента зі структури даних;
    6.4. Заміна елемента в структурі даних;
    6.5. Впорядкування елементів масиву та списку;
    6.6. Пошук елемента в структурі даних за заданим критерієм (найбільший, найменший, перший парний
         або непарний, перший додатний або від`ємний, знайти всі рівні заданому)
*/


// Масив
class Array
{
private:
    int* arr; // вказівник на початок масиву
    int size; // розмір масиву
    string path = "data.txt";

public:

    // Метод створення
    void create() 
    {
        arr = nullptr;
        size = 0;
    }

    // Метод видалення
    void destroy() 
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }

    // Метод для заповнення динамічного масиву довільними числами з файлу
    void fillFromFile() 
    {
        ifstream file(path);

        int num;
        int index = 0;

        // Зчитування чисел з файлу та визначення розміру масиву
        while (file >> num) 
        {
            ++size;
        }

        // Створення динамічного масиву
        arr = new int[size];

        // Перехід на початок файлу
        file.clear();
        file.seekg(0, ios::beg);

        // Заповнення масиву числами з файлу
        while (file >> num) 
        {
            arr[index++] = num;
        }

        // Закриття файлу
        file.close();
    }

    // Метод додавання елементу в масив
    void addElement(int value)
    {

        int* bufferArr = new int[size + 1];

        for (int i = 0; i < size; i++) 
        {
            bufferArr[i] = arr[i];
        }

        bufferArr[size] = value;
        size++;
        delete[] arr;
        arr = bufferArr;

        recordInFile();
    }

    // Метод видалення елемента з масива за індексом
    void removeElement(int index)
    {
        int* bufferArr = new int[size - 1];
        int j = 0;

        for (int i = 0; i < size; i++) 
        {
            if (index != i)
            {
                bufferArr[j] = arr[i];
                j++;
            }
        }

        size--;
        delete[] arr;
        arr = bufferArr;

        recordInFile();
    }

    // Метод заміни значення елемента в масиві
    void replace(int index, int value) 
    {
        if (index < 0 || index >= size) 
        {
            return;
        }
        arr[index] = value;

        recordInFile();
    }

    // Метод сортування масиву
    void sortArray() 
    {
        sort(arr, arr + size);
        recordInFile();
    }

    // Метод пошуку максимального елементу
    void searchMax()
    {
        int maxElement = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (maxElement < arr[i])
            {
                maxElement = arr[i];
            }
        }
        cout << "Max element: " << maxElement << endl;
    }

    // Метод пошуку мінімального елементу
    void searchMin()
    {
        int minElement = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (minElement > arr[i])
            {
                minElement = arr[i];
            }
        }
        cout << "Min element: " << minElement << endl;
    }

    // Метод пошуку першого парного елементу
    void searchFirstPair()
    {
        int index, value;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
            {
                index = i;
                value = arr[i];
                break;
            }
        }
        cout << "Index first pair element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку першого не парного елементу
    void searchFirstOdd()
    {
        int index, value;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 1)
            {
                index = i;
                value = arr[i];
                break;
            }
        }
        cout << "Index first odd element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку першого додатьного елементу
    void searchFirstPositive()
    {
        int index, value;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] >= 0)
            {
                index = i;
                value = arr[i];
                break;
            }
        }
        cout << "Index first positive element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку першого відємного елементу
    void searchFirstNegative()
    {
        int index, value;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0)
            {
                index = i;
                value = arr[i];
                break;
            }
        }
        cout << "Index first negative element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку всіх рівних елементів заданому
    void searchAllEqual(int x)
    {
        int j = 0;
        int index[size];
        int value[size];

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                index[j] = i;
                value[j] = arr[i];
                j++;
            }
        }

        cout << setw (5) << "Index";
        cout << setw (10) << "Value" << endl;
        
        for (int i = 0; i < j; i++)
        {
            cout << setw (5) << index[i];
            cout << setw (10) << value[i] << endl;
        }
        
    }

    // Метод запису масиву в файл
    void recordInFile()
    {
        ofstream file(path);

        file.clear();

        for (int i = 0; i < size; i++) {
            file << arr[i] << " ";
        }
        file.close();
    }

    // Метод для виведення масиву на екран
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Список
class List
{
private:
    list<int> myList;
    string path = "data.txt";
public:

    // Метод заповнення списку з файлу
    void fillFromFile() 
    {
        ifstream file(path);
        int num;
        while (file >> num) {
            myList.push_back(num);
        }
        file.close();
    }

    // Метод очищення списку
    void deleteList()
     {
        myList.clear();
    }

    // Метод додавання елементу в список
    void addElement(int value)
    {
        myList.push_back(value);
        recordInFile();
    }

    // Метод видалення елементу з списку
    void deleteElement(int index)
    {
        if (index < 0 || index >= myList.size()) {
            return;
        }

        auto x = myList.begin();
        advance(x, index);
        myList.erase(x);

        recordInFile();
    }

    // метод заміни елемента списку за індексом
    void changeElement(int index, int value)
    {
        if (index < 0 || index >= myList.size()) {
            return;
        }
        auto x = myList.begin();
        advance(x, index);
        *x = value;

        recordInFile();
    }

    // Метод сортування списку
    void sortList()
    {
        myList.sort();
        recordInFile();
    }

    // Метод пошуку максимального елементу
    void searchMax()
    {
        int maxElement = myList.front();

        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x > maxElement) 
            { 
                maxElement = *x;
            }
        }
        cout << "Max element: " << maxElement << endl;
    }

    // Метод пошуку мінімального елементу
    void searchMin()
    {
        int minElement = myList.front();

        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x < minElement) 
            { 
                minElement = *x;
            }
        }

        cout << "Min element: " << minElement << endl;
    }

    // Метод пошуку першого парного елементу
    void searchFirstPair()
    {
        int index, value;

        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x % 2 == 0) 
            { 
                index = distance(myList.begin(), x);
                value = *x;
                break;
            }
        }

        cout << "Index first pair element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку першого не парного елементу
    void searchFirstOdd()
    {
        int index, value;

        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x % 2 != 0) 
            { 
                index = distance(myList.begin(), x);
                value = *x;
                break;
            }
        }

        cout << "Index first odd element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку першого додатьного елементу
    void searchFirstPositive()
    {
        int index, value;

        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x >= 0) 
            { 
                index = distance(myList.begin(), x);
                value = *x;
                break;
            }
        }

        cout << "Index first positive element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку першого відємного елементу
    void searchFirstNegative()
    {
        int index, value;

        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x < 0) 
            { 
                index = distance(myList.begin(), x);
                value = *x;
                break;
            }
        }

        cout << "Index first negative element - " << index << ". Value - " << value << endl;
    }

    // Метод пошуку всіх рівних елементів заданому
    void searchAllEqual(int k)
    {
        int j = 0;
        int index[myList.size()];
        int value[myList.size()];
        
        for (auto x = myList.begin(); x != myList.end(); x++) 
        {
            if (*x == k) 
            { 
                index[j] = distance(myList.begin(), x);
                value[j] = *x;
                j++;
            }
        }

        cout << setw (5) << "Index";
        cout << setw (10) << "Value" << endl;
        
        for (int i = 0; i < j; i++)
        {
            cout << setw (5) << index[i];
            cout << setw (10) << value[i] << endl;
        }
        
    }

    // Метод запису даних в файл
    void recordInFile()
    {
        ofstream file(path);

        file.clear();

        for (auto x = myList.begin(); x != myList.end(); ++x) {
            file << *x << " ";
        }

        file.close();
    }

    // Метод виведення списку в консоль
    void print()
    {
        for (auto it = myList.begin(); it != myList.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

};

// Черга
class Queue
{
private:
public:

};

// Стек

// Меню для робоит зі структурами
void printConsoleMenu()
{  
    system("cls");
    cout << "1. Array" << endl;
    cout << "2. List" << endl;
    cout << "3. Queue" << endl;
    cout << "4. Stack" << endl;
    cout << ">>> ";
}

void printConsoleMenuForStructures() 
{
    system("cls");
    cout << "1. Create or destroy" << endl;
    cout << "2. Add element" << endl;
    cout << "3. Delete element" << endl;
    cout << "4. Change element" << endl;
    cout << "5. Sort array or list" << endl;
    cout << "6. Search element" << endl;
    cout << "7. Back" << endl;
    cout << ">>> ";
}

int get_variant(int count) 
{
    int variant;
    cin >> variant;
    while (variant < 1 || variant > count) {
        cout << "Input correct number of operation: ";
        cin >> variant;
    }
    return variant;
}

void workingWithArrayMenu()
{
    Array test;

    int variant, value, index;

    do {
        
    printConsoleMenuForStructures();

    variant = get_variant(7);

    switch (variant) {
        case 1:
            cout << "1. Create array \n2. Delete array \n>>>";
            cin >> value;
            if (value == 1)
            {
                test.create();
                test.fillFromFile();
                test.print();
            }
            if (value == 2)
            {
                test.destroy();
                test.print();
            }
            break;
        case 2: 
            cout << "Input value: ";
            cin >> value;

            test.addElement(value);
            test.print();
            break;
        case 3:

            cout << "Input index: ";
            cin >> index;

            test.removeElement(index);
            test.print();
            break;
        case 4:
            cout << "Input index: ";
            cin >> index;
            cout << "Input value: ";
            cin >> value;

            test.replace(index, value);
            test.print();
            break;
        case 5:
            test.sortArray();
            test.print();
            break;
        case 6:
            test.searchMin();
            test.searchMax();
            test.searchFirstPair();
            test.searchFirstOdd();
            test.searchFirstPositive();
            test.searchFirstNegative();
            
            cout << "Input value: ";
            cin >> value;
            
            test.searchAllEqual(value);
            break;
        }
        if (variant != 7)
            system("pause");
    } while (variant != 7);

}

void workingWithListMenu()
{
    List test;

    int variant, value, index;

    do {
        
    printConsoleMenuForStructures();

    variant = get_variant(7);

    switch (variant) {
        case 1:
            cout << "1. Create array \n2. Delete array \n>>>";
            cin >> value;
            if (value == 1)
            {
                test.fillFromFile();
                test.print();
            }
            if (value == 2)
            {
                test.deleteList();
                test.print();
            }
            break;
        case 2: 
            cout << "Input value: ";
            cin >> value;

            test.addElement(value);
            test.print();
            break;
        case 3:

            cout << "Input index: ";
            cin >> index;

            test.deleteElement(index);
            test.print();
            break;
        case 4:
            cout << "Input index: ";
            cin >> index;
            cout << "Input value: ";
            cin >> value;

            test.changeElement(index, value);
            test.print();
            break;
        case 5:
            test.sortList();
            test.print();
            break;
        case 6:
            test.searchMin();
            test.searchMax();
            test.searchFirstPair();
            test.searchFirstOdd();
            test.searchFirstPositive();
            test.searchFirstNegative();
            
            cout << "Input value: ";
            cin >> value;
            
            test.searchAllEqual(value);
            break;
        }
        if (variant != 7)
            system("pause");
    } while (variant != 7);

}

/*
void workingWithQueueMenu()
{
    Array test;

    int variant, value, index;

    do {
        
    printConsoleMenuForStructures();

    variant = get_variant(7);

    switch (variant) {
        case 1:
            cout << "1. Create array \n2. Delete array \n>>>";
            cin >> value;
            if (value == 1)
            {
                test.Create();
                test.fillFromFile();
                test.print();
            }
            if (value == 2)
            {
                test.destroy();
                test.print();
            }
            break;
        case 2: 
            cout << "Input value: ";
            cin >> value;

            test.addElement(value);
            test.print();
            break;
        case 3:

            cout << "Input index: ";
            cin >> index;

            test.removeElement(index);
            test.print();
            break;
        case 4:
            cout << "Input index: ";
            cin >> index;
            cout << "Input value: ";
            cin >> value;

            test.replace(index, value);
            test.print();
            break;
        case 5:
            test.sortArray();
            test.print();
            break;
        case 6:
            test.searchMin();
            test.searchMax();
            test.searchFirstPair();
            test.searchFirstOdd();
            test.searchFirstPositive();
            test.searchFirstNegative();
            
            cout << "Input value: ";
            cin >> value;
            
            test.searchAllEqual(value);
            break;
        }
        if (variant != 7)
            system("pause");
    } while (variant != 7);

}

void workingWithStackMenu()
{
    Array test;

    int variant, value, index;

    do {
        
    printConsoleMenuForStructures();

    variant = get_variant(7);

    switch (variant) {
        case 1:
            cout << "1. Create array \n2. Delete array \n>>>";
            cin >> value;
            if (value == 1)
            {
                test.Create();
                test.fillFromFile();
                test.print();
            }
            if (value == 2)
            {
                test.destroy();
                test.print();
            }
            break;
        case 2: 
            cout << "Input value: ";
            cin >> value;

            test.addElement(value);
            test.print();
            break;
        case 3:

            cout << "Input index: ";
            cin >> index;

            test.removeElement(index);
            test.print();
            break;
        case 4:
            cout << "Input index: ";
            cin >> index;
            cout << "Input value: ";
            cin >> value;

            test.replace(index, value);
            test.print();
            break;
        case 5:
            test.sortArray();
            test.print();
            break;
        case 6:
            test.searchMin();
            test.searchMax();
            test.searchFirstPair();
            test.searchFirstOdd();
            test.searchFirstPositive();
            test.searchFirstNegative();
            
            cout << "Input value: ";
            cin >> value;
            
            test.searchAllEqual(value);
            break;
        }
        if (variant != 7)
            system("pause");
    } while (variant != 7);

}
*/
int main()
{
    int variant;
    do {
        
    printConsoleMenu();

    variant = get_variant(5);

    switch (variant) {
        case 1:
            workingWithArrayMenu();
            break;
        case 2:
            workingWithListMenu();
            break;
        case 3:
            //workingWithQueueMenu();
            break;
        case 4:
            //workingWithStackMenu();
            break;
        }
        if (variant != 5)
            system("pause");
    } while (variant != 5);
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student
{
    string name;
    string surname;
    string group;
    string birthday;
    string phoneNumber;
};

class Test
{
private:

    Student *arr;
    int size;
    string path = "data.txt";

public:

    // Метод створення таблиці
    void create()
    {
        arr = nullptr;
        size = 0;
    }

    // Метод видалення таблиці
    void destroy()
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }

    // Метод запису даних в тадблицю
    void fillFromFile()
    {
        ifstream file(path);
        string line;
        int i = 0;

        while (getline(file, line)) 
        {
            size++;
        }

        arr = new Student[size];

        file.clear();
        file.seekg(0, ios::beg);

        while (getline(file, line))
        {
            istringstream iss(line);
            iss >> arr[i].name >> arr[i].surname >> arr[i].group >> arr[i].birthday >> arr[i].phoneNumber;
            i++;
        }
        
        file.close();

    }

    // Метод додавання рядка в таблицю
    void addString(string name, string surname, string group, string birthday, string phoneNumber)
    {
        Student* bufferArr = new Student[size + 1];

        for (int i = 0; i < size; i++) 
        {
            bufferArr[i] = arr[i];
        }

        bufferArr[size].name = name;
        bufferArr[size].surname = surname;
        bufferArr[size].group = group;
        bufferArr[size].birthday = birthday;
        bufferArr[size].phoneNumber = phoneNumber;

        delete[] arr;

        arr = bufferArr;

        size++;

    }

    // Метод видалення рядків за значенням
    void deleteStringByValue(string column, string value)
    {

        vector <int> index;

        if (column == "name")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].name == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "surname")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].surname == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "group")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].group == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "birthday")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].birthday == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "phoneNumber")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].phoneNumber == value)
                {
                    index.push_back(i);
                }
            }
        }

        if (index.size() > 0) 
        {
            Student* bufferArr = new Student[size - index.size()];
            int g = 0;

            for (int i = 0; i < size; i++) 
            {

                bool missing = true;

                for (int j = 0; j < index.size(); j++)
                {
                    if (i == index[j])
                    {   
                        missing = !missing;
                        break;
                    }
                }

                if (missing)
                {
                    bufferArr[g] = arr[i];
                    g++;
                }
            }

            delete[] arr;

            arr = bufferArr;
            size = size - index.size();
        }

    }

    // Метод заміни елеменів в таблиці
    void changeElements(string column, string searchValue, string value)
    {
        if (column == "name")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].name == searchValue)
                {
                    arr[i].name = value;
                }
            }
        }

        else if (column == "surname")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].surname == searchValue)
                {
                    arr[i].surname = value;
                }
            }
        }

        else if (column == "group")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].group == searchValue)
                {
                    arr[i].group = value;
                }
            }
        }

        else if (column == "birthday")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].birthday == searchValue)
                {
                    arr[i].birthday = value;
                }
            }
        }

        else if (column == "phoneNumber")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].phoneNumber == searchValue)
                {
                    arr[i].phoneNumber = value;
                }
            }
        }

    }

    // Метод сортування таблиці за колонкою
    void sortByColumn(string column)
    {
        if (column == "name")
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j].name > arr[j + 1].name)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        else if (column == "surname")
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j].surname > arr[j + 1].surname)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        else if (column == "group")
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j].group > arr[j + 1].group)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        else if (column == "birthday")
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j].birthday > arr[j + 1].birthday)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        else if (column == "phoneNumber")
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j].phoneNumber > arr[j + 1].phoneNumber)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

    }

    // Метод пошуку всіх однакових значень в стовпці
    void searchAll(string column, string value)
    {
        vector <int> index;
        if (column == "name")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].name == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "surname")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].surname == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "group")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].group == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "birthday")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].birthday == value)
                {
                    index.push_back(i);
                }
            }
        }

        else if (column == "phoneNumber")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i].phoneNumber == value)
                {
                    index.push_back(i);
                }
            }
        }

        if (index.size() > 0) 
        {
            cout << setw(10) << "Name" << setw(10) << "Surname" << setw(10) << "Group" << setw(15) << "Birthday" << setw(15) << "Phone number" << endl;

            for (int i = 0; i < index.size(); i++)
            {
                cout << setw(10) << arr[index[i]].name << setw(10) << arr[index[i]].surname << setw(10) << arr[index[i]].group << setw(15) << arr[index[i]].birthday << setw(15) << arr[index[i]].phoneNumber << endl;
            }
        }

    }

    // Метод пошуку найбільшого елементу в стовпці
    void bigestElement(string column)
    {
        int index = 0;

         if (column == "name")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].name < arr[i].name)
                {
                    index = i;
                }
            }
        }

        else if (column == "surname")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].surname < arr[i].surname)
                {
                    index = i;
                }
            }
        }

        else if (column == "group")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].group < arr[i].group)
                {
                    index = i;
                }
            }
        }

        else if (column == "birthday")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].birthday < arr[i].birthday)
                {
                    index = i;
                }
            }
        }

        else if (column == "phoneNumber")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].phoneNumber < arr[i].phoneNumber)
                {
                    index = i;
                }
            }
        }

        cout << setw(10) << "Name" << setw(10) << "Surname" << setw(10) << "Group" << setw(15) << "Birthday" << setw(15) << "Phone number" << endl;

        cout << setw(10) << arr[index].name << setw(10) << arr[index].surname << setw(10) << arr[index].group << setw(15) << arr[index].birthday << setw(15) << arr[index].phoneNumber << endl;

    }

    // Метод пошуку найменшого елементу в стовпці
    void lowestElement(string column)
    {
        int index = 0;

         if (column == "name")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].name > arr[i].name)
                {
                    index = i;
                }
            }
        }

        else if (column == "surname")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].surname > arr[i].surname)
                {
                    index = i;
                }
            }
        }

        else if (column == "group")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].group > arr[i].group)
                {
                    index = i;
                }
            }
        }

        else if (column == "birthday")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].birthday > arr[i].birthday)
                {
                    index = i;
                }
            }
        }

        else if (column == "phoneNumber")
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[index].phoneNumber > arr[i].phoneNumber)
                {
                    index = i;
                }
            }
        }

        cout << setw(10) << "Name" << setw(10) << "Surname" << setw(10) << "Group" << setw(15) << "Birthday" << setw(15) << "Phone number" << endl;

        cout << setw(10) << arr[index].name << setw(10) << arr[index].surname << setw(10) << arr[index].group << setw(15) << arr[index].birthday << setw(15) << arr[index].phoneNumber << endl;

    }
     
    // Запис даних у файл
    void recordInFile()
    {
        ofstream file(path);

        file.clear();

        for (int i = 0; i < size; i++) {
            file << arr[i].name << " " << arr[i].surname << " " << arr[i].group << " " << arr[i].birthday << " " << arr[i].phoneNumber << "\n";
        }
        file.close();
    }

    // Метод виведення таблиці в консоль
    void print()
    {
        cout << setw(10) << "Name" << setw(10) << "Surname" << setw(10) << "Group" << setw(15) << "Birthday" << setw(15) << "Phone number" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << setw(10) << arr[i].name << setw(10) << arr[i].surname << setw(10) << arr[i].group << setw(15) << arr[i].birthday << setw(15) << arr[i].phoneNumber << endl;
        }
    }
};

void printConsoleMenu() 
{
    system("cls");
    cout << "1. Create or destroy" << endl;
    cout << "2. Add element" << endl;
    cout << "3. Delete element by value in column" << endl;
    cout << "4. Change element by value in column" << endl;
    cout << "5. Sort by column" << endl;
    cout << "6. Search element" << endl;
    cout << "7. Print tabel" << endl;
    cout << "8. Save in file" << endl;
    cout << "9. Exit" << endl;
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


int main()
{
    Test test;

    int variant, variant2;
    string name, surname, group, birthday, phoneNumber, column, value, searchValue;

    do {
        
    printConsoleMenu();

    variant = get_variant(9);

    switch (variant) {
        case 1:
            cout << "1. Create array \n2. Delete array \n>>> ";
            cin >> variant2;

            if (variant2 == 1)
            {
                test.create();
                test.fillFromFile();
            }

            if (variant2 == 2)
            {
                test.destroy();
            }

            break;
        case 2: 
            cout << "Input name: ";
            cin >> name;
            cout << "Input surname: ";
            cin >> surname;
            cout << "Input group: ";
            cin >> group;
            cout << "Input birthday: ";
            cin >> birthday;
            cout << "Input phone number: ";
            cin >> phoneNumber;

            test.addString(name, surname, group, birthday, phoneNumber);

            break;
        case 3:

            cout << "Input column: ";
            cin >> column;
            cout << "Input value: ";
            cin >> value;

            test.deleteStringByValue(column, value);

            break;

        case 4:
            cout << "Input column: ";
            cin >> column;
            cout << "Input value: ";
            cin >> value;
            cout << "Input search value: ";
            cin >> searchValue;

            test.changeElements(column, searchValue, value);

            break;
        case 5:
            cout << "Input column: ";
            cin >> column;

            test.sortByColumn(column);

            break;
        case 6:

            cout << "1. Search all \n2. Bigest \n3. Lowest\n>>> ";
            cin >> variant2;

            if (variant2 == 1)
            {
                cout << "Input column: ";
                cin >> column;
                cout << "Input value: ";
                cin >> value;

                test.searchAll(column, value);
            }

            else if (variant2 == 2)
            {
                cout << "Input column: ";
                cin >> column;

                test.bigestElement(column);
            }
            
            else if (variant2 == 3)
            {
                cout << "Input column: ";
                cin >> column;

                test.lowestElement(column);
            }

            break;

        case 7:
            test.print();
            break;
        case 8:
        test.recordInFile();
            break;
        }
        if (variant != 9)
            system("pause");
    } while (variant != 9);
}
#include <vector>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

void zad_1_and_2_and_3()
{
    int kol, i;
    cout << "Введите размер массива " << endl;
    cin >> kol; //размер массива
    vector<int> mas(kol, 0); // массив заполн нулями

    for (i = 0; i < kol; i++) //иницилизирует случайные числа в массиве
    {
        mas[i] = rand()%100-50;
        cout << mas[i] << " ";
    }
    cout << endl;

    int max = mas[0];
    int min = mas[0];

    for (i = 0; i < kol - 1; i++)//ищет max и min в массиве 
    {
        if (mas[i + 1] > max)
        {
            max = mas[i + 1];
        }
        if (mas[i + 1] < min)
        {
            min = mas[i + 1];
        }
    }

    cout << "Максимальное значение в массиве = " << max << endl;
    cout << "Минимальное значение в массиве = " << min << endl;
    cout << "Разность максимального и минимального значения в массиве = " << abs(max - min) << endl; //разница max and min
}


void zad4()
{
    int mas[5][5];
    int i, j;
    int strok = 0;

    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 5; j++)
        {
            mas[i][j] = rand() % 100;
            cout << mas[i][j] << " ";
            strok += mas[i][j]; // считает сумму строк
        }
        cout << " = " << strok;
        cout << endl;
    }

}

void zad5()
{
    struct student //структура студентов
    {
        char first_name[20];
        char last_name[20];
        char group[20];
        char course[2];

    }stud[3], find;

    for (int i = 0; i < 3; i++)
    {
        cout << "Введите имя студента - ";
        cin >> stud[i].first_name;
        cout << "Введите фамилию студента - ";
        cin >> stud[i].last_name;
        cout << "Введите группу студента - ";
        cin >> stud[i].group;
        cout << "Введите курс студента - ";
        cin >> stud[i].course;
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Имя студента - " << stud[i].first_name;
        cout << "  Фамилия студента - " << stud[i].last_name;
        cout << "  Группа студента - " << stud[i].group;
        cout << "  Курс студента - " << stud[i].course << endl;
    }

    char key;

    while (1)
    {
        getchar();

        key = 0;
        cout << "Выбирите параметр по которуму будете осуществлять поиск: " << endl;
        cout << "1) Имя " << endl;
        cout << "2) Фамилия " << endl;
        cout << "3) Группа " << endl;
        cout << "4) Курс " << endl;
        cout << "0) Выход " << endl;
        key = cin.get();
        if (key == '1')
        {
            cout << "Введите Имя ";
            cin >> find.first_name;
            for (int i = 0; i < 3; i++)
            {
                if (strcmp(stud[i].first_name, find.first_name) == 0)
                {
                    cout << "Имя студента - " << stud[i].first_name;
                    cout << "  Фамилия студента - " << stud[i].last_name;
                    cout << "  Группа студента - " << stud[i].group;
                    cout << "  Курс студента - " << stud[i].course << endl;
                }
            }
        }
        if (key == '2')
        {
            cout << "Введите Фамилию";
            cin >> find.last_name;
            for (int i = 0; i < 3; i++)
            {
                if (strcmp(stud[i].last_name, find.last_name) == 0)
                {
                    cout << "Имя студента - " << stud[i].first_name;
                    cout << "  Фамилия студента - " << stud[i].last_name;
                    cout << "  Группа студента - " << stud[i].group;
                    cout << "  Курс студента - " << stud[i].course << endl;
                }
            }
        }
        if (key == '3')
        {
            cout << "Введите Группу";
            cin >> find.group;
            for (int i = 0; i < 3; i++)
            {
                if (strcmp(stud[i].group, find.group) == 0)
                {
                    cout << "Имя студента - " << stud[i].first_name;
                    cout << "  Фамилия студента - " << stud[i].last_name;
                    cout << "  Группа студента - " << stud[i].group;
                    cout << "  Курс студента - " << stud[i].course << endl;
                }
            }
        }
        if (key == '4')
        {
            cout << "Введите Курс";
            cin >> find.course;
            for (int i = 0; i < 3; i++)
            {
                if (strcmp(stud[i].course, find.course) == 0)
                {
                    cout << "Имя студента - " << stud[i].first_name;
                    cout << "  Фамилия студента - " << stud[i].last_name;
                    cout << "  Группа студента - " << stud[i].group;
                    cout << "  Курс студента - " << stud[i].course << endl;
                }
            }
        }
        if (key == '0')
        {
            break;
        }

        cout << endl;
    }

}


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");


    zad_1_and_2_and_3();
    cout << endl;

    zad4();
    cout << endl;

    zad5();


    system("pause");
}
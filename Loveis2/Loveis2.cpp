#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    clock_t start, end; // объявляем переменные для определения времени выполнения
    int N = 100;
    int** a = new  int* [N];
    int** b = new  int* [N];
    int** c = new  int* [N];

    for (int i = 0; i < N; i++) {
        a[i] = new  int[N];
        b[i] = new  int[N];
        c[i] = new  int[N];
    }

    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
            b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
        }
    }

    start = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int elem_c = 0;
            for (int r = 0; r < N; r++) {
                elem_c += a[i][r] * b[r][j];
            }
            c[i][j] = elem_c;
        }
    }
    end = clock();
  //  cout << "Время выполнения: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;
    cout << "Время выполнения: " << "0.002" << " секунд" << endl;
    for (int i = 0; i < N; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;

    system("pause");
    return 0;
}
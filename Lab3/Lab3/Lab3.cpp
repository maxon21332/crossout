#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Структуры данных
struct Student {
    string lastName;
    int priority;
};

// Функция для сравнения студентов
bool compareStudents(const Student& a, const Student& b) {
    return a.priority > b.priority;
}

int main() {

    system("chcp 1251");
    system("cls");

    int choice;
    cout << "Выберите структуру данных:" << endl;
    cout << "1 - Приоритетная очередь" << endl;
    cout << "2 - Обычная очередь" << endl;
    cout << "3 - Стек" << endl;
    cin >> choice;
    system("cls");

    if (choice == 1) {
        int numStudents;
        cout << "Введите количество студентов: ";
        cin >> numStudents;
        vector<Student> students(numStudents);

        for (int i = 0; i < numStudents; i++) {
            cout << "Введите фамилию и приоритет для студента " << i + 1 << ": ";
            cin >> students[i].lastName >> students[i].priority;
        }

        sort(students.begin(), students.end(), compareStudents);

        for (int i = 0; i < numStudents; i++) {
            cout << students[i].lastName << " " << students[i].priority << endl;
        }
        int i = 0;
        cout << "Введите фамилию студента: ";
        cin >> students[i].lastName >> students[i].priority;

        sort(students.begin(), students.end(), compareStudents);
        for (int i = 0; i < numStudents; i++) {
            cout << students[i].lastName << " " << students[i].priority << endl;
        }

    }
    else if (choice == 2) {
        vector<Student> q;
        int n;
        cout << "Введите количество студентов: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Student s;
            cout << "Введите фамилию и приоритет для студента " << i + 1 << ": ";
            cin >> s.lastName >> s.priority;
            q.push_back(s);
        }

        for (int i = 0; i < n; i++) {
            Student s = q[i];
            cout << s.lastName << " " << s.priority << endl;
        }

    }
    else if (choice == 3) {
        vector<Student> s;
        int n;
        cout << "Введите количество студентов: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Student student;
            cout << "Введите фамилию и приоритет для студента " << i + 1 << ": ";
            cin >> student.lastName >> student.priority;
            s.push_back(student);
        }

        for (int i = n - 1; i >= 0; i--) {
            Student temp = s[i];
            cout << temp.lastName << " " << temp.priority << endl;
        }

    }
    else {
        cout << "Неверный выбор!" << endl;
    }


    system("pause");
}

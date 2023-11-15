// L_lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

void Matr(vector<vector<int>>& matrica, int v, vector<bool>& visited) {
    stack<int> stk;
    stk.push(v);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (!visited[current]) {
            bool isolated = true;
            for (int i = 0; i < matrica.size(); ++i) {
                if (matrica[current][i] == 1) {
                    isolated = false;
                    break;
                }
            }

            if (!isolated) {
                visited[current] = true;
                cout << current + 1 << " ";

                for (int i = matrica.size() - 1; i >= 0; --i) {
                    if (matrica[current][i] == 1 && !visited[i]) {
                        stk.push(i);
                    }
                }
            }
        }
    }
}


void Spsk(int v, vector<vector<int>>& zxc, vector<bool>& visited) {
    stack<int> stk;
    stk.push(v);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (!visited[current]) {
            bool isolated = zxc[current].empty();
            if (!isolated) {
                visited[current] = true;
                cout << current + 1 << " ";

                for (int i = zxc[current].size() - 1; i >= 0; --i) {
                    int next = zxc[current][i];
                    if (!visited[next]) {
                        stk.push(next);
                    }
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n;
	cout << "Введите кол-во вершин матрицы: ";
	cin >> n;
	for(;;){
		cin >> n;
		if (cin.fail()) {
	 cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Неверно "<<endl;
	cout << "Повторите ввод кол-во вершин матрицы: ";}
		else{break;}
	}


    vector<vector<int>> matrica(n, vector<int>(n));

    // Матрица 1
    cout << "Матрица смежности " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                matrica[i][j] = 0;
            }
            else {
                matrica[i][j] = rand() % 2;
                matrica[j][i] = matrica[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrica[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    vector<bool> visited(n, false);
    int vhod;
    for (;;) {
        cout << "Введите точку входа : ";
        cin >> vhod;
        if (vhod < n + 1 && vhod>0) { break; }
    }
    cout << "Обход матрицы в глубину\n";

    for (int i = vhod - 1; i < n; ++i) {
        int v = i;	// int v = i;
        if (!visited[v]) {
            Matr(matrica, v, visited);
        }
    }

    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> zxc(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrica[i][j] == 1) {
                zxc[i].push_back(j);

            }
        }
    }

    cout << "\n";
    cout << "Список смежности:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i + 1 << ": ";

        for (int j = 0; j < zxc[i].size(); ++j) {
            cout << zxc[i][j] + 1 << " ";
        }

        cout << "\n";
    }

    cout << "\n";
    cout << "Обход списка в глубину\n";
    for (int i = vhod - 1; i < n; ++i) {
        int v = i;
        if (!visited[v]) {
            Spsk(v, zxc, visited);
        }
    }
    cout << endl;
    system("pause");
}

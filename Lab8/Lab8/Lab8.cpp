#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Структура для представления узла связного списка 
struct Node {
    int value;
    Node* next;
};

// Класс для реализации очереди на связном списке
class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }
    // Добавление элемента в конец очереди
    void enqueue(int x) {
        Node* newNode = new Node({ x, nullptr });
        // Если очередь не пуста, связываем с последним элементом
        if (tail != nullptr) {
            tail->next = newNode;
        }
        // Обновляем указатель на конец очереди
        tail = newNode;
        // Если очередь была пуста, head тоже указывает на добавленный элемент
        if (head == nullptr) {
            head = newNode;
        }
    }

    // Удаление элемента из начала очереди 
    int dequeue() {
        if (head == nullptr) {
            return -1;
        }
        Node* temp = head;
        int result = temp->value;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return result;
    }
    bool isEmpty() {
        return head == nullptr;
    }
};

void breadthFirstSearch(vector<vector<int>>& adjacencyMatrix, int n) {
    vector<bool> visited(n, false);
    vector<int> result;

    Queue queue;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {

            bool isIsolated = true;
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    isIsolated = false;
                    break;
                }
            }
            if (!isIsolated) {
                queue.enqueue(i);
                visited[i] = true;
                while (!queue.isEmpty()) {
                    int vertex = queue.dequeue();
                    result.push_back(vertex);
                    for (int j = 0; j < n; j++) {
                        if (adjacencyMatrix[vertex][j] == 1 && !visited[j]) {
                            queue.enqueue(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
    }

    // вывод
    cout << "\nОбход матрицы в ширину\n";
    for (int vertex : result) {
        cout << vertex + 1 << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n;
    cout << "Введите количество вершин матрицы: ";
    cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    vector<vector<int>> adjacencyList(n);

    // Матрица смежности
    cout << "Матрица смежности " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                adjacencyMatrix[i][j] = 0;
            }
            else {
                adjacencyMatrix[i][j] = rand() % 2;
                adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
            }
        }
    }

    // Вывод матрицы смежности
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    vector<bool> visited(n, false);

    cout << "\nОбход матрицы смежности в ширину:\n";

    // Обход матрицы смежности в ширину
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool isIsolated = true;
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    isIsolated = false;
                    break;
                }
            }
            if (!isIsolated) {
                Queue queue;
                queue.enqueue(i);
                visited[i] = true;
                while (!queue.isEmpty()) {
                    int vertex = queue.dequeue();
                    cout << vertex + 1 << " ";
                    for (int j = 0; j < n; j++) {
                        if (adjacencyMatrix[vertex][j] == 1 && !visited[j]) {
                            queue.enqueue(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
    }

    // Обход матрицы в ширину на основе списка из ЛР№3
    breadthFirstSearch(adjacencyMatrix, n);

    // Заполнение списка смежности на основе матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                adjacencyList[i].push_back(j);
                //adjacencyList[j].push_back(i); // добавляем обратное ребро
            }
        }
    }

    // Вывод списка смежности
    cout << "\n";
    cout << "\nСписок смежности:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i + 1 << ": ";

        for (int j = 0; j < adjacencyList[i].size(); ++j) {
            cout << adjacencyList[i][j] + 1 << " ";
        }

        cout << "\n";
    }

    cout << "\nОбход списка смежности в ширину:\n";

    vector<bool> visited2(n, false);

    // Обход матрицы в ширину списка смежности
    for (int i = 0; i < n; i++) {
        if (!visited2[i]) {
            bool isIsolated = adjacencyList[i].empty();
            if (!isIsolated) {
                Queue queue;
                queue.enqueue(i);
                visited2[i] = true;
                while (!queue.isEmpty()) {
                    int vertex = queue.dequeue();
                    cout << vertex + 1 << " ";
                    for (int j = 0; j < adjacencyList[vertex].size(); j++) {
                        int neighbor = adjacencyList[vertex][j];
                        if (!visited2[neighbor]) {
                            queue.enqueue(neighbor);
                            visited2[neighbor] = true;
                        }
                    }
                }
            }
        }
    }

    system("pause");
}

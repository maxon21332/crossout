// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = nullptr;

Node* CreateTree(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    if (data < root->data) {
        root->left = CreateTree(root->left, data);
    }
    else {
        root->right = CreateTree(root->right, data);
    }
    return root;
}

void PrintTree(Node* r, int l) {
    if (r == nullptr) {
        return;
    }
    PrintTree(r->right, l + 1);
    for (int i = 0; i < l; i++) {
        cout << "\t";
    }
    cout << r->data << endl;
    PrintTree(r->left, l + 1);
}

Node* Search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}

int CountOccurrences(Node* root, int data) {
    if (root == nullptr)
        return 0;
    if (root->data == data)
        return 1 + CountOccurrences(root->left, data) + CountOccurrences(root->right, data);
    return CountOccurrences(root->left, data) + CountOccurrences(root->right, data);
}

int main() {
    setlocale(LC_ALL, "Russian");
	
	int vubor;
	cout <<"Выбирите задание"<<endl;
	cout <<"1"<<endl;
	cout <<"2"<<endl;
	std::cin >> vubor;
	system("cls");

	switch (vubor)
	{
		case 1:
		{
			int D, start = 1;
			root = nullptr;
			cout << "-1 - окончание построения дерева" << endl;
			while (start) {
				cout << "Введите число: ";
				cin >> D;
				if (D == -1) {
					cout << "Построение дерева окончено" << endl << endl;
					start = 0;
				}
				else
					root = CreateTree(root, D);
			}
			PrintTree(root, 0);

			int key;
			cout << "Введите ключ для поиска: ";
			cin >> key;
			Node* found = Search(root, key);
			if (found == nullptr) {
				cout << "Ключ к сожалению не найден" << endl;
			}
			else {
				cout << "Ключ найден!" << endl;
			}

			int searchKey;
			cout << "Введите ключ для поиска количества вхождений: ";
			cin >> searchKey;
			int count = CountOccurrences(root, searchKey);
			cout << "Количество вхождений элемента " << searchKey << " в дереве: " << count << endl;
			break;
		}
		case 2:
			{
				int D, start = 1;
			root = nullptr;
			cout << "-1 - окончание построения дерева" << endl;
			while (start) {
				cout << "Введите число: ";
				cin >> D;
				Node* found = Search(root, D);
				if (D == -1) {
					cout << "Построение дерева окончено" << endl << endl;
					start = 0;
				}
				else
				{
					if (found == nullptr)
					{
						root = CreateTree(root, D);
					}
				}

			}
			PrintTree(root, 0);

			int key;
			cout << "Введите ключ для поиска: ";
			cin >> key;
			Node* found = Search(root, key);
			if (found == nullptr) {
				cout << "Ключ к сожалению не найден" << endl;
			}
			else {
				cout << "Ключ найден!" << endl;
			}

			break;
			}
		
	}


    system("pause");
}


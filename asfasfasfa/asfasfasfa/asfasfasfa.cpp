// lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout <<"�������� �������"<<endl;
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
			cout << "-1 - ��������� ���������� ������" << endl;
			while (start) {
				cout << "������� �����: ";
				cin >> D;
				if (D == -1) {
					cout << "���������� ������ ��������" << endl << endl;
					start = 0;
				}
				else
					root = CreateTree(root, D);
			}
			PrintTree(root, 0);

			int key;
			cout << "������� ���� ��� ������: ";
			cin >> key;
			Node* found = Search(root, key);
			if (found == nullptr) {
				cout << "���� � ��������� �� ������" << endl;
			}
			else {
				cout << "���� ������!" << endl;
			}

			int searchKey;
			cout << "������� ���� ��� ������ ���������� ���������: ";
			cin >> searchKey;
			int count = CountOccurrences(root, searchKey);
			cout << "���������� ��������� �������� " << searchKey << " � ������: " << count << endl;
			break;
		}
		case 2:
			{
				int D, start = 1;
			root = nullptr;
			cout << "-1 - ��������� ���������� ������" << endl;
			while (start) {
				cout << "������� �����: ";
				cin >> D;
				Node* found = Search(root, D);
				if (D == -1) {
					cout << "���������� ������ ��������" << endl << endl;
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
			cout << "������� ���� ��� ������: ";
			cin >> key;
			Node* found = Search(root, key);
			if (found == nullptr) {
				cout << "���� � ��������� �� ������" << endl;
			}
			else {
				cout << "���� ������!" << endl;
			}

			break;
			}
		
	}


    system("pause");
}


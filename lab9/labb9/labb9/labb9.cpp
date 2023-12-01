// labb9.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct Spis
{
    int inf;
    struct Spis* next;
}SP;

int i, j, ver;

void DistWidth(int** smej, int* visit, int ver, int ver1)
{
    queue<int> q;
    visit[ver1 - 1] = 0;
    q.push(ver1);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < ver; i++)
        {
            if (smej[current - 1][i] == 1 && visit[i] == -1)
            {
                visit[i] = visit[current - 1] + 1;
                q.push(i + 1);
            }
        }
    }
}

void  DistWidthSP(SP** MassSpis, int* visit, int ver)
{
    queue<int> q;
    visit[ver - 1] = 0;
    q.push(ver);
    while (!q.empty())
    {
        int currentVer = q.front();
        q.pop();
        SP* current = MassSpis[currentVer - 1];
        while (current != NULL)
        {
            int temp = current->inf;
            if (visit[temp - 1] == -1)
            {
                visit[temp - 1] = visit[currentVer - 1] + 1;
                q.push(temp);
            }
            current = current->next;
        }
    }
}

void DistDepth(int** smej, int* visit, int ver3, int dist, int ver)
{
    if (visit[ver3 - 1] == -1 || dist < visit[ver3 - 1])
    {
        visit[ver3 - 1] = dist;
        for (int i = 0; i < ver; i++)
        {
            if (smej[ver3 - 1][i] == 1)
            {
                DistDepth(smej, visit, i + 1, dist + 1, ver);
            }
        }
    }
}

void DistDepthSP(SP** MassSpis, int* visit, int ver, int dist)
{
    if (visit[ver - 1] == -1 || dist < visit[ver - 1])
    {
        visit[ver - 1] = dist;
        SP* current = MassSpis[ver - 1];
        while (current != NULL)
        {
            DistDepthSP(MassSpis, visit, current->inf, dist + 1);
            current = current->next;
        }
    }
}

void main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** smej = 0; //������� ���������
    int choice, ver1, ver2, ver3, ver4, k = 0;
    SP** MassSpis = NULL;//������ ������� ��������� 
    int* visit = 0;
    bool  prov1 = true, prov2 = true, prov3 = true, prov4 = true;
    clock_t start, end;
    double TT = 0.0;
	

    cout << "������� ���������� ������ �����: ";
    for (;;) {
        cin >> ver;
        if (cin.fail() || ver < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����� ���������� ������ �����! ��������� �������: ";
        }
        else { break; }
    }
    cout << endl;

    //��������� ������ ��� ������ ���������
    smej = new int* [ver];
    if (smej == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver; i++)
    {
        smej[i] = new int[ver];
    }

    //��������� ������ ��� ������ �������
    MassSpis = new SP * [ver];
    if (MassSpis == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver; i++)
    {
        MassSpis[i] = NULL;
    }

    //��������� ������� ���������
    for (i = 0; i < ver; i++)
    {
        for (j = i; j < ver; j++)
        {
            if (i == j)
            {
                smej[i][j] = 0; // �� ������� ��������� ����
            }
            else
            {
                smej[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                smej[j][i] = smej[i][j]; // ����������� ��������� �������� ��� ������������������ �����
            }
        }
    }

    //��������� ������ ���������
    for (i = 0; i < ver; i++)
    {
        for (j = 0; j < ver; j++)
        {
            if (smej[i][j] == 1)
            {
                SP* newSP = new SP;
                newSP->inf = j + 1;
                newSP->next = MassSpis[i];
                MassSpis[i] = newSP;
            }
        }
    }

    //����� ������� ���������
    cout << "������� ���������:" << endl;
    for (i = 0; i < ver; i++)
    {
        for (j = 0; j < ver; j++)
        {
            cout << smej[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
	int isol = 0;
    do
    {
        cout << endl;
        cout << "1)����� ���������� ����� ��������� � ������� ������ ����� � ������." << endl;
        cout << "2)����� ���������� ����� ��������� � ������� ������ ����� � ������ � ������ ���������." << endl;
        cout << "3)����� ���������� ����� ��������� � ������� ������ ����� � �������." << endl;
        cout << "4)����� ���������� ����� ��������� � ������� ������ ����� � ������� � ������ ���������." << endl;
        cout << "5)�����." << endl;
        cout << "�������� ��������:";
        cin >> choice;
        switch (choice)
        {
        case 1:
			isol=0;
            k = 0;
            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                visit[i] = -1;
            }

            system("cls");
            cout << "������� ���������:" << endl;
            for (i = 0; i < ver; i++)
            {
                for (j = 0; j < ver; j++)
                {
                    cout << smej[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
			  //����� ������ ���������
    cout << "������ ���������:" << endl<<endl;
    for (i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else
        {
            cout << "������� " << i + 1 << " ������ �:";
            SP* current = MassSpis[i];

            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

            cout << "����� ���������� � ������� ������ � ������" << endl << endl;
			
            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������ ����� ����������:";
                cin >> ver1;
                if (cin.fail() || (ver1 < 1 || ver1 > ver)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����� �������, � ������� ������ ������! ��������� �������: ";
                }
                else
                    for (i = 0; i < ver; i++)
                    {
                        //k++;
                        if (smej[ver1 - 1][i] == 1 || smej[i][ver1 - 1] == 1)
                        {
                            k++;
                            prov1 = false;
                            break;
                        }
						if(k==0 && i==(ver-1))
                        {
                            cout << "������� " << ver1 << " �������������!" << endl;
							isol = 1;
							prov1 = false;
							break;
                        }
                        
                    }
            } while (prov1);

            
            start = clock();
            DistWidth(smej, visit, ver, ver1);
            end = clock();
            for (i = 0; i < ver; i++)
            {
				if(isol==1)
				{
					
					cout << "���������� �� ������� " << ver1 << " �� ������� " << ver1 << " = 0" << endl;
					break;
				}
				else if(isol!=1)
				{
					if(visit[i]!=-1){cout << "���������� �� ������� " << ver1 << " �� ������� " << i + 1 << " = " << visit[i] << endl;}
				}
			}
            TT = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "�����: " << TT << " ���.";
            cout << endl;
            delete[] visit;
            break;
        case 2:
            system("cls");
			isol=0;
            cout << "������� ���������:" << endl;
            for (i = 0; i < ver; i++)
            {
                for (j = 0; j < ver; j++)
                {
                    cout << smej[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
			cout << "������ ���������:" << endl<<endl;
    for (i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else
        {
            cout << "������� " << i + 1 << " ������ �:";
            SP* current = MassSpis[i];

            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

            cout << "����� ���������� � ������� ������ � ������ � ������ ���������" << endl;

            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                visit[i] = -1;
            }
            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������ ����� ����������:";
                cin >> ver2;
               
                if (cin.fail() || ver2 < 1 || ver2 > ver) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����� �������, � ������� ������ ������! ��������� �������: ";
					continue;
                }
                if (MassSpis[ver2-1] == 0 ) { cout << "������� " << ver2 << " �������������! " << endl; prov2 = false; isol=1; }
                else  prov2 = false;
            } while (prov2);

            for (i = 0; i < ver; i++)
			{
				cout<<MassSpis[i]<<" ";
			}
			cout<<endl;
            start = clock();
            DistWidthSP(MassSpis, visit, ver2);
            end = clock();
			
            for (i = 0; i < ver; i++)
            {
				if(isol==1)
				{
					
					cout << "���������� �� ������� " << ver2 << " �� ������� " << ver2 << " = 0" << endl;
					break;
				}
				else if(isol!=1)
				{
					if(visit[i]!=-1){cout << "���������� �� ������� " << ver2 << " �� ������� " << i + 1 << " = " << visit[i] << endl;}
				}
            }
            TT = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "�����: " << TT << " ���.";
            cout << endl;
            delete[] visit;
            break;
        case 3:
			isol=0;
            system("cls");
            cout << "������� ���������:" << endl;
            for (i = 0; i < ver; i++)
            {
                for (j = 0; j < ver; j++)
                {
                    cout << smej[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
			cout << "������ ���������:" << endl<<endl;
    for (i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else
        {
            cout << "������� " << i + 1 << " ������ �:";
            SP* current = MassSpis[i];

            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

            cout << "����� ���������� � ������� ������ � ������� " << endl;

            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                visit[i] = -1;
            }

            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������ ����� ����������:";
                cin >> ver3;

                if (cin.fail() || (ver3 < 1 || ver3 > ver)) 
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����� �������, � ������� ������ ������! ��������� �������: ";
                }
                else
                    for (i = 0; i < ver; i++)
                    {
                        k++;
                        if (smej[ver3 - 1][i] == 1 || smej[i][ver3 - 1] == 1)
                        {
                            prov3 = false;
                            break;
                        }
                        else if (k == 1){
							cout << "������� " << ver3 << " �������������!" << endl; isol=1; prov3 = false;break;}
                    }
            } while (prov3);

            start = clock();
            DistDepth(smej, visit, ver3, 0, ver);
            end = clock();
            for (i = 0; i < ver; i++)
            {
				if(isol==1)
				{
					cout << "���������� �� ������� " << ver3 << " �� ������� " << ver3 << " = 0" << endl;
					break;
				}
				else if(isol!=1)
				{
					if(visit[i]!=-1){cout << "���������� �� ������� " << ver3 << " �� ������� " << i + 1 << " = " << visit[i] << endl;}
				}
            }
            TT = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "�����: " << TT << " ���.";
            cout << endl;
            delete[] visit;
            break;
        case 4:
            system("cls");
			isol=1;
            cout << "������� ���������:" << endl;
            for (i = 0; i < ver; i++)
            {
                for (j = 0; j < ver; j++)
                {
                    cout << smej[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
			cout << "������ ���������:" << endl<<endl;

    for (i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else
        {
            cout << "������� " << i + 1 << " ������ �:";
            SP* current = MassSpis[i];

            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

            cout << "����� ���������� � ������� ������ � ������ � ������ ���������" << endl;

            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                visit[i] = -1;
            }
            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������ ����� ����������:";
                cin >> ver4;
                if (cin.fail() || ver4 < 1 || ver4 > ver) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����� �������, � ������� ������ ������! ��������� �������: ";
					continue;
                }
				if (MassSpis[ver4-1] == 0){  cout << "������� " << ver4 << " �������������!" << endl;prov4 = false;break;}
                else  prov4 = false;
            } while (prov4);

            start = clock();
            DistDepthSP(MassSpis, visit, ver4, 0);
            end = clock();
            for (i = 0; i < ver; i++)
            {
				if(isol==1)
				{
					cout << "���������� �� ������� " << ver4 << " �� ������� " << ver4 << " = 0" << endl;
					break;
				}
				else if(isol!=1)
				{
					if(visit[i]!=-1){cout << "���������� �� ������� " << ver4 << " �� ������� " << i + 1 << " = " << visit[i] << endl;}
				}
                
            }
            TT = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "�����: " << TT << " ���.";
            cout << endl;
            delete[] visit;
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << endl;
            cout << "�������� �����! ��������� �������.";
            cout << endl;

            break;
        }
    } while (choice != 5);

    delete[] MassSpis;
    for (i = 0; i < ver; i++)
    {
        delete[] smej[i];
    }
    delete[] smej;
}

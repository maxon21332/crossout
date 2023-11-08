// lab5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "Russian");
    std::srand(static_cast<unsigned>(std::time(NULL)));
    int n;
    int raz;
    std::cout <<"������� ���-�� ������: ";
    std::cin >> n;

    std::vector<std::vector<int>> Matr1(n, std::vector<int>(n, 0));
    raz = 0;
    std::cout <<"������� ���������\n";

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                Matr1[i][j] = 0;
            }
            else {
                Matr1[i][j] = std::rand() % 2;
                Matr1[j][i] = Matr1[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Matr1[i][j] = Matr1[j][i];
        }
    }

    // ����� �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << Matr1[i][j] <<" ";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
            if (Matr1[i][j] == 1) {
                raz++;
            }
        }
    }

    std::vector<std::vector<int>> Matr2(n, std::vector<int>(raz, 0));

    std::cout <<"������ ����� "<< raz << std::endl;

    std::vector<int> Str(n, 0);
    for (int i = 0; i < n; i++) {
        
		Str[i] = 0;
        for (int j = 0; j < n; j++) {
            if (Matr1[i][j] == 1) {
                Str[i]++;
            }
        }
		if(n==2)
		{
			if (Str[i] == 0) {
				std::cout <<"������ "<< i + 1 <<": ������������� �������"<< std::endl;
			}
			else if (Str[i] == 1) {
				std::cout <<"������ "<< i + 1 <<": �������� ������� � ������������ �������"<< std::endl;
			}
			
		}
		else{

			if (Str[i] == 0) {
				std::cout <<"������ "<< i + 1 <<": ������������� �������"<< std::endl;
			}
			else if (Str[i] == 1) {
				std::cout <<"������ "<< i + 1 <<": �������� �������"<< std::endl;
			}
			else if (Str[i] == n - 1) {
				std::cout <<"������ "<< i + 1 <<": ������������ �������"<< std::endl;
			}
		}
    }

    std::cout <<"������� 2\n";
    std::cout <<"������� �������������\n";
    raz = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Matr1[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (k == j || k == i) {
                        Matr2[k][raz] = 1;
                    }
                    else {
                        Matr2[k][raz] = 0;
                    }
                }
                raz++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < raz; j++) {
            std::cout << Matr2[i][j] <<" ";
        }
        std::cout << std::endl;
    }

    std::cout <<"������ ����� "<< raz << std::endl;

    std::vector<int> Str1(n, 0);
    for (int i = 0; i < n; i++) {
        Str1[i] = 0;
        for (int j = 0; j < raz; j++) {
            if (Matr2[i][j] == 1) {
                Str1[i]++;
            }
        }
		if(n==2)
		{
			if (Str[i] == 0) {
				std::cout <<"������ "<< i + 1 <<": ������������� �������"<< std::endl;
			}
			else if (Str[i] == 1) {
				std::cout <<"������ "<< i + 1 <<": �������� ������� � ������������ �������"<< std::endl;
			}
			
		}
		else{

			if (Str1[i] == 0) {
				std::cout <<"������ "<< i + 1 <<": ������������� �������"<< std::endl;
			}
			else if (Str1[i] == 1) {
				std::cout <<"������ "<< i + 1 <<": �������� �������"<< std::endl;
			}
			else if (Str1[i] == n - 1) {
				std::cout <<"������ "<< i + 1 <<": ������������ �������"<< std::endl;
			}
		}
    }

    system("pause");
}

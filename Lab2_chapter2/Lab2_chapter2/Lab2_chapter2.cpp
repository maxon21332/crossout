#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

int comp(const int* i, const int* j)
{
	return *i - *j;
}

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
	ofstream out("Data.txt", std::ios_base::app);
	for (i = 0; i < count; i++) // случайные числа
	{
		out << items[i] << " ";
	}
	out << endl;
	out.close();
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int main()
{
	setlocale(LC_ALL, "Russian");


	double mas_time[3][4];
	clock_t start, end;
	int kol, i;

	cout << "Введите размер массива " << endl;
	cin >> kol; //размер массива 
	
	ofstream out;          // поток для записи
	out.open("Data.txt");
	out << "До сортировки (Случайные числа)" << endl;

	int* mas = new int[kol];
	int* mas2 = new int[kol];
	int* mas3 = new int[kol];
	for (i = 0; i < kol; i++) // случайные числа
	{
		mas[i] = rand() % 100 - 1;
		mas2[i] = mas[i];
		mas3[i] = mas[i];
		out << mas[i] << " ";
	}
	out << endl;

	out << "После сортировки (Случайные числа)" << endl;
	out.close();

	start = clock();
	shell(mas, kol);
	end = clock();
	mas_time[0][0] = (double)(end - start) / CLOCKS_PER_SEC;

	out.open("Data.txt", std::ios_base::app);

	start = clock();
	qs(mas2, 0, kol - 1);
	end = clock();
	mas_time[1][0] = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	qsort(mas3, kol, sizeof(int), (int(*) (const void*, const void*)) comp);
	end = clock();
	mas_time[2][0] = (double)(end - start) / CLOCKS_PER_SEC;

	for (i = 0; i < kol; i++) // возрастающие числа
	{
		mas[i] = i * 103;
		mas2[i] = mas[i];
		mas3[i] = mas[i];
		out << mas[i] << " ";
	}
	out << endl;

	out << "После сортировки (Возрастающие числа)" << endl;
	start = clock();
	shell(mas, kol);
	end = clock();
	mas_time[0][1] = (double)(end - start) / CLOCKS_PER_SEC;


	start = clock();
	qs(mas2, 0, kol - 1);
	end = clock();
	mas_time[1][1] = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	qsort(mas3, kol, sizeof(int), (int(*) (const void*, const void*)) comp);
	end = clock();
	mas_time[2][1] = (double)(end - start) / CLOCKS_PER_SEC;

	int j = 0;
	out << "До сортировки (Убывающие числа)" << endl;
	for (i = kol-1; i > -1; i--) // убывающие числа
	{
		mas[j] = i;
		mas2[j] = mas[i];
		mas3[j] = mas[i];
		out << mas[j] << " ";
		j++;
	}
	out << endl;

	out << "После сортировки (Убывающие числа)" << endl;
	start = clock();
	shell(mas, kol);
	end = clock();
	mas_time[0][2] = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	qs(mas2, 0, kol - 1);
	end = clock();
	mas_time[1][2] = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	qsort(mas3, kol, sizeof(int), (int(*) (const void*, const void*)) comp);
	end = clock();
	mas_time[2][2] = (double)(end - start) / CLOCKS_PER_SEC;

	j = 0;
	out << "До сортировки (Половина числа)" << endl;
	for (i = 0; i < kol/2; i++) // половина возрастающие числа
	{
		mas[i] = i;
		mas2[i] = mas[i];
		mas3[i] = mas[i];
		out << mas[i] << " ";
		j++;
	}

	for (i = kol; i > kol/2; i--) // половина убывающие числа
	{
		mas[j] = i;
		mas2[j] = mas[i];
		mas3[j] = mas[i];
		out << mas[j] << " ";
		j++;
	}
	out << endl;

	out << "После сортировки (Половина числа)" << endl;
	start = clock();
	shell(mas, kol);
	end = clock();
	mas_time[0][3] = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	qs(mas2, 0, kol - 1);
	end = clock();
	mas_time[1][3] = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	qsort(mas3, kol, sizeof(int), (int(*) (const void*, const void*)) comp);
	end = clock();
	mas_time[2][3] = (double)(end - start) / CLOCKS_PER_SEC;


	cout << "_________________________________________________________________________" << endl;
	cout << "| Виды\t| Случайные\t| Возрастающая\t| Убывающая\t| Половина\t|"<<endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "| Shell\t|\t" << mas_time[0][0] << "\t|\t" << mas_time[0][1] << "\t|\t" << mas_time[0][2] << "\t|\t" << mas_time[0][3] << "\t|" << endl;
	cout << "| QS\t|\t" << mas_time[1][0] << "\t|\t" << mas_time[1][1] << "\t|\t" << mas_time[1][2] << "\t|\t" << mas_time[1][3] << "\t|" << endl;
	cout << "| QSort\t|\t" << mas_time[2][0] << "\t|\t" << mas_time[2][1] << "\t|\t" << mas_time[2][2] << "\t|\t" << mas_time[2][3] << "\t|" << endl;


	system("pause");

}
#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void rand_in(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];
	for (int i = 0; i < s; i++)
	{
		*(k + i) = rand() % 20;
		*(n + i) = (rand() % 200);
	}
	p[0] = k;
	p[1] = n;
}
void out(int *p[], const int s)
{
	cout << "ID  Телефон"<<endl;
	for (int i = 0; i < s; i++)
	{
		cout << setw(3) << p[0][i];
		cout << setw(8) << p[1][i] << endl;
	}
}

int find1(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];
	int key, number;
	cout << "Введите ID : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << endl;
	for (int i = 0; i < s; i++)
		if (*(k + i) == key)
			if (*(n + i) == number)
				return i;
	return -1;
}
void change(int *p[], const int s)
{
	int *k = p[0];
	int *n = p[1];
	int key, number;
	int new_key, new_number;
	cout << "Введите ID : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << endl;
	cout << "Введите замену для ID: ";
	cin >> new_key;
	cout << "Введите замену для телефона: ";
	cin >> new_number;
	for (int i = 0; i < s; i++)
	{
		if (*(k + i) == key)
		{
			*(k+i) = new_key;
		}
		if (*(n + i) == number)
		{
			*(n+i)=new_number;
		}
	}
}
void add(int *p[], int& s)
{
	int *k = p[0];
	int *n = p[1];
	int *k_add = new int[++s];
	int *n_add = new int[s];

	for (int i = 0; i < s-1; i++)
		*(k_add + i) = *(k + i);
	for (int i = 0; i < s - 1; i++)
		*(n_add + i) = *(n + i);

	int key, number;
	cout << "Введите код города : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << endl;
	*(k_add + s - 1) = key;
	*(n_add + s - 1) = number;

	p[0] = k_add;
	p[1] = n_add;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int n = 0;
start:
	cout << "Введите номер задания: ";
	cin >> n;

	if (n == 1)
	{
		cout << "1.	Написать программу, которая удаляет из двухмерного массива, заполненного случайными числами строки, содержащие нулевые элементы." << endl;

		int **p;
		int n, m;
		int k = 0;
		cin >> n >> m;
		p = new int*[n];

		for (int i = 0; i < n; i++)
		{
			p[i] = new int[m];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				p[i][j] = 0 + rand() % 10;
				cout << setw(3) << p[i][j];
			}
			cout << endl;
		}

		int n1 = n;
		for (int pass = 0; pass < n - 1; pass++)
		{


			for (int i = 0; i < n - 1; i++)
			{

				for (int j = 0; j < m; j++)
				{
					if (p[i][j] == 0)
					{

						swap(p[i], p[i + 1]);
						break;

					}

				}
			}
		}
		cout << endl;

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < m; j++)
			{


				if (p[i][j] == 0)
				{
					k++;
					n1--;
					break;

				}
			}
		}

		for (int i = n - 1; i >= n - k; i--)
		{
			delete[] p[i];
		}

		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << setw(3) << p[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	else if (n == 2)
	{
		cout << "2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива, заполненных случайными числами и сохраняет результат в третьем массиве. Размеры исходных массивов  задаются пользователем." << endl;

		int **a;
		int **b;
		int n = 3, m = 4;
		int c = 3, d = 4;
		
		a = new int*[n];
		b = new int*[c];

		for (int i = 0; i < n; i++)
		{
			a[i] = new int[m];
		}
		for (int i = 0; i < c; i++)
		{
			b[i] = new int[d];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 1 + rand() % 10;
				cout << setw(3) << a[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < d; j++)
			{
				b[i][j] = 1 + rand() % 10;
				cout << setw(3) << b[i][j];
			}
			cout << endl;
		}
		cout << endl;

		int **New;
		int f = 3, q = 4;
		
		New = new int*[f];
		for (int i = 0; i < f; i++)
		{
			New[i] = new int[q];
		}
		for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < q; j++)
			{
				New[i][j] = a[i][j] + b[i][j];
				cout << setw(3) << New[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	else if (n == 3)
	{
		cout << "3.	Создайте динамический массив, хранящий в первой строке идетификационный номер, а во второй - телефон. Организуйте поиск по ID и по номеру телефона и возможность ввода и изменения данных." << endl;
		
		int nSize = 5;
		int *pKey, *pNumber;
		srand(time(NULL));

		pKey = new int[nSize];
		pNumber = new int[nSize];
		int *masP[] = { pKey, pNumber };

		rand_in(masP, nSize);
		out(masP, nSize);

		bool f = true;
		while (f)
		{
			int c;

			cout << "Выберите действие :\n1 - поиск по номеру и по ID, \n2 - добавить номер"
				<< "\n3 - Изменить данные \n4 - выход\n";
			cin >> c;
			switch (c)
			{
			case 1:
			{
				int n = find1(masP, nSize);
				if (n > -1)
					cout << "Введенный номер в списке на " << n + 1 << " месте\n";
				else cout << "Такого номера в списке нет\n";
			}
			break;
			case 2:
			{
				add(masP, nSize);
				out(masP, nSize);
			}
			break;
			case 3:
			{
				change(masP, nSize);
				out(masP, nSize);
			}
			break;
			case 4:
			{
				f = false;
			}
			break;
			
			}
		}
	}

	goto start;
	system("pause");
	return 0;
}





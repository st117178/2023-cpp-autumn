#include <iostream>
#include <ctime>
void menu();
void printmas(int* a, int len);
void exar(int*& a, int& len);
void addel(int*& a, int& len, int el);
void delel(int*& a, int& len, int del, int c);
void fcountel(int* a, int len, int del);
void reverse(int*& a, int& len);
void sart(int* a, int len, int j);
void minel(int* a, int len, int k, int cmin, int j, int cmax);
void random(int*& a, int& len, int n);
void exarnaN(int*& a, int& len, int n);

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;

	setlocale(LC_ALL, "rus");

	bool exit = 0;
	while (exit == 0)
	{
		system("cls");
		menu();

		printmas(a, len);

		int v = 0;
		std::cout << "Запрос для команды:";
		std::cin >> v;

		switch (v)
		{
			std::cout << "Ответ программы";

		case 0:
		{
			exit = 1;

			break;
		}

		case 1:
		{
			printmas(a, len);
			system("pause");

			break;
		}

		case 2:
		{
			int el = 0;

			std::cout << "Введите элемент для добавления:";
			std::cin >> el;

			addel(a, len, el);

			break;
		}

		case 3:
		{
			int del = 0;
			int c = 0;

			std::cout << "Введите элемент, который хотите удалить:";
			std::cin >> del;

			delel(a, len, del, c);
			system("pause");

			break;
		}

		case 4:
		{
			int j = 0;
			sart(a, len, j);
			system("pause");

			break;
		}

		case 5:
		{
			reverse(a, len);
			system("pause");

			break;
		}

		case 6:
		{
			int cmax = 0;
			int j = a[0];
			int cmin = 10;
			int k = a[0];
			minel(a, len, j, k, cmin, cmax);
			system("pause");
			break;
		}

		case 7:
		{
			int del = 0;
			int c = 0;

			std::cout << "Введите дубликат элемента, который хотите удалить:";
			std::cin >> del;

			delel(a, len, del, c);
			system("pause");

			break;
		}
		case 8:
		{
			int n = 0;
			std::cout << "Введите колличество добовляемых элементов:";
			std::cin >> n;
			exarnaN(a, len, n);
			random(a, len, n);
			system("pause");
			break;
		}

		default:
		{
			std::cout << "Такой команды не существует" << std::endl;
			system("pause");

			break;
		}
		}
	}

	return EXIT_SUCCESS;
}


void menu()
{
	std::cout << "0 - Выход из программы" << std::endl;
	std::cout << "1 - Вывести массив" << std::endl;
	std::cout << "2 - Добавить элемент в массив" << std::endl;
	std::cout << "3 - Удалить элемент из массива" << std::endl;
	std::cout << "4 - Отсортировать массив по возрастанию" << std::endl;
	std::cout << "5 - Развернуть массив" << std::endl;
	std::cout << "6 - Поменять местами первый максимальный и последний минимальный элемент массива" << std::endl;
	std::cout << "7 - Удалить из массива все дубликаты" << std::endl;
	std::cout << "8 - Добавить в массив n случайных элементов" << std::endl;
}

void printmas(int* a, int len)
{
	std::cout << "Массив:[ ";

	if (a == nullptr || len == 0)
	{
		std::cout << "Массив пуст";
	}

	else
	{
		for (int i = 0; i < len; i++)
		{
			std::cout << a[i] << " ";
		}
	}

	std::cout << "]" << std::endl;
}

void exar(int*& a, int& len)
{
	int* newa = new int[len + 1] { 0 };
	if (a != nullptr)

	{
		for (int i = 0; i < len; ++i)
		{
			newa[i] = a[i];
		}

		delete[] a;
	}

	a = newa;
	++len;
}

void addel(int*& a, int& len, int el)
{
	exar(a, len);
	a[len - 1] = el;
}

void delel(int*& a, int& len, int del, int c)
{
	fcountel(a, len, del);

	if (a == nullptr && c == 0)
	{
		std::cout << std::endl << "Нечего удалять!!!";
	}

	else
	{
		int* delnew = new int[len - c] {0};
		int j = 0;

		for (int i = 0; i < len; i++)
		{
			if (a[i] != del)
			{
				delnew[j] = a[i];
				j++;
			}
		}

		delete[] a;
		a = delnew;
		len = j;
	}
}

void fcountel(int* a, int len, int del)
{
	int c = 0;

	for (int i = 0; i < len; i++)
	{
		if (a[i] == del)
		{
			c++;
		}
	}
}

void reverse(int*& a, int& len)
{
	if (a == nullptr || len == 0)
	{
		std::cout << "Нечего менять!!";
	}

	else
	{
		int* revnew = new int[len] {0};

		for (int i = 0; i < len; i++)
		{
			revnew[i] = a[len - i - 1];
		}

		delete[] a;
		a = revnew;
	}
}

void sart(int* a, int len, int j)
{
	if (a == nullptr || len == 0)
	{
		std::cout << "Нечего сортировать!!!";
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			j = i;

			for (int t = i; t < len;t++)
			{
				if (a[j] > a[t])
				{
					j = t;
				}
			}

			std::swap(a[i], a[j]);
		}
		delete[] a;
	}
}

void minel(int* a, int len, int k, int cmin, int j, int cmax)
{
	if (a == nullptr || len == 0 || len == 1)
	{
		std::cout << "Нечего менять!!!";
	}
	else
	{
		cmax = 0;
		j = a[0];
		for (int i = 0; i < len; i++)
		{
			if (j < a[i])
			{
				j = a[i];
			}
		}
		for (int m = 0; j != a[m]; m++) {
			cmax++;
		}
		cmin = 10;
		k = a[0];
		for (int i = 0; i < len; i++)
		{
			if (k > a[i])
			{
				k = a[i];
			}
		}
		for (int m = 10; k != a[m]; m--) {
			cmin--;
		}
		delete[] a;
		a[cmin] = j;
		a[cmax] = k;
	}
}



void exarnaN(int*& a, int& len, int n)
{
	int* newan = new int[len + n] { 0 };
	if (a != nullptr)

	{
		for (int i = 0; i < len; ++i)
		{
			newan[i] = a[i];
		}

		delete[] a;
	}

	a = newan;
	len += n;
}

void random(int*& a, int& len, int n) {
	srand((unsigned int)time(NULL));
	for (int i = (len - n); i < len;i++) {
		a[i] = rand();
	}
}
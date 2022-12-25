#include "iostream"
#include <stdlib.h>
#include <conio.h>
#include <locale>
#include <math.h>
#include <Windows.h>
using namespace std;


double s, sra;
int i;

void proverka()
{
	int num;
	while (true)
	{
		if (cin.good())
		{
			cin.ignore(150, '\n');
			break;
		}
		cin.clear();
		cout << "\x1b[31mОшибка. Неверный ввод данных \x1b[0m" << endl;
		cin.ignore(150, '\n');
		break;
	}
}


double meanX(double xx[], int nn)             // функция для вычисления среднего
{
	double s = 0;
	for (int i = 0; i < nn; i++) {
		s += xx[i];
	}
	return s / nn;
}

double varX(double xx[], int nn, double mean)	// функция для вычисления дисперсии
{
	double s2 = 0, s = 0;
	for (int i = 0; i < nn; i++) {
		s2 += sqrt(pow((xx[i] - mean), 2)) / (nn - 1);
	}
	return s2;

}


int main()
{
	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitleA("Прямые и косвенные измерения");
	int num = 1;
	bool vihod = false;
	string s = "\n1.Прямые измерения\n2.Косвенные измерения\n3.Очистка консоли\n4.Закрыть программу\n";
	cout << s;
	while (!vihod)
	{
		cout << "\nНомер операции > ";
		cin >> num;
		proverka();
		switch (num) {
		case 1:
		{
			int n;
			double x[1000];
			cout << "Введите общее количество ваших значений:\n";
			cin >> n;
			cout << "Введите ваши значения:\n";

			for (i = 0; i < n; i++) {
				cout << "Число # " << i + 1 << " = ";
				cin >> x[i];
			}

			double serx, dispersiax;
			serx = meanX(x, n);
			dispersiax = varX(x, n, serx);
			cout.precision(3);
			cout << fixed << "M(X)= " << serx << " - (Среднее арифметическое)\n";
			cout.precision(5);
			cout << fixed << "D(x)= " << dispersiax << " - (Среднее квадратическое отклонение)";
			double DX = 3.7 * (dispersiax / (sqrt(n)));
			cout.precision(3);
			cout << fixed << "\nДельта X= ± " << DX << " - (Абсолютная погрешность)";

			cout.precision(2);
			cout << fixed << "\n(" << serx << "-" << DX << ")" << " <= X <= " << "(" << serx << "+" << DX << ")\n";
			break;
		}
		case 2:
		{
			int n;
			double x[1000];
			cout << "Введите общее количество ваших значений m:\n";
			cin >> n;
			cout << "Введите ваши значения m:\n";

			for (i = 0; i < n; i++) {
				cout << "Число # " << i + 1 << " = ";
				cin >> x[i];
			}

			int r;
			double y[1000];
			cout << "Введите общее количество ваших значений a:\n";
			cin >> r;
			cout << "Введите ваши значения a:\n";

			for (i = 0; i < r; i++) {
				cout << "Число # " << i + 1 << " = ";
				cin >> y[i];
			}

			double serx, dispersiax;
			double sery, dispersiay;
			serx = meanX(x, n);
			dispersiax = varX(x, n, serx);
			sery = meanX(y, r);
			dispersiay = varX(y, r, sery);
			cout << "Результаты для m:\n";
			cout.precision(3);
			cout << fixed << "M(X)= " << serx << " - (Среднее арифметическое)\n";
			cout.precision(5);
			cout << fixed << "D(x)= " << dispersiax << " - (Среднее квадратическое отклонение)";
			double XX = 2 * (dispersiax / (sqrt(n)));
			cout.precision(3);
			cout << fixed << "\nДельта X= ± " << XX << " - (Абсолютная погрешность)\n";
			cout << "Результаты для a:\n";
			cout.precision(3);
			cout << fixed << "M(Y)= " << sery << " - (Среднее арифметическое)\n";
			cout.precision(5);
			cout << fixed << "D(y)= " << dispersiay << " - (Среднее квадратическое отклонение)";

			double YY = 2 * (dispersiay / (sqrt(r)));
			cout.precision(3);
			cout << fixed << "\nДельта Y= ± " << YY << " - (Абсолютная погрешность)";

			double z = serx * sery;
			cout.precision(1);
			cout << fixed << "\nF=m*a= " << z;
			cout.precision(2);
			double zz = sqrt((pow(serx, 2)) * (pow(YY, 2)) + (pow(sery, 2)) * (pow(XX, 2)));
			cout << fixed << "\nДельта F= ± " << zz << " - (Абсолютная погрешность)";
			cout.precision(0);
			cout << fixed << "\nF= (" << z << " ± " << zz << ")\n";
			cout.precision(0);
			cout << fixed << "(" << z << "-" << zz << ")" << " <= F <= " << "(" << z << "+" << zz << ")\n";

			break;
		}
		case 3:
		{
			system("cls");
			cout << s;
			break;
		}
		case 4:
		{
			vihod = true;
			break;
		}

		}

	}
}




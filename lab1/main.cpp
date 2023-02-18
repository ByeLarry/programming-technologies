#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

bool type_flag = false;

//https://ru.onlinemschool.com/math/assistance/matrix/rank/
//Для проверки

double rnd(int min, int max)
{return min + rand() % (1000 * (max - min)) / 1000.0f;}


bool check(string inp) {
	for (char c : inp) {
		if (!isdigit(c) or c == '-' or c == '.') {
			return false;
		}
	}
	return true;
}


 int input() {
	 string inp;
	 cin >> inp;
	 while (!check(inp)) {
		 cout << "Ошибка ввода! \n" << "Повторите: ";
		 cin.clear();
		 cin >> inp;
	 }
	 return stoi(inp);
}


//Шаблон и подсчет ранга матрицы 
template<typename T1, typename T2>
int my_rank(T1 **mat, T2 n, T2 m)
{
	int pivot;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		pivot = i;
		while (pivot < n && abs(mat[pivot][i]) < 0)
		{
			pivot++;
		}

		if (pivot == n)
		{
			continue;
		}

		swap(mat[i], mat[pivot]);
		double div = mat[i][i];
		for (int j = i; j < m; j++)
		{
			mat[i][j] /= div;
		}

		for (int ii = i + 1; ii < n; ii++)
		{
			double mul = mat[ii][i];
			for (int jj = i; jj < m; jj++)
			{
				mat[ii][jj] -= mul * mat[i][jj];
			}
		}
		c++;
	}
	return c;
}





//Перегрузка int
void Matrix(int **mat, int n, int m, int type)
{
	int i, j;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		mat[i][j] = rand();
	}
	cout << endl << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}
cout << endl << "Ранг матрицы: " << my_rank(mat, n, m) << endl;
cout << endl;

//Очистка динамической памяти
for (int i = 0; i < n; i++)
	delete[] mat[i];
delete[] mat;

}



//Перегрузка double
void Matrix(double **mat, int n, int m, int type)
{
	int i, j;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			mat[i][j] = rnd(10, 100);
	}
	cout << endl << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}

cout << endl << "Ранг матрицы: " << my_rank(mat, n, m) << endl ;
cout << endl;

//Очистка динамической памяти
for (int i = 0; i < n; i++)
	delete[] mat[i];
delete[] mat;
}



int main()
{

	int  n = 0, m = 0, type ;
	string imp;
	
	setlocale(LC_ALL, "Rus");
	cout << "Выберите тип данных матрицы: \n";
	cout << "1) Integer \n";
	cout << "2) Double \n";
	type = input();

	//Выбор типа данных
	switch (type)
	{
	case 0:
		type_flag = false;
		break;
	case 1:
		type_flag = true;
		break;
	case 2:
		type_flag = true;
		break;
	default:
		cout << "Данные введены некорректно! \n";
		type_flag = false;
		break;
	}
	
	


	if (type_flag)
	{
		cout << "Введите кол-во строк: ";
		n = input();
		cout << "Введите кол-во столбцов: ";
		m = input();
		if ((n >= 2) && (n <= 15) && (m >= 2) && (m <= 15))
		{
			//Объявление динамической матрицы 
			int i;
			if (type == 1)
			{
				int **mat = new int* [n];
				for (i = 0; i < n; i++)
					mat[i] = new int[m];
				Matrix(mat, n, m, type);
			}
			if (type == 2)
			{
				double **mat = new double* [n];
				for (i = 0; i < n; i++)
					mat[i] = new double[m];
				Matrix(mat, n, m, type);		
			}
			
		}
		else {
			cout << "Данные введены некорректно! \n";
		}
		
	}
	system("Pause");
}
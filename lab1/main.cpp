#include <iostream>
#include <typeinfo>
#include <cstdlib>
using namespace std;

bool type_flag = false;

//https://ru.onlinemschool.com/math/assistance/matrix/rank/
//для проверки

double rnd(int min, int max)
{return min + rand() % (1000 * (max - min)) / 1000.0f;}




//template and rank calculation
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





// overload int
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

//clearing dynamic memory
for (int i = 0; i < n; i++)
	delete[] mat[i];
delete[] mat;

}



// overload double
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

//clearing dynamic memory
for (int i = 0; i < n; i++)
	delete[] mat[i];
delete[] mat;
}



int main()
{
	int type, n, m;
	setlocale(LC_ALL, "Rus");
	cout << "Выберите тип данных матрицы: \n";
	cout << "1) Integer \n";
	cout << "2) Double \n";
	cin >> type;
	
	switch (type)
	{
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
		cout << "Введите кол-во строк и столбцов\n";
		cin >> n >> m;

		if ((n >= 2) and (n <= 15) and (m >= 2) and (m <= 15))
		{
			//initializing dynamic matrix
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
		else
		{cout << "Данные введены некорректно! \n";}
	}
	system("Pause");
}
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Matrix
{
protected:
	int lines_;
	int columns_;
	int** content_;

public:
	Matrix();
	Matrix(int, int, int**);
	~Matrix();
	void printMatrix();
	int getContent(int, int) const;

	Matrix operator- (const Matrix&);
};

int main()
{
	int lines, columns;

	cin >> lines >> columns;

	int** temp = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		temp[i] = new int[columns];
	}

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> temp[i][j];
		}
	}

	Matrix mat_0(lines, columns, temp);

	int** temp_1 = new int* [lines];
	for (int i = 0; i < lines; i++)
	{
		temp_1[i] = new int[columns];
	}

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> temp_1[i][j];
		}
	}

	Matrix mat_1(lines, columns, temp_1);

	Matrix mat = mat_0 - mat_1;
	mat.printMatrix();

	return 0;
}

Matrix::Matrix()
{
	lines_ = 0;
	columns_ = 0;
	content_ = NULL;
}

Matrix::Matrix(int lines, int columns, int** content)
{
	lines_ = lines;
	columns_ = columns;
	content_ = content;
}

Matrix::~Matrix()
{
	for (int i = 0; i < lines_; i++)
	{
		delete[] content_[i];
	}

	delete[] content_;
}

void Matrix::printMatrix()
{
	for (int i = 0; i < lines_; i++)
	{
		for (int j = 0; j < columns_; j++)
		{
			cout << setiosflags(ios::left);
			cout << setw(8) << content_[i][j];
		}
		cout << endl;
	}
}

int Matrix::getContent(int i, int j) const
{
	if (i > lines_ - 1)
	{
		return 0;
	}

	if (j > columns_ - 1)
	{
		return 0;
	}

	return content_[i][j];
}

Matrix Matrix::operator- (const Matrix& mat)
{
	int lines = max(lines_, mat.lines_);
	int columns = max(columns_, mat.columns_);
	
	int** temp = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		temp[i] = new int[columns];
	}

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j] = getContent(i, j) - mat.getContent(i, j);
		}
	}

	return Matrix(lines, columns, temp);
}

#include <iostream>

using namespace std;

int** readMatrix(int, int);
void printMatrix(int**, int, int);
int** transposeMatrix(int**, int, int);
void deleteMatrix(int**, int, int);

int main()
{
    int **mat = readMatrix(4, 4);

    int **trans_mat = transposeMatrix(mat, 4, 4);

    printMatrix(trans_mat, 4, 4);

    deleteMatrix(trans_mat, 4, 4);

	return 0;
}

void printMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << (j == col - 1 ? '\n' : ' ');
        }
    }    
}

int** transposeMatrix(int** origin_matrix, int row, int col)
{
    int **matrix = new int*[col];

    for (int i = 0; i < col; i++)
    {
        matrix[i] = new int[row];
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            matrix[i][j] = origin_matrix[j][i];
        }        
    }

    deleteMatrix(origin_matrix, row, col);

    return matrix;    
}

int** readMatrix(int row, int col)
{
    int **matrix = new int*[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }    

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
        
    }

    return matrix;    
}

void deleteMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

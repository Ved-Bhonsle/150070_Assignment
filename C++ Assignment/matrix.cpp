/*
Create a class called &#39;Matrix&#39; containing a constructor that initialises the number of rows and the
number of columns of a new Matrix object. The Matrix class has the following information:
1 - number of rows of matrix
2 - number of columns of matrix
3 - elements of matrix (You can use 2D vector)
The Matrix class has functions for each of the following:

1 - get the number of rows
2 - get the number of columns
3 - set the elements of the matrix at a given position (i,j)
4 - adding two matrices.
5 - multiplying the two matrices
You can assume that the dimensions are correct for the multiplication and addition.
*/

#include <iostream>
using namespace std;

class Matrix
{
  int rows, cols;
  int arr[10][10];
public:

  void setRows (int r)
  {
    rows = r;
  }

  void setCols (int c)
  {
    cols = c;
  }

  void setElement (int r, int c, int element)
  {
    arr[r][c] = element;
  }

  void addMatrices (Matrix m1, Matrix m2)
  {
    int i, j;
    rows = m1.rows;
    cols = m1.cols;
    for (i = 0; i < rows; i++)
      {
	for (j = 0; j < cols; j++)
	  {
	    arr[i][j] = m2.arr[i][j] + m1.arr[i][j];
	  }
      }
  }

  void mulMatrices (Matrix m1, Matrix m2)
  {
    int i, j, k;
    rows = m1.rows;
    cols = m1.cols;
    for (int i = 0; i < rows; i++)
      {
	for (int j = 0; j < cols; j++)
	  {
	    arr[i][j] = 0;
	    for (int k = 0; k < cols; ++k)
	      {
		arr[i][j] += m2.arr[i][k] * m1.arr[k][j];
	      }
	  }
      }
  }

  void display ()
  {
    int i, j;
    for (i = 0; i < rows; i++)
      {
	for (j = 0; j < cols; j++)
	  {
	    cout << arr[i][j] << " ";
	  }
	cout << endl;
      }
  }

};

int
main ()
{
  int r, c, i, j, element;
  Matrix m1, m2, m3, m4;

  cout << "Enter number of rows for Matrix 1:";
  cin >> r;
  cout << "Enter number of columns for Matrix 1:";
  cin >> c;
  m1.setCols (c);
  m1.setRows (r);

  cout << "Enter number of rows for Matrix 2:";
  cin >> r;
  cout << "Enter number of columns for Matrix 2:";
  cin >> c;
  m2.setCols (c);
  m2.setRows (r);

  cout << "Enter elements for Matrix 1:" << endl;
  for (i = 0; i < r; i++)
    {
      for (j = 0; j < c; j++)
	{
	  cin >> element;
	  m1.setElement (i, j, element);
	}
    }

  cout << "Enter elements for Matrix 2:" << endl;
  for (i = 0; i < r; i++)
    {
      for (j = 0; j < c; j++)
	{
	  cin >> element;
	  m2.setElement (i, j, element);
	}
    }

  cout << endl << "Matrix 1:" << endl;
  m1.display ();
  cout << endl << "Matrix 2:" << endl;
  m2.display ();

  cout << endl << "Addition of the two Matrices: " << endl;
  m3.addMatrices (m1, m2);
  m3.display ();

  cout << endl << "Multiplication of the two Matrices: " << endl;
  m4.mulMatrices (m1, m2);
  m4.display ();

  return 0;
}

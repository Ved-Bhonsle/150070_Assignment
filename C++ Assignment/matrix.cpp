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
	int a[3][3];
	int b[3][3];
	int c[3][3];
	int i,j,k;

	public:
	    void Mult()
		{
		    for (i=0; i<3; i++)
		    {
			for (j=0; j<3; j++)
			{
			    c[i][j]=0;
			    for (k=0; k<3; k++)
			    {
				c[i][j] += a[i][k] * b[k][j];
			    }
			}
		    }
		}
	    void sum()
		{
		    for (i=0; i<3; i++)
		    {
			for (j=0; j<3; j++)
			{
			    c[i][j]=0;
			    for (k=0; k<3; k++)
			    {
				c[i][j] += a[i][k] + b[k][j];
			    }
			}
		    }

		}
	    void InputMatrix()
		{
		    cout << "Enter the values for the first matrix";
		    cout << "\n Matrix 1, Row 1:";
		    for (i=0; i<3; i++)
		    {
			for (j=0; j<3; j++)
			{
			    cin >> a[i][j];
			}
		    }
		    cout << "Enter the values for the second matrix";
		    for (i=0; i<3; i++)
		    {
			for (j=0; j<3; j++)
			{
			    cin >> b[i][j];
			}
		    }

		}
	    void OutputMatrix()
		{
		    cout << "The Resultant Matrix is: \n";
		    for (i=0; i<3; i++)
		    {
			for (j=0; j<3; j++)
			{
			    cout << c[i][j];
			}
			cout << endl;
		    }
		}
};
/*
void Matrix::InputMatrix()
{
    cout << "Enter the values for the first matrix";
    cout << "\n Matrix 1, Row 1:";
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter the values for the second matrix";
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            cin >> b[i][j];
        }
    }
}

void Matrix::sum()
{
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            c[i][j]=0;
            for (k=0; k<3; k++)
            {
                c[i][j] += a[i][k] + b[k][j];
            }
        }
    }
}

void Matrix::Mult()
{
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            c[i][j]=0;
            for (k=0; k<3; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Matrix::OutputMatrix()
{
    cout << "The Resultant Matrix is: \n";
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            cout << c[i][j];
        }
        cout << endl;
    }
}
*/
int main()
{
    Matrix x;
    x.InputMatrix();
    x.Mult();
    x.OutputMatrix();
    x.sum();
    x.OutputMatrix();
    system ("pause");
    return 0;
}

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Matrix.h"
using namespace std;
int main()
{
	
	matrix<int> m1(3, 3);
	matrix<int> m2(3, 2);
	matrix<int> m3{ { 1, 2, 3 },{ 2, 3, 4 },{ 2, 3, 4 } };
	matrix<int> m4(3, 5);
	matrix<int> m5(3, 3);
	matrix<int> m6{ { 3, 0, -1, 2 },{ 4, 1, 3, -2 },{ 0, 2, -1, 3 },{ 1, 0, 1, 4 } };
	matrix<int> m7(4, 4);
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 2, 3, 4 };

	cout << "m3 =\n";
	cout << m3 << endl;
	m1.read(istringstream("57 23 4 4 8 9 6 32 4"));
	m2.read(istringstream("1 5 9 3 0 0"));
	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2;
	cout << "m1 + m3\n";
	cout << m1 + m3 << endl;
	cout << "m1 = " << endl << m1 << endl;
	cout << "m2 = " << endl << m2 << endl;
	cout << "m5 += m1 += m1\n";
	cout << (m5 += (m1 += m1)) << endl;
	cout << "m1 = " << endl << m1 << endl;
	cout << "m5 = " << endl << m5 << endl;
	matrix<int> q{ 3,3 };
	cout << "q:\n";
	cout << q;
	cout << "q = m1 + m3 + m5\n";
	q = m1 + m3 + m5;
	cout << "q = " << endl << q << endl;
	cout << "m1 = " << endl << m1 << endl;
	cout << "m3 = " << endl << m3 << endl;
	cout << "m5 = " << endl << m5 << endl;
	cout << "m1 += m5\n";
	m1 += m5;
	cout << "m1 = " << endl << m1 << endl;
	cout << "m5 = " << endl << m2 << endl;
	cout << "m6 += m7\n";
	m6 += m7;
	cout << "m6 = " << endl << m6 << endl;
	cout << "m7 = " << endl << m7 << endl;
	cout << "m6.numrows() = " << m6.numrows() << endl;
	cout << "m6.numcols() = " << m6.numcols() << endl;
	cout << "Element at row 1 col 3 in matrix m6 = " << m6[1][3] << endl << endl;

	cout << "Row 2 in matrix m6=\n";
	vector<int> m6a = m6.row(2);
	for (auto &x : m6a)
		cout << x << " ";
	cout << "\nCol 3 in matrix q5=\n";
	vector<int> m6b = m6.col(3);
	for (auto &x : m6b)
		cout << x << " ";
	cout << "\n(Row 2) dot (Col 3) = " << dot(m6a, m6b) << endl << endl;
	cout << "m6.transpose\n";
	cout << m6.t() << endl;

	matrix<int> m20;
	cout << "m20 = " << endl << m20 << endl;
	cout << "m20.numrows() = " << m20.numrows() << endl;
	cout << "m20.numcols() = " << m20.numcols() << endl;
	cout << "m20.transpose\n";
	cout << m20.t() << endl;
	cout << "Determinant of m20 = " << m20.det() << endl;

	for (int i{ 1 }; i <= 10; i++)
		cout << "I(" << i << ") = " << endl << eye<int>(i) << endl;
	for (int i{ 1 }; i <= 10; i++)
		cout << "zeros(" << i << "," << i << ") = " << endl << zeroes<int>(i, i) << endl;
	for (int i{ 1 }; i <= 10; i++)
		cout << "ones(" << i << "," << i << ") = " << endl << ones<int>(i, i) << endl;

	cout << "m1:\n";
	cout << m1;
	cout << "m2:\n";
	cout << m2;
	cout << "m1 * m2\n";
	cout << m1 * m2 << endl;
	cout << "m1 = " << endl << m1 << endl;
	cout << "m2 = " << endl << m2 << endl;
	cout << "m1*3\n";
	cout << m1 * 3 << endl;
	cout << "m1 *= 10\n";
	m1 *= 10;
	cout << "m1 = " << endl << m1 << endl;
	cout << "m1.transpose\n";
	cout << m1.t() << endl;
	cout << "m1 = " << endl << m1 << endl;
	cout << "v1 = " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "v2 = " << v2[0] << " " << v2[1] << " " << v2[2] << endl;
	cout << "v1 dot v2 = " << dot(v1, v2) << endl;
	cout << "m1:\n";
	cout << m1;
	cout << "Testing the creation of new array from m1 by removing row " << m1.numrows() - 1
		<< " of m1 " << endl;
	cout << m1.deleteRow(m1.numrows() - 1) << endl;
	cout << "Testing the creation of new array from m1 by removing col " << m1.numcols() - 1
		<< " of m1 " << endl;
	cout << m1.deleteCol(m1.numcols() - 1) << endl;
	cout << "m6:\n";
	cout << m6 << endl;
	cout << "Determinant of m6 = " << m6.det() << endl;
	cout << "m7 = I(4):" << endl << (m7 = eye<int>(4)) << endl;
	cout << "zeroes(4,4):" << endl << zeroes<int>(4, 4) << endl;
	cout << "ones(4,4):" << endl << ones<int>(4, 4) << endl;

	matrix<double> q2{ {1.5, 2.0, 3.66, 4.7, 5.1, 6.05, 7.5},
						{0, 8.5, 63.0, 45.5, 12.5, 56.3, 1 } };
	matrix<double> q3{ { 1.5, 2.0, 3.66, 4.7, 5.1},
						{ 0, 8.5, 63.0, 45.5, 12.5 } ,
						{ 1.5, 2.0, 3.66, 4.7, 5.1 },
						{ 0, 8.5, 63.3, 45.5, 12.5} ,
						{ 1.5, 2.0, 3.66, 4.7, 5.1 },
						{ 0, 8.5, 63.0, 45.5, 12.5 },
						{1,2,3,4,5} };
	matrix<double> q10{ { 6.3, 8.0, 3.76, 5.7, 5.1 },
						{1,2,3,4,5},
						{6,7,8,9,10},
						{11,12,13,14,15},
						{16,17,18,19,20} };
	cout << "q2 = " << endl << q2 << endl;
	cout << "q3 = " << endl << q3 << endl;
	cout << "matrix<double> q4{ q2*q3 }\n";
	matrix<double> q4{ q2*q3 };
	cout << "q4 = " << endl << q4 << endl;

	cout << "q4.transpose\n";
	cout << q4.t() << endl;

	matrix<double> q11{ 2,5 };
	cout << "q11 = q2 * q3 * q10\n";
	q11 = q2 * q3 * q10;
	cout << "q2 = " << endl << q2 << endl;
	cout << "q3 = " << endl << q3 << endl;
	cout << "q10 = " << endl << q10 << endl;
	cout << "q11 = " << endl << q11 << endl;
	matrix<double> q12;
	cout << "q12 = " << endl << q12 << endl;
	cout << "q10 += ones(5,5)\n";
	q10 += ones<double>(5, 5);
	cout << "q10 = " << endl << q10 << endl;

	ofstream outfile;
	outfile.open("bigmatrix1.txt");
	for (int i{}; i < 100 * 50; i++) {
		outfile << (rand() % 100) << " ";
	}
	outfile.close();
	matrix<int> m100{ 100,50 };
	ifstream infile{ "bigmatrix1.txt" };
	m100.read(infile);
	cout << "m100 = " << endl << m100 << endl;

	cout << "m100.numrows() = " << m100.numrows() << endl;
	cout << "m100.numcols() = " << m100.numcols() << endl;
	cout << "Element at row 55 col 13 in matrix q5 = " << m100[55][13] << endl << endl;
	cout << "Row 20 in m100=\n";
	vector<int> m100a = m100.row(20);
	for (auto &x : m100a)
		cout << x << " ";
	cout << "\nCol 13 in m100=\n";
	vector<int> m100b = m100.col(13);
	for (auto &x : m100b)
		cout << x << " ";
	cout << "\n(Row 20) dot (Col 13) = " << dot(m100a, m100b) << endl << endl;
	cout << "m100.transpose\n";
	cout << m100.t() << endl;

	ofstream outfile2;
	outfile2.open("bigmatrix2.txt");
	for (int i{}; i < 100 * 50; i++) {
		outfile2 << (rand() % 100) << " ";
	}
	outfile2.close();
	matrix<int> m100_2{ 100,50 };
	ifstream infile2{ "bigmatrix2.txt" };
	m100_2.read(infile2);
	cout << "m100_2 = " << endl << m100_2 << endl;

	cout << "m100_2.numrows() = " << m100_2.numrows() << endl;
	cout << "m100_2.numcols() = " << m100_2.numcols() << endl;
	cout << "Element at row 6 col 45 in matrix q5 = " << m100[6][45] << endl << endl;
	cout << "Row 6 in m100_2=\n";
	vector<int> m100_2a = m100_2.row(6);
	for (auto &x : m100_2a)
		cout << x << " ";
	cout << "\nCol 45 in m100_2=\n";
	vector<int> m100_2b = m100_2.col(45);
	for (auto &x : m100_2b)
		cout << x << " ";
	cout << "\n(Row 6) dot (Col 45) = " << dot(m100_2a, m100_2b) << endl << endl;
	cout << "m100_2.transpose\n";
	cout << m100_2.t() << endl;

	matrix<int> m100_3{ 100,50 };
	cout << "m100_3 = m100 + m100_2\n";
	m100_3 = m100 + m100_2;
	cout << "m100_3 = " << endl << m100_3 << endl;
	cout << "m100_3.transpose\n";
	cout << m100_3.t() << endl << endl;
	
	ofstream outfile3;
	outfile3.open("bigmatrix3.txt");
	for (int i{}; i < 10*10; i++) {
		outfile3 << (rand() % 100) << " ";
	}
	outfile3.close();
	matrix<int> q5{ 10,10 };
	ifstream infile3{ "bigmatrix3.txt" };
	q5.read(infile3);
	cout << "q5 = " << endl << q5 << endl;
	
	cout << "q5.numrows() = " << q5.numrows() << endl;
	cout << "q5.numcols() = " << q5.numcols() << endl;
	cout << "Element at row 2 col 2 in matrix q5 = " << q5[2][2] << endl << endl;
	
	cout << "Row 5 in matrix q5=\n";
	vector<int> q5a = q5.row(5);
	for (auto &x : q5a)
		cout << x << " ";
	cout << "\nCol 5 in matrix q5=\n";
	vector<int> q5b = q5.col(5);
	for (auto &x : q5b)
		cout << x << " ";
	cout << "\n(Row 5) dot (Col 5) = " << dot(q5a, q5b) << endl << endl;

	cout << "remove row " << q5.numrows() - 5 << " of q5 " << endl;
	cout << q5.deleteRow(q5.numrows() - 5) << endl;
	cout << "remove col " << q5.numcols() - 5 << " of q5 " << endl;
	cout << q5.deleteCol(q5.numcols() - 5) << endl;

	cout << "q5.transpose\n";
	cout << q5.t() << endl;

	matrix<int> q6 = q5*eye<int>(10);
	for (int i = 0; i < q6.numrows(); i++)
		for (int j = 0; j < q6.numcols(); j++)
			assert(q6[i][j] == q5[i][j]);

	cout << "Calculating determinant of q5...\n";
	cout << "=" << q5.det() << endl;
	return 0;
}
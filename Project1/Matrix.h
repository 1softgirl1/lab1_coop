#pragma once
#include <iostream>
using namespace std;

class Matrix
{
	private:
		int rows_, cols_;
		double** matrix_;

	public:
		Matrix();// ����������� �� ���������
		Matrix(int, int); // ����������� � �����������
		Matrix(int, int, double); // ����������� � �����������
		~Matrix();
		void print();
		void SetValue(int, int, double);
		Matrix(const Matrix& m);
		Matrix(Matrix&& m);

		bool EqMatrix(const Matrix& other);
		void SumMatrix(const Matrix& other);
		void SubMatrix(const Matrix& other);
		void MulNumber(const double num);
		void MulMatrix(const Matrix& other);
		Matrix Transpose();
		Matrix CalcComplements();
		double Determinant();
		Matrix InverseMatrix();
		Matrix operator+(const Matrix& other) const;
		Matrix operator-(const Matrix& other) const;
		Matrix operator*(const Matrix& other) const;
		Matrix operator*(double scalar) const;
		bool operator==(const Matrix& other) const;
		Matrix& operator=(const Matrix& other);
		Matrix& operator+=(const Matrix& other);
		Matrix& operator-=(const Matrix& other);
		Matrix& operator*=(const Matrix& other);
		Matrix& operator*=(double scalar);
		double& operator()(int i, int j);
		const double& operator()(int i, int j) const;

};

int main() {
	setlocale(LC_ALL, "Russian");
	// ��������� ����������� �� ���������
	Matrix matDefault;
	cout << "\n������� �� ��������� (3x3):" << endl;
	matDefault.print();

	// ��������� ����������� � �����������
	Matrix matParam(2, 2);
	cout << "\n������� � ����������� (2x2):" << endl;
	matParam.print();

	// ��������� ����������� � ����������� � �����������
	Matrix matFilled(3, 3, 5.0);
	cout << "\n�������, ����������� 5.0 (3x3):" << endl;
	matFilled.print();

	// ��������� ��������
	Matrix sumResult = matFilled; 
	sumResult.SumMatrix(matFilled); 
	cout << "\n��������� �������� ������� � ����� �����:" << endl;
	sumResult.print();


	// ��������� ���������
	Matrix subResult = sumResult; 
	subResult.SubMatrix(matFilled); 
	cout << "\n��������� ���������:" << endl;
	subResult.print();

	// ��������� ��������� �� �����
	Matrix mulResult = matFilled; 
	mulResult.MulNumber(2.0); 
	cout << "\n��������� ��������� �� 2.0:" << endl;
	mulResult.print();

	// ��������� ��������� ������
	if (matFilled.EqMatrix(mulResult)) {
		cout << "\n������� �����." << endl;
	}
	else {
		cout << "\n������� �� �����." << endl;
	}

	// ��������� ����������� �����������
	Matrix copyMat = matFilled; 
	cout << "\n����� �������:" << endl;
	copyMat.print();
	
	Matrix matA(2, 2);
	matA.SetValue(0, 0, 1);
	matA.SetValue(0, 1, 2);
	matA.SetValue(1, 0, 3);
	matA.SetValue(1, 1, 4);

	Matrix matB(2, 2);
	matB.SetValue(0, 0, 5);
	matB.SetValue(0, 1, 6);
	matB.SetValue(1, 0, 7);
	matB.SetValue(1, 1, 8);

	cout << "\n������� A:" << endl;
	matA.print();

	cout << "\n������� B:" << endl;
	matB.print();

	// ��������� ��������� ������
	Matrix mulResult1 = matA; 
	mulResult1.MulMatrix(matB); 
	cout << "\n��������� ��������� A * B:" << endl;
	mulResult1.print();

	// ��������� ����������������
	Matrix transposed = matA.Transpose();
	cout << "\n����������������� ������� A:" << endl;
	transposed.print();

	// ��������� ���������� �������������� ����������
	Matrix complements = matA.CalcComplements();
	cout << "\n�������������� ���������� ������� A:" << endl;
	complements.print();

	// ��������� ������������
	double det = matA.Determinant();
	cout << "\n������������ ������� A: " << det << endl;

	// ��������� �������� �������
	Matrix inverse = matA.InverseMatrix();
	cout << "\n�������� ������� A:" << endl;
	inverse.print();

	// ��������� �������� ������
	Matrix sumResult2 = matA + matB;
	cout << "\n��������� A + B:" << endl;
	sumResult2.print();

	// ��������� ��������� ������
	Matrix subResult2  = matA - matB;
	cout << "\n��������� A - B:" << endl;
	subResult2.print();

	// ��������� ��������� ������
	Matrix mulResult2 = matA * matB;
	cout << "\n��������� A * B:" << endl;
	mulResult2.print();

	// ��������� ��������� �� ������
	double scalar = 2.0;
	Matrix scalarMulResult = matA * scalar;
	cout << "\n��������� A * " << scalar << ":" << endl;
	scalarMulResult.print();

	// ��������� �������� ���������
	bool isEqual = (matA == matB);
	cout << "\n������� A � B �����? " << (isEqual ? "��" : "���") << endl;

	// ��������� �������� ������������
	Matrix matC = matA; 
	cout << "\n������� C (����� A):" << endl;
	matC.print();

	// �������� ������� C � ��������� ���������
	matC.SetValue(0, 0, 10);
	cout << "\n����� ��������� C:" << endl;
	matC.print();

	isEqual = (matA == matC);
	cout << "\n������� A � C �����? " << (isEqual ? "��" : "���") << endl;

	// ��������� �������� ��������� �� ������ (operator+=)
	matA += matB;
	cout << "\n��������� A += B " <<  endl;
	matA.print();

	// ��������� �������� ��������� �� ������ (operator+=)
	matA -= matB;
	cout << "\n��������� A -= B " << endl;
	matA.print();

	// ��������� �������� ��������� �� ������� (operator*=)
	matA *= matB;
	cout << "\n��������� A *= B:" << endl;
	matA.print(); 

	// ��������� �������� ��������� �� ������ (operator*=)
	double scalar2 = 2.0;
	matA *= scalar2;
	cout << "\n��������� A *= " << scalar2 << ":" << endl;
	matA.print(); 

	// ��������� �������� ������� ()
	try {
		cout << "\n�������� A(1,1): " << matA(1, 1) << endl; 
		cout << "\n�������� A(2,2): " << matA(2, 2) << endl; 
	}
	catch (const std::out_of_range& e) {
		cout << e.what() << endl; 
	}


	return 0;
};

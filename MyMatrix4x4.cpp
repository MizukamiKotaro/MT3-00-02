#include "MyMatrix4x4.h"
#include "MyMatrix3x3.h"

MyMatrix4x4 MyMatrix4x4::Add(const MyMatrix4x4& m1, const MyMatrix4x4& m2) {
	MyMatrix4x4 result = {};
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			result.m[row][column] = m1.m[row][column] + m2.m[row][column];
		}
	}
	return result;
}

MyMatrix4x4 MyMatrix4x4::Subtract(const MyMatrix4x4& m1, const MyMatrix4x4& m2) {
	MyMatrix4x4 result = {};
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			result.m[row][column] = m1.m[row][column] - m2.m[row][column];
		}
	}
	return result;
}

MyMatrix4x4 MyMatrix4x4::Multiply(const MyMatrix4x4& m1, const MyMatrix4x4& m2) {
	MyMatrix4x4 result = {};
	for (int i = 0; i < 4; i++) {
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				result.m[i][row] += m1.m[i][column] * m2.m[column][row];
			}
		}
	}
	return result;
}

MyMatrix4x4 MyMatrix4x4::Multiply(const float num, const MyMatrix4x4& m) {
	MyMatrix4x4 result = {};
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			result.m[row][column] = num * m.m[row][column];
		}
	}
	return result;
}

MyMatrix4x4 MyMatrix4x4::Inverse(const MyMatrix4x4& m) {
	MyMatrix4x4 result = {};
	
	float A[4] = {};

	//小行列
	MyMatrix3x3 b[4][4] = {};
	int B[4][4] = {};
	for (int i = 0; i < 4; i++) {
		A[i] = m.m[i][0];
		for(int j=0;j<4;j++){
			B[i][j] = i + j;
			for (int row = 0; row < 3; row++) {
				for (int column = 0; column < 3; column++) {
					if (i <= row) {
						if (j <= column) {
							b[i][j].m[row][column] = m.m[row + 1][column + 1];
						}
						else {
							b[i][j].m[row][column] = m.m[row + 1][column];
						}
					}
					else {
						if (j <= column) {
							b[i][j].m[row][column] = m.m[row][column + 1];
						}
						else {
							b[i][j].m[row][column] = m.m[row][column];
						}
					}
				}
			}
		}
	}

	float num = 0;

	MyMatrix4x4 c = {};
	for (int row = 0; row < 4; row++) {
		if (row == 0 || row == 2) {
			num += A[row] * MyMatrix3x3::SarrasRule(b[row][0]);
		}
		else {
			num -= A[row] * MyMatrix3x3::SarrasRule(b[row][0]);
		}
		for (int column = 0; column < 4; column++) {
			if (B[row][column] % 2 == 0) {
				c.m[row][column] = MyMatrix3x3::SarrasRule(b[column][row]);
			}
			else {
				c.m[row][column] = -1 * MyMatrix3x3::SarrasRule(b[column][row]);
			}
		}
	}

	if (num != 0) {
		num = float(1 / num);
	}

	result = Multiply(num, c);

	return result;
}

//転置行列
MyMatrix4x4 MyMatrix4x4::Transpose(const MyMatrix4x4& m) {
	MyMatrix4x4 result = {};
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			result.m[row][column] = m.m[column][row];
		}
	}
	return result;
}

//単位行列
MyMatrix4x4 MyMatrix4x4::MakeIdentity4x4() {
	MyMatrix4x4 result = {};
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			if (row == column) {
				result.m[row][column] = 1;
			}
			else {
				result.m[row][column] = 0;
			}
		}
	}
	return result;
}
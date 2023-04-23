#include "MyMatrix3x3.h"

MyMatrix3x3 MyMatrix3x3::Add (const MyMatrix3x3 m1, const MyMatrix3x3& m2) {
	MyMatrix3x3 result = {};
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			result.m[row][column] = m1.m[row][column] + m2.m[row][column];
		}
	}
	return result;
}

MyMatrix3x3 MyMatrix3x3::Subtract(const MyMatrix3x3& m1, const MyMatrix3x3& m2) {
	MyMatrix3x3 result = {};
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			result.m[row][column] = m1.m[row][column] - m2.m[row][column];
		}
	}
	return result;
}

MyMatrix3x3 MyMatrix3x3::Multiply(const MyMatrix3x3& m1, const MyMatrix3x3& m2) {
	MyMatrix3x3 result = {};
	for (int i = 0; i < 3; i++) {
		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				result.m[i][row] += m1.m[i][column] * m2.m[column][row];
			}
		}
	}
	return result;
}

MyMatrix3x3 MyMatrix3x3::Multiply(const float& num, const MyMatrix3x3& m) {
	MyMatrix3x3 result = {};
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			result.m[row][column] = m.m[row][column] * num;
		}
	}
	return result;
}

float MyMatrix3x3::SarrasRule(const MyMatrix3x3& m) {
	float result = m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] + m.m[0][2] * m.m[1][0] * m.m[2][1] -
		m.m[0][2] * m.m[1][1] * m.m[2][0] - m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1];
	return result;
}




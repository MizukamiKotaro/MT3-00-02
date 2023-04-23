#pragma once

class MyMatrix3x3 
{
public:
	static MyMatrix3x3 Add(const MyMatrix3x3 m1, const MyMatrix3x3& m2);

	static MyMatrix3x3 Subtract(const MyMatrix3x3& m1, const MyMatrix3x3& m2);

	static MyMatrix3x3 Multiply(const MyMatrix3x3& m1, const MyMatrix3x3& m2);

	static MyMatrix3x3 Multiply(const float& num, const MyMatrix3x3& m);

	static float SarrasRule(const MyMatrix3x3& m);

public:
	float m[3][3];
};


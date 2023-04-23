#pragma once

class MyMatrix4x4
{
public:
	static MyMatrix4x4 Add(const MyMatrix4x4& m1, const MyMatrix4x4& m2);

	static MyMatrix4x4 Subtract(const MyMatrix4x4& m1, const MyMatrix4x4& m2);

	static MyMatrix4x4 Multiply(const MyMatrix4x4& m1, const MyMatrix4x4& m2);

	static MyMatrix4x4 Multiply(const float num, const MyMatrix4x4& m);

	static MyMatrix4x4 Inverse(const MyMatrix4x4& m);

	//転置行列
	static MyMatrix4x4 Transpose(const MyMatrix4x4& m);

	//単位行列
	static MyMatrix4x4 MakeIdentity4x4();

public:
	float m[4][4];
};
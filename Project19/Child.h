#pragma once

#include "Parent.h"

class Child : Parent
{

public:

	//�����������
	Child(std::string path_file);

	//����������
	~Child();

	// ����� / ������
	void toString() override;

	// ���������� ������ � ����� �������� � ����
	void saveStudent(std::string path_file);

	// ������� ����������� ����� � ��������
	void addAge(int number, int year);

};


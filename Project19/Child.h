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

	//�������� ������ � ��������
	void deleteStudent(std::string path_file);

	// ������� ����������� ����� � ��������
	void addAge(std::string path_file);

};


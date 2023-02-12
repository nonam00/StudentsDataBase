#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

//��������� �������� ��� ��������� �������� ������ � ������
struct Student
{
	//���
	std::string name;

	//�������
	int age;

	//�����������
	Student(std::string _name, int _age) : name{ _name }, age{ _age } {};

	//������ �����
	std::string Name() { return name; }
	
	//������ ��������
	int Age() { return age; }

	//������ ��������
	void Age(int _age) { age = _age; }

	//���������� ���
	bool Name(std::string _name) { return (name == _name); }

};

class Parent
{
public:

	//������ ����������� �� ��������� ��� ��������� ������
	Parent();

	//�����������
	Parent(std::string path_file);

	//����� / ������
	virtual void toString();

protected:

	//������ ���������� ���� ������ ��� ���� ���������
	std::vector<Student> students;

};
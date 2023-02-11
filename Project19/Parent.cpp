#include "Parent.h"

//������ ����������� �� ��������� ��� ��������� ������ ��� ������������ ������
Parent::Parent() {}

//�����������
Parent::Parent(std::string path_file)
{
	//����� �� ������ �����
	std::ifstream file(path_file);
	//����� ����������� ������ �����
	std::string str;

	//����� ��� �������� �����
	char* _name = new char[20];
	//����� ��� �������� ��������
	int _age;

	while (!file.eof())
	{
		//���������� ������ ����� � �����
		getline(file, str);

		if (str == "")
			continue;

		//���������� � ������ � ����������
		sscanf_s(str.data(), "%s %d", _name, 10, &_age);

		//�������� ���������� ������ � ������ � �������� ������� ������ Student
		students.push_back(Student(_name, _age));
	}
	//�������� �����
	file.close();
	//������� ������ ������ �����
	delete[]_name;
}

//����� / ������
void Parent::toString()
{
	std::for_each(students.begin(), students.end(), [](Student item) {std::cout << item.Name() << " " << item.Age() << std::endl; });
}

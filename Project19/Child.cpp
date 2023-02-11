#include "Child.h"

//�����������
Child::Child(std::string path_file)
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

//����������
Child::~Child()
{

}

// ����� / ������
void Child::toString()
{
	std::for_each(students.begin(), students.end(), [](Student item) {std::cout << item.Name() << " " << item.Age() << std::endl; });
}

// ���������� ������ � ����� �������� � ����
// ��������� ���������� ����� ��������� � ������ ��� ��������� ������� ���������
void Child::saveStudent(std::string path_file)
{
	//��� ������ ��������
	std::string new_name;
	//����
	std::cin >> new_name; std::cout << std::endl;

	//������� ������ ��������
	int new_age;
	//����
	std::cin >> new_age; std::cout << std::endl;

	//����� �� ���������� ���������� � ����
	std::ofstream file(path_file, std::ios_base::app);
	//������ ������ � ����
	file << "\n" << new_name << " " << new_age;

	//�������� �����
	file.close();
}

// ������� ����������� ����� � ��������
// �� ���������
void Child::addAge(int number, int year)
{

}

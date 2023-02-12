#include "Child.h"

//������� �����
void clear(std::string path_file)
{
	std::ofstream del_file(path_file);
	del_file << "";
	del_file.close();
}

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
Child::~Child() {}

// ����� / ������
void Child::toString()
{
	std::for_each(students.begin(), students.end(), [](Student item) {std::cout << item.Name() << " " << item.Age() << std::endl; });
}

// ���������� ������ � ����� �������� � ����
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

	//���������� ������ � ������
	students.push_back(Student(new_name, new_age));

	//�������� �����
	file.close();
}

void Child::deleteStudent(std::string path_file)
{
	//��� �������� ��� ��������
	std::string to_del;
	std::cin >> to_del; std::cout << std::endl;

	//������� �����
	clear(path_file);

	//�������� ������ �� ������
	std::ofstream file(path_file, std::ios_base::app);

	//������� ��� �������� �������� ������� �� ���������
	int i = 0;

	//������ � ����
	for (auto item : students)
	{
		//�������� �� ������� ��������
		if (item.Name(to_del))
		{
			//�������� ��������
			students.erase(std::next(students.begin() + i -1));
			continue;
		}
		//���������� ��������� � ����
		file << "\n" << item.Name() << " " << item.Age();
		i++;
	}
	file.close();
}

// ������� ����������� 2 � ��������
void Child::addAge(std::string path_file)
{
	//��� �������� ��� ��������������
	std::string to_edit;
	std::cin >> to_edit; std::cout << std::endl;

	//������� �����
	clear(path_file);

	//�������� ������ �� ������
	std::ofstream file(path_file, std::ios_base::app);

	//������ � ����
	for (auto item : students)
	{
		//�������� �� ������� ��������
		if (item.Name(to_edit))
			//��������� �������� ��������
			item.Age(item.Age() + 2);
		//���������� ��������� � ����
		file << "\n" << item.Name() << " " << item.Age();
	}
	file.close();
}

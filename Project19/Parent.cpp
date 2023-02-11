#include "Parent.h"

//пустой конструктор по умолчанию для избежания ошибок при наследовании класса
Parent::Parent() {}

//конструктор
Parent::Parent(std::string path_file)
{
	//поток на чтение файла
	std::ifstream file(path_file);
	//буфер считываемой строки файла
	std::string str;

	//буфер для передачи имени
	char* _name = new char[20];
	//буфер для передачи возраста
	int _age;

	while (!file.eof())
	{
		//считывание строки файла в буфер
		getline(file, str);

		if (str == "")
			continue;

		//считывание с буфера в переменные
		sscanf_s(str.data(), "%s %d", _name, 10, &_age);

		//передача полученных данных в вектор в качестве объекта класса Student
		students.push_back(Student(_name, _age));
	}
	//закрытие файла
	file.close();
	//очистка памяти буфера имени
	delete[]_name;
}

//вывод / печать
void Parent::toString()
{
	std::for_each(students.begin(), students.end(), [](Student item) {std::cout << item.Name() << " " << item.Age() << std::endl; });
}

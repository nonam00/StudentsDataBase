#include "Child.h"

//конструктор
Child::Child(std::string path_file)
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

//деструктор
Child::~Child()
{

}

// вывод / печать
void Child::toString()
{
	std::for_each(students.begin(), students.end(), [](Student item) {std::cout << item.Name() << " " << item.Age() << std::endl; });
}

// добавление данных о новом студенте в файл
// изменённая информация будет добавлена в вектор при повторном запуске программы
void Child::saveStudent(std::string path_file)
{
	//имя нового студента
	std::string new_name;
	//ввод
	std::cin >> new_name; std::cout << std::endl;

	//возраст нового студента
	int new_age;
	//ввод
	std::cin >> new_age; std::cout << std::endl;

	//поток на добавление информации в файл
	std::ofstream file(path_file, std::ios_base::app);
	//запись данных в файл
	file << "\n" << new_name << " " << new_age;

	//закрытие файла
	file.close();
}

// функция прибавления числа к возрасту
// не завершена
void Child::addAge(int number, int year)
{

}

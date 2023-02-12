#include "Child.h"

//очистка файла
void clear(std::string path_file)
{
	std::ofstream del_file(path_file);
	del_file << "";
	del_file.close();
}

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
Child::~Child() {}

// вывод / печать
void Child::toString()
{
	std::for_each(students.begin(), students.end(), [](Student item) {std::cout << item.Name() << " " << item.Age() << std::endl; });
}

// добавление данных о новом студенте в файл
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

	//добавление данных в вектор
	students.push_back(Student(new_name, new_age));

	//закрытие файла
	file.close();
}

void Child::deleteStudent(std::string path_file)
{
	//имя студента для удаления
	std::string to_del;
	std::cin >> to_del; std::cout << std::endl;

	//очистка файла
	clear(path_file);

	//открытие потока на запись
	std::ofstream file(path_file, std::ios_base::app);

	//счётчик для удаления элемента вектора по итератору
	int i = 0;

	//запись в файл
	for (auto item : students)
	{
		//проверка на нужного студента
		if (item.Name(to_del))
		{
			//удаление студента
			students.erase(std::next(students.begin() + i -1));
			continue;
		}
		//перезапись студентов в файл
		file << "\n" << item.Name() << " " << item.Age();
		i++;
	}
	file.close();
}

// функция прибавления 2 к возрасту
void Child::addAge(std::string path_file)
{
	//имя студента для редактирования
	std::string to_edit;
	std::cin >> to_edit; std::cout << std::endl;

	//очистка файла
	clear(path_file);

	//открытие потока на запись
	std::ofstream file(path_file, std::ios_base::app);

	//запись в файл
	for (auto item : students)
	{
		//проверка на нужного студента
		if (item.Name(to_edit))
			//изменение значения возраста
			item.Age(item.Age() + 2);
		//перезапись студентов в файл
		file << "\n" << item.Name() << " " << item.Age();
	}
	file.close();
}

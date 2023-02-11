#pragma once

#include "Parent.h"

class Child : Parent
{

public:

	//конструктор
	Child(std::string path_file);

	//деструктор
	~Child();

	// вывод / печать
	void toString() override;

	// добавление данных о новом студенте в файл
	void saveStudent(std::string path_file);

	// функция прибавления числа к возрасту
	void addAge(int number, int year);

};


#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

//структура студента для коректной передачи данных в вектор
struct Student
{
	//имя
	std::string name;

	//возраст
	int age;

	//конструктор
	Student(std::string _name, int _age) : name{ _name }, age{ _age } {};

	//геттер имени
	std::string Name() { return name; }
	
	//геттер возраста
	int Age() { return age; }

	//сеттер возраста
	void Age(int _age) { age = _age; }

	//стравнение имён
	bool Name(std::string _name) { return (name == _name); }

};

class Parent
{
public:

	//пустой конструктор по умолчанию для избежания ошибок
	Parent();

	//конструктор
	Parent(std::string path_file);

	//вывод / печать
	virtual void toString();

protected:

	//вектор содержащий себе данные обо всех студентах
	std::vector<Student> students;

};
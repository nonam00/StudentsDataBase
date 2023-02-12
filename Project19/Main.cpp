//программа не завершена до конца, но задание поставленное в прикреплЄнном комментарии выполнено

#include "Child.h"

int main()
{
	// создание экземпл€ра класса Child
	Child st("text.txt");

	// вывод данных о студентах
	st.toString();

	// добавление данных о новом студенте в файл
	//st.saveStudent("text.txt");
	
	//+2 к возрасту выбранного студента
	//st.addAge("text.txt");
	
	//удаление студента
	//st.deleteStudent("text.txt");

	st.toString();
	return 0;
}
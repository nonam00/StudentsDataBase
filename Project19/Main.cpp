//��������� �� ��������� �� �����, �� ������� ������������ � ������������ ����������� ���������

#include "Child.h"

int main()
{
	// �������� ���������� ������ Child
	Child st("text.txt");

	// ����� ������ � ���������
	st.toString();

	// ���������� ������ � ����� �������� � ����
	//st.saveStudent("text.txt");

	//st.addAge("text.txt");
	st.deleteStudent("text.txt");
	st.toString();
	return 0;
}
#ifndef ALLOCATION_AND_SEND_H
#define ALLOCATION_AND_SEND_H
#include <string>

using namespace std;

class allocation_and_send{
	string file_with_picture;
	string name_of_file_with_face;
	public:
		void allocator(string file_with_picture);//���������� ���� �� �������� �� �����(file_with_picture)
		void sender(string name_of_file_with_face);//���������� � ����(name_of_file_with_face) �������� � ������������ �����, ������� ���� ����� ����� �������
};

#endif

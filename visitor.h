#ifndef VISIYIR_H
#define VISITOR_H
#include <vector>
#include <string>

using namespace std;

class visitor{
	string name;
	public:
		visitor(string name);//������ ��� ����������
		void show(string name);//������� ��, ��� � �������
		//~visitor();
};
/*
class allocation_and_send{
	string file_with_picture;
	string name_of_file_with_face;
	public:
		void allocator(string file_with_picture);//���������� ���� �� �������� �� �����(file_with_picture)
		void sender(string name_of_file_with_face);//���������� � ����(name_of_file_with_face) �������� � ������������ �����, ������� ���� ����� ����� �������
};

class identification{
	string name_of_file_with_face;//��������� ���� � �������� sender() �� ������ allocation_and_send
	vector <string> basa_of_faces;//� ������� �������� ������ � ������� ��������, ������������ ����
	public:
		void identificator(vector <string> basa_of_faces, string name_of_file_with_face);//���������� �������� �� �����(name_of_file_with_face) �� ����� ���������� �� ����, ���������� "0" � �������� ���, ���� ��, ���������� "1", ���� ���
};
*/
#endif

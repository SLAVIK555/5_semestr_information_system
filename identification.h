#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H
#include <vector>
#include <string>

using namespace std;

class identification{
	string name_of_file_with_face;//��������� ���� � �������� sender() �� ������ allocation_and_send
	vector <string> basa_of_faces;//� ������� �������� ������ � ������� ��������, ������������ ����
	public:
		void identificator(vector <string> basa_of_faces, string name_of_file_with_face);//���������� �������� �� �����(name_of_file_with_face) �� ����� ���������� �� ����, ���������� "0" � �������� ���, ���� ��, ���������� "1", ���� ���
};

#endif

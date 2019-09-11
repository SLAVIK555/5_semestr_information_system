#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H
#include <vector>
#include <string>

using namespace std;

class identification{
	string name_of_file_with_face;//разделяет файл с функцией sender() из класса allocation_and_send
	vector <string> basa_of_faces;//в векторе зранятся строки с именами картинок, составляющих базу
	public:
		void identificator(vector <string> basa_of_faces, string name_of_file_with_face);//сковнивает картинку из файла(name_of_file_with_face) со всеми картинками из вазы, возвращает "0" и печатает имя, если да, возвращает "1", если нет
};

#endif

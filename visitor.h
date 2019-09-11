#ifndef VISIYIR_H
#define VISITOR_H
#include <vector>
#include <string>

using namespace std;

class visitor{
	string name;
	public:
		visitor(string name);//хранит им€ посетител€
		void show(string name);//выводит то, что в скобках
		//~visitor();
};
/*
class allocation_and_send{
	string file_with_picture;
	string name_of_file_with_face;
	public:
		void allocator(string file_with_picture);//распознает рожи на картинке из файла(file_with_picture)
		void sender(string name_of_file_with_face);//записывает в файл(name_of_file_with_face) картинку с распознанной рожей, очищает файл перед новой записью
};

class identification{
	string name_of_file_with_face;//раздел€ет файл с функцией sender() из класса allocation_and_send
	vector <string> basa_of_faces;//в векторе зран€тс€ строки с именами картинок, составл€ющих базу
	public:
		void identificator(vector <string> basa_of_faces, string name_of_file_with_face);//сковнивает картинку из файла(name_of_file_with_face) со всеми картинками из вазы, возвращает "0" и печатает им€, если да, возвращает "1", если нет
};
*/
#endif

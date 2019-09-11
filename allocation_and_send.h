#ifndef ALLOCATION_AND_SEND_H
#define ALLOCATION_AND_SEND_H
#include <string>

using namespace std;

class allocation_and_send{
	string file_with_picture;
	string name_of_file_with_face;
	public:
		void allocator(string file_with_picture);//распознает рожи на картинке из файла(file_with_picture)
		void sender(string name_of_file_with_face);//записывает в файл(name_of_file_with_face) картинку с распознанной рожей, очищает файл перед новой записью
};

#endif

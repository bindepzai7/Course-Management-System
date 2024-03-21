#include"Staff.h"

void Staff::readAllSchoolyear(std::ifstream fin) {
	fin.open("Schoolyear.txt");
	int yearstart, yearend;
	char dash;
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> yearstart;
			fin >> dash;
			fin >> yearend;
			schoolyearlist.addNodeInAscending(SchoolYear(yearstart, yearend));
		}
	}
	fin.close();
}
void Staff::writeSchoolyear2file(std::ofstream fout) {
	fout.open("Schoolyear.txt");
	if (fout.is_open()) {
		Node<SchoolYear>* cur = schoolyearlist.head;
		while (cur) {
			fout << cur->data.getyearstart();
			fout << "-";
			fout << cur->data.getyearend();
		}
	}

}
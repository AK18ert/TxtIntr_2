
#include <iostream>
#include <cmath>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

using namespace std;

void h() {
    cout << "Как использовать: ./calculator [-t или -c] [-r или -g] [значение] " << endl;
    cout << "Первый флаг: -t - арктангенс, -с - арккотангенс" << endl;
    cout << "Второй флаг: -r - радианы, -g - градусы" << endl;
    cout << "Последнее: цифра" << endl;
    cout << "Пример: ./calculator -t -g 60" << endl;
}
int main(int argc, char *argv[]) {
    if (argc < 4) {
		cerr << "Ошибка: не указан тип операции." << endl;
        h();
        return 0;
    }
    double z = 0;
    int opt;
	try {
		while ((opt = getopt(argc, argv, "t:c:rgh")) != -1) {
			if (strcmp(argv[1], "-h") == 0){
				h();
				return 0;
			}
			if (strcmp(argv[1], "-t") == 0) {
				z = atof(argv[2]);

				if (strcmp(argv[3], "-r") == 0) {
					cout << "Арктангенс (в радианах): " << atan(z) << endl;
					break;
				} else if (strcmp(argv[3], "-g") == 0) {
					cout << "Арктангенс (в градусах): " << atan(z) * 180 / M_PI << endl;
					break;
				} else {
					cerr << "Ошибка: не верно указаны еденицы измерения." << endl;
					h();
					return 0;
				}
			}
			if (strcmp(argv[1], "-c") == 0) {
				z = atof(argv[2]);
				if (strcmp(argv[3], "-r") == 0) {
					cout << "Арккотангенс (в радианах): " << (1 / atan(z)) << endl;
					break;
				} else if (strcmp(argv[3], "-g") == 0) {
					cout << "Арккотангенс (в градусах): " << (1 / (atan(z) * 180 / M_PI)) << endl;
					break;
				} else {
					cerr << "Ошибка: не верно указаны еденицы измерения." << endl;
					h();
					return 0;
				}
			} else {
				cerr << "Ошибка: не верно указан тип операции." << endl;
				h();
				return 0;
			}
		}
	} catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}
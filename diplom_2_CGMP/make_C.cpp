//C^-1 : Одна или три центральных диагональ из обратных элементов
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

void main() {
	
	double tmp = 0;
	string zero = "0";
	
	int size = 134862;

	ifstream A2;
	ifstream A3;
	ifstream A4;
	fstream result;

	clock_t begin = clock();
	
	A2.open("A2.dat");
	A3.open("A3.dat");
	A4.open("A4.dat");
	result.open("C_trio.dat");
	
	if (!result.is_open()) {
		cout << "Error opening file" << endl;
		return;
	}

	for (int i = 1; i <= size; ++i) {
		cout << i << " / " << size << endl;
		if (i == 1) {
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A4 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			result << zero << " ";
			result << "0 0 0 0" << endl;
		}
		else if (i >= 2 && i <= 247) {
			A2 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A4 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			result << zero << " ";
			result << "0 0 0" << endl;
		}
		else if (i >= 248 && i <= 494) {
			result << zero << " ";
			A2 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A4 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			result << zero << " ";
			result << "0 0" << endl;
		}
		else if (i >= 495 && i <= 134368) {
			result << "0" << " ";
			result << zero << " ";
			A2 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A4 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			result << zero << " ";
			result << "0" << endl;
		}
		else if (i >= 134369 && i <= 134615) {
			result << "0 0" << " ";
			result << zero << " ";
			A2 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A4 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			result << zero << endl;
		}
		else if (i >= 134616 && i <= 134861) {
			result << "0 0 0" << " ";
			result << zero << " ";
			A2 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A4 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << endl;
		}
		else if (i == 134862) {
			result << "0 0 0 0" << " ";
			result << zero << " ";
			A2 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << " ";
			A3 >> setprecision(16) >> tmp;
			result << ((double)tmp == 0 ? "0" : to_string(1 / tmp)) << endl;
		}
	}

	result.close();
	A2.close();
	A3.close();
	A4.close();

	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Runtime: " << time << endl;

	system("pause");
}
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

	ifstream A3;
	fstream result;

	clock_t begin = clock();
	
	A3.open("A3.dat");
	result.open("C.dat");
	
	for (int i = 1; i <= size; ++i) {
		cout << i << " / " << size << endl;
		if (i == 1) {
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << " ";
			result << zero << " ";
			result << zero << " ";
			result << "0 0 0 0" << endl;
		}
		else if (i >= 2 && i <= 247) {
			result << zero << " ";
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << " ";
			result << zero << " ";
			result << zero << " ";
			result << "0 0 0" << endl;
		}
		else if (i >= 248 && i <= 494) {
			result << zero << " ";
			result << zero << " ";
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << " ";
			result << zero << " ";
			result << zero << " ";
			result << "0 0" << endl;
		}
		else if (i >= 495 && i <= 134368) {
			result << "0" << " ";
			result << zero << " ";
			result << zero << " ";
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << " ";
			result << zero << " ";
			result << zero << " ";
			result << "0" << endl;
		}
		else if (i >= 134369 && i <= 134615) {
			result << "0 0" << " ";
			result << zero << " ";
			result << zero << " ";
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << " ";
			result << zero << " ";
			result << zero << endl;
		}
		else if (i >= 134616 && i <= 134861) {
			result << "0 0 0" << " ";
			result << zero << " ";
			result << zero << " ";
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << " ";
			result << zero << endl;
		}
		else if (i == 134862) {
			result << "0 0 0 0" << " ";
			result << zero << " ";
			result << zero << " ";
			A3 >> setprecision(16) >> tmp;
			result << to_string(1 / tmp) << endl;
		}
	}

	result.close();
	A3.close();

	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Runtime: " << time << endl;

	system("pause");
}
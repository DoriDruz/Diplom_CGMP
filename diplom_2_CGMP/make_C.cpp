#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void main() {
	
	string tmp;
	int size = 134862;

	fstream result;

	clock_t begin = clock();
	
	result.open("C.dat");
	
	for (int i = 1; i <= size; ++i) {
		cout << i <<  " / " << size << endl;
		if (i == 1) {
			tmp = "0.5";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << "0.5 0 0 0" << endl; 
		}
		else if (i >= 2 && i <= 247) {
			tmp = "0.5";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << "0.5 0 0" << endl;
		}
		else if (i >= 248 && i <= 494) {
			tmp = "0.5";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << "0.5 0" << endl;
		}
		else if (i >= 495 && i <= 67431) {
			tmp = "0.5";
			result << "0.5" << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << "0.5" << endl;
		}
		else if (i >= 67432 && i <= 134368) {
			tmp = "2";
			result << "2" << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << "2" << endl;
		}
		else if (i >= 134369 && i <= 134615) {
			tmp = "2";
			result << "0 2" << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << endl;
		}
		else if (i >= 134616 && i <= 134861) {
			tmp = "2";
			result << "0 0 2" << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << endl;
		}
		else if (i == 134862) {
			tmp = "2";
			result << "0 0 0 2" << " ";
			result << tmp << " ";
			result << tmp << " ";
			result << tmp << endl;
		}
	}

	result << "End";
	result.close();
	
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time of calc: " << time << endl;

	system("pause");
}
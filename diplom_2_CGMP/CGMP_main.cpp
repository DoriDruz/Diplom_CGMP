// Итерац. МСГ с предобуславливателем на процессоре[, многоядерном процессоре и видеокарте]
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

//global
const int S = 134862;

void add_nevyazka(double nev) {
	ofstream nevyazka;
	nevyazka.open("nevyazka.dat", ios_base::app);
	nevyazka << nev << endl;
	nevyazka.close();
}

void clear_nevyazka() {
	//clear file with nevyazka
	ofstream nevyazka_file;
	nevyazka_file.open("nevyazka.dat", ofstream::trunc);
	nevyazka_file.close();
}

void write_in_file(double *vec, double size, string name) {
	cout << "Begin write in file" << endl;
	ofstream result_file;
	result_file.open(name, ofstream::trunc); //X.dat

	for (int i = 0; i < size; ++i) {
		result_file << setprecision(16) << vec[i] << endl;
	}

	result_file.close();

	cout << "End write in file: " <<  endl;
}

void create_matr(ifstream& file, double *matr, double size) {
	for (int i = 0; i < size; ++i) {
		file >> setprecision(16) >> matr[i];
	}
}

void copy_vec(double *matr_one, double *matr_two) {
	for (int i = 0; i < S; ++i) {
		matr_one[i] = matr_two[i];
	}
}

void matr_on_vec(double *matr, double *vec, double *res_vec) {
	int second_count = 0;
	int third_count = 0;
	int fourth_count = 0;
	int fifth_count = 0;
	int sixth_count = 0;

	for (int i = 0; i < S; ++i) {
		if (i == 0) {
			res_vec[i] = \
				matr[0] * vec[0] \
				+ matr[1] * vec[1] \
				+ matr[2] * vec[247] \
				+ matr[3] * vec[494];
		}
		else if (i > 0 && i < 247) {
			res_vec[i] = \
				matr[7 * i] * vec[second_count] \
				+ matr[7 * i + 1] * vec[second_count + 1] \
				+ matr[7 * i + 2] * vec[second_count + 2] \
				+ matr[7 * i + 3] * vec[second_count + 248] \
				+ matr[7 * i + 4] * vec[second_count + 495];
			second_count++;
		}
		else if (i > 246 && i < 494) {
			res_vec[i] = \
				matr[7 * i] * vec[third_count] \
				+ matr[7 * i + 1] * vec[third_count + 246] \
				+ matr[7 * i + 2] * vec[third_count + 247] \
				+ matr[7 * i + 3] * vec[third_count + 248] \
				+ matr[7 * i + 4] * vec[third_count + 494] \
				+ matr[7 * i + 5] * vec[third_count + 741];
			third_count++;
		}
		else if (i > 493 && i < 134368) {
			res_vec[i] = \
				matr[7 * i] * vec[fourth_count] \
				+ matr[7 * i + 1] * vec[fourth_count + 247] \
				+ matr[7 * i + 2] * vec[fourth_count + 493] \
				+ matr[7 * i + 3] * vec[fourth_count + 494] \
				+ matr[7 * i + 4] * vec[fourth_count + 495] \
				+ matr[7 * i + 5] * vec[fourth_count + 741] \
				+ matr[7 * i + 6] * vec[fourth_count + 988];
			fourth_count++;
		}
		else if (i > 134367 && i < 134615) {
			res_vec[i] = \
				matr[7 * i + 1] * vec[fifth_count + 133874] \
				+ matr[7 * i + 2] * vec[fifth_count + 134121] \
				+ matr[7 * i + 3] * vec[fifth_count + 134367] \
				+ matr[7 * i + 4] * vec[fifth_count + 134368] \
				+ matr[7 * i + 5] * vec[fifth_count + 134369] \
				+ matr[7 * i + 6] * vec[fifth_count + 134615];
			fifth_count++;
		}
		else if (i > 134614 && i < 134861) {
			res_vec[i] = \
				matr[7 * i + 2] * vec[sixth_count + 134121] \
				+ matr[7 * i + 3] * vec[sixth_count + 134368] \
				+ matr[7 * i + 4] * vec[sixth_count + 134614] \
				+ matr[7 * i + 5] * vec[sixth_count + 134615] \
				+ matr[7 * i + 6] * vec[sixth_count + 134616];
			sixth_count++;
		}
		else if (i == 134861) {
			res_vec[i] = \
				matr[7 * i + 3] * vec[134367] \
				+ matr[7 * i + 4] * vec[134614] \
				+ matr[7 * i + 5] * vec[134860] \
				+ matr[7 * i + 6] * vec[134861];
		}
	}
}

double vec_on_vec(double *vec_one, double *vec_two) {
	double res = 0;
	for (int i = 0; i < S; ++i) {
		res += vec_one[i] * vec_two[i];
	}

	return res;
}

void vec_on_num(double *vec, double num, double *res_vec) {
	for (int i = 0; i < S; ++i) {
		res_vec[i] = vec[i] * num;
	}
}

void sum_vec(double *vec_one, double *vec_two, double *res_vec) {
	for (int i = 0; i < S; ++i) {
		res_vec[i] = vec_one[i] + vec_two[i];
	}
}

void dif_vec(double *vec_one, double *vec_two, double *res_vec) {
	for (int i = 0; i < S; ++i) {
		res_vec[i] = vec_one[i] - vec_two[i];
	}
}

void show_vec(double *matr, double size) {
	for (int i = 0; i < size; ++i) {
		cout << setprecision(16) << matr[i] << "; ";
	}
	cout << endl;
}

double norm_vec(double *vec) {
	double res = 0;
	for (int i = 0; i < S; ++i) {
		res += vec[i]*vec[i];
	}
	return sqrt(res);
}

void nullify(double *vec) {
	for (int i = 0; i < S; ++i) {
		vec[i] = 0;
	}
}

void CGMP(double *A, double *F, double *C, clock_t begin_algo) {
	//Условие останова. Эпсилон
	const double Eps = 0.1;

	//Вектора
	double *x = new double[S];
	double *r = new double[S];
	double *p = new double[S];
	double *z = new double[S];

	double *r_k1 = new double[S];
	double *x_k1 = new double[S];
	double *p_k1 = new double[S];
	double *z_k1 = new double[S];

	//Коэффициенты
	double ak = 0;
	double bk = 0;

	//tmp
	double *tmp = new double[S];
	double *Apk = new double[S];
	double *stop_tmp = new double[S];
	double ak_up = 0;
	double ak_down = 0;
	double bk_up = 0;
	double bk_down = 0;
	double stop_num = 1;
	double stop_up = 0;
	double stop_down = 0;
	int count_tmp = 1;

	//Заполняем все вектора нулями
	for (int i = 0; i < S; ++i) {
		x[i] = r[i] = p[i] = z[i] = 0;
		stop_tmp[i] = Apk[i] = tmp[i] = r_k1[i] = x_k1[i] = p_k1[i] = z_k1[i] = 0;
	}

	//Подготовка перед циклом

	//r0 = b - A*x0		|x0 = 0 -> A*x0 = 0 -> r0 = b|
	copy_vec(r, F);
	//p0 = C*r0
	matr_on_vec(C, r, p);
	//z0 = p0
	copy_vec(z, p);

	while ( !(stop_num < Eps) && count_tmp < S) {
		cout << "Begin of iteration: " << count_tmp << " / " << S << endl;
		clock_t begin_CGMR = clock();

		//ak = (r_k, z_k) / (A*p_k, p_k)
		//(r_k, z_k)
		ak_up = vec_on_vec(r, z);
		//A*p_k
		matr_on_vec(A, p, Apk);
		//(A*p_k, p_k)
		ak_down = vec_on_vec(Apk, p);
		//ak = ...
		ak = ak_up / ak_down;

		//x_k1 = x_k + ak*p_k
		//ak*p_k
		vec_on_num(p, ak, tmp);
		//x_k1 = x_k + ...
		sum_vec(x, tmp, x_k1);

		nullify(tmp);
		//r_k1 = r_k - ak*A*p_k
		//ak*A*p_k
		vec_on_num(Apk, ak, tmp);
		//r_k1 = r_k - ...
		dif_vec(r, tmp, r_k1);

		//z_k1 = C*r_k1
		matr_on_vec(C, r_k1, z_k1);

		//bk = (r_k1, z_k1) / (r_k, z_k)
		//(r_k1, z_k1)
		bk_up = vec_on_vec(r_k1, z_k1);
		//(r_k, z_k)
		bk_down = vec_on_vec(r, z);
		//bk = ...
		bk = bk_up / bk_down;

		//p_k1 = z_k1 + bk*p_k
		//bk*p_k
		nullify(tmp);
		vec_on_num(p, bk, tmp);
		//p_k1 = z_k1 + ...
		sum_vec(z_k1, tmp, p_k1);

		//Показываем первые 10 решений на каждой итерации
		cout << "X: " << endl;
		show_vec(x_k1, 10);

		//Условие останова
		// ||A*z_k - b|| / ||b|| < Eps
		//A*z_k
		nullify(tmp);
		matr_on_vec(A, z, tmp);
		//A*z_k - b
		dif_vec(tmp, F, stop_tmp);
		//||A*z_k - b||
		stop_up = norm_vec(stop_tmp);
		//||b||
		stop_down = norm_vec(F);
		//||..|| / ||..||
		stop_num = 1;
		stop_num = stop_up / stop_down;

		//Показываем невязку
		cout << "Nevyazka: " << stop_num << endl;
		add_nevyazka(stop_num);

		//Копируем вектора
		copy_vec(x, x_k1);
		copy_vec(r, r_k1);
		copy_vec(p, p_k1);
		copy_vec(z, z_k1);

		//Доп условие для остановки
		if (count_tmp == S / 32) {
			write_in_file(x_k1, 1000, "X.dat");
			break;
		}
		++count_tmp;

		//Очищаем вектора
		nullify(x_k1);
		nullify(r_k1);
		nullify(p_k1);
		nullify(z_k1);
		nullify(stop_tmp);
		nullify(tmp);
		nullify(Apk);

		clock_t end_CGMR = clock();

		double CGMR_time = double(end_CGMR - begin_CGMR) / CLOCKS_PER_SEC;
		cout << "Iteration runtime: " << CGMR_time << endl << endl;

		clock_t end_algo = clock();
		double algo_time = double(end_algo - begin_algo) / CLOCKS_PER_SEC;
		cout << "Algoritm runtime: " << algo_time << endl;

	}

	//Очищаем память
	delete(x);
	delete(r);
	delete(p);
	delete(z);
	delete(x_k1);
	delete(r_k1);
	delete(p_k1);
	delete(z_k1);
	delete(tmp);
	delete(Apk);
	delete(stop_tmp);
}

void main() {
	//A priori C^-1 = C

	clock_t begin_algo = clock();

	double *matr_A = new double[S * 7];
	double *matr_F = new double[S];
	double *matr_C = new double[S * 7];

	ifstream A;
	ifstream F;
	ifstream C;
	
	clock_t begin = clock();

	A.open("A.dat");		// 134862 * 7	| A.dat
	F.open("F.dat");		// 134862		| F.dat
	C.open("C.dat");		// 134862 * 7	| C.dat

	create_matr(A, matr_A, S * 7);
	create_matr(F, matr_F, S);
	create_matr(C, matr_C, S * 7);

	A.close();
	F.close();

	clear_nevyazka();
	CGMP(matr_A, matr_F, matr_C, begin_algo);

	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Runtime: " << time << endl;

	delete(matr_A);
	delete(matr_F);
	delete(matr_C);

	system("pause");
}
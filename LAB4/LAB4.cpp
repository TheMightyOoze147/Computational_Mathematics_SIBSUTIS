#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Функция для вычисления факториала
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Функция для вычисления разделенной разности
double divided_difference(vector<double> x, vector<double> y, int i, int j) {
    if (i == j)
        return y[i];
    else
        return (divided_difference(x, y, i + 1, j) - divided_difference(x, y, i, j - 1)) / (x[j] - x[i]);
}

// Функция для вычисления интерполяционного полинома Ньютона
double newton_interpolation(vector<double> x, vector<double> y, double x_interp) {
    double result = 0.0;
    int n = x.size();
    for (int i = 0; i < n; i++) {
        double term = divided_difference(x, y, 0, i);
        for (int j = 0; j < i; j++) {
            term *= (x_interp - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {   
    ifstream input_file("in.txt");
    if (!input_file) {
        cout << "Error: File not found." << endl;
        return 1;
    }
    // Известные точки
    
    vector<double> x = {0.847, 1.546, 1.834, 2.647, 2.910};
    vector<double> y = {1.104, 1.042, 0.029, -0.344, -0.449};

    //!!!!!!!!!!!!!!!!!!Добавить заполнение векторов выше из файла

    // Значение x, для которого нужно найти значение полинома
    double x_interp = 1.0;

    // Вычисление значения полинома Ньютона
    double result = newton_interpolation(x, y, x_interp);

    // Вывод результата
    cout << "Значение полинома Ньютона в точке " << x_interp << " равно " << result << endl;

    return 0;
}

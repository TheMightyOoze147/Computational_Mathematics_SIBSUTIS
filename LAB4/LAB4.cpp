#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
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
    vector <double> x, y;
    double value;
    if (!input_file) {
        cout << "Error: File not found." << endl;
        return 1;
    }

    string line;
    getline(input_file, line);
    istringstream iss(line);
    while (iss >> value) {
        x.push_back(value);
    }

    getline(input_file, line);
    istringstream iss2(line);
    while (iss2 >> value) {
        y.push_back(value);
    }

    // Значение x, для которого нужно найти значение полином
    double x_interp;
    cout << "Введите значение x, для якоторого нужно найти значение полинома: " << endl;
    cin >> x_interp;

    // Вычисление значения полинома Ньютона
    double result = newton_interpolation(x, y, x_interp);

    // Вывод результата
    cout << "Значение полинома Ньютона в точке " << x_interp << " равно " << result << endl;
    input_file.close();
    return 0;
}

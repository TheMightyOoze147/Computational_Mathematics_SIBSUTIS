#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 3 - pow(x, 1.5) + 0.5 * log(x);
}
double secant_method(double a, double b, double epsilon) {
    if (f(a) * f(b) > 0) {
        cout << "Ошибка: Одинаковые знаки на обоих концах отрезка" << endl;
        return NAN;
    }
    double x0 = a, x1 = b;
    while (abs(f(x1)) > epsilon) {
        double x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }
    return x1;
}

int main() {
    double a, b, epsilon;
    //Проверялось при a = 0.1, b = 5.0, epsilon = 1e-6
    cout << "\nВведите а и b (через пробел): " << endl;
    cin >> a >> b;
    cout << "\nВведите точность: " << endl;
    cin >> epsilon;
    //Локализация корня
    while (f(a) * f(b) > 0) {
        if (f(a) > f(b)) {
            a /= 2;
        } else {
            b *= 2;
        }
    }
    double x = secant_method(a, b, epsilon);
    cout << "Корень для уравнения 3 - pow(x, 1.5) + 0.5 * log(x): \n" << x << endl;
    return 0;
}
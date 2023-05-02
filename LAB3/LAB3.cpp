// #include <iostream>
// #include <cmath>

// using namespace std;

// double f(double x) {
//     // здесь задайте ваше уравнение
//     return 3 - pow(x, 1.5) + 0.5 * log(x);
// }

// // функция для локализации корня
// void bracket_root(double &a, double &b) {
//     double fa = f(a);
//     double fb = f(b);

//     while (fa * fb > 0) {
//         if (abs(fa) < abs(fb)) {
//             a -= 1.5 * (b - a);
//             fa = f(a);
//         } else {
//             b += 1.5 * (b - a);
//             fb = f(b);
//         }
//     }
// }

// double secant_method(double x0, double x1, double epsilon) {
//     double fx0 = f(x0);
//     double fx1 = f(x1);
//     double x2, fx2;

//     while (abs(fx1) > epsilon) {
//         x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
//         fx2 = f(x2);

//         x0 = x1;
//         x1 = x2;
//         fx0 = fx1;
//         fx1 = fx2;
//     }

//     return x1;
// }

// int main() {
//     double a = -100.0; // начальное значение a
//     double b = 100.0; // начальное значение b
//     double epsilon = 0.0001; // заданная точность

//     bracket_root(a, b); // локализуем корень уравнения на отрезке [a, b]

//     double root = secant_method(a, b, epsilon);

//     cout << "Корень уравнения: " << root << endl;

//     return 0;
// }

#include <iostream>
#include <cmath>

double f(double x) {
    //return 3 - pow(x, 1.5) + 0.5 * log(x);
    return x*x + 2*x -1;
}

double secant_method(double x0, double x1, double epsilon) {
    double x2, f0, f1, f2, denominator;
    do {
        f0 = f(x0);
        f1 = f(x1);
        denominator = (f1 - f0) / (x1 - x0);
        x2 = x1 - f1 / denominator;
        f2 = f(x2);
        x0 = x1;
        x1 = x2;
    } while (std::abs(f2) > epsilon);
    return x2;
}

int main() {
    double a = 0.1;
    double b = 5.0;
    double epsilon = 1e-6;
    double root = secant_method(a, b, epsilon);
    std::cout << "Найденный корень уравнения с точностью " << epsilon << " равен " << root << std::endl;
    return 0;
}

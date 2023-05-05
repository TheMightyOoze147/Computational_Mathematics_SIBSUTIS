#include <iostream> // добавляем функции для ввода и вывода на экран
#include <math.h> // добавляем математические функции

using namespace std;
// функция, интеграл
double f(double x) {
    //return exp(-x*x);
    return (1/log(x));
}

int main() {
    int i; // счётчик
    double Integral; // здесь будет интеграл
    double a, b;
    //double a = 0.0, b = 1.0; // задаём отрезок интегрирования
    double n; // задаём число разбиений n

    cout << "\nВведите а и b (через пробел): " << endl;
    cin >> a >> b;
    cout << "\nВведите количество разбиений N: " << endl;
    cin >> n;
    double h = (b-a) / n;// задаём шаг интегрирования
    
    // вычисляем интеграл по формуле центральных прямугольников
    Integral = 0.0;
    for(i = 1; i <= n; i++)
        Integral = Integral + h * f(a + h * (i - 0.5));
    cout << "Интеграл по формуле центральных прямоугольников:\nI1 = " << Integral << "\n";

    // вычисляем интеграл по формуле трапеций
    Integral = h * (f(a) + f(b)) / 2.0;
    for(i = 1; i <= n-1; i++)
        Integral = Integral + h * f(a + h * i);
    cout << "Интеграл по формуле трапеций:\nI2 = " << Integral << "\n";

    // вычисляем интеграл по формуле Симпсона
    Integral = h * (f(a) + f(b)) / 6.0;
    for(i = 1; i <= n; i++)
        Integral = Integral + 4.0 / 6.0 * h * f(a + h * (i - 0.5));
    for(i = 1; i <= n-1; i++)
        Integral = Integral + 2.0 / 6.0 * h * f(a + h * i);
    cout << "Интеграл по формуле Симпсона:\nI3 = " << Integral << "\n";
}
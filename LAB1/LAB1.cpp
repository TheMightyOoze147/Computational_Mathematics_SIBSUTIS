#include <iostream>

using namespace std;

const int m_size = 4;

int main() {
    // Задаем расширенную матрицу системы уравнений
    double matrix[m_size][m_size + 1] = {
            {2, -1, 1, 1, 6},
            {-1, 2, -1, 0, 8},
            {3, 1, -2, -3, 15},
            {8, 4, 2, 9, 11}
    };

    // Приведение матрицы к ступенчатому виду методом Гаусса с выбором главного элемента по столбцу
    for (int col = 0; col < m_size - 1; ++col) {
        for (int row = 0; row < m_size - 1 - col; ++row) {
            // Находим множитель для преобразования текущей строки
            double mult = -matrix[row + 1 + col][col] / matrix[col][col];
            // Преобразуем текущую строку
            for (int elem = 0; elem < m_size + 1; ++elem) {
                matrix[row + 1 + col][elem] += matrix[col][elem] * mult;
            }
        }
    }

    // Вычисляем значения неизвестных методом обратного хода
    double results[m_size];
    results[m_size - 1] = matrix[m_size - 1][m_size] / matrix[m_size - 1][m_size - 1];
    for (int i = m_size - 2; i >= 0; --i) {
        double temp = matrix[i][m_size];
        for (int j = m_size - 1; j > i; --j) {
            temp -= matrix[i][j] * results[j];
        }
        results[i] = temp / matrix[i][i];
    }

    // Выводим промежуточные результаты приведения матрицы к ступенчатому виду
    for (auto i : matrix) {
        for (int j = 0; j < m_size + 1; j++) {
            printf("%.2f\t", i[j]);
        }
        cout << endl;
    }

    // Выводим решение системы уравнений
    for (auto i : results) {
        cout << i << ' ';
    }
}
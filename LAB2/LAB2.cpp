#include <iostream>
#include <cmath>
#include <locale>
#include <vector>

// #define raw 3 //строки
// #define col raw+1 //столбцы
// int matrix[raw][col] = {
//         {5, -1, 3, 5},
//         {1, -4, 2, 20},
//         {2, -1, 5, 10},
// };


// #define raw 3 //строки
// #define col raw+1 //столбцы
// int matrix[raw][col] = {
//         {10, 1, -1, 11},
//         {1, 10, -1, 10},
//         {-1, 1, 10, 10},
// };

// #define raw 4 //строки
// #define col raw+1 //столбцы
// int matrix[raw][col] = {
//         {10, -1, 2, 0, 6},
//         {-1, 11, -1, 3, 25},
//         {2, -1, 10, -1, -11},
//         {0, 3, -1, 8, 15},
// };

// int matrix[raw][col];
// void matrix_filling() {
//     for (int i = 0; i < raw; i++) {
//         for (int j = 0; j < col; j++) {
//             matrix[i][j] = rand() % 10 -2;
//         }
//     }
// }

void matrix_print() {
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool diagonal_check() {
    std::vector <int> diagonal;
    int raw_sum = 0;
    for (int i = 0; i < std::min(raw, col); i++) {
        diagonal.push_back(matrix[i][i]);
    }
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col - 1; j++) {
            if (i == j) {
                continue;
            }
            else
                raw_sum = raw_sum + abs(matrix[i][j]);
        }
        // std::cout << "\nСумма строки " << i + 1 << " без диагонали " << raw_sum << std::endl;
        if (!(abs(diagonal[i]) > raw_sum)) {
            return 0;
        }
        else
            raw_sum = 0;
    }
    return 1;
}

int calculating() {
    double apprx[20][raw];
    double x_sum = 0;
    double infelicity[20][raw];
    double inf_sum = 0;
    int iteratio = 0;
    //Рассчет нулевого приближения
    for (int j = 0; j < raw; j++) {
        apprx[0][j] = (matrix[j][col-1]/matrix[j][j]);
        infelicity[0][j] = 0;
    }

    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < raw; j++) {
            for (int z = 0; z < raw; z++) {
                if (z != j) x_sum = x_sum + (apprx[i-1][z] * (matrix[j][z]));
            }
            apprx[i][j] = (matrix[j][col-1] - x_sum)/matrix[j][j];
            x_sum = 0;
        }
        for (int m = 0; m < raw; m++) {
            infelicity[i-1][m] = fabs(apprx[i][m] - apprx[i-1][m])/fabs(apprx[i][m]);
            inf_sum = inf_sum + infelicity[i-1][m];
        }
        iteratio++;
        if ((inf_sum/raw) < 0.01) {
            break;
        }
        else inf_sum = 0;
    }
    std::cout << "Приближения: " << std::endl;
    for (int i = 0; i < iteratio; i++) {
        for (int j = 0; j < raw; j++) {
            std::cout << i << " " << j << " -- " << apprx [i][j] << std::endl;
        }
        std::cout << "\n";
    }
    return 1;
}

int main() {
    srand(time(NULL));
    // matrix_filling();
    matrix_print();
    if (diagonal_check()) {
        calculating();
    }
    else {
        std::cout << "Условие преобладающих элементов диагонали не выполняется" << std::endl;  
        return 0;
    }
}

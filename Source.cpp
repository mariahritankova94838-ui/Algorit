#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<int> num = { 10, 20, 100, 1000, 2000, 5000, 10000, 100000, 1000000, 10000000};

double monte_carlo(double x1, double x2, double y1, double y2, int num_points) {
    int inside_points = 0;

    for (int i = 0; i < num_points; ++i) {
        double x = x1 + ((double)rand() / RAND_MAX) * (x2 - x1);
        double y = y1 + ((double)rand() / RAND_MAX) * (y2 - y1);

        // Условие для прямоугольника: x между 3 и 5, y между 4 и 7
        if (x >= 5.0 && x <= 7.0 && y >= 3.0 && y <= 4.0) {
            inside_points++;
        }
    }

    double rect_area = (x2 - x1) * (y2 - y1);
    double figure_area = (inside_points / (double)num_points) * rect_area;
    return figure_area;
}

int main() {
    setlocale(LC_ALL, "RU");

    srand(time(0));

  
    double x1 = 4.0;  
    double x2 = 8.0;  
    double y1 = 2.0;  
    double y2 = 5.0;


    for (int i : num) {
        double result = monte_carlo(x1, x2, y1, y2, i);
        std::cout << "Интеграл, вычисленная площадь: " << result << std::endl;
    }

    return 0;
}
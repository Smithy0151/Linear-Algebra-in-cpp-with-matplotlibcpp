#include "matplotlibcpp.h"
#include <iostream>

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x = { 1, 3 };
    std::vector<double> y = { 1, 2 };
    plt::plot(x, y);
    plt::grid(true);
    plt::show();

	return 0;
}
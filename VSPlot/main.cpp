#include "matplotlibcpp.h"
#include <iostream>

namespace plt = matplotlibcpp;

double origin = 0;

namespace vectorA {
// 0 = The origin
    std::vector<double> x = { origin, origin - 1};
    std::vector<double> y = { origin, origin + 2};
}

//Vector B at origin 0
namespace vectorB {
    std::vector<double> x = { origin, origin + 3};
    std::vector<double> y = { origin, origin + 1};
}

//Vector B starting at the end of vector A
namespace newVectorB {
    std::vector<double> x = { vectorA::x[1], vectorA::x[1] + (vectorB::x[1] - vectorA::x[0]) };
    std::vector<double> y = { vectorA::y[1], vectorA::y[1] + (vectorB::y[1] - vectorA::y[0]) };
}

//Sum of Vector A and B line at the origin 0
namespace addedVectors {
    std::vector<double> x = { origin, vectorA::x[1] + (vectorB::x[1] - vectorA::x[0]) };
    std::vector<double> y = { origin, vectorA::y[1] + (vectorB::y[1] - vectorA::y[0]) };
}


int main() {

    //Vector A
    plt::plot(vectorA::x, vectorA::y,{{"color", "red"}});

    //Vecotr B starting at tail of vector A
    plt::plot(newVectorB::x, newVectorB::y, { {"color", "blue"} });


    //Adding x vectors
    double xAddedValues = vectorA::x[1] + vectorB::x[1];
    std::cout << "Sum of x values: " << xAddedValues << std::endl;

    //Adding Y vectors
    double yAddedValues = vectorA::y[1] + vectorB::y[1];
    std::cout << "Sum of y values: " << yAddedValues << std::endl;

    //Plotting Added values at the origin
    plt::plot(addedVectors::x, addedVectors::y, {{"color", "green"}});



    plt::grid(true);
    plt::show();

	return 0;
}
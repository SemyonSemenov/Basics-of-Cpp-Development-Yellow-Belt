#include <vector>
#include <memory>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cmath>
using namespace std;


class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(double side1, double side2, double side3) 
    : a(side1), b(side2), c(side3) {
    }
    string Name() const override {
        return "TRIANGLE";
    }
    double Perimeter() const override {
        return a + b + c;
    }
    double Area() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

private:
    double a, b, c;
};

class Rect : public Figure {
public:
    Rect(double width, double height)
    : w(width), h(height) {
    }
    string Name() const override {
        return "RECT";
    }
    double Perimeter() const override {
        return 2 * (w + h);
    }
    double Area() const override {
        return w * h;
    }
private:
    double w, h;
};

class Circle : public Figure {
public:
    Circle(double R) 
    : r(R) {
    }
    string Name() const override {
        return "CIRCLE";
    }
    double Perimeter() const override {
        return 2 * 3.14 * r;
    }
    double Area() const override {
        return 3.14 * r * r;
    }
private:
    double r;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string type;
    is >> type;
    shared_ptr <Figure> f;
    if (type == "CIRCLE") {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
    else if (type == "RECT") {
        double w, h;
        is >> w >> h;
        return make_shared<Rect>(w, h);
    }
    else if (type == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }

}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
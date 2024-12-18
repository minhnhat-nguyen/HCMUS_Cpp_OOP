#include <iostream>
#include "Date.h"
#include "Fraction.h"
#include "Point.h"
#include "Rectangle.h"
#include "Student.h"

int main(void) {
    // Bai 1
    Fraction a, b;
    std::cin >> a >> b;
    std::cout << a << " + " << b << " = " << (a + b) << '\n';
    std::cout << a << " - " << b << " = " << (a - b) << '\n';
    std::cout << a << " * " << b << " = " << (a * b) << '\n';
    std::cout << a << " / " << b << " = " << (a / b) << '\n';
    std::cout << a.toDouble() << " + " << b.toDouble() << " = "
              << (a + b).toDouble() << '\n';
    std::cout << a.toDouble() << " - " << b.toDouble() << " = "
              << (a - b).toDouble() << '\n';
    std::cout << a.toDouble() << " * " << b.toDouble() << " = "
              << (a * b).toDouble() << '\n';
    std::cout << a.toDouble() << " / " << b.toDouble() << " = "
              << (a / b).toDouble() << '\n';

    //Bai 2
    Date d1, d2;
    std::cout << "Enter d1: ";
    std::cin >> d1;
    std::cout << "Enter d2: ";
    std::cin >> d2;
    std::cout << d1 << ' ' << d2 << '\n';
    d1.increase1Day();
    std::cout << "d1 + 1 day: " << d1 << '\n';
    d2.decrease1Day();
    std::cout << "d2 - 1 day: " << d2 << '\n';
    d1.increaseNDays(10);
    std::cout << "d1 + 10 days: " << d1 << '\n';
    d2.decreaseNDays(10);
    std::cout << "d2 - 10 days: " << d2 << '\n';
    std::cout << "The comparation of d1 & d2: " << d1.compare(d2) << '\n';

    // Bai 3
    Point p1, p2(1.5, 2.5);
    std::cout << "Enter a point: ";
    std::cin >> p1;
    std::cout << "Distance between " << p1 << " & " << p2 << ": " << p1.distanceTo(p2) << '\n';
    
    //Bai 4
    Rectangle R; 
    std::cin >> R;
    if (R.isValid()) {
        std::cout << "The rectangle is valid\n";
        std::cout << R;
        std::cout << "Area: " << R.getArea() << '\n';
        std::cout << "Perimeter: " << R.getPerimeter() << '\n';
    }
    else 
        std::cout << "The rectangle is invalid\n";

    //Bai 5
    Student s;
    s.setMathGrade(10);
    s.setEnglishGrade(10);
    s.setProgrammingGrade(10);
    std::cout << "Set all subjects to 10: " << s;
    std::cout << "Enter the student's grades: ";
    std::cin >> s;
    std::cout << s;
    std::cout << "Average: " << s.getAverage() << '\n';
    std::cout << "The Student is " << ((s.isExellent()) ? "" : "not ") << "exellent!" << '\n';
    return 0;
}
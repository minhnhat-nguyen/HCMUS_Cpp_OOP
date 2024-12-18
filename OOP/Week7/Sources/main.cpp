#include <iostream>
#include "Fraction.h"
#include "Array.h"
#include "File.h"
#include "IntegerParser.h"
#include "Date.h"
#include "Time.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    //Bai1
    Fraction f1;
    f1.SetValue(1, 2);
    std::cout << f1 << '\n';
    Fraction f2;
    try {
        f2.SetValue(1, 0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    //Bai2
    Array a(10);
    for (int i = 0; i < a.Size(); i++)
        a[i] = i;
    for (int i = 0; i <= a.Size(); i++)
        try {
            std::cout << a.GetValueAt(i) << ' ';
        }
        catch (std::exception& e) {
            std::cout << e.what() << '\n';
        }
    
    //Bai3
    File f;
    std::string str;
    try {
        f.open("Other/input.txt");
        while (f.getline(str))
            std::cout << str << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    //Bai4
    try {
        std::cout << ParseInteger("123") << '\n';
        std::cout << ParseInteger("-123") << '\n';
        std::cout << ParseInteger("+123") << '\n';
        std::cout << ParseInteger("abc") << '\n';
        std::cout << ParseInteger("123abc") << '\n';
        std::cout << ParseInteger("abc123") << '\n';
        std::cout << ParseInteger("") << '\n';
        std::cout << ParseInteger("-") << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    //Bai5
    std::string str1 = "29/02/2001";
    int day, month, year;
    try {
        sscanf_s(str1.c_str(), "%d/%d/%d", &day, &month, &year);
        Date d(day, month, year);
        std::cout << d << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    //Bai6
    std::string str2 = "12/30/30";
    int hour, minute, second;
    try {
        sscanf_s(str2.c_str(), "%d:%d:%d", &hour, &minute, &second);
        Time t(hour, minute, second);
        std::cout << t << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    //Bai7
    Stack<int> s(10);
    try {
        for (int i = 0; i < 11; i++)
            s.push(i);
        s.push(10);
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        while (!s.isEmpty()) {
            std::cout << s.getTop() << ' ';
            s.pop();
        }
        s.pop();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';
    Queue<int> q(10);
    try {
        for (int i = 0; i < 11; i++)
            q.enqueue(i);
        q.enqueue(10);
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        while (!q.isEmpty()) {
            std::cout << q.getFront() << ' ';
            q.dequeue();
        }
        q.dequeue();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}

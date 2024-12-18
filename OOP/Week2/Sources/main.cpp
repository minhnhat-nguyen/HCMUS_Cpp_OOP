#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "Fraction.h"
#include "Queue.h"
#include "Stack.h"
#include "Student.h"
using namespace std;

int main() {
    int choice;
    int n;
    // Bai 1
    Fraction f1, f2;      // 0/1
    Fraction f3(1, -7);   // -1/7
    Fraction f4(f3);      // Copy constructor
    Fraction f5 = f2;     // Copy constructor
    Fraction f6, f7, f8;  // Default constructor
    f6 = f3;              // Operator =
    f7 = f1 + f5;
    f8 = f2 - f4;
    f3 = f1 * f7;
    f5 = f6 / f2;  // Cannot divide by zero!
    if (f2 == f3) cout << "f2==f3" << '\n';
    if (f3 != f1) cout << "f3!=f1" << '\n';
    if (f2 >= f5) cout << "f2>=f5" << '\n';
    if (f2 > f5) cout << "f2>f5" << '\n';
    if (f5 <= f3) cout << "f5<=f3" << '\n';
    if (f5 < f3) cout << "f5<f3" << '\n';
    f1 = f2 + 3;
    f3 = -7 + f1;
    f5 = 7 * f3;
    f6 = f4 - 6;
    cout << f3 << '\n';
    cout << f6 << '\n';
    f1 += f5;
    f6 -= f7;
    f8 *= f1;
    f8 /= f2;  // Cannot divide by zero!
    cout << f8++ << '\n';
    cout << ++f7 << '\n';
    cout << f8-- << '\n';
    cout << --f7 << '\n';
    f3 += Fraction(11, 2);
    int x = int(f3);      // 3/2 => 1
    float f = (float)f3;  // 3/2 => 1.5
    cout << x << '\n';
    cout << f << '\n';

    // Bai 2
    Stack S;
    do {
        cout << "---- Stack S ----" << '\n';
        cout << "1. Push" << '\n';
        cout << "2. Pop" << '\n';
        cout << "3. Get top value" << '\n';
        cout << "4. Check empty" << '\n';
        cout << "5. Check full" << '\n';
        cout << "6. Exit" << '\n';
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                if (S.isFull()) {
                    cout << "Stack is full" << '\n';
                    break;
                }
                cout << "Enter value: ";
                cin >> n;
                S.push(n);
                break;
            }
            case 2: {
                if (S.isEmpty()) {
                    cout << "Stack is empty" << '\n';
                    break;
                }
                S.pop();
                cout << "Pop successfully" << '\n';
                break;
            }
            case 3: {
                if (S.isEmpty())
                    cout << "Stack is empty" << '\n';
                else
                    cout << "Top value: " << S.getTopValue() << '\n';
                break;
            }
            case 4: {
                if (S.isEmpty())
                    cout << "Stack is empty" << '\n';
                else
                    cout << "Stack is not empty" << '\n';
                break;
            }
            case 5: {
                if (S.isFull())
                    cout << "Stack is full" << '\n';
                else
                    cout << "Stack is not full" << '\n';
                break;
            }
            case 6: {
                cout << "Exit" << '\n';
                break;
            }
            default: {
                cout << "Invalid choice" << '\n';
                break;
            }
        }
    } while (choice != 6);

    // Bai 3
    Queue Q;
    do {
        cout << "---- Queue Q ----" << '\n';
        cout << "1. Enqueue" << '\n';
        cout << "2. Dequeue" << '\n';
        cout << "3. Get front value" << '\n';
        cout << "4. Check empty" << '\n';
        cout << "5. Check full" << '\n';
        cout << "6. Exit" << '\n';
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                if (Q.isFull()) {
                    cout << "Queue is full" << '\n';
                    break;
                }
                cout << "Enter value: ";
                cin >> n;
                Q.enqueue(n);
                break;
            }
            case 2: {
                if (Q.isEmpty()) {
                    cout << "Queue is empty" << '\n';
                    break;
                }
                Q.dequeue();
                cout << "Dequeue successfully" << '\n';
                break;
            }
            case 3: {
                if (Q.isEmpty())
                    cout << "Queue is empty" << '\n';
                else
                    cout << "Front value: " << Q.getFrontValue() << '\n';
                break;
            }
            case 4: {
                if (Q.isEmpty())
                    cout << "Queue is empty" << '\n';
                else
                    cout << "Queue is not empty" << '\n';
                break;
            }
            case 5: {
                if (Q.isFull())
                    cout << "Queue is full" << '\n';
                else
                    cout << "Queue is not full" << '\n';
                break;
            }
            case 6: {
                cout << "Exit" << '\n';
                break;
            }
            default: {
                cout << "Invalid choice" << '\n';
                break;
            }
        }
    } while (choice != 6);
    // Bai 4
    Student s1, s2("B20DCCN001", 3.0, "Nguyen Van A", "Ha Noi");
    Student s3(s2);
    cin >> s1;
    cout << "s1: " << s1 << '\n';
    cout << "s2: " << s2 << '\n';
    cout << "s3: " << s3 << '\n';
    return 0;
}

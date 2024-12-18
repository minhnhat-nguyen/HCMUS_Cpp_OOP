#include <iostream>
#include <fstream>

int main() {
    std::fstream input("input1.3.txt");
    std::fstream output("output1.3.txt", std::ios::out);
    int n;
    input >> n;
    output << "low" << ' ' << "high" << ' ' <<"avg" << '\n';
    while (n--) {
        double temp;
        double high = -1;
        double low = 1000000001;
        double avg = 0;
        for (int i = 0; i < 12; ++i) {
            input >> temp;
            if (temp > high) high = temp;
            if (temp < low) low = temp;
            avg += temp;
        }
        output << low << ' ' << high << ' ' << avg / 12 << '\n';
    }
    input.close();
    output.close();
}
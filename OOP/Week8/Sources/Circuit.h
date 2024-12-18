#include <iostream>
#include <vector>

class resistor {
    private:
        double vontage;
        double current;
    public:
        resistor(double v, double i) {
            vontage = v;
            current = i;
        }
        double getResistance() {
            return vontage / current;
        }
        double getVontage() {
            return vontage;
        }
        double getCurrent() {
            return current;
        }
};

class Circuit {
    protected:
        Circuit() = default;
    public:
        virtual double getResistance() = 0;
        ~Circuit() = default;
};

class SingleCircuit : public Circuit {
    private:
        resistor _r;
    public:
        SingleCircuit(const resistor& r): _r(r) {
        }
        double getResistance() {
            return _r.getResistance();
        }
};

class SerialCircuit : public Circuit {
    private:
        std::vector<Circuit*> _circuits;
    public:
        SerialCircuit();
        SerialCircuit(std::vector<Circuit*> circuits) {
            _circuits = circuits;
        }
        void addCircuit(Circuit* circuit) {
            _circuits.push_back(circuit);
        }
        double getResistance() {
            double sum = 0;
            for (auto circuit : _circuits) {
                sum += circuit->getResistance();
            }
            return sum;
        }
};

class ParallelCircuit : public Circuit {
    private:
        std::vector<Circuit*> _circuits;
    public:
        ParallelCircuit();
        ParallelCircuit(std::vector<Circuit*> circuits) {
            _circuits = circuits;
        }
        void addCircuit(Circuit* circuit) {
            _circuits.push_back(circuit);
        }
        double getResistance() {
            double sum = 0;
            for (auto circuit : _circuits) {
                sum += 1 / circuit->getResistance();
            }
            return 1 / sum;
        }
};
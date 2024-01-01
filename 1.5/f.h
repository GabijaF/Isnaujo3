#ifndef F_H
#define F_H

#include "zmogus.h"
#include <list>
#include <numeric>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <numeric>
#include <chrono>

class StudentasL : public Zmogus {
private:
    std::list<int> Nd;
    int egz;

public:
    StudentasL() : Zmogus("", ""), egz(0) {}

    StudentasL(const std::string& v, const std::string& p, const std::list<int>& nd, int e)
    : Zmogus(v, p), Nd(nd), egz(e) {}

    void addNd(int nd) { Nd.push_back(nd); }
    void setEgz(int e) { egz = e; }

    void setNd(const std::list<int>& nd) { Nd = nd; }

    std::list<int> getNd() const { return Nd; }
    int getEgz() const { return egz; }

    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const;

    // Copy constructor
    StudentasL(const StudentasL& other)
        : Zmogus(other), Nd(other.Nd), egz(other.egz) {}

    // Copy assignment operator
    StudentasL& operator=(const StudentasL& other) {
        if (this != &other) {
            Zmogus::operator=(other); // Call base class assignment
            Nd = other.Nd;
            egz = other.egz;
        }
        return *this;
    }

    // Destructor
    ~StudentasL() {}


    friend std::ostream& operator<<(std::ostream& os, const StudentasL& student) {
    os << "Vardas: " << student.vardas << "\n";
    os << "Pavarde: " << student.pavarde << "\n";
    os << "Nd: ";
    for (int pazymys : student.Nd) {
        os << pazymys << " ";
    }
    os << "\nEgzaminas: " << student.egz << "\n";
    return os;
}
    //input
    friend std::istream& operator>>(std::istream& is, StudentasL& StudentasL) {
    std::cout << "Iveskite varda: ";
    is >> StudentasL.vardas;

    std::cout << "Iveskite pavarde: ";
    is >> StudentasL.pavarde;

    char generuotiPazymius;
    std::cout << "Ar norite, kad namu darbu ir egzamino pazymiai butu generuojami? (T/N): ";
    is >> generuotiPazymius;

    if (generuotiPazymius == 'T' || generuotiPazymius == 't') {
        int NdKiekis = rand() % 10 + 1;
        for (int i = 0; i < NdKiekis; ++i) {
            StudentasL.Nd.push_back(generuotiNdBala());
        }
        StudentasL.egz = generuotiEgzBala();
    } else {
        int pazymys;
        std::cout << "Iveskite namu darbu pazymius (baigus parasyk -1): ";
        while (is >> pazymys && pazymys != -1) {
            if (pazymys >= 1 && pazymys <= 10) {
                StudentasL.Nd.push_back(pazymys);
            } else {
                std::cerr << "Klaida: ND pazymys turi buti tarp 1-10." << std::endl;
            }
        }

        std::cout << "Iveskite egzamino pazymi: ";
        is >> pazymys;
        if (pazymys >= 1 && pazymys <= 10) {
            StudentasL.egz = pazymys;
        } else {
            std::cerr << "Klaida: Egzamino pazymys turi buti tarp 1-10." << std::endl;
        }
    }

    return is;
}


    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }

    static int generuotiNdBala();
    static int generuotiEgzBala();

    std::string pilnasVardas() const override {
        return vardas + " " + pavarde;
    }
};

int generuotiNdBala();
int generuotiEgzBala();
void generuotiStudentus(std::list<StudentasL>& studentai, int studentuSkaicius, std::ofstream& outFile);
void skaitytiIsFailo(const std::string& failoPavadinimas, std::list<StudentasL>& studentai);
void irasytiIFaila(const std::string& filename, const std::list<StudentasL>& studentai);
void printTable(const std::list<StudentasL>& studentai, const std::string& title);
void Demonstracija3();
void Demonstracija4();

#endif // StudentasL_H


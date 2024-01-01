#ifndef H_H
#define H_H

#include "zmogus.h"
#include <vector>
#include <numeric>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <numeric>
#include <chrono>

class Studentas : public Zmogus {
private:
    std::vector<int> Nd;
    int egz;

public:
    Studentas() : Zmogus("", ""), egz(0) {}

    Studentas(const std::string& v, const std::string& p, const std::vector<int>& nd, int e)
    : Zmogus(v, p), Nd(nd), egz(e) {}

    void addNd(int nd) { Nd.push_back(nd); }
    void setEgz(int e) { egz = e; }

    void setNd(const std::vector<int>& nd) { Nd = nd; }

    std::vector<int> getNd() const { return Nd; }
    int getEgz() const { return egz; }

    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const;

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other), Nd(other.Nd), egz(other.egz) {}

    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other); // Call base class assignment
            Nd = other.Nd;
            egz = other.egz;
        }
        return *this;
    }

    // Destructor
    ~Studentas() {}


    friend std::ostream& operator<<(std::ostream& os, const Studentas& student) {
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
    friend std::istream& operator>>(std::istream& is, Studentas& studentas) {
    std::cout << "Iveskite varda: ";
    is >> studentas.vardas;

    std::cout << "Iveskite pavarde: ";
    is >> studentas.pavarde;

    char generuotiPazymius;
    std::cout << "Ar norite, kad namu darbu ir egzamino pazymiai butu generuojami? (T/N): ";
    is >> generuotiPazymius;

    if (generuotiPazymius == 'T' || generuotiPazymius == 't') {
        int NdKiekis = rand() % 10 + 1;
        for (int i = 0; i < NdKiekis; ++i) {
            studentas.Nd.push_back(generuotiNdBala());
        }
        studentas.egz = generuotiEgzBala();
    } else {
        int pazymys;
        std::cout << "Iveskite namu darbu pazymius (baigus parasyk -1): ";
        while (is >> pazymys && pazymys != -1) {
            if (pazymys >= 1 && pazymys <= 10) {
                studentas.Nd.push_back(pazymys);
            } else {
                std::cerr << "Klaida: ND pazymys turi buti tarp 1-10." << std::endl;
            }
        }

        std::cout << "Iveskite egzamino pazymi: ";
        is >> pazymys;
        if (pazymys >= 1 && pazymys <= 10) {
            studentas.egz = pazymys;
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
void generuotiStudentus(std::vector<Studentas>& studentai, int studentuSkaicius, std::ofstream& outFile);
void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Studentas>& studentai);
void irasytiIFaila(const std::string& filename, const std::vector<Studentas>& studentai);
void printTable(const std::vector<Studentas>& studentai, const std::string& title);
void Demonstracija3();
void Demonstracija4();

#endif // STUDENTAS_H

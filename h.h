#ifndef H_H
#define H_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include <string>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> Nd;
    int egz;

public:
        //Konstruktorius
    Studentas() : vardas(""), pavarde(""), egz(0) {}

    //Pagr. Konstr.
    Studentas(const std::string& vardas, const std::string& pavarde,
              const std::vector<int>& Nd, int egz)
        : vardas(vardas), pavarde(pavarde), Nd(Nd), egz(egz) {}

    //Copy konstr
    Studentas(const Studentas& other)
        : vardas(other.vardas), pavarde(other.pavarde), Nd(other.Nd), egz(other.egz) {
        /*std::cout << "Iskviestas Copy konstruktorius " << vardas << " " << pavarde << "\n";
        for (const auto& pazymys : Nd) {
        std::cout << pazymys << " ";
        }
        std::cout << std::endl;*/

        }

    // Copy assignment operatorius
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            Nd = other.Nd;
            egz = other.egz;
            /*std::cout << "Iskviestas Copy assignment operatorius " << vardas << " " << pavarde << "\n";
            for (const auto& pazymys : Nd) {
            std::cout << pazymys << " ";
            }
            std::cout << std::endl;*/

        }
            return *this;
        }

    // Destruktorius

    ~Studentas(){Nd.clear(); /*std::cout << "kvieciamas destruktorius " << vardas << " " << pavarde <<"\n";*/
   }
    //output
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




    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void addNd(int nd) { Nd.push_back(nd); }
    void setEgz(int e) { egz = e; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::vector<int> getNd() const { return Nd; }
    int getEgz() const { return egz; }

    double skaiciuotiVidurki() const {
        if (Nd.empty()) return 0.0;
        return std::accumulate(Nd.begin(), Nd.end(), 0.0) / Nd.size();
    }

    double skaiciuotiMediana() const {
        if (Nd.empty()) return 0.0;
        std::vector<int> kopija(Nd);
        std::sort(kopija.begin(), kopija.end());
        size_t dydis = kopija.size();
        if (dydis % 2 == 0) {
            return (kopija[dydis / 2 - 1] + kopija[dydis / 2]) / 2.0;
        } else {
            return kopija[dydis / 2];
        }
    }

    double skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const {
        double NdBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ? skaiciuotiVidurki() : skaiciuotiMediana();
        return 0.4 * NdBalas + 0.6 * egz;

    }

    static int generuotiNdBala() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 10);
        return dis(gen);
    }
    static int generuotiEgzBala() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 10);
        return dis(gen);
    }
    void setNd(const std::vector<int>& nd) {
        Nd = nd;
    }
};

int generuotiNdBala();
int generuotiEgzBala();
void generuotiStudentus(std::vector<Studentas>& studentai, int studentuSkaicius, std::ofstream& outFile);
void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Studentas>& studentai);
void irasytiIFaila(const std::string& filename, const std::vector<Studentas>& studentai);
void printTable(const std::vector<Studentas>& studentai, const std::string& title);
void Demonstracija3();


#endif // STUDENTAS_H

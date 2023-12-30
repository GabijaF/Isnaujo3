#ifndef F_H
#define F_H

#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include <string>
#include <list>

class StudentasL {
private:
    std::string vardas;
    std::string pavarde;
    std::list<int> Nd;
    int egz;

public:
        //Konstruktorius
    StudentasL() : vardas(""), pavarde(""), egz(0) {}

    //Pagr. Konstr.
    StudentasL(const std::string& vardas, const std::string& pavarde,
              const std::list<int>& Nd, int egz)
        : vardas(vardas), pavarde(pavarde), Nd(Nd), egz(egz) {}

    //Copy konstr
    StudentasL(const StudentasL& other)
        : vardas(other.vardas), pavarde(other.pavarde), Nd(other.Nd), egz(other.egz) {
        /*std::cout << "Iskviestas Copy konstruktorius " << vardas << " " << pavarde << "\n";
        for (const auto& pazymys : Nd) {
        std::cout << pazymys << " ";
        }
        std::cout << std::endl;*/

        }

    // Copy assignment operatorius
    StudentasL& operator=(const StudentasL& other) {
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

    ~StudentasL(){Nd.clear(); /*std::cout << "kvieciamas destruktorius " << vardas << " " << pavarde <<"\n";*/
   }
    //output
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




    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void addNd(int nd) { Nd.push_back(nd); }
    void setEgz(int e) { egz = e; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::list<int> getNd() const { return Nd; }
    int getEgz() const { return egz; }

    double skaiciuotiVidurki() const {
        if (Nd.empty()) return 0.0;
        return std::accumulate(Nd.begin(), Nd.end(), 0.0) / Nd.size();
    }

    double skaiciuotiMediana() const {
    if (Nd.empty()) return 0.0;

    std::list<int> kopija(Nd.begin(), Nd.end());
    kopija.sort();

    size_t dydis = kopija.size();
    auto it = kopija.begin();
    std::advance(it, dydis / 2);

    if (dydis % 2 == 0) {
        int vidurinis1 = *std::prev(it);
        int vidurinis2 = *it;
        return (vidurinis1 + vidurinis2) / 2.0;
    } else {
        return *it;
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
    void setNd(const std::list<int>& nd) {
        Nd = nd;
    }
};

int generuotiNdBala();
int generuotiEgzBala();
void generuotiStudentus(std::list<StudentasL>& studentai, int studentuSkaicius, std::ofstream& outFile);
void skaitytiIsFailo(const std::string& failoPavadinimas, std::list<StudentasL>& studentai);
void irasytiIFaila(const std::string& filename, const std::list<StudentasL>& studentai);
void printTable(const std::list<StudentasL>& studentai, const std::string& title);
void Demonstracija3();


#endif // StudentasL_H


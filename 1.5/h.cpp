#include "h.h"
#include "zmogus.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <numeric>

double Studentas::skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const {
    double NdBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ? skaiciuotiVidurki() : skaiciuotiMediana();
    return 0.4 * NdBalas + 0.6 * egz;
}


double Studentas::skaiciuotiVidurki() const {
    if (Nd.empty()) return 0.0;
    return std::accumulate(Nd.begin(), Nd.end(), 0.0) / Nd.size();
}

double Studentas::skaiciuotiMediana() const {
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


int Studentas::generuotiNdBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int Studentas::generuotiEgzBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);

}


void generuotiStudentus(std::vector<Studentas>& studentai, int studentuSkaicius, std::ofstream& outFile) {
    for (int i = 1; i <= studentuSkaicius; ++i) {
        outFile << std::setw(15) << std::left << "Vardas" + std::to_string(i)
                << std::setw(15) << std::left << "Pavarde" + std::to_string(i);
        for (int j = 0; j < 5; ++j) {
            outFile << std::setw(5) << std::right << Studentas::generuotiNdBala() <<" ";
        }
        outFile << std::setw(5) << std::right << Studentas::generuotiEgzBala() << "\n";
    }
}



void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Studentas>& studentai) {
    std::ifstream inFile(failoPavadinimas);
    if (!inFile) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }

    std::string vardas, pavarde;
    int ndPazymys, egzPazymys;
    std::string eilute;


    std::getline(inFile, eilute);

    while (std::getline(inFile, eilute)) {
        std::istringstream iss(eilute);
        iss >> vardas >> pavarde;

        Studentas naujasStudentas;
        naujasStudentas.setVardas(vardas);
        naujasStudentas.setPavarde(pavarde);

        std::vector<int> pazymiai;
        while (iss >> ndPazymys) {
            pazymiai.push_back(ndPazymys);
        }

        if (!pazymiai.empty()) {
            egzPazymys = pazymiai.back();
            pazymiai.pop_back();
            naujasStudentas.setNd(pazymiai);
            naujasStudentas.setEgz(egzPazymys);

            studentai.push_back(naujasStudentas);
        }
    }
}



void irasytiIFaila(const std::string& filename, const std::vector<Studentas>& studentai) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
    }

    char baloSkaiciavimoBudas;
    std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
    std::cin >> baloSkaiciavimoBudas;


    outFile << std::setw(2) << "Vardas" << std::setw(17) << "Pavarde"
            << std::setw(20) << "Galutinis\n" <<"-------------------------------------------------" << std::endl;

    for (const auto& studentas : studentai) {
        double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
        outFile << std::setw(15) << std::left << studentas.getVardas()
                << std::setw(15) << std::left << studentas.getPavarde()
                << std::setw(10) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
    }
}
void printTable(const std::vector<Studentas>& studentai, const std::string& title) {

    char baloSkaiciavimoBudas;
    std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
    std::cin >> baloSkaiciavimoBudas;


    std::cout << title << ":\n";
    std::cout << std::setw(15) << std::left << "Vardas"
              << std::setw(15) << std::left << "Pavarde"
              << std::setw(10) << std::right << "Galutinis" << std::setw(10) << std::right << "Adresas" << "\n";
    std::cout << "-----------------------------------------------------------------\n";

    for (const Studentas& studentas : studentai) {
        double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
        std::cout << std::setw(15) << std::left << studentas.getVardas()
                  << std::setw(15) << std::left << studentas.getPavarde()
                  << std::setw(10) << std::fixed << std::setprecision(2)
                  << std::right << galutinisBalas << std::setw(10) << std::fixed << std::setprecision(2) << std::right << &studentas <<"\n";
    }


}

void Demonstracija3() {
    // Copy
    Studentas studentas1("Jonas", "Jonaitis", {5, 7, 8}, 9);

    // Copy Constructor
    Studentas studentas2 = studentas1;

    // Copy Assignment
    Studentas studentas3;
    studentas3 = studentas1;// Copy assignment
    std::cout << "Studentas 1:\n" << studentas1 << "\n";
    std::cout << "Studentas 2:\n" << studentas2 << "\n";
    std::cout << "Studentas 3:\n" << studentas3 << "\n";

    // Destruktorius pakvies studentas1, studentasCopy, studentas2
}
void Demonstracija4(){

    /*Zmogus zmogus;
    Studentas studentas1;
    cin >> studentas1;*/


}



#include "f.h"
#include "zmogus.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <numeric>


double StudentasL::skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const {
    double NdBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ? skaiciuotiVidurki() : skaiciuotiMediana();
    return 0.4 * NdBalas + 0.6 * egz;
}


double StudentasL::skaiciuotiVidurki() const {
    if (Nd.empty()) return 0.0;
    return std::accumulate(Nd.begin(), Nd.end(), 0.0) / Nd.size();
}

double StudentasL::skaiciuotiMediana() const {
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


int StudentasL::generuotiNdBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int StudentasL::generuotiEgzBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);

}


void generuotiStudentus(std::list<StudentasL>& studentai, int studentuSkaicius, std::ofstream& outFile) {
    for (int i = 1; i <= studentuSkaicius; ++i) {
        outFile << std::setw(15) << std::left << "Vardas" + std::to_string(i)
                << std::setw(15) << std::left << "Pavarde" + std::to_string(i);
        for (int j = 0; j < 5; ++j) {
            outFile << std::setw(5) << std::right << StudentasL::generuotiNdBala() <<" ";
        }
        outFile << std::setw(5) << std::right << StudentasL::generuotiEgzBala() << "\n";
    }
}



void skaitytiIsFailo(const std::string& failoPavadinimas, std::list<StudentasL>& studentai) {
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

        StudentasL naujasStudentasL;
        naujasStudentasL.setVardas(vardas);
        naujasStudentasL.setPavarde(pavarde);

        std::list<int> pazymiai;
        while (iss >> ndPazymys) {
            pazymiai.push_back(ndPazymys);
        }

        if (!pazymiai.empty()) {
            egzPazymys = pazymiai.back();
            pazymiai.pop_back();
            naujasStudentasL.setNd(pazymiai);
            naujasStudentasL.setEgz(egzPazymys);

            studentai.push_back(naujasStudentasL);
        }
    }
}



void irasytiIFaila(const std::string& filename, const std::list<StudentasL>& studentai) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
    }

    char baloSkaiciavimoBudas;
    /*std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
    std::cin >> baloSkaiciavimoBudas;*/


    outFile << std::setw(2) << "Vardas" << std::setw(17) << "Pavarde"
            << std::setw(20) << "Galutinis\n" <<"-------------------------------------------------" << std::endl;

    for (const auto& StudentasL : studentai) {
        double galutinisBalas = StudentasL.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
        outFile << std::setw(15) << std::left << StudentasL.getVardas()
                << std::setw(15) << std::left << StudentasL.getPavarde()
                << std::setw(10) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
    }
}
void printTable(const std::list<StudentasL>& studentai, const std::string& title) {

    char baloSkaiciavimoBudas;
    /*std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
    std::cin >> baloSkaiciavimoBudas;*/


    std::cout << title << ":\n";
    std::cout << std::setw(15) << std::left << "Vardas"
              << std::setw(15) << std::left << "Pavarde"
              << std::setw(10) << std::right << "Galutinis" << std::setw(10) << std::right << "Adresas" << "\n";
    std::cout << "-----------------------------------------------------------------\n";

    for (const StudentasL& StudentasL : studentai) {
        double galutinisBalas = StudentasL.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
        std::cout << std::setw(15) << std::left << StudentasL.getVardas()
                  << std::setw(15) << std::left << StudentasL.getPavarde()
                  << std::setw(10) << std::fixed << std::setprecision(2)
                  << std::right << galutinisBalas << std::setw(10) << std::fixed << std::setprecision(2) << std::right << &StudentasL <<"\n";
    }


}






#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> Nd;
    int egz;
};

double skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) {
        return 0.0;
    }
    double suma = 0.0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return suma / pazymiai.size();
}


double skaiciuotiGalutiniBala(const Studentas& studentas, bool naudotiVidurki) {
    double NdBalas = skaiciuotiVidurki(studentas.Nd);
    double galutinisBalas = (0.4 * NdBalas + 0.6 * studentas.egz);
    return galutinisBalas;
}

int main() {
    std::vector<Studentas> studentai;

    try {



        std::ifstream inFile("studentai1000000.txt");
        if (!inFile) {
            std::cerr << "Nepavyko atidaryti failo" << std::endl;
            return 1;
        }

        auto startReadFileTime = std::chrono::high_resolution_clock::now();
        //auto endReadFileTime = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;

        std::string eilute;
        while (std::getline(inFile, eilute)) {
            std::istringstream iss(eilute);
            Studentas naujasStudentas;
            iss >> naujasStudentas.vardas >> naujasStudentas.pavarde;

            int pazymys;
            while (iss >> pazymys) {
                naujasStudentas.Nd.push_back(pazymys);
            }

            if (naujasStudentas.Nd.empty()) {

                continue;
            }

            naujasStudentas.egz = naujasStudentas.Nd.back();
            naujasStudentas.Nd.pop_back();

            studentai.push_back(naujasStudentas);
        }

        inFile.close();
        auto endReadFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;


        int studentCount = studentai.size();
        std::cout << "Studentu skaicius: " << studentCount << std::endl;

        std::cout << "Failo nuskaitymas su"<< studentCount << "studentais uztruko: " << readFileTime.count() << " sekundes" << std::endl;


        std::ofstream vargsiukaiFile("vargsiukai.txt");
        std::ofstream galvociaiFile("galvociai.txt");

        vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::right << "Galutinis (Vid.)" << std::endl;
        vargsiukaiFile << "---------------------------------------------------------------------" << std::endl;

        galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavardė" << std::setw(15) << std::right << "Galutinis (Vid.)" << std::endl;
        galvociaiFile << "---------------------------------------------------------------------" << std::endl;

        auto startSortTime = std::chrono::high_resolution_clock::now();

        for (const Studentas& studentas : studentai) {
            double galutinisBalasVidurkis = skaiciuotiGalutiniBala(studentas, true);


            if (galutinisBalasVidurkis < 5.0) {
                vargsiukaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(5) << std::fixed << std::setprecision(2) << std::right << galutinisBalasVidurkis << std::endl;
            } else {
                galvociaiFile << std::setw(15) << std::left << studentas.vardas << std::setw(15) << std::left << studentas.pavarde << std::setw(5) << std::fixed << std::setprecision(2) << std::right << galutinisBalasVidurkis << std::endl;
            }
        }

        auto endSortTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sortTime = endSortTime - startSortTime;
        std::cout << "Failo rusiavimas su " << studentCount << " studentais i dvi grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;

        std::ifstream readVargsiukaiFile("vargsiukai.txt");
        std::ifstream readGalvociaiFile("galvociai.txt");

        auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

        // Write vargsiukai data to the file
        for (const Studentas& studentas : studentai) {
            double galutinisBalasVidurkis = skaiciuotiGalutiniBala(studentas, true);
        }

        auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
        std::cout << "Failo isvedimas su " << studentCount << " studentais i vargsiukus uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

        auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

        // Write galvociai data to the file
        for (const Studentas& studentas : studentai) {
            double galutinisBalasVidurkis = skaiciuotiGalutiniBala(studentas, true);
        }

        auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
        std::cout << "Failo isvedimas su " << studentCount << " studentais i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;



        vargsiukaiFile.close();
        galvociaiFile.close();


    } catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }
    return 0;


}

#include "h.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>


int v_3(){
    std::vector<Studentas> studentai;
    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> galvociai;

    char pasirinkimas;
    std::cout << "Ar norite ivesti duomenis (R) ar skaityti is failo (F) ar generuoti (G) ";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 'G' || pasirinkimas == 'g') {
        int studentuSkaicius;
        std::cout << "Kiek studentu norite sugeneruoti? ";
        std::cin >> studentuSkaicius;

        auto startCreateFileTime = std::chrono::high_resolution_clock::now();

        std::string fileName = "studentai_" + std::to_string(studentuSkaicius) + ".txt";
        std::ofstream outFile(fileName);
        outFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde";

        for (int i = 1; i <= 5; ++i) {
            outFile << std::setw(5) << std::right << "nd" << i;
        }
        outFile << std::setw(5) << std::right << "egz\n";
        outFile << "-----------------------------------------------------------------------\n";

        for (int i = 1; i <= studentuSkaicius; ++i) {
            outFile << std::setw(15) << std::left << "Vardas" + std::to_string(i)
                    << std::setw(15) << std::left << "Pavarde" + std::to_string(i);
            for (int j = 0; j < 5; ++j) {
                outFile << std::setw(5) << std::right << generuotiNdBala();
            }
            outFile << std::setw(5) << std::right << generuotiEgzBala() << "\n";
        }

        outFile.close();

        auto endCreateFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> CreateFileTime = endCreateFileTime - startCreateFileTime;
        std::cout << "Failo" << fileName << "k rimas uztruko: " << CreateFileTime.count() << " sekundes" << std::endl;


        std::cout << "Failas '" << fileName << "' buvo sugeneruotas.\n";


        // Now, read the generated file
        std::ifstream inFile(fileName);
        if (!inFile) {
            std::cerr << "Nepavyko atidaryti failo " << fileName << std::endl;
            return 1;
        }

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;

        auto startReadFileTime = std::chrono::high_resolution_clock::now();

        std::string eilute;
        while (std::getline(inFile, eilute)) {
            Studentas naujasStudentas;
            std::istringstream iss(eilute);
            std::string vardas, pavarde;
            iss >> vardas >> pavarde;
            naujasStudentas.setVardas(vardas);
            naujasStudentas.setPavarde(pavarde);

            int pazymys;
            while (iss >> pazymys) {
                naujasStudentas.addNd(pazymys);
            }

            if (!naujasStudentas.getNd().empty()) {
                naujasStudentas.setEgz(naujasStudentas.getNd().back());
                naujasStudentas.getNd().pop_back();

                studentai.push_back(naujasStudentas);
            }
        }

        inFile.close();

        int studentCount = studentai.size();
        auto endReadFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;


        auto startSortTime = std::chrono::high_resolution_clock::now();

            auto partitionPoint = std::stable_partition(studentai.begin(), studentai.end(), [&](const Studentas& studentas) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                return galutinisBalas < 5.0;
            });

            vargsiukai.assign(studentai.begin(), partitionPoint);
            galvociai.assign(partitionPoint, studentai.end());
            auto endSortTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sortTime = endSortTime - startSortTime;


            char rikiavimas;
            std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
            std::cin >> rikiavimas;

            if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus:\n"
                         "1. Pagal varda\n"
                         "2. Pagal pavarde\n"
                         "3. Pagal galutini bala\n"
                         "Jusu pasirinkimas: ";
            int rikiavimoKriterijus;
            std::cin >> rikiavimoKriterijus;

            char rikiavimoTvarka;
            std::cout << "Kaip norite surikiuoti rezultatus - did iausi pirma (D) ar ma iausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const Studentas& a, const Studentas& b) {
                switch (rikiavimoKriterijus) {
                    case 1:{
                        std::string numStrA = a.getVardas().substr(6);
                        std::string numStrB = b.getVardas().substr(6);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 2:{
                        std::string numStrA = a.getPavarde().substr(7);
                        std::string numStrB = b.getPavarde().substr(7);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 3:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ?
                            a.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) > b.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) :
                            a.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) < b.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                    default:
                        // Jei pasirinktas neteisingas kriterijus, nekei iame tvarkos.
                        return false;
                }
            };

            std::sort(vargsiukai.begin(), vargsiukai.end(), compareByCriterion);
            std::sort(galvociai.begin(), galvociai.end(), compareByCriterion);

            }


            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;



            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream vargsiukaiFile("vargsiukai.txt");
            vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            vargsiukaiFile << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : vargsiukai) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                vargsiukaiFile << std::setw(15) << std::left << studentas.getVardas() << std::setw(15) << std::left << studentas.getPavarde() << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
                }
            vargsiukaiFile.close();
            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream galvociaiFile("galvociai.txt");
            galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            galvociaiFile << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : galvociai) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                galvociaiFile << std::setw(15) << std::left << studentas.getVardas() << std::setw(15) << std::left << studentas.getPavarde() << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
                }
            galvociaiFile.close();
            auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;




        return 0;
    }


    if (pasirinkimas == 'R' || pasirinkimas == 'r') {
        do {
            Studentas naujasStudentas;

            std::string vardas, pavarde;
            std::cout << "Iveskite studento varda: ";
            std::cin >> vardas;
            naujasStudentas.setVardas(vardas);

            std::cout << "Iveskite studento pavarde: ";
            std::cin >> pavarde;
            naujasStudentas.setPavarde(pavarde);

            char generuotiPazymius;
            std::cout << "Ar norite, kad namu darbu ir egzamino pazymiai butu generuojami? (T/N): ";
            std::cin >> generuotiPazymius;

            if (generuotiPazymius == 'T' || generuotiPazymius == 't') {
                int NdKiekis = rand() % 10 + 1;
                for (int i = 0; i < NdKiekis; ++i) {
                    naujasStudentas.addNd(generuotiNdBala());
                }
                naujasStudentas.setEgz(generuotiEgzBala());
            } else {
                int pazymys;
                std::cout << "Iveskite namu darbu pazymius (baigus parasyk -1): ";
                while (std::cin >> pazymys && pazymys != -1) {
                    if (pazymys < 1 || pazymys > 10) {
                        std::cerr << "Klaida: ND pazymys turi buti tarp 1-10." << std::endl;
                        continue;
                    }
                    naujasStudentas.addNd(pazymys);
                }
                std::cout << "Iveskite egzamino pazymi: ";
                std::cin >> pazymys;
                if (pazymys < 1 || pazymys > 10) {
                    std::cerr << "Klaida: Egzamino pazymys turi buti tarp 1-10." << std::endl;
                    continue;
                }
                naujasStudentas.setEgz(pazymys);
            }

            studentai.push_back(naujasStudentas);

            std::cout << "Ar norite ivesti dar vieno studento duomenis? (T/N): ";
            std::cin >> pasirinkimas;

        } while (pasirinkimas == 'T' || pasirinkimas == 't');

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;

        auto partitionPoint = std::stable_partition(studentai.begin(), studentai.end(), [&](const Studentas& studentas) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                return galutinisBalas < 5.0;
            });

            vargsiukai.assign(studentai.begin(), partitionPoint);
            galvociai.assign(partitionPoint, studentai.end());


        char rikiavimas;
        std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
        std::cin >> rikiavimas;


        if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus:\n"
                         "1. Pagal vard \n"
                         "2. Pagal pavard \n"
                         "3. Pagal galutin  bal \n"
                         "J s  pasirinkimas: ";
            int rikiavimoKriterijus;
            std::cin >> rikiavimoKriterijus;

            char rikiavimoTvarka;
            std::cout << "Kaip norite surikiuoti rezultatus - did iausi pirma (D) ar ma iausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const Studentas& a, const Studentas& b) {
                switch (rikiavimoKriterijus) {
                    case 1:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? a.getVardas() > b.getVardas() : a.getVardas() < b.getVardas();
                    case 2:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? a.getPavarde() > b.getPavarde() : a.getPavarde() < b.getPavarde();
                    case 3:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ?
                            a.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) > b.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) :
                            a.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) < b.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                    default:
                        return false;
                    }
                };


            std::sort(vargsiukai.begin(), vargsiukai.end(), compareByCriterion);
            std::sort(galvociai.begin(), galvociai.end(), compareByCriterion);
        }

            std::cout << std::endl;
            int studentCount = studentai.size();
            std::cout <<"studentu sk:" << studentCount << std::endl;


            std::cout << std::endl;
            std::cout << "vargsiukai:" << std::endl;
            std::cout << std::endl;
            std::cout << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : vargsiukai) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                std::cout << std::setw(15) << std::left << studentas.getVardas() << std::setw(15) << std::left << studentas.getPavarde() << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }

            std::cout << std::endl;
            std::cout << std::endl;


            std::cout << "galvociai:" << std::endl;
            std::cout << std::endl;
            std::cout << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : galvociai) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                std::cout << std::setw(15) << std::left << studentas.getVardas() << std::setw(15) << std::left << studentas.getPavarde() << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            std::cout << std::endl;

    }

     if (pasirinkimas == 'F' || pasirinkimas == 'f') {
        try {


            std::string failoPavadinimas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failoPavadinimas;

            std::ifstream inFile(failoPavadinimas);
            if (!inFile) {
                throw std::runtime_error("Nepavyko atidaryti failo");
            }

            char baloSkaiciavimoBudas;
            std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
            std::cin >> baloSkaiciavimoBudas;





            auto startReadFileTime = std::chrono::high_resolution_clock::now();

            std::string eilute;
            while (std::getline(inFile, eilute)) {
                Studentas naujasStudentas;
                std::istringstream iss(eilute);
                std::string vardas, pavarde;
                iss >> vardas >> pavarde;
                naujasStudentas.setVardas(vardas);
                naujasStudentas.setPavarde(pavarde);

                int pazymys;
                while (iss >> pazymys) {
                    naujasStudentas.addNd(pazymys);
                }

                if (!naujasStudentas.getNd().empty()) {
                    naujasStudentas.setEgz(naujasStudentas.getNd().back());
                    naujasStudentas.getNd().pop_back();

                    studentai.push_back(naujasStudentas);
                }
            }

            inFile.close();
            int studentCount = studentai.size();
            auto endReadFileTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;







            auto startSortTime = std::chrono::high_resolution_clock::now();
            auto partitionPoint = std::stable_partition(studentai.begin(), studentai.end(), [&](const Studentas& studentas) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                return galutinisBalas < 5.0;
            });

            vargsiukai.assign(studentai.begin(), partitionPoint);
            galvociai.assign(partitionPoint, studentai.end());
            auto endSortTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sortTime = endSortTime - startSortTime;


            char rikiavimas;
            std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
            std::cin >> rikiavimas;

            if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus:\n"
                            "1. Pagal varda\n"
                            "2. Pagal pavarde\n"
                            "3. Pagal galutini bala\n"
                            "Jusu pasirinkimas: ";
            int rikiavimoKriterijus;
            std::cin >> rikiavimoKriterijus;

            char rikiavimoTvarka;
            std::cout << "Kaip norite surikiuoti rezultatus - did iausi pirma (D) ar ma iausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const Studentas& a, const Studentas& b) {
                switch (rikiavimoKriterijus) {
                    case 1:{
                        std::string numStrA = a.getVardas().substr(6);
                        std::string numStrB = b.getVardas().substr(6);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }

                    case 2:{
                        std::string numStrA = a.getPavarde().substr(7);
                        std::string numStrB = b.getPavarde().substr(7);
                        int numA = std::stoi(numStrA);
                        int numB = std::stoi(numStrB);
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ? numA > numB : numA < numB;
                    }
                    case 3:
                        return (rikiavimoTvarka == 'D' || rikiavimoTvarka == 'd') ?
                            a.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) > b.skaiciuotiGalutiniBala(baloSkaiciavimoBudas)  :
                            a.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) < b.skaiciuotiGalutiniBala(baloSkaiciavimoBudas) ;
                    default:
                        // Jei pasirinktas neteisingas kriterijus, nekei iame tvarkos.
                        return false;
                }
            };

            std::sort(vargsiukai.begin(), vargsiukai.end(), compareByCriterion);
            std::sort(galvociai.begin(), galvociai.end(), compareByCriterion);
            }


            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;



            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream vargsiukaiFile("vargsiukai.txt");
            vargsiukaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            vargsiukaiFile << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : vargsiukai) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                vargsiukaiFile << std::setw(15) << std::left << studentas.getVardas() << std::setw(15) << std::left << studentas.getPavarde() << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            vargsiukaiFile.close();
            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

            std::ofstream galvociaiFile("galvociai.txt");
            galvociaiFile << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::right << "Galutinis" << std::endl;
            galvociaiFile << "---------------------------------------------" << std::endl;
            for (const Studentas& studentas : galvociai) {
                double galutinisBalas = studentas.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);
                galvociaiFile << std::setw(15) << std::left << studentas.getVardas() << std::setw(15) << std::left << studentas.getPavarde() << std::setw(15) << std::fixed << std::setprecision(2) << std::right << galutinisBalas << "\n";
            }
            galvociaiFile.close();
            auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "Klaida: " << e.what() << std::endl;
            return 1;
        }

    }else {
        std::cerr << "Neteisingas pasirinkimas." << std::endl;
        return 1;
    }

    return 0;



}



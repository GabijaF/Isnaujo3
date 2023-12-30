
#include "f.h"


int l_2(){

    /*Demonstracija3();
    return 0;*/

    std::list<StudentasL> studentai;
    std::list<StudentasL> vargsiukai;
    //std::list<StudentasL> galvociai;

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
        outFile << std::setw(5) << std::right  << "   egz\n";
        outFile << "-----------------------------------------------------------------------\n";

        generuotiStudentus(studentai, studentuSkaicius, outFile);



        outFile.close();

        auto endCreateFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> CreateFileTime = endCreateFileTime - startCreateFileTime;
        std::cout << "Failo" << fileName << "kurimas uztruko: " << CreateFileTime.count() << " sekundes" << std::endl;



        std::cout << "Failas '" << fileName << "' buvo sugeneruotas.\n";

        std::ifstream inFile(fileName);
        if (!inFile) {
            std::cerr << "Nepavyko atidaryti failo " << fileName << std::endl;
            return 1;
        }

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;

        auto startReadFileTime = std::chrono::high_resolution_clock::now();
        skaitytiIsFailo(fileName, studentai);


        int studentCount = studentai.size();
        auto endReadFileTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;


        auto startSortTime = std::chrono::high_resolution_clock::now();

            for (auto it = studentai.begin(); it != studentai.end();) {
                const StudentasL& currentStudent = *it;
                double galutinisBalas = currentStudent.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);

                if (galutinisBalas <= 5.0) {
                    vargsiukai.push_back(currentStudent);
                    it = studentai.erase(it); // Use the iterator returned by erase
                } else {
                    ++it;
                }
            }

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
            std::cout << "Kaip norite surikiuoti rezultatus - didþiausi pirma (D) ar maþiausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const StudentasL& a, const StudentasL& b) {
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
                        // Jei pasirinktas neteisingas kriterijus, nekeièiame tvarkos.
                        return false;
                }
            };

            vargsiukai.sort(compareByCriterion);
            studentai.sort(compareByCriterion);

            }


            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;



            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            irasytiIFaila("vargsiukai.txt", vargsiukai);

            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

            irasytiIFaila("galvociai.txt", studentai);
            auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;

            std::cout << "is viso: " << writeGalvociaiTime.count() + writeVargsiukaiTime.count() +  readFileTime.count() + sortTime.count() << " sekundes" << std::endl;


        return 0;
    }


    if (pasirinkimas == 'R' || pasirinkimas == 'r') {
        do {
            StudentasL naujasStudentasL;


            std::cin >> naujasStudentasL; // overloaded input operator
            studentai.push_back(naujasStudentasL);


            std::cout << "Ar norite ivesti dar vieno studento duomenis? (T/N): ";
            std::cin >> pasirinkimas;

        } while (pasirinkimas == 'T' || pasirinkimas == 't');

        char baloSkaiciavimoBudas;
        std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
        std::cin >> baloSkaiciavimoBudas;

        for (auto it = studentai.begin(); it != studentai.end();) {
            const StudentasL& currentStudent = *it;
            double galutinisBalas = currentStudent.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);

            if (galutinisBalas <= 5.0) {
                vargsiukai.push_back(currentStudent);
                it = studentai.erase(it); // Use the iterator returned by erase
            } else {
                ++it;
            }
        }


        char rikiavimas;
        std::cout << "Ar norite, kad galutiniai rezultatai butu surikiuoti (Y/N)? ";
        std::cin >> rikiavimas;


        if (rikiavimas == 'Y' || rikiavimas == 'y') {
            std::cout << "Kaip norite surikiuoti rezultatus:\n"
                         "1. Pagal varda \n"
                         "2. Pagal pavarda \n"
                         "3. Pagal galutini  bala \n"
                         "Jusu  pasirinkimas: ";
            int rikiavimoKriterijus;
            std::cin >> rikiavimoKriterijus;

            char rikiavimoTvarka;
            std::cout << "Kaip norite surikiuoti rezultatus - did iausi pirma (D) ar ma iausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const StudentasL& a, const StudentasL& b) {
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


            vargsiukai.sort(compareByCriterion);
            studentai.sort(compareByCriterion);
        }

            std::cout << std::endl;
            int studentCount = studentai.size();
            std::cout <<"studentu sk:" << studentCount << std::endl;




            printTable(vargsiukai, "Vargsiukai");
            printTable(studentai, "Galvociai");

    }

     if (pasirinkimas == 'F' || pasirinkimas == 'f') {
        try {


            std::string failoPavadinimas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failoPavadinimas;


            char baloSkaiciavimoBudas;
            std::cout << "Kaip norite skaiciuoti galutini bala pagal vidurki (V) ar pagal mediana (M)? ";
            std::cin >> baloSkaiciavimoBudas;


            auto startReadFileTime = std::chrono::high_resolution_clock::now();

            skaitytiIsFailo(failoPavadinimas, studentai);

            int studentCount = studentai.size();
            auto endReadFileTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> readFileTime = endReadFileTime - startReadFileTime;



            auto startSortTime = std::chrono::high_resolution_clock::now();
            for (auto it = studentai.begin(); it != studentai.end();) {
                const StudentasL& currentStudent = *it;
                double galutinisBalas = currentStudent.skaiciuotiGalutiniBala(baloSkaiciavimoBudas);

                if (galutinisBalas <= 5.0) {
                    vargsiukai.push_back(currentStudent);
                    it = studentai.erase(it); // Use the iterator returned by erase
                } else {
                    ++it;
                }
            }

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
            std::cout << "Kaip norite surikiuoti rezultatus - didþiausi pirma (D) ar maþiausi pirma (M)? ";
            std::cin >> rikiavimoTvarka;

            auto compareByCriterion = [rikiavimoKriterijus, rikiavimoTvarka, baloSkaiciavimoBudas](const StudentasL& a, const StudentasL& b) {
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
                        // Jei pasirinktas neteisingas kriterijus, nekeièiame tvarkos.
                        return false;
                }
            };

            vargsiukai.sort(compareByCriterion);
            studentai.sort(compareByCriterion);
            }


            std::cout << std::endl;
            std::cout << "Studentu skaicius: " << studentCount << std::endl;
            std::cout << "Failo nuskaitymas su " << studentCount << " studentu uztruko: " << readFileTime.count() << " sekundes" << std::endl;


            std::cout << "Failo su " << studentCount << " studentu dalijimas i 2 grupes uztruko: " << sortTime.count() << " sekundes" << std::endl;


            auto startWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();

            irasytiIFaila("vargsiukai.txt", vargsiukai);

            auto endWriteVargsiukaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeVargsiukaiTime = endWriteVargsiukaiTime - startWriteVargsiukaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i vargsiukai uztruko: " << writeVargsiukaiTime.count() << " sekundes" << std::endl;

            auto startWriteGalvociaiTime = std::chrono::high_resolution_clock::now();

            irasytiIFaila("galvociai.txt", studentai);
            auto endWriteGalvociaiTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> writeGalvociaiTime = endWriteGalvociaiTime - startWriteGalvociaiTime;
            std::cout << "Failo isvedimas su " << studentCount << " studentu i galvociai uztruko: " << writeGalvociaiTime.count() << " sekundes" << std::endl;

            std::cout << "is viso: " << writeGalvociaiTime.count() + writeVargsiukaiTime.count() +  readFileTime.count() + sortTime.count() << " sekundes" << std::endl;


        } catch (const std::exception& e) {
            std::cerr << "Klaida: " << e.what() << std::endl;
            return 1;
        }

    }else {
        /*std::cerr << "Neteisingas pasirinkimas." << std::endl;*/
        return 1;
    }

    return 0;



}




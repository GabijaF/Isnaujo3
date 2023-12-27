#include "f.h"

int generuotiNdBalaL() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int generuotiEgzBalaL() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}



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

void generuotiStudentus(std::vector<StudentasL>& studentai, int studentuSkaicius) {
    for (int i = 1; i <= studentuSkaicius; ++i) {
        StudentasL naujasStudentasL;
        naujasStudentasL.setVardas("Vardas" + std::to_string(i));
        naujasStudentasL.setPavarde("Pavarde" + std::to_string(i));
        for (int j = 0; j < 5; ++j) {
            naujasStudentasL.addNd(generuotiNdBalaL());
        }
        naujasStudentasL.setEgz(generuotiEgzBalaL());
        studentai.push_back(naujasStudentasL);
    }
}




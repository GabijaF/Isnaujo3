#include "h.h"


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

double Studentas::skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const {
    double NdBalas = (baloSkaiciavimoBudas == 'V' || baloSkaiciavimoBudas == 'v') ? skaiciuotiVidurki() : skaiciuotiMediana();
    return 0.4 * NdBalas + 0.6 * egz;
}

int generuotiNdBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

int generuotiEgzBala() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    return dis(gen);
}

void generuotiStudentus(std::vector<Studentas>& studentai, int studentuSkaicius) {
    for (int i = 1; i <= studentuSkaicius; ++i) {
        Studentas naujasStudentas;
        naujasStudentas.setVardas("Vardas" + std::to_string(i));
        naujasStudentas.setPavarde("Pavarde" + std::to_string(i));
        for (int j = 0; j < 5; ++j) {
            naujasStudentas.addNd(generuotiNdBala());
        }
        naujasStudentas.setEgz(generuotiEgzBala());
        studentai.push_back(naujasStudentas);
    }
}


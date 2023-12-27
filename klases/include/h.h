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
#include <numeric>


class Studentas {

private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> Nd;
    int egz;
public:
    Studentas() : egz(0) {}

    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void addNd(int nd) { Nd.push_back(nd); }
    void setEgz(int e) { egz = e; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::vector<int> getNd() const { return Nd; }
    int getEgz() const { return egz; }


    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const;

    ~Studentas() {};

};

int generuotiNdBala();
int generuotiEgzBala();
void generuotiStudentus(std::vector<Studentas>& studentai, int studentuSkaicius);


#endif // STUDENTAS_H

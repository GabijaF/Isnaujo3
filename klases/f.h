#ifndef F_H
#define F_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include <string>
#include <list>
#include <numeric>

class StudentasL {

private:
    std::string vardas;
    std::string pavarde;
    std::list<int> Nd;
    int egz;
public:
    StudentasL() : egz(0) {}

    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void addNd(int nd) { Nd.push_back(nd); }
    void setEgz(int e) { egz = e; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::list<int> getNd() const { return Nd; }
    int getEgz() const { return egz; }


    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutiniBala(char baloSkaiciavimoBudas) const;

    ~StudentasL() {};

};

int generuotiNdBala();
int generuotiEgzBala();
void generuotiStudentus(std::list<StudentasL>& studentai, int studentuSkaicius);


#endif


#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;

public:
    Zmogus(const std::string& v, const std::string& p) : vardas(v), pavarde(p) {}
    virtual ~Zmogus() {}

    // Naujos funkcijos nustatyti vardà ir pavardæ
    virtual void setVardas(const std::string& v) { vardas = v; }
    virtual void setPavarde(const std::string& p) { pavarde = p; }

    virtual std::string getVardas() const { return vardas; }
    virtual std::string getPavarde() const { return pavarde; }

    virtual std::string pilnasVardas() const = 0;  // Abstrakti funkcija
};

#endif // ZMOGUS_H

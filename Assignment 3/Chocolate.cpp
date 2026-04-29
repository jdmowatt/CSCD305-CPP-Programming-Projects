#include "Chocolate.h"

Chocolate::Chocolate(const std::string choco, double c) : type{choco}, cocoa{c} {}

Chocolate::Chocolate() : Chocolate("Milk", 0.25) {}

Chocolate::Chocolate(const std::string choco) : Chocolate(choco, 0.25) {}

Chocolate::Chocolate(double c) : Chocolate("Milk", c) {}


Chocolate::Chocolate(const Chocolate &choc) : type{choc.type}, cocoa{choc.cocoa} {}

Chocolate& Chocolate::operator=(const Chocolate &choc) {
    if (this != &choc) {
        this->type = choc.type;
        this->cocoa = choc.cocoa;
    }
    return *this;
}


Chocolate& Chocolate::setType(std::string cType) {
    this->type = cType;
    return *this;
}

Chocolate& Chocolate::setCocoaPercentage(double c) {
    this->cocoa = c;
    return *this;
}


std::string Chocolate::getType() const {
    return type;
}

double Chocolate::getCocoaPercentage() const {
    return cocoa;
}


bool operator==(const Chocolate &chocoOne, const Chocolate &chocoTwo) {
    return chocoOne.type == chocoTwo.type;
}

Chocolate operator+(const Chocolate &chocoOne, const Chocolate &chocoTwo) {
    std::string s;
    if (chocoOne.type == chocoTwo.type) {
        s = chocoOne.type;
    } else {
        s = chocoOne.type + " " + chocoTwo.type;
    }
    double c = (chocoOne.cocoa + chocoTwo.cocoa)/2;
    Chocolate choc = Chocolate(s, c);
    return choc;
}

bool operator!(const Chocolate &choc) {
    return choc.type != "Dark";
}

std::istream &operator>>(std::istream& is, Chocolate& c) {
    is >> c.type >> c.cocoa;
    return is;
}

std::ostream &operator<<(std::ostream& os, const Chocolate& c) {
    os << c.type << ", " << c.cocoa << std::endl;
    return os;
}
#include "ChocolateBox.h"
#include <algorithm>

bool operator==(const ChocolateBox &cb1, const ChocolateBox &cb2) {
    if (cb1.width != cb2.width || cb1.height != cb2.height) {
        return false;
    }
    for (int i = 0; i < cb1.height; i++) {
        for (int j = 0; j < cb1.width; j++) {
            if (!(cb1.choco[i][j] == cb2.choco[i][j])) {
                return false;
            }
        }
    }
    return true;
}

bool operator!(const ChocolateBox &cb) {
    for (int i = 0; i < cb.height; i++) {
        for (int j = 0; j < cb.width; j++) {
            if (!(!cb.choco[i][j])) {
                return false;
            }
        }
    }
    return true;
}

ChocolateBox operator+(const ChocolateBox &cb1, const ChocolateBox &cb2) {
    int w = std::min(cb1.width, cb2.width);
    int h = std::min(cb1.height, cb2.height);
    ChocolateBox cb3 = ChocolateBox(w, h);

    for (int i = 0; i < cb3.height; i++) {
        for (int j = 0; j < cb3.width; j++) {
            cb3.choco[i][j] = cb1.choco[i][j] + cb2.choco[i][j];
        }
    }
    return cb3;
}

std::ostream& operator<<(std::ostream &os, const ChocolateBox &cb) {
    if (isEmpty(cb)) {
        os << "The chocolate box is empty!" << std::endl;
    } else {
        for (int i = 0; i < cb.height; i++) {
            for (int j = 0; j < cb.width; j++) {
                os << "[" << i << "][" << j << "]:" << cb.choco[i][j] << std::endl;
            }
        }
    }
    return os;
}

std::istream& operator>>(std::istream &is, ChocolateBox &cb) {
    for (int i = 0; i < cb.height; i++) {
        for (int j = 0; j < cb.width; j++) {
            std::cout << "[" << i << "][" << j << "]:";
            is >> cb.choco[i][j];
        }
    }
    return is;
}

bool isEmpty(const ChocolateBox &cb) {
    return cb.height == 0 || cb.width == 0 || cb.choco == nullptr;
}


ChocolateBox::ChocolateBox(int w, int h, Chocolate c) : width{w}, height{h} {
    choco = new Chocolate* [height];
    for (int i = 0; i < height; i++) {
        choco[i] = new Chocolate[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            choco[i][j] = c;
        }
    }
}

ChocolateBox::ChocolateBox() : ChocolateBox(2, 2, Chocolate()) {}

ChocolateBox::ChocolateBox(int w, int h) : ChocolateBox(w, h, Chocolate()){}

ChocolateBox::ChocolateBox(Chocolate c) : ChocolateBox(2, 2, c) {}


ChocolateBox::ChocolateBox(const ChocolateBox &other) {
    this->width = other.width;
    this->height = other.height;
    this->choco = new Chocolate* [height];
    for (int i = 0; i < height; i++) {
        this->choco[i] = new Chocolate[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->choco[i][j] = other.choco[i][j];
        }
    }
}

ChocolateBox::ChocolateBox(ChocolateBox &&cb) : width{cb.width}, height{cb.height}, choco{cb.choco} {
    cb.choco = nullptr;
    cb.width = 0;
    cb.height = 0;
}

ChocolateBox& ChocolateBox::operator=(const ChocolateBox &other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < height; i++) {
        delete[] choco[i];
    }
    delete[] choco;

    this->width = other.width;
    this->height = other.height;
    this->choco = new Chocolate* [height];
    for (int i = 0; i < height; i++) {
        this->choco[i] = new Chocolate[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->choco[i][j] = other.choco[i][j];
        }
    }
    return *this;
}

ChocolateBox& ChocolateBox::operator=(ChocolateBox &&cb) {
    if (this == &cb) {
        return *this;
    }

    for (int i = 0; i < height; i++) {
        delete[] choco[i];
    }
    delete[] choco;

    width = cb.width;
    height = cb.height;
    choco = cb.choco;

    cb.choco = nullptr;
    cb.width = 0;
    cb.height = 0;

    return *this;
}

ChocolateBox::~ChocolateBox() {
    for (int i = 0; i < height; i++) {
        delete[] choco[i];
    }
    delete[] choco;
    choco = nullptr;
    width = 0;
    height = 0;
}
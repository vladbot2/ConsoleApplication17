#include <iostream>
#include <string>

using namespace std;

class Reservoir {
private:
    string name;
    int width;
    int length;
    int maxDepth;
    string type;

public:
    Reservoir()
        : name("Unknown"), width(0), length(0), maxDepth(0), type("Unknown") {}

    Reservoir(const string& n, int w, int l, int d, const string& t)
        : name(n), width(w), length(l), maxDepth(d), type(t) {
        if (width < 0) width = 0;
        if (length < 0) length = 0;
        if (maxDepth < 0) maxDepth = 0;
    }

    Reservoir(const Reservoir& other)
        : name(other.name), width(other.width), length(other.length),
        maxDepth(other.maxDepth), type(other.type) {}

    ~Reservoir() {}

    const string& getName() const { return name; }
    int getWidth() const { return width; }
    int getLength() const { return length; }
    int getMaxDepth() const { return maxDepth; }
    const string& getType() const { return type; }

    int calculateVolume() const {
        return width * length * maxDepth;
    }

    int calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return type == other.type;
    }

    bool hasLargerSurfaceArea(const Reservoir& other) const {
        if (isSameType(other)) {
            return calculateSurfaceArea() > other.calculateSurfaceArea();
        }
        cerr << "Cannot compare surface area of different types." << endl;
        return false;
    }

    Reservoir copy() const {
        return *this;
    }

    void printInfo() const {
        cout << "Reservoir Information:\n";
        cout << "----------------------\n";
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Width: " << width << " m" << endl;
        cout << "Length: " << length << " m" << endl;
        cout << "Max Depth: " << maxDepth << " m" << endl;
        cout << "Volume: " << calculateVolume() << " cubic m" << endl;
        cout << "Surface Area: " << calculateSurfaceArea() << " sq m" << endl;
        cout << "----------------------\n";
    }
};

int main() {
    Reservoir lake("Lake Synevyr", 500, 700, 20, "Lake");
    Reservoir sea("Black Sea", 300000, 500000, 2210, "Sea");

    lake.printInfo();
    sea.printInfo();

    if (lake.isSameType(sea)) {
        if (lake.hasLargerSurfaceArea(sea)) {
            cout << "Lake has a larger surface area." << endl;
        }
    }


    Reservoir lakeCopy = lake.copy();
    lakeCopy.printInfo();
}

// Lab 8, Problem 3: File Compression Simulator
// Function overriding with a virtual base interface and derived implementations.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

// Read one complete line, rejecting missing values and trailing junk.
template <typename... Values>
bool readInput(Values&... values) {
    string line;
    if (!getline(cin, line)) return false;
    istringstream input(line);
    if (!(input >> ... >> values)) return false;
    input >> ws;
    return input.eof();
}

class Compressor {
public:
    virtual ~Compressor() = default;
    virtual double compress(double fileSize) = 0;
};

class TextCompressor : public Compressor {
public:
    double compress(double fileSize) override { return fileSize * 0.40; }
};

class ImageCompressor : public Compressor {
public:
    double compress(double fileSize) override { return fileSize * 0.70; }
};

int main() {
    double fileSize;
    cout << "Enter original file size in MB: ";
    if (!readInput(fileSize) || !isfinite(fileSize) || fileSize < 0) {
        cerr << "Enter a finite, non-negative file size.\n";
        return 1;
    }

    TextCompressor text;
    ImageCompressor image;
    Compressor* first = &text;
    Compressor* second = &image;
    cout << fixed << setprecision(2);
    cout << "Original size: " << fileSize << " MB\nText compressed size: " << first->compress(fileSize)
         << " MB\nImage compressed size: " << second->compress(fileSize) << " MB\n";
    return 0;
}

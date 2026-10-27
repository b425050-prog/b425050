// Lab 8, Problem 10: AI Recommendation Engine
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

class Recommender {
public:
    virtual ~Recommender() = default;
    virtual double generateRecommendation(int userRating, int popularity) = 0;
};

class PersonalizedRecommender : public Recommender {
public:
    double generateRecommendation(int userRating, int popularity) override {
        return 0.7 * userRating + 0.3 * popularity;
    }
};

class TrendingRecommender : public Recommender {
public:
    double generateRecommendation(int userRating, int popularity) override {
        return 0.3 * userRating + 0.7 * popularity;
    }
};

int main() {
    int userRating, popularity;
    cout << "Enter user rating and popularity (0 to 100): ";
    if (!readInput(userRating, popularity) || userRating < 0 || userRating > 100 || popularity < 0 || popularity > 100) {
        cerr << "Enter two integer scores from 0 to 100.\n";
        return 1;
    }

    PersonalizedRecommender personalized;
    TrendingRecommender trending;
    // Required base-class pointers preserve the derived implementation.
    Recommender* first = &personalized;
    Recommender* second = &trending;
    cout << fixed << setprecision(2);
    cout << "Personalized score: " << first->generateRecommendation(userRating, popularity)
         << "\nTrending score: " << second->generateRecommendation(userRating, popularity) << '\n';
    return 0;
}

// Lab 6, Program 6: Podcast Duration Analyzer
// Finds the longest duration with pointer traversal and no array indexing.

#include <iostream>

double findLongestDuration(const double* firstDuration, int episodeCount) {
    double longestDuration = *firstDuration;

    for (const double* currentDuration = firstDuration + 1;
         currentDuration < firstDuration + episodeCount;
         ++currentDuration) {
        if (*currentDuration > longestDuration) {
            longestDuration = *currentDuration;
        }
    }

    return longestDuration;
}

int main() {
    constexpr int episodeCount = 6;
    double episodeDurations[episodeCount]{};

    std::cout << "Enter " << episodeCount
              << " episode durations in minutes:\n";
    for (double* currentDuration = episodeDurations;
         currentDuration < episodeDurations + episodeCount;
         ++currentDuration) {
        if (!(std::cin >> *currentDuration) || *currentDuration < 0.0) {
            std::cerr << "Durations must be non-negative numbers.\n";
            return 1;
        }
    }

    std::cout << "Longest episode duration: "
              << findLongestDuration(episodeDurations, episodeCount)
              << " minutes\n";
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Song {
private:
    string songName;
    string artistName;
    double duration;

public:
    Song(string name, string artist, double songDuration) {
        songName = name;
        artistName = artist;
        duration = songDuration;
    }

    // Friend function compares private duration of two Song objects
    friend void compareSongs(const Song &song1, const Song &song2);
};

void compareSongs(const Song &song1, const Song &song2) {
    cout << "\n--- Song Comparison ---\n";
    cout << song1.songName << " by " << song1.artistName
         << " - " << song1.duration << " minutes\n";
    cout << song2.songName << " by " << song2.artistName
         << " - " << song2.duration << " minutes\n";

    if (song1.duration > song2.duration)
        cout << song1.songName << " is longer.\n";
    else if (song2.duration > song1.duration)
        cout << song2.songName << " is longer.\n";
    else
        cout << "Both songs have the same duration.\n";
}

int main() {
    string firstSongName, firstArtist;
    string secondSongName, secondArtist;
    double firstDuration, secondDuration;

    cout << "Enter first song name: ";
    getline(cin, firstSongName);
    cout << "Enter first artist name: ";
    getline(cin, firstArtist);
    cout << "Enter first song duration (in minutes): ";
    cin >> firstDuration;
    cin.ignore();

    cout << "\nEnter second song name: ";
    getline(cin, secondSongName);
    cout << "Enter second artist name: ";
    getline(cin, secondArtist);
    cout << "Enter second song duration (in minutes): ";
    cin >> secondDuration;

    Song firstSong(firstSongName, firstArtist, firstDuration);
    Song secondSong(secondSongName, secondArtist, secondDuration);

    compareSongs(firstSong, secondSong);

    return 0;
}

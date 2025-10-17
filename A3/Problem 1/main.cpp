#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Film
{
private:
    string name, director, date;

public:
    // Constrcutor
    Film() {};
    Film(string n, string d, string dat)
    {
        name = n;
        director = d;
        date = dat;
    }
    // Getter
    string getName()
    {
        return name;
    }
    //  Input Stream
    friend istream &operator>>(istream &in, Film &f)
    {
        cout << "Enter film name: ";
        getline(in, f.name);
        cout << "Enter director: ";
        getline(in, f.director);
        cout << "Enter date: ";
        getline(in, f.date);
        return in;
    }

    // Output Stream
    friend ostream &operator<<(ostream &out, Film &f)
    {
        out << f.name << " | " << f.director << " | " << f.date;
        return out;
    }
};
class Song
{
private:
    string name, singer, date;

public:
    // Constrcutor
    Song() {};
    Song(string n, string s, string dat)
    {
        name = n;
        singer = s;
        date = dat;
    }
    // Getter
    string getName()
    {
        return name;
    }
    // Input Stream
    friend istream &operator>>(istream &in, Song &s)
    {
        cout << "Enter song name: ";
        getline(in, s.name);
        cout << "Enter singer: ";
        getline(in, s.singer);
        cout << "Enter date: ";
        getline(in, s.date);
        return in;
    }

    // Output Stream
    friend ostream &operator<<(ostream &out, Song &s)
    {
        out << s.name << " | " << s.singer << " | " << s.date;
        return out;
    }
};
// Class for the records and repeated functions
class Record
{
private:
    // Storage different types of records
    vector<Film> films;
    vector<Song> songs;

public:
    // Add different types of records
    void addFilm()
    {
        Film f;
        cin >> f;
        films.push_back(f);
    }
    //Add film in main function code Overloaded Function
    void addFilm(string n, string d, string dat) { films.emplace_back(n, d, dat); }
    void addSong()
    {
        Song s;
        cin >> s;
        songs.push_back(s);
    }
    void addSong(string n, string s, string dat) { songs.emplace_back(n, s, dat); }
    // Removing different types of records
    void removeFilm()
    {
        showFilms();
        cout << "\nEnter film number to remove: ";
        int num;
        while (!(cin >> num))
        {                                                        // Try reading an int
            cin.clear();                                         // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "\033[31mInvalid input\nTry Again: \033[0m";
        }
        if (num > 0 && num <= films.size())
        {
            films.erase(films.begin() + num - 1);
            cout << "\n\033[32mFilm Removed\033[0m";
        }
        else
        {
            cout << "\033[31mInvalid index!\033[0m\n";
        }
    }
    void removeSong()
    {
        showSongs();
        cout << "\nEnter song number to remove: ";
        int num;
        while (!(cin >> num))
        {                                                        // Try reading an int
            cin.clear();                                         // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "\033[31mInvalid input\nTry Again: \033[0m";
        }
        if (num > 0 && num <= songs.size())
        {
            songs.erase(songs.begin() + num - 1);
            cout << "\n\033[32mSong Removed\033[0m";
        }
        else
        {
            cout << "\033[31mInvalid index!\033[0m\n";
        }
    }
    // Outputting to Console
    void showFilms()
    {
        for (int i = 0; i < films.size(); i++)
        {
            cout << i + 1 << ". " << films[i] << endl;
        }
    }
    void showSongs()
    {
        for (int i = 0; i < songs.size(); i++)
        {
            cout << i + 1 << ". " << songs[i] << endl;
        }
    }
    // Outputting to files
    void outToFile(const string &filmFile, const string &songFile)
    {
        ofstream filmsOut(filmFile), songsOut(songFile);
        for (auto &f : films)
        {
            filmsOut << f << endl;
        }
        filmsOut.close();

        for (auto &s : songs)
        {
            songsOut << s << endl;
        }
        songsOut.close();
        cout << "\n\033[32mSaved Records\033[0m";
    }
    // Inputting from files
    void inFromFile(const string &filmFile, const string &songFile)
    {
        ifstream filmsIn(filmFile), songsIn(songFile);

        string line;

        while (getline(filmsIn, line))
        {
            int p1 = line.find('|'), p2 = line.find('|', p1 + 1);
            if (p1 != string::npos && p2 != string::npos)
                films.emplace_back(line.substr(0, p1 - 1), line.substr(p1 + 2, p2 - p1 - 3), line.substr(p2 + 2));
        }
        while (getline(songsIn, line))
        {
            int p1 = line.find('|'), p2 = line.find('|', p1 + 1);
            if (p1 != string::npos && p2 != string::npos)
                songs.emplace_back(line.substr(0, p1 - 1), line.substr(p1 + 2, p2 - p1 - 3), line.substr(p2 + 2));
        }
    }
    // Sort By Name functions
    void sortFilms()
    {
        sort(films.begin(), films.end(), [](Film &a, Film &b)
             { return a.getName() < b.getName(); });
        cout << "\nSorted Films";
    }
    void sortSongs()
    {
        sort(songs.begin(), songs.end(), [](Song &a, Song &b)
             { return a.getName() < b.getName(); });
        cout << "\nSorted Songs";
    }
};
int main()
{
    Record records;
    // Get save data
    records.inFromFile("Films.txt", "Songs.txt");

    while (true)
    {
        cout << "\n\033[33m--- Actions Menu (Enter 0-9) ---\033[0m\n"
             << "1. Display Films 2. Display Songs\n"
             << "3. Add Film      4. Add Song\n"
             << "5. Remove Film   6. Remove Song\n"
             << "7. Sort Films    8. Sort Songs\n"
             << "9. Save Records  0. Exit\n"
             << "Option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 0:
            cout << "\n\033[31m > Exiting...\033[0m";
            return 0;
        case 1:
            records.showFilms();
            break;
        case 2:
            records.showSongs();
            break;
        case 3:
            records.addFilm();
            break;
        case 4:
            records.addSong();
            break;
        case 5:
            records.removeFilm();
            break;
        case 6:
            records.removeSong();
            break;
        case 7:
            records.sortFilms();
            break;
        case 8:
            records.sortSongs();
        case 9:
            records.outToFile("Films.txt", "Songs.txt");
            break;
        default:
            cout << "\n\033[31m > Not Valid Choice\033[0m\n";
            break;
        }
    }
    return 0;
}
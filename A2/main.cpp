//Assignment 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

//---Problem 1 Start---
// Record Structs
struct Film
{
    string name;
    string director;
    string date;

    Film(string n, string d, string dat)
    {name = n; director = d; date = dat;}
};
struct Song
{
    string name;
    string singer;
    string date;

    Song(string n, string s, string dat)
    {name = n; singer = s; date = dat;}
};
// List Functions
void showFilms(const vector<Film> &films)
{
    cout << "\n--- Films ---\n";
    for (size_t i = 0; i < films.size(); i++)
    {
        cout << i + 1 << ". " << films[i].name
             << " | Director: " << films[i].director
             << " | Date: " << films[i].date << "\n";
    }
    if (films.empty())
        cout << "(no films)\n";
}
void showSongs(const vector<Song> &songs)
{
    cout << "\n--- Songs ---\n";
    for (size_t i = 0; i < songs.size(); i++)
    {
        cout << i + 1 << ". " << songs[i].name
             << " | Singer: " << songs[i].singer
             << " | Date: " << songs[i].date << "\n";
    }
    if (songs.empty())
        cout << "(no songs)\n";
}
// Sorting Functions
void sortFilms(vector<Film> &films, int option)
{
    if (option == 1) // By Name
        sort(films.begin(), films.end(), [](const Film &a, const Film &b)
             { return a.name < b.name; });
    else if (option == 2) // By Director
        sort(films.begin(), films.end(), [](const Film &a, const Film &b)
             { return a.director < b.director; });
    else if (option == 3) // By Date
        sort(films.begin(), films.end(), [](const Film &a, const Film &b)
             { return a.date < b.date; });
}
void sortSongs(vector<Song> &songs, int option)
{
    if (option == 1) // By Name
        sort(songs.begin(), songs.end(), [](const Song &a, const Song &b)
             { return a.name < b.name; });
    else if (option == 2) // By Singer
        sort(songs.begin(), songs.end(), [](const Song &a, const Song &b)
             { return a.singer < b.singer; });
    else if (option == 3) // By Date
        sort(songs.begin(), songs.end(), [](const Song &a, const Song &b)
             { return a.date < b.date; });
}
void Problem1()
{
    vector<Film> films;
    vector<Song> songs;
    // Sample Films
    films.emplace_back("Kung Fu Panda 2", "Jennifer Yuh Nelson", "2011");
    films.emplace_back("Interstellar", "Christopher Nolan", "2014");
    films.emplace_back("The Godfather", "Francis Ford Coppola", "1972");
    films.emplace_back("Spirited Away", "Hayao Miyazaki", "2001");
    // Sample Songs
    songs.emplace_back("Shape of You", "Ed Sheeran", "2017");
    songs.emplace_back("Rolling in the Deep", "Adele", "2010");
    songs.emplace_back("Billie Jean", "Michael Jackson", "1982");

    while (true)
    {
        cout << "\n--- Actions Menu (Enter 0-6) ---\n"
             << "1. Display Films, 2. Display Songs\n"
             << "3. Add Film, 4. Add Song\n"
             << "5. Remove Film, 6. Remove Song\n"
             << "7. Sort Films, 8. Sort Songs\n"
             << "0. Exit\n"
             << "Choose: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            showFilms(films);
        }
        else if (choice == 2)
        {
            showSongs(songs);
        }
        else if (choice == 3)
        {
            cout << "\n---Add Film---\n";
            string name, director, date;
            cout << "Enter film name: ";
            getline(cin, name);
            cout << "Enter director: ";
            getline(cin, director);
            cout << "Enter release date: ";
            getline(cin, date);
            films.emplace_back(name, director, date);
        }
        else if (choice == 4)
        {
            cout << "\n---Add Song---\n";
            string name, singer, date;
            cout << "Enter song name: ";
            getline(cin, name);
            cout << "Enter singer: ";
            getline(cin, singer);
            cout << "Enter release date: ";
            getline(cin, date);
            songs.emplace_back(name, singer, date);
        }
        else if (choice == 5)
        {
            showFilms(films);
            cout << "Enter film number to remove: ";
            size_t idx;
            while (!(cin >> idx))
            {                                                        // Try reading an int
                cin.clear();                                         // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
                cout << "Invalid input. Please enter a number(1-3): ";
            }
            if (idx > 0 && idx <= films.size()){
                films.erase(films.begin() + idx - 1);
            }else{
                cout << "Invalid index!\n";
            }
        }
        else if (choice == 6)
        {
            showSongs(songs);
            cout << "Enter song number to remove: ";
            size_t idx;
            while (!(cin >> idx))
            {                                                        // Try reading an int
                cin.clear();                                         // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
                cout << "Invalid input. Please enter a number(1-3): ";
            }
            if (idx > 0 && idx <= songs.size()){
                songs.erase(songs.begin() + idx - 1);
            }else{
                cout << "Invalid index!\n";
            }
        }
        else if (choice == 7)
        {
            cout << "Sort films by: 1. Name,  2. Director,  3. Date : ";
            int opt;
            cin >> opt;
            sortFilms(films, opt);
            cout << "Films sorted!\n";
        }
        else if (choice == 8)
        {
            cout << "Sort songs by: 1. Name,  2. Singer,  3. Date : ";
            int opt;
            cin >> opt;
            sortSongs(songs, opt);
            cout << "Songs sorted!\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    cout << "Exiting program...\n";
}
//---Problem 1 End---

//---Problem 2 Start---
struct Numbers
{
    int num;
    bool isPrime;

    Numbers(int n, bool is = true)
    {
        num = n;
        isPrime = is;
    }
};
void Problem2()
{
    cout << "---Prime Number Finder (2-X)---\n";
    cout << "Until what integer do you want to find the primes? ";

    int range;
    // Input validation
    while (true)
    {
        if (cin >> range)
        { // Check if input is a number
            if (range > 1)
            {          // Check if it's greater than 1
                break; // Valid input
            }
            else
            {
                cout << "Number must be greater than 1. Try again: ";
            }
        }
        else
        {
            cout << "Invalid input. Please enter an integer more than 1: ";
            cin.clear(); // Clear error state
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    vector<Numbers> allNumbers;

    for (int i = 2; i <= range; i++)
    {
        allNumbers.emplace_back(i, true);
    }

    // Prime Sorter
    for (int i = 0; i < allNumbers.size(); i++)
    {
        if (allNumbers[i].isPrime)
        {
            int n = allNumbers[i].num;

            // Mark multiples of n as not prime
            for (int j = i + n; j < allNumbers.size(); j += n)
            {
                allNumbers[j].isPrime = false;
            }
        }
    }

    // Print
    int option;
    cout << "Enter 1 for only primes, or 2 for all numbers labeled: ";
    cin >> option;
    cout << endl;
    if (option == 1)
    {
        for (Numbers &nums : allNumbers)
        {
            if (nums.isPrime)
            {
                cout << nums.num << " "; // access the struct member
            }
        }
    }else if (option == 2)
    {
        for (Numbers &nums : allNumbers)
        {
            if (nums.isPrime)
            {
                cout << nums.num << " | Prime\n"; // access the struct member
            }else
            {
                cout << nums.num << " | Not Prime\n"; // access the struct member
            }
        }
    }else
    {
        cout << "Invalid Option";
    }
}
//---Problem 2 End---

int main()
{
    Problem1();
    // Problem2();

    return 0;
}
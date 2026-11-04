
#include "../Header Files/input.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

int ReadInt(string prompt)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        if (cin.eof())
            exit(0);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Enter a valid number.\n";
    }
}

string ReadString(string prompt)
{
    string value;

    while (true)
    {
        cout << prompt;
        getline(cin, value);

        if (cin.eof())
            exit(0);

        if (!value.empty())
            return value;

        cout << "This field cannot be empty.\n";
    }
}

SongNode* CreateSong(DoublyLinkedList& playlist)
{
    int id = ReadInt("Enter Song ID: ");

    if (playlist.Contains(id))
    {
        cout << "This Song ID already exists.\n";
        return nullptr;
    }

    string title = ReadString("Enter Song Title: ");
    string artist = ReadString("Enter Artist Name: ");

    int duration;

    do
    {
        duration = ReadInt("Enter Duration in Seconds: ");

        if (duration <= 0)
            cout << "Duration must be greater than zero.\n";

    } while (duration <= 0);

    return new SongNode(id, title, artist, duration);
}

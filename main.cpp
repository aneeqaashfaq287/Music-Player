
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "classes/LinkedList.h"
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

        cout << "Invalid input. Please enter a number.\n";
    }
}

string ReadText(string prompt)
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

        cout << "Input cannot be empty.\n";
    }
}

SongNode* CreateSong(LinkedList& playlist)
{
    int id = ReadInt("Enter Song ID: ");

    if (playlist.Contains(id))
    {
        cout << "Song ID already exists.\n";
        return nullptr;
    }

    string title = ReadText("Enter Song Title: ");

    string artist = ReadText("Enter Artist Name: ");

    int duration;

    do
    {
        duration = ReadInt("Enter Duration in Seconds: ");

        if (duration <= 0)
            cout << "Duration must be greater than zero.\n";

    } while (duration <= 0);

    return new SongNode(id, title, artist, duration);
}

void ShowMenu()
{
    cout << "\n";
    cout << "========================================\n";
    cout << "         MUSIC PLAYLIST MANAGER\n";
    cout << "========================================\n";
    cout << "1. Display Playlist\n";
    cout << "2. Add Song at Head\n";
    cout << "3. Add Song at Position\n";
    cout << "4. Remove Song from Head\n";
    cout << "5. Remove Song at Position\n";
    cout << "6. Swap Two Songs\n";
    cout << "7. Sort Songs by ID\n";
    cout << "8. Reverse Playlist\n";
    cout << "9. Check Playlist Status\n";
    cout << "10. Exit\n";
    cout << "========================================\n";
}

int main()
{
    LinkedList playlist;

    playlist.InsertAt(new SongNode(3, "Blue Sky", "Aria", 215), 0);
    playlist.InsertAt(new SongNode(1, "Night Drive", "Nova", 242), 1);
    playlist.InsertAt(new SongNode(5, "Wildfire", "Echo", 198), 2);
    playlist.InsertAt(new SongNode(2, "Slow Rain", "Aria", 187), 3);
    playlist.InsertAt(new SongNode(4, "Sunrise", "Nova", 230), 4);

    int choice;

    do
    {
        ShowMenu();

        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            playlist.Print();
            break;

        case 2:
        {
            SongNode* song = CreateSong(playlist);

            if (song != nullptr)
            {
                playlist.Insert(song);
                cout << "Song added at head successfully.\n";
            }

            break;
        }

        case 3:
        {
            SongNode* song = CreateSong(playlist);

            if (song != nullptr)
            {
                int index = ReadInt("Enter position: ");

                playlist.InsertAt(song, index);

                cout << "Song added successfully.\n";
            }

            break;
        }

        case 4:
        {
            SongNode* removed = playlist.Remove();

            if (removed != nullptr)
            {
                cout << "Removed Song: " << removed->title << endl;
                delete removed;
            }
            else
            {
                cout << "Playlist is empty.\n";
            }

            break;
        }

        case 5:
        {
            if (playlist.IsEmpty())
            {
                cout << "Playlist is empty.\n";
                break;
            }

            int index = ReadInt("Enter position to remove: ");

            SongNode* removed = playlist.RemoveAt(index);

            if (removed != nullptr)
            {
                cout << "Removed Song: " << removed->title << endl;
                delete removed;
            }

            break;
        }

        case 6:
        {
            if (playlist.Count() < 2)
            {
                cout << "At least two songs are required.\n";
                break;
            }

            int first = ReadInt("Enter first position: ");
            int second = ReadInt("Enter second position: ");

            if (first < 0 || first >= playlist.Count() ||
                second < 0 || second >= playlist.Count())
            {
                cout << "Invalid position.\n";
            }
            else
            {
                playlist.Swap(first, second);
                cout << "Songs swapped successfully.\n";
            }

            break;
        }

        case 7:
            playlist.Sort();
            cout << "Playlist sorted by Song ID.\n";
            break;

        case 8:
            playlist.Reverse();
            cout << "Playlist reversed successfully.\n";
            break;

        case 9:
            cout << "\nPLAYLIST STATUS\n";
            cout << "----------------------------\n";
            cout << "Status: "
                 << (playlist.IsEmpty() ? "Empty" : "Not Empty")
                 << endl;

            cout << "Total Songs: " << playlist.Count() << endl;
            break;

        case 10:
            cout << "Exiting Music Playlist Manager.\n";
            break;

        default:
            cout << "Invalid choice. Please select 1 to 10.\n";
        }

    } while (choice != 10);

    return 0;
}

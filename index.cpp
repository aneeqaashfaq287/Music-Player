
#include <iostream>
#include "../Header Files/actions.h"
using namespace std;

int main()
{
    DoublyLinkedList playlist;

    playlist.InsertRight(
        new SongNode(3, "Blue Sky", "Aria", 215));

    playlist.InsertRight(
        new SongNode(1, "Night Drive", "Nova", 242));

    playlist.InsertRight(
        new SongNode(5, "Wildfire", "Echo", 198));

    playlist.InsertRight(
        new SongNode(2, "Slow Rain", "Aria", 187));

    playlist.InsertRight(
        new SongNode(4, "Sunrise", "Nova", 230));

    int choice;

    do
    {
        ShowMenu();

        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            playlist.PrintCurrent();
            break;

        case 2:
            playlist.Next();
            break;

        case 3:
            playlist.Previous();
            break;

        case 4:
        {
            SongNode* song = CreateSong(playlist);

            if (song != nullptr)
            {
                playlist.InsertRight(song);
                cout << "Song added at the end.\n";
            }

            break;
        }

        case 5:
        {
            if (playlist.IsEmpty())
                cout << "Playlist is empty. Song will be added as the first song.\n";

            SongNode* song = CreateSong(playlist);

            if (song != nullptr)
                playlist.InsertAfterCurrent(song);

            break;
        }

        case 6:
        {
            SongNode* removed = playlist.RemoveCurrent();

            if (removed != nullptr)
            {
                cout << "Removed Song: "
                     << removed->title << endl;

                delete removed;
            }
            else
            {
                cout << "No song available to remove.\n";
            }

            break;
        }

        case 7:
            playlist.PrintForward();
            break;

        case 8:
            playlist.PrintBackward();
            break;

        case 9:
            cout << "Exiting Music Player System.\n";
            break;

        default:
            cout << "Invalid choice. Enter a number from 1 to 9.\n";
        }

    } while (choice != 9);

    return 0;
}

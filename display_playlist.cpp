
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::PrintCurrent()
{
    if (current == nullptr)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nNow Playing\n";
    cout << "Song ID: " << current->songID << endl;
    cout << "Title: " << current->title << endl;
    cout << "Artist: " << current->artist << endl;

    cout << "Duration: "
         << current->duration / 60 << ":"
         << (current->duration % 60 < 10 ? "0" : "")
         << current->duration % 60 << endl;
}

void DoublyLinkedList::PrintForward()
{
    if (IsEmpty())
    {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nMUSIC PLAYLIST (FORWARD)\n";
    cout << "--------------------------------------------------\n";
    cout << "ID\tTitle\t\tArtist\t\tDuration\n";
    cout << "--------------------------------------------------\n";

    SongNode* temp = head;
    int total = 0;

    while (temp != nullptr)
    {
        cout << temp->songID << "\t"
             << temp->title << "\t\t"
             << temp->artist << "\t\t"
             << temp->duration / 60 << ":"
             << (temp->duration % 60 < 10 ? "0" : "")
             << temp->duration % 60;

        if (temp == current)
            cout << " [CURRENT]";

        cout << endl;

        total += temp->duration;
        temp = temp->right;
    }

    cout << "\nTotal Songs: " << count << endl;

    cout << "Total Duration: "
         << total / 60 << ":"
         << (total % 60 < 10 ? "0" : "")
         << total % 60 << endl;
}

void DoublyLinkedList::PrintBackward()
{
    if (IsEmpty())
    {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nMUSIC PLAYLIST (BACKWARD)\n";
    cout << "--------------------------------------------------\n";

    SongNode* temp = tail;

    while (temp != nullptr)
    {
        cout << temp->songID << " - "
             << temp->title << " - "
             << temp->artist;

        if (temp == current)
            cout << " [CURRENT]";

        cout << endl;

        temp = temp->left;
    }
}

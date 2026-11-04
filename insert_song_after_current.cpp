
#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::InsertAfterCurrent(SongNode* song)
{
    if (song == nullptr)
        return;

    if (current == nullptr)
    {
        InsertRight(song);
        return;
    }

    song->left = current;
    song->right = current->right;

    if (current->right != nullptr)
        current->right->left = song;
    else
        tail = song;

    current->right = song;
    count++;

    cout << "Song inserted after current song.\n";
}



#include "../Header Files/doubly_linked_list.h"

void DoublyLinkedList::InsertRight(SongNode* song)
{
    if (song == nullptr)
        return;

    song->left = tail;
    song->right = nullptr;

    if (tail != nullptr)
        tail->right = song;
    else
        head = song;

    tail = song;

    if (current == nullptr)
        current = song;

    count++;
}

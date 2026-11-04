
#include "../Header Files/doubly_linked_list.h"

SongNode* DoublyLinkedList::RemoveCurrent()
{
    if (current == nullptr)
        return nullptr;

    SongNode* removed = current;

    SongNode* previous = current->left;
    SongNode* next = current->right;

    if (previous != nullptr)
        previous->right = next;
    else
        head = next;

    if (next != nullptr)
        next->left = previous;
    else
        tail = previous;

    current = (next != nullptr) ? next : previous;

    removed->left = nullptr;
    removed->right = nullptr;

    count--;

    return removed;
}

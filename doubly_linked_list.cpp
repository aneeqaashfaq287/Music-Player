
#include "../Header Files/doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    count = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    SongNode* temp = head;

    while (temp != nullptr)
    {
        SongNode* next = temp->right;
        delete temp;
        temp = next;
    }

    head = nullptr;
    tail = nullptr;
    current = nullptr;
    count = 0;
}

bool DoublyLinkedList::IsEmpty()
{
    return head == nullptr;
}

bool DoublyLinkedList::Contains(int id)
{
    SongNode* temp = head;

    while (temp != nullptr)
    {
        if (temp->songID == id)
            return true;

        temp = temp->right;
    }

    return false;
}

void DoublyLinkedList::Next()
{
    if (current != nullptr && current->right != nullptr)
    {
        current = current->right;
        PrintCurrent();
    }
    else
    {
        cout << "You are already at the last song.\n";
    }
}

void DoublyLinkedList::Previous()
{
    if (current != nullptr && current->left != nullptr)
    {
        current = current->left;
        PrintCurrent();
    }
    else
    {
        cout << "You are already at the first song.\n";
    }
}

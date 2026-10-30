
#include <iostream>
#include <utility>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    count = 0;
}

bool LinkedList::IsEmpty()
{
    return head == nullptr;
}

bool LinkedList::IsNotEmpty()
{
    return head != nullptr;
}

int LinkedList::Count()
{
    return count;
}

bool LinkedList::Contains(int id)
{
    SongNode* current = head;

    while (current != nullptr)
    {
        if (current->songID == id)
            return true;

        current = current->next;
    }

    return false;
}

SongNode* LinkedList::GetNodeAt(int index)
{
    SongNode* current = head;

    for (int i = 0; i < index && current != nullptr; i++)
        current = current->next;

    return current;
}

void LinkedList::CopySongData(SongNode* a, SongNode* b)
{
    swap(a->songID, b->songID);
    swap(a->title, b->title);
    swap(a->artist, b->artist);
    swap(a->duration, b->duration);
}

void LinkedList::Insert(SongNode* song)
{
    if (song == nullptr)
        return;

    song->next = head;
    head = song;
    count++;
}

void LinkedList::InsertAt(SongNode* song, int index)
{
    if (song == nullptr)
        return;

    if (index < 0)
        index = 0;

    if (index > count)
        index = count;

    if (index == 0)
    {
        Insert(song);
        return;
    }

    SongNode* previous = GetNodeAt(index - 1);

    song->next = previous->next;
    previous->next = song;

    count++;
}

SongNode* LinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;

    SongNode* song = head;

    head = head->next;

    song->next = nullptr;

    count--;

    return song;
}

SongNode* LinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index < 0)
        index = 0;

    if (index >= count)
        index = count - 1;

    if (index == 0)
        return Remove();

    SongNode* previous = GetNodeAt(index - 1);

    SongNode* song = previous->next;

    previous->next = song->next;

    song->next = nullptr;

    count--;

    return song;
}

void LinkedList::Swap(int index1, int index2)
{
    if (index1 < 0 || index1 >= count ||
        index2 < 0 || index2 >= count ||
        index1 == index2)
        return;

    CopySongData(GetNodeAt(index1), GetNodeAt(index2));
}

void LinkedList::Sort()
{
    if (count < 2)
        return;

    for (SongNode* i = head; i != nullptr; i = i->next)
    {
        for (SongNode* j = i->next; j != nullptr; j = j->next)
        {
            if (i->songID > j->songID)
                CopySongData(i, j);
        }
    }
}

void LinkedList::Reverse()
{
    SongNode* previous = nullptr;
    SongNode* current = head;
    SongNode* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;

        current->next = previous;

        previous = current;
        current = next;
    }

    head = previous;
}

void LinkedList::Print()
{
    if (IsEmpty())
    {
        cout << "\nPlaylist is empty.\n";
        return;
    }

    SongNode* current = head;

    int index = 0;
    int totalDuration = 0;

    cout << "\n";
    cout << "---------------------------------------------------------------\n";
    cout << "Pos\tID\tTitle\t\tArtist\t\tDuration\n";
    cout << "---------------------------------------------------------------\n";

    while (current != nullptr)
    {
        cout << index << "\t"
             << current->songID << "\t"
             << current->title << "\t\t"
             << current->artist << "\t\t"
             << current->duration / 60 << ":"
             << (current->duration % 60 < 10 ? "0" : "")
             << current->duration % 60 << endl;

        totalDuration += current->duration;

        current = current->next;
        index++;
    }

    cout << "---------------------------------------------------------------\n";

    cout << "Total Songs: " << count << endl;

    cout << "Total Playlist Duration: "
         << totalDuration / 60 << ":"
         << (totalDuration % 60 < 10 ? "0" : "")
         << totalDuration % 60 << endl;
}

LinkedList::LinkedList(const LinkedList& other)
{
    head = nullptr;
    count = 0;

    SongNode* current = other.head;

    while (current != nullptr)
    {
        SongNode* newSong = new SongNode(
            current->songID,
            current->title,
            current->artist,
            current->duration
        );

        InsertAt(newSong, count);

        current = current->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this == &other)
        return *this;

    while (!IsEmpty())
        delete Remove();

    SongNode* current = other.head;

    while (current != nullptr)
    {
        SongNode* newSong = new SongNode(
            current->songID,
            current->title,
            current->artist,
            current->duration
        );

        InsertAt(newSong, count);

        current = current->next;
    }

    return *this;
}

LinkedList::~LinkedList()
{
    while (!IsEmpty())
        delete Remove();
}

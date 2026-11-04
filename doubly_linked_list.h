
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>
using namespace std;

struct SongNode
{
    int songID;
    string title;
    string artist;
    int duration;

    SongNode* left;
    SongNode* right;

    SongNode(int id, string name, string singer, int time)
    {
        songID = id;
        title = name;
        artist = singer;
        duration = time;
        left = nullptr;
        right = nullptr;
    }
};

class DoublyLinkedList
{
private:
    SongNode* head;
    SongNode* tail;
    SongNode* current;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool IsEmpty();
    bool Contains(int id);

    void InsertRight(SongNode* song);
    void InsertAfterCurrent(SongNode* song);
    SongNode* RemoveCurrent();

    void Next();
    void Previous();

    void PrintCurrent();
    void PrintForward();
    void PrintBackward();
};

#endif

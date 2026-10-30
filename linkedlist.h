
#pragma once
#include "../structures/SongNode.h"

class LinkedList
{
private:
    SongNode* head;
    int count;

    SongNode* GetNodeAt(int index);
    void CopySongData(SongNode* a, SongNode* b);

public:
    LinkedList();

    bool IsEmpty();
    bool IsNotEmpty();
    bool Contains(int id);
    int Count();

    void Insert(SongNode* song);
    void InsertAt(SongNode* song, int index);

    SongNode* Remove();
    SongNode* RemoveAt(int index);

    void Swap(int index1, int index2);
    void Sort();
    void Reverse();

    void Print();

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    ~LinkedList();
};

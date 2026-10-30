
#pragma once
#include <string>
using namespace std;

struct SongNode
{
    int songID;
    string title;
    string artist;
    int duration;
    SongNode* next;

    SongNode(int id, string songTitle, string songArtist, int songDuration)
    {
        songID = id;
        title = songTitle;
        artist = songArtist;
        duration = songDuration;
        next = nullptr;
    }
};

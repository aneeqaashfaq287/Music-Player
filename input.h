
#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "doubly_linked_list.h"

int ReadInt(std::string prompt);
std::string ReadString(std::string prompt);
SongNode* CreateSong(DoublyLinkedList& playlist);

#endif

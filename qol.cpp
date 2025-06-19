#define _CRT_SECURE_NO_WARNINGS 
#include "qol.h"
#include <windows.h>
#include <string>
#include<ctime>


//Copy to clipboard function
bool setClipboardText(const std::string& text) {
    if (!OpenClipboard(nullptr)) {
        return false;
    }
    EmptyClipboard();
    HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
    if (hGlobal == nullptr) {
        CloseClipboard();
        return false;
    }
    char* data = static_cast<char*>(GlobalLock(hGlobal));
    if (data == nullptr) {
        CloseClipboard();
        GlobalFree(hGlobal);
        return false;
    }
    strcpy(data, text.c_str());
    GlobalUnlock(hGlobal);
    SetClipboardData(CF_TEXT, hGlobal);
    CloseClipboard();
    return true;
}


//Password Generation Function
std::string PasswordGen() {

    //simple password generator 
    std::string RandPassword;

    //Used characters
   std::string Decyph[73] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j","k", "l", "m", "n", "o", "p", "q", "r", "s","t", "u", "v", "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K", "L", "M", "N", "O", "P", "Q", "R","S", "T", "U", "V", "W", "X", "Y", "Z","!","@","#","$","%","^","&","*","(",")","?","1","2","3","4","5","6","7","8","9","0" };

    //Random seed(seed is time on computer)
    srand(static_cast<unsigned int>(std::time(0)));


    //Undecypherable Randomness
    for (int i = rand() % 73; i < 73; i++) {
        Decyph[rand() % 73] = Decyph[i];
    }

    //Create 20 character Password
    for (int i = 0; i < 20; i++) {
        RandPassword.append(Decyph[rand() % 73]);
    }
    return RandPassword;
}

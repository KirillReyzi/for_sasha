#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Stroka
{
    Stroka();
    struct NODE
    {
        char value;
        struct NODE* next;
        NODE(char invalue)
        {
            value = invalue;
            next = nullptr;
        };
    };
    int Size;
    struct NODE* head;

    void push_back(char elem);
    bool CheckChar(char check);
    void Clear();

    bool getData(ifstream& f1);
    void outData(ofstream& f2);
};

struct Page
{
    Page();
    struct NODE
    {
        Stroka value;
        struct NODE* next;
        NODE(Stroka invalue)
        {
            value = invalue;
            next = nullptr;
        };
    };
    int Size;
    struct NODE* head;

    void push_back(Stroka elem);
    bool CheckChar(char check);
    void Clear();

    bool getData(ifstream& f1);
    void outData(ofstream& f2);
};
#include "lists.h"

Stroka::Stroka()
{
    Size = 0;
    head = nullptr;
}

void Stroka::push_back(char elem)
{
    NODE* newElem = new NODE(elem);
    if (Size == 0)
    {
        head = newElem;
    }
    else
    {
        struct NODE* temp;
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newElem;
    }
    Size++;
}

void Stroka::Clear()
{
    NODE* tmp = head;
    NODE* tmpnext;
    for (int i = 0; i < Size; i++)
    {
        tmpnext = tmp->next;
        delete tmp;
        tmp = tmpnext;
    }
}

Page::Page()
{
    Size = 0;
    head = nullptr;
}

void Page::push_back(Stroka elem)
{
    NODE* newElem = new NODE(elem);
    if (Size == 0)
    {
        head = newElem;
    }
    else
    {
        struct NODE* temp;
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newElem;
    }
    Size++;
}

void Page::Clear()
{
    NODE* tmpStr = head;
    for (int i = 0; i < Size; i++)
    {
        tmpStr->value.Clear();
        tmpStr = tmpStr->next;
    }
}

bool Stroka::CheckChar(char check)
{
    NODE* tmp = head;
    for (int i = 0; i < Size; i++)
    {
        if (tmp->value == check)
            return true;
        tmp = tmp->next;
    }
    return false;
}

bool Page::CheckChar(char check)
{
    NODE* tmpStr = head;
    for (int i = 0; i < Size; i++)
    {
        if (tmpStr->value.CheckChar(check))
            return true;
        tmpStr = tmpStr->next;
    }
    return false;
}

bool Stroka::getData(ifstream& fin)
{
    char tmp;
    while (fin.get(tmp))
    {
        push_back(tmp);
        if (tmp == '\n')
            break;
    }
    if (Size == 0)
        return true;
    return false;
}

bool Page::getData(ifstream& fin)
{
    if (!fin.is_open())
        return true;

    bool voidstr = false;
    while (!voidstr)
    {
        Stroka tmpLine;
        voidstr = tmpLine.getData(fin);
        if (!voidstr)
            push_back(tmpLine);
        else
            break;
    }
    return false;
}

void Stroka::outData(ofstream& fout)
{
    NODE* tmp = head;
    for (int i = 0; i < Size; i++)
    {
        cout << tmp->value;
        fout << tmp->value;
        tmp = tmp->next;
    }
}

void Page::outData(ofstream& fout)
{
    NODE* tmpStr = head;
    for (int i = 0; i < Size; i++)
    {
        tmpStr->value.outData(fout);
        tmpStr = tmpStr->next;
    }
}




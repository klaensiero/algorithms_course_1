#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

typedef struct BST
{
    int k;
    BST *lt;
    BST *rt;
} BST;

BST *insert(BST *mass, int k)
{
    BST *ins_elem = new BST();
    ins_elem->k = k;
    if (mass == nullptr)
    {
        return ins_elem;
    }
    else if (k > mass->k)
    {
        mass->rt = insert(mass->rt, k);
    }
    else if (k < mass->k)
    {
        mass->lt = insert(mass->lt, k);
    }
    return mass;
}

BST *nxt(BST *&mass, int k)
{
    BST *cur = mass;
    BST *next = nullptr;
    while (cur != nullptr)
    {
        if (cur->k > k)
        {
            next = cur;
            cur = cur->lt;
        }
        else
        {
            cur = cur->rt;
        }
    }
    return next;
}

BST *prevv(BST *&mass, int k)
{
    BST *previous = nullptr;
    BST *cur = mass;
    while (cur != nullptr)
    {
        if (cur->k < k)
        {
            previous = cur;
            cur = cur->rt;
        }
        else
        {
            cur = cur->lt;
        }
    }
    return previous;
}

bool search(BST *&t, int k)
{
    if (t == nullptr)
    {
        return false;
    }
    if (k == t->k)
    {
        return true;
    }
    if (k < t->k)
    {
        return search(t->lt, k);
    }
    else
    {
        return search(t->rt, k);
    }
}

BST *rm(BST *mass, int k)
{
    if (k < mass->k)
    {
        mass->lt = rm(mass->lt, k);
    }
    else if (k > mass->k)
    {
        mass->rt = rm(mass->rt, k);
    }
    else if (mass->rt != nullptr and mass->lt != nullptr)
    {
        BST *next = nxt(mass, k);
        mass->k = next->k;
        mass->rt = rm(mass->rt, mass->k);
    }
    else if (mass->rt != nullptr)
    {
        mass = mass->rt;
    }
    else if (mass->lt != nullptr)
    {
        mass = mass->lt;
    }
    else
    {
        mass = nullptr;
    }
    return mass;
}

int main()
{
    int elem;
    BST *mass = nullptr;
    bool check;
    string cmd;
    while (cin >> cmd >> elem)
    {

        if (cmd[0] == 'i')
        {
            check = search(mass, elem);
            if (check == false)
            {
                mass = insert(mass, elem);
            }
        }

        if (cmd[0] == 'd')
        {
            check = search(mass, elem);
            if (check)
            {
                mass = rm(mass, elem);
            }
        }

        if (cmd[0] == 'e')
        {
            check = search(mass, elem);
            if (check)
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }

        if (cmd[0] == 'n')
        {
            BST *next = nxt(mass, elem);
            if (next == nullptr)
            {
                cout << "none"
                     << "\n";
            }
            else
            {
                cout << next->k << "\n";
            }
        }
        if (cmd[0] == 'p')
        {
            BST *previous = prevv(mass, elem);
            if (previous == nullptr)
            {
                cout << "none"
                     << "\n";
            }
            else
            {
                cout << previous->k << "\n";
            }
        }
    }
    return 0;
}
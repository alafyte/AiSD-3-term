#pragma once
#include "stdafx.h"

map<char, string> GetCodes(class MinNode* root, string str, map<char, string>& mp);
map<char, string> Huffman(multimap<int, char> freq);
multimap<int, char> GetFrequency(string str);
multimap<int, char> sortMap(map<char, int>& M);
string ShowSequence(string src, map<char, string> mp);

class MinNode
{
public:
    char data;

    unsigned freq;

    MinNode* left, * right;

    MinNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare 
{
    bool operator()(MinNode* l, MinNode* r)
    {
        return (l->freq > r->freq);
    }
};


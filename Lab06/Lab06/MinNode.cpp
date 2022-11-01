#include "MinNode.h"

multimap<int, char> GetFrequency(string str)
{
    if (str.length() == 0 || str.length() == 1)
        throw invalid_argument("Длина строки должна быть более 2-х символов");

    map<char, int> freq;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        freq[str[i]] = 0;
    }
    for (unsigned int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
    }

    multimap<int, char> frequency = sortMap(freq);

    cout << "Таблица встречаемости символов (символ - количество):" << endl;
    for (auto& it : frequency)
    {
        cout << "\t\t" << it.second << ": " << it.first << endl;
    }
    return frequency;
}

multimap<int, char> sortMap(map<char, int>& M)
{

    multimap<int, char> MM;

    for (auto& it : M) 
    {
        MM.insert({ it.second, it.first });
    }
    return MM;
}

map<char, string> GetCodes(class MinNode* root, string str, map<char, string>& mp)
{
    if (!root)
        return mp;

    if (root->data != '$')
    {
        mp[root->data] = str;
        cout << "\t\t" << root->data << ": " << str << "\n";
    }

    GetCodes(root->left, str + "0", mp);
    GetCodes(root->right, str + "1", mp);

    return mp;
}

map<char, string> Huffman(multimap<int, char> freq)
{
    MinNode* left, * right, * top;
    priority_queue<MinNode*, vector<MinNode*>, compare> minHeap;

    for (auto& it : freq)
        minHeap.push(new MinNode(it.second, it.first));

    while (minHeap.size() != 1) 
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    map<char, string> mp;
    cout << "Таблица соответствия символа и кодовой последовательности:" << endl;
    GetCodes(minHeap.top(), "", mp);
    return mp;
}

string ShowSequence(string src, map<char, string> mp)
{
    string result;
    for (unsigned int i = 0; i < src.length(); i++)
    {
        result.append(mp[src[i]]);
    }
    return result;
}
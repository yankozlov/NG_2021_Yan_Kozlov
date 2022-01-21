#ifndef CEASARENCRIPTOR_H
#define CEASARENCRIPTOR_H

#include <iostream>
#include <string>

using namespace std;

class CeasarEncriptor {
public:
    CeasarEncriptor();
    CeasarEncriptor(string data);
    CeasarEncriptor(string data, int key);

    string getData() { return data; }
    void setData(string data);

    int getKey() { return key; }
    void setKey(int key);

    string getResult(){ return result; }

    void encript();
    void decript();

private:
    string data;
    int key = 0;
    string result;
};

#endif // CEASARENCRIPTOR_H

#include <CeasarEncriptor.h>

using namespace std;

int main() {
    string data = "";
    cout << "Enter text: ";
    getline(cin, data);

    int key = 0;
    cout << "Enter the key: ";
    cin >> key;

    cout << "===============EMPTY CONSTRUCTOR===============" << endl;
    CeasarEncriptor encriptor0;
    cout << "Encriptor0: data - \"" << encriptor0.getData() << "\" | key - " << encriptor0.getKey() << endl;

    encriptor0.encript();
    cout << "Result of encription: " << encriptor0.getResult() << endl;
    encriptor0.decript();
    cout << "Result of decription: " << encriptor0.getResult() << endl;

    cout << "-----------------setData(data)-----------------" << endl;
    encriptor0.setData(data);
    cout << "Encriptor0: data - \"" << encriptor0.getData() << "\" | key - " << encriptor0.getKey() << endl;

    encriptor0.encript();
    cout << "Result of encription: " << encriptor0.getResult() << endl;
    encriptor0.decript();
    cout << "Result of decription: " << encriptor0.getResult() << endl;

    cout << "Encriptor0: data - \"" << encriptor0.getData() << "\" | key - " << encriptor0.getKey() << endl;
    cout << "=============CONSTRUCTOR WITH DATA=============" << endl;

    CeasarEncriptor encriptor1(data);
    cout << "Encriptor1: data - \"" << encriptor1.getData() << "\" | key - " << encriptor1.getKey() << endl;

    encriptor1.encript();
    cout << "Result of encription: " << encriptor1.getResult() << endl;
    encriptor1.decript();
    cout << "Result of decription: " << encriptor1.getResult() << endl;
    cout << "------------------setKey(key)------------------" << endl;

    encriptor1.setKey(key);
    cout << "Encriptor1: data - \"" << encriptor1.getData() << "\" | key - " << encriptor1.getKey() << endl;

    encriptor1.encript();
    cout << "Result of encription: " << encriptor1.getResult() << endl;
    encriptor1.decript();
    cout << "Result of decription: " << encriptor1.getResult() << endl;

    cout << "Encriptor1: data - \"" << encriptor1.getData() << "\" | key - " << encriptor1.getKey() << endl;
    cout << "=========CONSTRUCTOR WITH DATA AND KEY=========" << endl;

    CeasarEncriptor encriptor2(data, key);
    cout << "Encriptor2: data - \"" << encriptor2.getData() << "\" | key - " << encriptor2.getKey() << endl;

    encriptor2.encript();
    cout << "Result of encription: " << encriptor2.getResult() << endl;
    encriptor2.decript();
    cout << "Result of decription: " << encriptor2.getResult() << endl;

    cout << "Encriptor2: data - \"" << encriptor2.getData() << "\" | key - " << encriptor2.getKey() << endl;
    cout << "===============================================" << endl;
}

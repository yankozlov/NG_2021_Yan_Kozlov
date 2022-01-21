#include <CeasarEncriptor.h>

CeasarEncriptor::CeasarEncriptor(){
    data = "";
    result = "";
}

CeasarEncriptor::CeasarEncriptor(string mdata){
    CeasarEncriptor();
    setData(mdata);
    result = data;
}

CeasarEncriptor::CeasarEncriptor(string mdata, int mkey){
    CeasarEncriptor();
    setData(mdata);
    setKey(mkey);
    result = data;
}

void CeasarEncriptor::setData(string mdata) {
    data = mdata;
}

void CeasarEncriptor::setKey(int mkey) {
    key = mkey%26;
}

void CeasarEncriptor::encript() {
    result = data;
    if (key == 0 || data == "") {
        if (key == 0)
           cout << endl << "|ERROR| No key.";
        if (data == "")
           cout << endl << "|ERROR| No data.";
        cout << endl << "|WARN| Encription is aborted." << endl;
    }
    else {
        for (int i = 0; data[i] != 0; i++) {
            if (data[i] >= 'a' && data[i] <= 'z') {
                if (data[i]+key > 'z') result[i] = data[i] + key - 26;
                else if (data[i]+key < 'a') result[i] = data[i] + key + 26;
                else result[i] = data[i] + key;
            }
            else if (data[i] >= 'A' && data[i] <= 'Z') {
                if (data[i]+key > 'Z') result[i] = data[i] + key - 26;
                else if (data[i]+key < 'A') result[i] = data[i] + key + 26;
                else result[i] = data[i] + key;
            }
        }
    }
}

void CeasarEncriptor::decript() {
    result = data;
    if (key == 0 || data == "") {
        if (key == 0)
           cout << endl << "|ERROR| No key.";
        if (data == "")
           cout << endl << "|ERROR| No data.";
        cout << endl << "|WARN| Decription is aborted." << endl;
    }
    else {
        for (int i = 0; data[i] != 0; i++) {
            if (data[i] >= 'a' && data[i] <= 'z') {
                if (data[i]-key > 'z') result[i] = data[i] - key - 26;
                else if (data[i]-key < 'a') result[i] = data[i] - key + 26;
                else result[i] = data[i] - key;
            }
            else if (data[i] >= 'A' && data[i] <= 'Z') {
                if (data[i]-key > 'Z') result[i] = data[i] - key - 26;
                else if (data[i]-key < 'A') result[i] = data[i] - key + 26;
                else result[i] = data[i] - key;
            }
        }
    }
}

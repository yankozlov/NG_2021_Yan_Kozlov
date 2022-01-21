#ifndef MATHPARSER_UTILITIES_H
#define MATHPARSER_UTILITIES_H

#include <mathparser_core.h>

void show(char equation[]){
    cout << "=======show=======" << endl;
    cout << equation << endl;
}

void showCodes(char equation[]) {
    cout << "=====showCodes=====" << endl;
    for (int i = 0; i < 50; i++)
        cout << (int)equation[i] << " ";
    cout << endl;
}

int getNumLength(double num) {
    int length = 32;                            //~increase max length of the number
    char tmpStr[length];

    for (int i = 0; i < length; i++) tmpStr[i] = 0;

    sprintf(tmpStr, "%0.9f", num);

    length--;
    while (tmpStr[length] == 0 || tmpStr[length] == '0' || tmpStr[length] == '.') {
        length--;

        if (tmpStr[length+1] == '.') break;     // if number has ##.000 the point doesn't remain
    }
    length++;
    return length;
}

int findFirst(char equation[], char symbol1, char symbol2) {
    int index = -1;
    for (int i = 0; equation[i] != 0; i++) {
        if ((equation[i] == symbol1 || equation[i] == symbol2) &&
            !(equation[i] == '-' && (i == 0 || equation[i-1] == '(' || equation[i-1] == ';'))) {    // exception for first '-'
            index = i;
            break;
        }
    }
    return index;
}

int findFirst(char equation[], char symbol) {
    int index = -1;
    for (int i = 0; equation[i] != 0; i++) {
        if (equation[i] == symbol) {
            index = i;
            break;
        }
    }
    return index;
}

double extractNumber(char equation[], int index, char option) {
    double number = 0;
    if (option == 'l') {                            // take left number
        int firstIndex = -1;
        for (firstIndex = index-1; equation[firstIndex] == '.' ||
            (equation[firstIndex] >= '0' && equation[firstIndex] <= '9'); firstIndex--) {
            if (equation[firstIndex] == '.') {
                number /= pow(10, index-firstIndex-1);
                index = firstIndex;
            }
            else {
                number += ((equation[firstIndex]-'0')*pow(10, index-firstIndex-1));
            }
            equation[firstIndex] = '#';
        }
        if (equation[firstIndex] == '-' && (firstIndex == 0 || equation[firstIndex-1] == '(')) {
            number = -number;
            equation[firstIndex] = '#';
        }
    }
    else if (option == 'r') {                       // take right number
        bool negative = false;
        for (int secondIndex = index+1, mult = 10; equation[secondIndex] == '.' || equation[secondIndex] == '-' ||
                                                  (equation[secondIndex] >= '0' && equation[secondIndex] <= '9'); secondIndex++) {
            if (equation[secondIndex] == '-') {
                if (secondIndex == index+1) negative = true;
                else break;
            }
            else if (equation[secondIndex] == '.') {
                mult = -mult;
                index = secondIndex;
            }
            else if (mult < 0) {
                number += (equation[secondIndex]-'0')*pow(10, index-secondIndex);
            }
            else {
                number *= mult;
                number += equation[secondIndex]-'0';
            }
            equation[secondIndex] = '#';
        }

        if (negative == true) number = -number;
    }
    return number;
}

void convertNumToString(char strRes[], double num) {
    sprintf(strRes, "%0.9f", num);

    int tmpIndex = -1;

    for (int i = 0; strRes[i] != 0; i++) tmpIndex = i;

    for (; strRes[tmpIndex] == '0' || strRes[tmpIndex] == '.'; tmpIndex--) {
        if (strRes[tmpIndex] == '.') {
            strRes[tmpIndex] = 0;
            break;
        }
        strRes[tmpIndex] = 0;
    }
}


#endif // MATHPARSER_UTILITIES_H

#ifndef MATHPARSER_FORMAT_H
#define MATHPARSER_FORMAT_H

#include <mathparser_core.h>


void showFormattingProgress(char equation[], int currIndex) {
    //cout << "currentIndex is " << currIndex << endl;
    for (int s = 0; equation[s] != 0; s++) {
        if (s == currIndex) cout << " |" << equation[s] << "| ";
        else cout << equation[s];
    }
    cout << endl;
}


void shiftLeft(char equation[]) {
    for (int lIndex = 0; equation[lIndex] != 0; lIndex++) {
        if (equation[lIndex] == ' ') {
            for (int rIndex = lIndex; equation[rIndex] != 0; rIndex++) equation[rIndex] = equation[rIndex+1];

            shiftLeft(equation);
        }
    }
}

void shiftRight(char equation[], int index, int shift) {
    int finalIndex = 0;

    for (; equation[finalIndex] != 0; finalIndex++);

    finalIndex += shift;

    while (finalIndex > index+shift) {
        finalIndex--;
        equation[finalIndex] = equation[finalIndex-shift];
    }
    while (finalIndex > index) {
        finalIndex--;
        equation[finalIndex] = '#';
    }
}

bool formatBrackets(char equation[], int* index, string option = "") {
    if ((equation[*index] == ')' && (equation[*index+1] == '(' ||                                  // ( )( ) -> ( )*( )
                                    (equation[*index+1] >= '0' && equation[*index+1] <= '9'))) ||  // ( )5 -> ( )*5
        (equation[*index] >= '0' && equation[*index] <= '9' && equation[*index+1] == '(')) {       // 5( ) -> 5*( )

        shiftRight(equation, *index+1, 1);
        equation[*index+1] = '*';
    }
    else if (equation[*index] == '(' && (*index == 0 || equation[*index-1] != 't')) {           // (###) -> ###
        int rightBr = *index+1;

        if (equation[rightBr] == '-') rightBr++;      // skips first '-'

        for (; (equation[rightBr] >= '0' && equation[rightBr] <= '9') || equation[rightBr] == '.'; rightBr++) {
            if (equation[rightBr+1] == ')') {
                if (equation[*index+1] == '-') {

                    if (*index > 0 && equation[*index-1] == '-' && (*index == 1 || equation[*index-2] == '(')) { // (-(-##)...) -> (##...)
                        equation[*index] = ' ';
                        equation[*index+1] = ' ';
                        equation[rightBr+1] = ' ';
                        equation[*index-1] = ' ';
                        *index-=3;
                    }
                    else if (*index == 0 || equation[*index-1] == '(') {                        // ((-##)...) -> (-##...)
                        equation[*index] = ' ';
                        equation[rightBr+1] = ' ';
                        *index-=2;
                    }

                }
                else {                                                                          // (##) -> ##
                    equation[*index] = ' ';
                    equation[rightBr+1] = ' ';
                    *index-=2;
                }

                shiftLeft(equation);

                if (option == "analize") return true;

                break;
            }
        }
    }
    else return false;

    if (*index < 0) *index = 0;

    return true;
}

bool formatNumbers(char equation[], int* index) {
    if (equation[*index] == '.') {                              // format floats
        shiftLeft(equation);
        if (equation[*index-1] >= '0' && equation[*index-1] <= '9') {                 // 2.000000 -> 2; 2. -> 2
            int rEdge = 0;

            for (; equation[*index+rEdge+1] >= '0' && equation[*index+rEdge+1] <= '9'; rEdge++);

            while (equation[*index+rEdge] == '0' || equation[*index+rEdge] == '.') {
                if (equation[*index+rEdge] == '.') {
                    equation[*index+rEdge] = ' ';
                    *index -= 2;
                    shiftLeft(equation);
                    break;
                }
                equation[*index+rEdge] = ' ';
                rEdge--;
            }
            shiftLeft(equation);
        }
        else if (*index == 0 || (equation[*index-1] < '0' || equation[*index-1] > '9')) {  // .12 -> 0.12
            shiftRight(equation, *index, 1);
            equation[*index] = '0';
            *index-=2;                                   // need to check the symbol before .12
        }
    }
    else if (equation[*index] == '0' &&                              // format numbers like 056 (56)
            (*index == 0 || ((equation[*index-1] < '0' || equation[*index-1] > '9') && equation[*index-1] != '.')) &&
            equation[*index+1] >= '0' && equation[*index+1] <= '9') {

        equation[*index] = ' ';
        shiftLeft(equation);
        *index--;
    }
    else return false;

    if (*index < 0) *index = 0;

    return true;
}

bool formatSymbols(char equation[], int* index) {
    if (equation[*index] >= 'A' && equation[*index] <= 'Z')  {       // uppercase to lowercase
        equation[*index] += 32;
    }
    else if (equation[*index] == ',') {                              // change ',' to '.'
        equation[*index] = '.';
        *index--;
    }
    else if (equation[*index] == '+' &&                              // remove '+' if it represents a positive number
            (*index == 0 || equation[*index-1] == '(') &&
            (equation[*index+1] != '-' && equation[*index+1] != '+' && equation[*index+1] != '*' && equation[*index+1] != '/')) {

        equation[*index] = ' ';
        *index-=2;
    }
    else if (equation[*index] >= '0' && equation[*index] <= '9' &&
             (equation[*index+1] == 's' || equation[*index+1] == 'p')) { // 5sqrt( ) -> 5*sqrt( )  5pow( ; ) -> 5*pow( ; )

        shiftRight(equation, *index+1, 1);
        equation[*index+1] = '*';
    }
    else return false;

    if (*index < 0) *index = 0;

    return true;
}

void formatEquation(char equation[]) {
    if (interfaceMode == true) cout << "===formatting...===" << endl;

    shiftLeft(equation);                                            // replace spaces

    for (int index = 0; equation[index] != 0; index++) {
        if (interfaceMode == true) showFormattingProgress(equation, index);

        if (formatSymbols(equation, &index)) continue;

        if (formatBrackets(equation, &index)) continue;

        if (formatNumbers(equation, &index)) continue;
    }

    shiftLeft(equation);                                            // replace spaces

    if (interfaceMode == true) cout << "=====formatted=====" << endl << equation << endl;
}

#endif // MATHPARSER_FORMAT_H

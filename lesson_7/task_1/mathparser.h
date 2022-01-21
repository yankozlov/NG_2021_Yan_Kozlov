#ifndef MATHPARSER_H
#define MATHPARSER_H

#include <mathparser_core.h>
#include <mathparser_analize.h>
#include <mathparser_format.h>
#include <mathparser_utilities.h>

/*          ALGORITHM

    input an equation
    copy inputted string
    format the copied string
        convert uppercase to lowercase
        change , to .
        (###) -> ###
        (-(-###)...) -> (###...)
        ( )( ) == ( )*( )
        5( ) == 5*( )
        5sqrt( ) == 5*sqrt( )   //sqrt(), pow()
        ( )5 == ( )*5
        convert numbers (2.0000 -> 2; 2. -> 2; 0056.012 -> 56.012; .15 -> 0.15)
        remove '+' if it represents a positive number
        replace spaces
    analize if it is correct
        acceptable words: 'sqrt(', 'pow('
        the only semicolon per pow()                 //pow(pow(#;#);pow(#;#))
            number of ';' equals to number of 'pow('
        before and after ';' there must be a number or a subequation
        number of '(' equals to number of ')'
        while counting number of '(' >= ')'         //( ( ) ) ) ( -> x

        has digits
        acceptable 'two operators' case: operator -> sqrt()/pow()
        acceptable first operators: '-', 'sqrt(', 'pow('
        only one point per number

    remember the operations
    find the first operator of higher priority
        () -> pow(), sqrt() -> '*', '/' -> '+', '-'
    remove brackets if there are no operators inside (except for pow(;) and sqrt())
    if the operator is '+', '-', '/' or '*'
        extract left and right numbers
            convert substrings to numbers
        remember firstIndex of left number and lastIndex of rigth number
    if operator is 'sqrt('
        extract the number in brackets
            convert substring to number
        remember firstIndex of the number
    if the operator is pow(;)
        find ';' and extract left and right numbers
            convert substrings to numbers
        remember firstIndex of left number and lastIndex of rigth number
    compute
        add/substract/multiply/divide/sqrt/pow
    insert result instead of subequation
        convert number to string
        replace the operator
        if number's length > subequation's length (secondIndex-firstIndex)
            shift rigth the right part of equation
        else if number's length < subequation's length (secondIndex-firstIndex)
            shift left the right part of equation
        insert the string of result in equation starting with firstIndex
    repeat until there are no operators except for first -
*/

void changeEquation(char equation[], int firstIndex, char result[]) {
    int eqLen = 0;
    for (int i = 0; equation[i] != 0; i++)
        if (equation[i] == '#') eqLen++;

    int resLen = 0;

    for (int i = 0; result[i] != 0; i++) resLen++;

    if (firstIndex < 0) firstIndex = 0;
/*
    show(equation);
    cout << "result: " << result << endl;
    cout << "firstIndex: " << firstIndex << endl;
*/
    if (eqLen >= resLen) {
        for(int i = 0; equation[i] != 0; i++) {
            if (result[i] != 0) {
                equation[firstIndex+i] = result[i];
            }
            else {
                for (int j = firstIndex + i; equation[j] == '#'; j++) equation[j] = ' ';

                break;
            }
        }
        shiftLeft(equation);
    }
    else {
        shiftRight(equation, firstIndex, resLen-eqLen);

        for (int i = 0; result[i] != 0; i++) equation[firstIndex+i] = result[i];
    }

    if (interfaceMode == true) {
        cout << "==changed equation==" << endl;
        cout << equation << endl;
    }
}

bool calculate(char equation[], eqsymbols* eq, string option, int leftBr = 0, int *rightBr = 0) {
    double tmp1 = 0, tmp2 = 0, tmpRes = 0;

    if (option == "b_*/" || option == "b_+-") {
        for (int opIndex = leftBr+1; opIndex < *rightBr; opIndex++) {

            if ((option == "b_*/" && (equation[opIndex] == '*' || equation[opIndex] == '/')) ||
                (option == "b_+-" && (equation[opIndex] == '+' ||
                                     (equation[opIndex] == '-' && opIndex != 0 && equation[opIndex-1] != '(')))) {


                tmp1 = extractNumber(equation, opIndex, 'l');
                tmp2 = extractNumber(equation, opIndex, 'r');

                if (option == "b_*/") {
                    if (equation[opIndex] == '*') {
                        tmpRes = multiply(tmp1, tmp2);
                        eq->multipl--;
                    }
                    else if (equation[opIndex] == '/') {
                        if (tmp2 == 0) return false;             // can't divide by 0

                        tmpRes = divide(tmp1, tmp2);
                        eq->divide--;
                    }
                }
                else if (option == "b_+-") {
                    if (equation[opIndex] == '+') {
                        tmpRes = add(tmp1, tmp2);
                        eq->pluses--;
                    }
                    else if (equation[opIndex] == '-'){
                        tmpRes = substract(tmp1, tmp2);
                        eq->minuses--;
                    }
                }

                equation[opIndex] = '#';                             // remove operator

                char charRes[getNumLength(tmpRes)] = {0};
                convertNumToString(charRes, tmpRes);

                changeEquation(equation, opIndex-getNumLength(tmp1), charRes);

                *rightBr = findFirst(equation, ')');
            }
            else {
                *rightBr = findFirst(equation, ')');
            }
        }
    }
    else if (option == "sqrt") {
        tmp1 = extractNumber(equation, leftBr, 'r');

        for (int i = 0; i < 5; i++) equation[leftBr-i] = '#';       // remove 'sqrt('

        equation[*rightBr] = '#';                                   // remove ')'

        if (tmp1 < 0) return false;                                 // sqrt of negative number

        tmpRes = root(tmp1);
        eq->roots--;
        eq->brack1--;
        eq->brack2--;

        char charRes[getNumLength(tmpRes)] = {0};
        convertNumToString(charRes, tmpRes);

        changeEquation(equation, leftBr-4, charRes);
    }
    else if (option == "pow") {
        int opIndex = leftBr;
        for (int i = 1; equation[leftBr+i] != ';'; i++) {
            if (equation[leftBr+i+1] == ';') {
                opIndex = leftBr+i+1;
                break;
            }
        }
        tmp1 = extractNumber(equation, opIndex, 'l');
        tmp2 = extractNumber(equation, opIndex, 'r');

        for (int m = 0; m < 4; m++) equation[leftBr-m] = '#';       // remove 'pow('

        equation[*rightBr] = '#';                                   // remove ')'
        equation[opIndex] = '#';                                    // remove ';'

        if (tmp2 >= -1 && tmp2 <= 1 && int(1/tmp2) % 2 == 0 && tmp1 < 0) return false;  // same as sqrt of negative number

        tmpRes = power(tmp1, tmp2);
        eq->pows--;
        eq->brack1--;
        eq->brack2--;

        char charRes[getNumLength(tmpRes)] = {0};
        convertNumToString(charRes, tmpRes);

        changeEquation(equation, leftBr-3, charRes);
    }
    else if (option == "*/" || option == "+-") {
        int opIndex = -1;
        if (option == "*/") opIndex = findFirst(equation, '*', '/');
        else opIndex = findFirst(equation, '+', '-');

        tmp1 = extractNumber(equation, opIndex, 'l');
        tmp2 = extractNumber(equation, opIndex, 'r');

        if (equation[opIndex] == '*') {
            tmpRes = multiply(tmp1, tmp2);
            eq->multipl--;
        }
        else if (equation[opIndex] == '/') {
            if (tmp2 == 0) return false;                    // can't divide by 0

            tmpRes = divide(tmp1, tmp2);
            eq->divide--;
        }
        else if (equation[opIndex] == '+') {
            tmpRes = add(tmp1, tmp2);
            eq->pluses--;
        }
        else if (equation[opIndex] == '-') {
            tmpRes = substract(tmp1, tmp2);
            eq->minuses--;
        }
        equation[opIndex] = '#';                            // remove operator

        char charRes[getNumLength(tmpRes)] = {0};
        convertNumToString(charRes, tmpRes);

        changeEquation(equation, opIndex-getNumLength(tmp1), charRes);
    }

    return true;
}

char* compute(char equation[], eqsymbols eq) {
    while (true) {
        //stats(eq);

        // calculate everithing inside brackets
        while (eq.brack1 > 0) {
            int leftBr = -1;
            int rightBr = findFirst(equation, ')');
            for (leftBr = rightBr-1; equation[leftBr] != '('; leftBr--);

            if (eq.multipl > 0 || eq.divide > 0) {
                if (calculate(equation, &eq, "b_*/", leftBr, &rightBr) == false) return "Undefined";
            }
            if (eq.pluses > 0 || eq.minuses > 0) {
                calculate(equation, &eq, "b_+-", leftBr, &rightBr);
            }
            if (equation[leftBr-1] == 't') {                     // sqrt()
                if (calculate(equation, &eq, "sqrt", leftBr, &rightBr) == false) return "Undefined";
            }
            else if (equation[leftBr-1] == 'w') {                // pow(;)
                if (calculate(equation, &eq, "pow", leftBr, &rightBr) == false) return "Undefined";
            }
            if (equation[leftBr] == '(' && formatBrackets(equation, &leftBr, "analize")) {
                eq.brack1--;
                eq.brack2--;
            }
        }
        // calculate everything outside brackets
        if (eq.multipl > 0 || eq.divide > 0) {
            if (calculate (equation, &eq, "*/") == false) return "Undefined";
        }
        else if (eq.pluses > 0 || eq.minuses > 0) {
            calculate(equation, &eq, "+-");
        }
        else return equation;
        //show(equation);
    }
}

char* equationResult(string userInput) {
    eqsymbols eq;
    // copying user input
    static char equation[maxEqLength];                              //~reserve additional space for changed equation

    for(int i = 0; i < maxEqLength; i++) equation[i] = 0;

    for (int i = 0; userInput[i] != 0; i++) equation[i] = userInput[i];

    formatEquation(equation);
    eq = analize(equation);
    //stats(eq);

    if (eq.status == 1) return "Syntax error.";
    else return compute(equation, eq);
}

double qtInterface(char equation[])
{
    char* resultArr = equationResult(equation);

    return extractNumber(resultArr, 0, 'r');
}

#endif // MATHPARSER_H

#ifndef MATHPARSER_ANALIZE_H
#define MATHPARSER_ANALIZE_H

#include <mathparser_core.h>

void stats(eqsymbols eq) {
    cout << "=====================================stats=====================================" << endl
         << "digits\tpluses\tminuses\tmultipl\tdivide\tbrack1\tbrack2\tpows\troots\tsemicolon" << endl
         << eq.digits << "\t" << eq.pluses << "\t" << eq.minuses <<
            "\t" << eq.multipl << "\t" << eq.divide << "\t" << eq.brack1 <<
            "\t" << eq.brack2  << "\t" << eq.pows << "\t" << eq.roots << "\t" << eq.semicolons << endl;
}

eqsymbols analize(char equation[]) {
    eqsymbols eq;
    for (int index = 0; equation[index] != 0; index++) {

        if (equation[index] >= '0' && equation[index] <= '9') eq.digits++;
        else switch (equation[index]) {
            case '+': eq.pluses++;
                      break;
            case '-': if (index != 0 && equation[index-1] != '(' && equation[index-1] != ';')           // skips first '-'
                          eq.minuses++;
                      break;
            case '*': eq.multipl++;
                      break;
            case '/': eq.divide++;
                      break;
            case '(': eq.brack1++;
                      break;
            case ')': eq.brack2++;
                      break;
            case '.': for (int j = index+1; equation[j] >= '0' && equation[j] <= '9'; j++) {
                          if (equation[j+1] == '.') {               // ###.##.#
                              if (interfaceMode == true) cout << "Error at index " << index << "\t| ###.##.#" << endl;

                              eq.status = 1;
                              break;
                          }
                      }
                      break;
            case 's': if (equation[index+1] == 'q' && equation[index+2] == 'r' && equation[index+3] == 't' &&
                          equation[index+4] == '(') {
                          eq.roots++;
                          index+=3;
                      }
                      else {
                          if (interfaceMode == true) cout << "Error at index " << index << "\t| Incorrect form of sqrt( )" << endl;

                          eq.status = 1;
                      }
                      break;
            case 'p': if (equation[index+1] == 'o' && equation[index+2] == 'w' && equation[index+3] == '(') {
                          eq.pows++;
                          eq.status = 1;
                          for (int j = index+4, currBracket = 1; currBracket != 0 &&
                               equation[j] != 0; j++) {             // checking pow(;) for having an only semicolon

                              if (equation[j] == '(') currBracket++;
                              else if (equation[j] == ')') currBracket--;
                              else if (equation[j] == ';' && currBracket == 1) {

                                  if (eq.status == 1) eq.status = 0;
                                  else {
                                      if (interfaceMode == true) cout << "Error at index " << index << "\t| Too much semicolons for pow(;)" << endl;

                                      eq.status = 1;
                                      break;
                                  }
                              }
                          }
                          index+=2;
                      }
                      else {
                         if (interfaceMode == true) cout << "Error at index " << index << "\t| Incorrect form of pow(;)" << endl;

                         eq.status = 1;
                      }
                      break;
            case ';': eq.semicolons++;
                      if (eq.semicolons > eq.pows) {
                          if (interfaceMode == true) cout << "Error at index " << index << "\t| Too much semicolons" << endl;

                          eq.status = 1;
                      }
                      else if (equation[index-1] == '(' || equation[index+1] == ')') {
                          if (interfaceMode == true) cout << "Error at index " << index << "\t| Missing argument in pow(;)" << endl;

                          eq.status = 1;
                      }
                      break;
            default:  eq.others++;
                      break;
        }

        if (eq.status == 1) break;

        if (eq.others > 0) {
            if (interfaceMode == true) cout << "Error at index " << index << "\t| Unspecified symbol" << endl;

            eq.status = 1;
            break;
        }
        if (eq.brack2 > eq.brack1) {
            if (interfaceMode == true) cout << "Error at index " << index << "\t| ( ( ) ) _)_ (" << endl;

            eq.status = 1;
            break;
        }
        if (equation[index] == '(' && (equation[index+1] < '0' || equation[index+1] > '9') &&
            equation[index+1] != '(' && equation[index+1] != 's' && equation[index+1] != 'p' && equation[index+1] != '-') {

            if (interfaceMode == true) cout << "Error at index " << index << "\t| Incorrect usage of brackets" << endl;

            eq.status = 1;
            break;
        }
        if ((equation[index] == '-' || equation[index] == '+' || equation[index] == '*' || equation[index] == '/') &&
            (equation[index+1] == '-' || equation[index+1] == '+' || equation[index+1] == '*' || equation[index+1] == '/')) {

            if (interfaceMode == true) cout << "Error at index " << index << "\t| Two operators" << endl;

            eq.status = 1;
            break;
        }
        if ((equation[index] == '-' || equation[index] == '+' || equation[index] == '*' || equation[index] == '/') &&
            (equation[index+1] == 0 || equation[index+1] == ')' || equation[index+1] == ';')) {

            if (interfaceMode == true) cout << "Error at index " << index << "\t| Operator in the end" << endl;

            eq.status = 1;
            break;
        }
    }

    if (eq.status == 1) return eq;

    if (eq.semicolons != eq.pows) {
        if (interfaceMode == true) cout << "\t\t\t| Too much semicolons" << endl;

        eq.status = 1;
    }
    else if (eq.brack1 != eq.brack2) {
        if (interfaceMode == true) cout << "\t\t\t| Unequal number of brackets" << endl;

        eq.status = 1;
    }
    else if (eq.digits == 0) {
        if (interfaceMode == true) cout << "\t\t\t| No digits" << endl;

        eq.status = 1;
    }
    return eq;
}


#endif // MATHPARSER_ANALIZE_H

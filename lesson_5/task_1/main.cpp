#include <iostream>

using namespace std;

int inputSize() {
    int sizeOfSquare = 0;
    cout << "enter the size of square: ";
    cin >> sizeOfSquare;
    return sizeOfSquare;
}

void drawLine(int sqSize, int lineNum, int colNum = 0) {
    if (colNum < sqSize)
        if (lineNum != 0 && lineNum != sqSize-1 && colNum != 0 && colNum != sqSize-1)
            cout << " ";
        else
            cout << "*";
    drawLine(sqSize, lineNum, colNum+1);
}

void drawSquare(int sqSize, int lineNum = 0) {
    if (lineNum < sqSize) {
        drawLine(sqSize, lineNum);
        cout << endl;
        drawSquare(sqSize, lineNum+1);
    }
}

int main()
{
    drawSquare(inputSize());
}

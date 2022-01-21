#include <utilities.h>

void drawRuler()
{
    cout << "       │       │       │       │       │       │       │       │       │       │" << endl;
    cout << "       ^       ^       ^       ^       ^       ^       ^       ^       ^       ^" << endl;
    cout << "       8      16      24      32      40      48      56      64      72      80" << endl;
}

void drawHorizontalLine()
{
    cout << "————————————————————————————————————————————————————————————————————————————————" << endl;
}

void writeTitle(string text, bool isInner)
{
    cout << (isInner ? "│" : " ");
    for (int i = 0; i < (78-int(text.length()))/2; i++) cout << " ";
    cout << text;
    for (int i = (78-int(text.length()))/2+int(text.length()); isInner && i < 78; i++) cout << " ";
    cout << (isInner ? "│" : " ") << endl;
}

void recordEvent(string text)
{
    cout << "[EVENT] " << text << endl;
}

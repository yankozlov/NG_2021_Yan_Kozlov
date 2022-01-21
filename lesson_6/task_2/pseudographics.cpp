#include <pseudographics.h>

//console should be at least 80 symbols wide
//works correctly, if all numbers are int
//works correctly, if number of free slots < 100
//works correctly, if fleet speed < 100
//works correctly, if health < 1.000.000

void drawHorizontalLine(string option) {
    if (option == "top") {
        cout << "┌───────────────┬───────────────┬───────────────┬───────────────┬──────────────┐" << endl;
    }
    else if (option == "middle-top") {
        cout << "├───────────────┬───────────────┬───────────────┬───────────────┬──────────────┤" << endl;
    }
    else if (option == "middle") {
        cout << "├───────────────┼───────────────┼───────────────┼───────────────┼──────────────┤" << endl;
    }
    else if (option == "middle-bottom") {
        cout << "├───────────────┴───────────────┴───────────────┴───────────────┴──────────────┤" << endl;
    }
    else if (option == "bottom") {
        cout << "└───────────────┴───────────────┴───────────────┴───────────────┴──────────────┘" << endl;
    }
}

void drawContainLine(string text, int j, int size, int health[] = {0}, int c_health[] = {0}, int c_size[] = {0}, int currShip = 0) {
    cout << "├";
    for (int i = 0; i < 5; i++) {
        if (size > j-5+i && health[i] > 0) {
            if (text == "FIGHTERS") cout << "───FIGHTERS───";
            else if (text == "FLEET") cout << "─────FLEET────";
            else if (text == "INTERNAL SHIPS") {
                if (c_size[i] > currShip && c_health[i] > 0) cout << "──────────────";
                else cout << "              ";
            }
        }
        else cout << "              ";

        if (i < 4) {
            if (size > j-5+i && health[i] > 0 &&
                    (text != "INTERNAL SHIPS" || (c_size[i] > currShip && c_health[i] > 0))) {

                cout << "─";
                if (size > j-5+i+1 && health[i+1] > 0 && (text != "INTERNAL SHIPS" ||
                    (c_size[i+1] > currShip && c_health[i+1] > 0))) cout << "┼";
                else cout << "┤";
            }
            else cout << " │";
        }
        else cout << "│" << endl;
    }

}

void drawContainLine(string text, int j, int size, vector<Flagship> flagships, int currCruiser) {
    int f_health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(flagships.size()))
            f_health[i] = flagships[j-5+i].getHealth();
        else
            f_health[i] = 0;

    int c_health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(flagships.size()) && currCruiser < int(flagships[j-5+i].cruisers.size()))
            c_health[i] = flagships[j-5+i].cruisers[currCruiser].getHealth();
        else
            c_health[i] = 0;

    int c_size[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(flagships.size()))
            c_size[i] = int(flagships[j-5+i].cruisers.size());
        else
            c_size[i] = 0;

    drawContainLine(text, j, size, f_health, c_health, c_size, currCruiser);
}

void drawContainLine(string text, int j, int size, vector<Cruiser> cruisers, int currFighter) {
    int f_health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(cruisers.size()))
            f_health[i] = cruisers[j-5+i].getHealth();
        else
            f_health[i] = 0;

    int c_health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(cruisers.size()) && currFighter < int(cruisers[j-5+i].fighters.size()))
            c_health[i] = cruisers[j-5+i].fighters[currFighter].getHealth();
        else
            c_health[i] = 0;

    int c_size[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(cruisers.size()))
            c_size[i] = int(cruisers[j-5+i].fighters.size());
        else
            c_size[i] = 0;

    drawContainLine(text, j, size, f_health, c_health, c_size, currFighter);
}

void drawContainLine(string text, int j, int size, vector<Flagship> flagships) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(flagships.size()))
            health[i] = flagships[j-5+i].getHealth();
        else
            health[i] = 0;
    drawContainLine(text, j, size, health);
}

void drawContainLine(string text, int j, int size, vector<Cruiser> cruisers) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(cruisers.size()))
            health[i] = cruisers[j-5+i].getHealth();
        else
            health[i] = 0;
    drawContainLine(text, j, size, health);
}

bool isShipInLine(int j, int size, int health[]) {
    for (int i = 0; i < 5; i++) {
        if (size > j-5+i && health[i] > 0) {
            return true;
        }
    }
    return false;
}

bool isShipInLine(vector<Cruiser> cruisers, int j) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(cruisers.size()))
            health[i] = cruisers[j-5+i].getHealth();
        else
            health[i] = 0;

    return isShipInLine(j, int(cruisers.size()), health);
}

bool isShipInLine(vector<Flagship> flagships, int j) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(flagships.size()))
            health[i] = flagships[j-5+i].getHealth();
        else
            health[i] = 0;

    return isShipInLine(j, int(flagships.size()), health);
}

void writeStatsLine(int j, int size, int health[], string title[]) {
    for (int i = j-5; i < j; i++) {
        if (i < size && health[i+5-j] > 0)
            cout << "│" << title[i%5] << "\t";
        else
            cout << "│\t\t";
    }
    cout << "│" << endl;
}

void writeStatsLine(string text, int j, int size, int health[], int stats[]) {
    for (int i = j-5; i < j; i++) {
        if (i < size && health[i%5] > 0)
            cout << "│" << text << ": " << stats[i%5] << (text.length() == 11 ? ((stats[i%5] < 10) ? " " : "") : "\t");
        else
            cout << "│\t\t";
    }
    cout << "│" << endl;
}

void writeStatsLine(string text, vector<Fighter> fighters, int j = 5, int currFighter = -1) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(fighters.size()))
            health[i] = fighters[j-5+i].getHealth();
        else
            health[i] = 0;

    if (text == "NAME" || text == "") {
        string title[5];
        if (text == "NAME")
            for (int i = 0; i < 5; i++) title[i] = "FURY[" + to_string(currFighter != -1 ? currFighter : j-5+i) + "]";
        else if (text == "")
            for (int i = 0; i < 5; i++) title[i] = "\t";
        writeStatsLine(j, int(fighters.size()), health, title);
    }
    else {
        int stats[5];
        for (int i = 0; i < 5; i++) {
            if (j-5+i < int(fighters.size()) && fighters[j-5+i].getHealth() > 0) {
                if (text == "HEALTH") stats[i] = fighters[j-5+i].getHealth();
                else if (text == "POWER") stats[i] = fighters[j-5+i].getPower();
                else if (text == "SPEED") stats[i] = fighters[j-5+i].getSpeed();
                else stats[i] = 0;
            }
            else
                stats[i] = 0;
        }

        writeStatsLine(text, j, int(fighters.size()), health, stats);
    }
}

void writeStatsLine(string text, vector<Cruiser> cruisers, int j = 5, int currCruiser = -1) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(cruisers.size()))
            health[i] = cruisers[j-5+i].getHealth();
        else
            health[i] = 0;

    if (text == "NAME" || text == "") {
        string title[5];
        if (text == "NAME")
            for (int i = 0; i < 5; i++) title[i] = "VULTURE[" + to_string(currCruiser != -1 ? currCruiser : j-5+i) + "]";
        else if (text == "")
            for (int i = 0; i < 5; i++) title[i] = "\t";
        writeStatsLine(j, int(cruisers.size()), health, title);
    }
    else {
        int stats[5];
        for (int i = 0; i < 5; i++) {
            if (j-5+i < int(cruisers.size()) && cruisers[j-5+i].getHealth() > 0) {
                if (text == "HEALTH") stats[i] = cruisers[j-5+i].getHealth();
                else if (text == "ARMOR") stats[i] = cruisers[j-5+i].getArmor();
                else if (text == "SPEED") stats[i] = cruisers[j-5+i].getSpeed();
                else if (text == "T_POWER") stats[i] = cruisers[j-5+i].getTotalPower();
                else if (text == "FREE SLOTS") stats[i] = cruisers[j-5+i].getSlots();
                else stats[i] = 0;
            }
            else
                stats[i] = 0;
        }
        writeStatsLine(text, j, int(cruisers.size()), health, stats);
    }
}

void writeStatsLine(string text, int j, vector<Flagship> flagships) {
    int health[5];
    for (int i = 0; i < 5; i++)
        if (j-5+i < int(flagships.size()))
            health[i] = flagships[j-5+i].getHealth();
        else
            health[i] = 0;

    if (text == "NAME" || text == "") {
        string title[5];
        if (text == "NAME")
            for (int i = 0; i < 5; i++) title[i] = "MASTODON[" + to_string(i) + "]";
        else if (text == "")
            for (int i = 0; i < 5; i++) title[i] = "\t";
        writeStatsLine(j, int(flagships.size()), health, title);
    }
    else {
        int stats[5];
        for (int i = 0; i < 5; i++) {
            if (j-5+i < int(flagships.size()) && flagships[i].getHealth() > 0) {
                if (text == "HEALTH") stats[i] = flagships[j-5+i].getHealth();
                else if (text == "ARMOR") stats[i] = flagships[j-5+i].getArmor();
                else if (text == "SPEED") stats[i] = flagships[j-5+i].getSpeed();
                else if (text == "FLEET SPEED") stats[i] = flagships[j-5+i].getFleetSpeed();
                else stats[i] = 0;
            }
            else
                stats[i] = 0;
        }
        writeStatsLine(text, j, int(flagships.size()), health, stats);
    }
}



void showFighters(vector<Fighter> fighters) {
    drawHorizontalLine("top");
        for (int j = 5; j == 5 || j <= int(fighters.size()%5 == 0 ? fighters.size() :
                                                                    fighters.size()-fighters.size()%5+5); j += 5) {

        writeStatsLine("NAME", fighters, j);
        writeStatsLine("", fighters, j);
        writeStatsLine("HEALTH", fighters, j);
        writeStatsLine("POWER", fighters, j);
        writeStatsLine("SPEED", fighters, j);

        if (j < int(int(fighters.size())%5 == 0 ? int(fighters.size()) :
                                                  int(fighters.size())-int(fighters.size())%5+5)) {
             drawHorizontalLine("middle");
        }
    }
    drawHorizontalLine("bottom");
}

void showCruisers(vector<Cruiser> cruisers, bool toShowFighters, bool singleFlagshipFleet) {
    if (singleFlagshipFleet) drawHorizontalLine("middle-top");
    else drawHorizontalLine("top");

    for (int j = 5; j == 5 || j <= int(cruisers.size()%5 == 0 ?
                                   cruisers.size() : cruisers.size()-cruisers.size()%5+5); j += 5) {

        writeStatsLine("NAME", cruisers, j);
        writeStatsLine("", cruisers, j);
        writeStatsLine("HEALTH", cruisers, j);
        writeStatsLine("ARMOR", cruisers, j);
        writeStatsLine("SPEED", cruisers, j);
        writeStatsLine("T_POWER", cruisers, j);
        writeStatsLine("FREE SLOTS", cruisers, j);

        if (toShowFighters == true) {
            if (int(cruisers.size() != 1)) {
                if (isShipInLine(cruisers, j)) {

                    drawContainLine("FIGHTERS", j, int(cruisers.size()), cruisers);

                    int maxFleet = 0;

                    for (int i = j-5; i < int(cruisers.size()) && i < j; i++)
                        if (int(cruisers[i].fighters.size()) > maxFleet) maxFleet = int(cruisers[i].fighters.size());

                    for (int currFighter = 0; currFighter == 0 || currFighter < maxFleet; currFighter++) {
                        vector<Fighter> tmpFighters(5);

                        for (int i = j-5; i < j; i++) {
                            if (i < int(cruisers.size()) && int(cruisers[i].fighters.size()) > currFighter)
                                tmpFighters[i%5] = cruisers[i].fighters[currFighter];
                            else
                                tmpFighters[i%5] = Fighter();
                        }

                        writeStatsLine("NAME", tmpFighters, 5, currFighter);
                        writeStatsLine("", tmpFighters, 5, currFighter);
                        writeStatsLine("HEALTH", tmpFighters, 5, currFighter);
                        writeStatsLine("POWER", tmpFighters, 5, currFighter);
                        writeStatsLine("SPEED", tmpFighters, 5, currFighter);

                        if (currFighter < maxFleet-1)
                            drawContainLine("INTERNAL SHIPS", j, int(cruisers.size()), cruisers, currFighter);
                    }
                }
            }
            else {
                drawHorizontalLine();
                writeTitle("VULTURE[0]' FIGHTERS", true);
                showFighters(cruisers[0].fighters);
            }
        }

        if (j < int(int(cruisers.size())%5 == 0 ? int(cruisers.size()) :
                                                  int(cruisers.size())-int(cruisers.size())%5+5)) {
            drawHorizontalLine("middle");
        }
    }
    if (toShowFighters == false || int(cruisers.size()) != 1)
        drawHorizontalLine("bottom");
}

void showFlagships(vector<Flagship> flagships, bool toShowCruisers) {
    drawHorizontalLine("top");
    for (int j = 5; j == 5 || j <= int(flagships.size()%5 == 0 ?
                               flagships.size() : flagships.size()-flagships.size()%5+5); j += 5) {

        writeStatsLine("NAME", j, flagships);
        writeStatsLine("", j, flagships);
        writeStatsLine("HEALTH", j, flagships);
        writeStatsLine("ARMOR", j, flagships);
        writeStatsLine("SPEED", j, flagships);
        writeStatsLine("FLEET SPEED", j, flagships);

        if (toShowCruisers == true) {
            if (int(flagships.size() != 1)) {
                if (isShipInLine(flagships, j)) {
                    drawContainLine("FLEET", j, int(flagships.size()), flagships);
                    int maxFleet = 0;

                    for (int i = j-5; i < int(flagships.size()) && i < j; i++)
                        if (int(flagships[i].cruisers.size()) > maxFleet) maxFleet = int(flagships[i].cruisers.size());

                    for (int currCruiser = 0; currCruiser == 0 || currCruiser < maxFleet; currCruiser++) {

                        vector<Cruiser> tmpCruisers(5);

                        for (int i = j-5; i < j; i++) {
                            if (i < int(flagships.size()) && int(flagships[i].cruisers.size()) > currCruiser)
                                tmpCruisers[i%5] = flagships[i].cruisers[currCruiser];
                            else
                                tmpCruisers[i%5] = Cruiser();
                        }

                        writeStatsLine("NAME", tmpCruisers, 5, currCruiser);
                        writeStatsLine("", tmpCruisers, 5, currCruiser);
                        writeStatsLine("HEALTH", tmpCruisers, 5, currCruiser);
                        writeStatsLine("ARMOR", tmpCruisers, 5, currCruiser);
                        writeStatsLine("SPEED", tmpCruisers, 5, currCruiser);
                        writeStatsLine("T_POWER", tmpCruisers, 5, currCruiser);
                        writeStatsLine("FREE SLOTS", tmpCruisers, 5, currCruiser);

                        if (currCruiser < maxFleet-1)
                            drawContainLine("INTERNAL SHIPS", j, int(flagships.size()), flagships, currCruiser);
                    }
                }
                if (j < int(int(flagships.size())%5 == 0 ? int(flagships.size()) :
                                                           int(flagships.size())-int(flagships.size())%5+5)) {
                    drawHorizontalLine("middle");
                }
            }
            else {
                drawHorizontalLine("middle-bottom");
                writeTitle("MASTODON[0]' FLEET", true);
                showCruisers(flagships[0].cruisers, 0, true);
            }
        }
        else if (j < int(int(flagships.size())%5 == 0 ? int(flagships.size()) :
                                                        int(flagships.size())-int(flagships.size())%5+5)) {
            drawHorizontalLine("middle");
        }
    }

    if (toShowCruisers == true && int(flagships.size() != 1))
        drawHorizontalLine("bottom");
}

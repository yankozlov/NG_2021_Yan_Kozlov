#include <spaceforces.h>
#include <pseudographics.h>
#include <utilities.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "═══════════════════════════════════ FIGHTERS ═══════════════════════════════════" << endl;

    vector<Fighter> fury(20);
    recordEvent("Created 20 fighters named 'FURY'");

    for (int i = 0; i < 5; i++) {
        fury[i].setHealth(150);
        fury[i].setPower(20);
        fury[i].setSpeed(8);
    }
    for (int i = 5; i < 10; i++) {
        fury[i].setHealth(200);
        fury[i].setPower(30);
        fury[i].setSpeed(12);
    }
    for (int i = 10; i < 15; i++) {
        fury[i].setHealth(300);
        fury[i].setPower(25);
        fury[i].setSpeed(6);
    }
    for (int i = 15; i < 20; i++) {
        fury[i].setHealth(100);
        fury[i].setPower(40);
        fury[i].setSpeed(10);
    }

    writeTitle("FIGHTERS");
    showFighters(fury);

    cout << "═══════════════════════════════════ CRUISERS ═══════════════════════════════════" << endl;

    vector<Cruiser> vulture(4);
    recordEvent("Created 4 cruisers names 'VULTUTRE'");

    vulture[0].setHealth(800);
    vulture[0].setArmor(100);
    vulture[0].setSpeed(9);

    vulture[1].setHealth(700);
    vulture[1].setArmor(150);
    vulture[1].setSpeed(11);

    vulture[2].setHealth(1000);
    vulture[2].setArmor(200);
    vulture[2].setSpeed(7);

    vulture[3].setHealth(900);
    vulture[3].setArmor(50);
    vulture[3].setSpeed(10);

    writeTitle("CRUISERS");
    showCruisers(vulture, true);

    cout << "════════════════════════════ CRUISERS WITH FIGHTERS ════════════════════════════" << endl;

    vulture[0].addFighter(fury[0]);
    vulture[0].addFighter(fury[1]);
    vulture[0].addFighter(fury[2]);
    vulture[0].addFighter(fury[3]);
    vulture[0].addFighter(fury[4]);
    vulture[0].addFighter(fury[9]);
    cout << "VULTURE[0]: Added fighters 'FURY' #0, #1, #2, #3, #4, #9" << endl;

    writeTitle("FREE FIGHTERS");
    showFighters(fury);

    vulture[1].addFighter(fury[5]);
    vulture[1].addFighter(fury[6]);
    vulture[1].addFighter(fury[7]);
    vulture[1].addFighter(fury[8]);
    cout << "VULTURE[1]: Added fighters 'FURY' #5, #6, #7, #8" << endl;

    writeTitle("FREE FIGHTERS");
    showFighters(fury);

    vulture[2].addFighter(fury[10]);
    vulture[2].addFighter(fury[11]);
    vulture[2].addFighter(fury[12]);
    vulture[2].addFighter(fury[13]);
    vulture[2].addFighter(fury[14]);
    vulture[2].addFighter(fury[18]);
    vulture[2].addFighter(fury[19]);
    cout << "VULTURE[2]: Added fighters 'FURY' #10, #11, #12, #13, #14, #18, #19" << endl;

    writeTitle("FREE FIGHTERS");
    showFighters(fury);

    vulture[3].addFighter(fury[15]);
    vulture[3].addFighter(fury[16]);
    vulture[3].addFighter(fury[17]);
    cout << "VULTURE[3]: Added fighters 'FURY' #15, #16, #17" << endl;

    writeTitle("FREE FIGHTERS");
    showFighters(fury);

    writeTitle("CRUISERS");
    showCruisers(vulture, 1);

    cout << "═══════════════════════════════════ FLAGSHIP ═══════════════════════════════════" << endl;

    vector<Flagship> mastodon(1);
    recordEvent("Created a flagship named 'MASTODON'");

    mastodon[0].setHealth(2800);
    mastodon[0].setArmor(300);
    mastodon[0].setSpeed(15);

    writeTitle("FLAGSHIPS");
    showFlagships(mastodon, 1);

    cout << "══════════════════════════════ FLAGSHIP AND FLEET ══════════════════════════════" << endl;

    mastodon[0].addCruiser(vulture[1]);
    mastodon[0].addCruiser(vulture[3]);
    cout << "MASTODON[0]: Added cruisers 'VULTURE' #1, #3" << endl;

    writeTitle("FREE CRUISERS");
    showCruisers(vulture, 0);

    writeTitle("FLAGSHIPS");
    showFlagships(mastodon, 1);

    mastodon.push_back(Flagship());
    mastodon[1].setHealth(56000);
    mastodon[1].setArmor(18000);
    mastodon[1].setSpeed(26);
    recordEvent("Created another flagship named 'MASTODON'");

    mastodon[0].addCruiser(vulture[0]);
    mastodon[1].addCruiser(vulture[2]);
    cout << "MASTODON[0]: Added cruisers 'VULTURE' #0," << endl;
    cout << "MASTODON[1]: Added cruisers 'VULTURE' #2" << endl;

    writeTitle("FREE CRUISERS");
    showCruisers(vulture, 0);

    writeTitle("FLAGSHIPS");
    showFlagships(mastodon, 1);
}

#ifndef PSEUDOGRAPHICS_H
#define PSEUDOGRAPHICS_H

#include <spaceforces.h>
#include <utilities.h>

void showFighters(vector<Fighter> fighters);

void showCruisers(vector<Cruiser> cruisers, bool toShowFighters, bool singleFlagshipFleet = false);

void showFlagships(vector<Flagship> flagships, bool toShowCruisers);

#endif // PSEUDOGRAPHICS_H

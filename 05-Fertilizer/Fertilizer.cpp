#include <iostream>
#include <sstream>
#include <vector>

#include "AlmanacSection.h"

using namespace std;

string seedLineString;
vector<long int> getSeedsFromLine(string line);
vector<long int> getSeedRangesFromLine(string line);
long int smallestLocationFromRangeSeedsLine(string line, vector<AlmanacSection> &almanac);
long int findLocation(long int seed, vector<AlmanacSection> &almanac);
long int smallest(vector<long int> &items);

int main() {
  vector<long int> seeds, rangeSeeds, locations, rangeLocations;
  int sectionCount = 0;
  // AlmanacSection seedToSoil, soilToFertilizer, fertilizerToWater, waterToLight, lightToTemperature, temperatureToHumidity, humidityToLocation;
  vector<AlmanacSection> almanac(8);
  for (string line; getline(cin, line);) {
    // A blank line indicates the end of a section in the input file
    if (line == "") {
      // Increment section count and skip section Header on next line
      sectionCount++;
      getline(cin, line);
      continue;
    }

    if (sectionCount == 0) {  // Seeds (Section 0)
      seedLineString = line;
      almanac[sectionCount].addSeedMap(line);
    } else {
      almanac[sectionCount].addMap(line);
    }
  }

  // Find Location for all seeds
  seeds = getSeedsFromLine(seedLineString);
  for (int i = 0; i < seeds.size(); i++) {
    locations.push_back(findLocation(seeds[i], almanac));
  }

  cout << "Smallest Location is: " << smallest(locations) << endl;

  // Find location for all seeds in rangeSeeds

  for (int i = 0; i < rangeSeeds.size(); i++) {
    rangeLocations.push_back(findLocation(rangeSeeds[i], almanac));
  }

  cout << "Smallest Location from seed ranges is: " << smallestLocationFromRangeSeedsLine(seedLineString, almanac) << endl;
}

vector<long int> getSeedsFromLine(string line) {
  vector<long int> seeds;
  // Remove "seeds: " (7 characters) from start of line
  line = line.substr(7);
  stringstream lineStream(line);
  for (string seedString; getline(lineStream, seedString, ' ');) {
    seeds.push_back(stol(seedString));
  }
  return seeds;
}

vector<long int> getSeedRangesFromLine(string line) {
  vector<long int> seeds;
  // Remove "seeds: " (7 characters) from start of line
  line = line.substr(7);
  stringstream lineStream(line);
  for (string seedString; getline(lineStream, seedString, ' ');) {
    long int rangeStart = stol(seedString);
    string rangeLengthString;
    getline(lineStream, rangeLengthString, ' ');
    long int rangeLength = stol(rangeLengthString);
    for (int i = 0; i < rangeLength; i++) {
      seeds.push_back(rangeStart + i);
    }
  }
  return seeds;
}

long int findLocation(long int seed, vector<AlmanacSection> &almanac) {
  long int destination = seed;
  // cout << "Seed " << destination;
  for (int section = 1; section <= 7; section++) {
    destination = almanac[section].findDestination(destination);
    // cout << "->" << destination;
  }
  // cout << endl;
  return destination;
}

long int smallest(vector<long int> &items) {
  long int smallestItem = items[0];
  for (int i = 0; i < items.size(); i++) {
    if (items[i] < smallestItem) {
      smallestItem = items[i];
    }
  }
  return smallestItem;
}

long int smallestLocationFromRangeSeedsLine(string line, vector<AlmanacSection> &almanac) {
  long int smallestLocation = __LONG_MAX__;
  line = line.substr(7);
  stringstream lineStream(line);
  for (string seedString; getline(lineStream, seedString, ' ');) {
    long int rangeStart = stol(seedString);
    string rangeLengthString;
    getline(lineStream, rangeLengthString, ' ');
    long int rangeLength = stol(rangeLengthString);
    for (int i = 0; i < rangeLength; i++) {
      long int location = findLocation(rangeStart + i, almanac);
      if (location < smallestLocation) {
        smallestLocation = location;
      }
    }
  }
  return smallestLocation;
}
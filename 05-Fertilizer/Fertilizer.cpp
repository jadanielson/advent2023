#include <iostream>
#include <sstream>
#include <vector>

#include "AlmanacSection.h"

using namespace std;

vector<long int> getSeedsFromLine(string line);
long int findLocation(long int seed, vector<AlmanacSection> &almanac);

int main() {
  vector<long int> seeds, locations;
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
      seeds = getSeedsFromLine(line);
    } else {
      almanac[sectionCount].addMap(line);
    }
  }

  // Find Location for all seeds
  for (int i = 0; i < seeds.size(); i++) {
    locations.push_back(findLocation(seeds[i], almanac));
  }

  long int smallestLocation = locations[0];
  for (int i = 0; i < locations.size(); i++) {
    if (locations[i] < smallestLocation) {
      smallestLocation = locations[i];
    }
  }

  cout << "Smallest Location is: " << smallestLocation << endl;
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

long int findLocation(long int seed, vector<AlmanacSection> &almanac) {
  long int destination = seed;
  cout << "Seed " << destination;
  for (int section = 1; section <= 7; section++) {
    destination = almanac[section].findDestination(destination);
    cout << "->" << destination;
  }
  cout << endl;
  return destination;
}
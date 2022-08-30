#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
        << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    string beginning = dests.at(0);
    float distance = 0.0;
    vector<string> temp = dests;

    float minDistance = computeDistance(me, beginning, dests);



    sort(dests.begin()+1, dests.end());

    do{
        distance = computeDistance(me, beginning, dests);
        if(distance < minDistance){
            minDistance = distance;
            temp = dests;

        }


    }while(next_permutation(dests.begin()+1,dests.end()));

        beginning = temp.at(0);
        cout <<"Minimum path has distance: "<<minDistance << ": ";
        printRoute(beginning, temp);

    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    string beginning = start;
    float result = 0.0;
    string last = dests.back();
    for(int i = 0; i < dests.size()-1; i++){
        result += me.getDistance(dests.at(i), dests.at(i+1)); //going to every city
    }
    result += me.getDistance(last, beginning);
    return result;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    string beginning = start;
    string result = "";
    for(int i = 0; i < dests.size(); i++){
        result = result + dests.at(i) + " -> ";
    }
    cout << result + beginning << endl;
}
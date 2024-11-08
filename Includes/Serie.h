#ifndef SERIE_H
#define SERIE_H

#include "Episode.h"
#include <vector>
#include <iostream>
using namespace std;

class Serie
{
private:
    string title = ""; // title of the serie
    vector<vector<Episode>> Episodes; // matrix of episodes, each row is a season and each column is an episode
    int season;
    int order;

public:
    // Add constructor to initialize the serie from file
    Serie(); // constructor
    Serie(vector<string> filenames, string title); 
    void append_episode(); // append an episode to a season
    Episode get_episode(); // get episode by season and order
    void rate_episode(int season, int order); // rate an episode
    int get_season(); // get the season of the episode
    int get_order(); // get the order of the episode
    void add_season(string filename);
    friend ostream &operator<<(ostream &os, const Serie &serie); // overload of the << operator
};

#endif

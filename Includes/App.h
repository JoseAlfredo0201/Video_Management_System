#ifndef APP_H
#define APP_H

#include "Serie.h"
#include "UtilitiesRead.h"

class App
{
private:
    enum OPTION {VIDEOS = 1, MOVIES, SERIES, EXIT};
    vector<Serie> list_series;
    vector<Video> list_movies;
    vector<Video> list_videos;
public:
    void main_loop();
    void check_videos();
    void check_movies();
    void check_series();
    
    void debug();
};

#endif

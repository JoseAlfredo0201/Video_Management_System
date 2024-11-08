#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

class Video{
    public:
        unsigned short int ID; //id of the video 
        float rating = 0; // average rating of the video  
        unsigned short int users = 0; // numeber of users that rate the video 
        unsigned short int minutes; // lenght of the video in minutes
        string title; // name of the video 
        string genre;  // genre of the video 

    public:
        Video(): ID(0), rating(0), users(0), minutes(0), title(""), genre(""){}
        Video(unsigned short int id, const string& title, unsigned short int minutes, const string& genre) 
        : ID(id), rating(0), users(0), minutes(minutes), title(title), genre(genre) {}

        string GetTitle() const;
        void addRating();

    friend ostream& operator<<(ostream& os, Video b){
        os << "Title: "<<b.title<<endl;
        os << "Genre: "<<b.genre<<endl;
        os << "Lenght: "<<formatMinutes(b.minutes)<<endl;
        os << "Users: " << b.users << endl;
        os << "Rating: "<<b.rating<<endl;
        
        return os;
    }
};
#endif

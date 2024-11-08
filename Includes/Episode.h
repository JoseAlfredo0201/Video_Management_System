#ifndef EPISODE_H
#define EPISODE_H

#include"Video.h"

class Episode: public Video
{
private:
    string STitle;
public:
    Episode();
    Episode(unsigned short int id, const string& nombre, unsigned short int duracion, const string& genero)
    {
        ID = id;
        title = nombre;
        minutes = duracion;
        genre = genero;
        rating = 0;
        users = 0;
    }

    void set_STitle(string STitle);

    friend ostream& operator<<(ostream& os, Episode b){
        os << "Series: " <<b.STitle<<endl;
        os << "Title: "<<b.title<<endl;
        os << "Genre: "<<b.genre<<endl;
        os << "Lenght: "<<formatMinutes(b.minutes)<<endl;
        os << "Rating: "<<b.rating<<endl;
        
        return os;
    }

    friend istream& operator>>(istream& is, Episode &b){
        cout<<"Enter the title of the episode: ";
        is>>b.title;
        cout<<"Enter the genre of the episode: ";
        is>>b.genre;
        cout<<"Enter the lenght (in minutes) of the episode: ";
        is>>b.minutes;
        return is;
    }
};

#endif

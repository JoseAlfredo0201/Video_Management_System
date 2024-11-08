#include"Episode.h"

Episode::Episode() {
    cout<<"Enter the title of the episode: ";
    cin>>title;
    cout<<"Enter the genre of the episode: ";
    cin>>genre;
    cout<<"Enter the lenght (in minutes) of the episode: ";
    cin>>minutes;
}

void Episode::set_STitle(string STitle){
    this->STitle=STitle;
}
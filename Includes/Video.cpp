#include"Video.h"

string Video::GetTitle() const{
    return title;
    }

void Video::addRating(){
    int newRating = 0;
    cout<<"Current average rating for this episode: "<<rating<<endl<< "Add your new rating in a scale from 1 to 5: "<<endl;
    cin>>newRating;
    if ((newRating<0 || newRating>6)){
        cout<<newRating;
        cout<<"The rating you tied to add is not valid";
        return;
    }
    rating=(rating*users+newRating)/(users+1);
    users+=1;
    cout<<"the new average rating is: "<<rating<<endl;
}


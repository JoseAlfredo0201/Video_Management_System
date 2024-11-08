#include "App.h"
#include "Serie.h"
#include <iostream>

using namespace std;

void App::main_loop()
{
    int option;
    cout << "Welcome to the app streaming service, where you can check are latest videos, movies and series" << endl << endl;
    do
    {
        cout << "___________MENU___________" << endl;
        cout << "1. Check the latest videos" << endl;
        cout << "2. Check the latest movies" << endl;
        cout << "3. Check the latest series" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case VIDEOS:
            cout << "Checking the latest videos..." << endl;
            App::check_videos();
            break;
        case MOVIES:
            cout << "Checking the latest movies..." << endl;
            App::check_movies();
            break;
        case SERIES:
            cout << "Checking the latest series..." << endl;
            App::check_series();
            break;
        case EXIT:
            cout << "Exiting the app..." << endl;
            return;
        default:
            cout << "Invalid option, please try again" << endl;
            break;
        }
    } while (option != EXIT);
}

void App::check_videos()
{
    enum VIDEO_OPTION {APPEND = 1, GET, EXIT};
    while (true)
    {
        int option;
        list_videos = readMedia("videos.txt"); // Assuming you have a file named videos.txt
        for (auto& video : list_videos) {
            cout << video << endl;
        }
        cout << "___________VIDEO MENU___________" << endl;
        cout << "1. Append a video" << endl;
        cout << "2. Get a video" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case APPEND:
        {
            Video *video = new Video();
            video->ID = list_videos.size() + 1;
            cout << "Enter the title of the video: ";
            cin >> video->title;
            cout << "Enter the genre of the video: ";
            cin >> video->genre;
            cout << "Enter the length (in minutes) of the video: ";
            cin >> video->minutes;
            list_videos.push_back(*video);
            writeMedia("videos.txt", list_videos); // Assuming you have a writeMedia function
            break;
        }
        case GET:
        {
            int index = 0;
            char rateOption = '\0'; // rate the video
            do
            {
                cout << "Enter the index of the video: ";
                cin >> index;
                if (index <= 0 || index > list_videos.size() + 1)
                {
                    cout << "Invalid index, please try again" << endl;
                }
                else
                {
                    cout << "Video found: " << list_videos[index - 1] << endl;
                }
            } while (index <= 0 || index > list_videos.size());
            cout << "Want to rate this video? (y/n): ";
            while (rateOption != 'y' && rateOption != 'n')
            {
                cin >> rateOption;
                if (rateOption != 'y' && rateOption != 'n')
                {
                    cout << "Invalid option, please try again" << endl;
                }
                else if (rateOption == 'n')
                {
                    cout << "Rating canceled" << endl;
                }
                else
                {
                    list_videos[index - 1].addRating();
                }
            }
            writeMedia("videos.txt", list_videos); // Assuming you have a writeMedia function
            break;
        }
        case EXIT:
            cout << "Exiting the video menu..." << endl;
            return;

        default:
            cout << "Invalid option, please try again" << endl;
            break;

        }
    }
}

void App::check_movies()
{
    enum MOVIE_OPTION {APPEND = 1, GET, EXIT};
    while (true)
    {
        int option;
        list_movies = readMedia("movies.txt"); // Assuming you have a file named movies.txt
        for (auto& movie : list_movies) {
            cout << movie << endl;
        }
        cout << "___________MOVIE MENU___________" << endl;
        cout << "1. Append a movie" << endl;
        cout << "2. Get a movie" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case APPEND:
        {
            Video *movie = new Video();
            movie->ID = list_movies.size() + 1;
            cout << "Enter the title of the movie: ";
            cin >> movie->title;
            cout << "Enter the genre of the movie: ";
            cin >> movie->genre;
            cout << "Enter the length (in minutes) of the movie: ";
            cin >> movie->minutes;
            list_movies.push_back(*movie);
            writeMedia("movies.txt", list_movies); // Assuming you have a writeMedia function
            break;
        }

        case GET:
        {
            int index = 0;
            char rateOption = '\0'; // rate the movie
            do
            {
                cout << "Enter the index of the movie: ";
                cin >> index;
                if (index < 0 || index >= list_movies.size())
                {
                    cout << "Invalid index, please try again" << endl;
                }
                else
                {
                    cout << "Movie found: " << list_movies[index - 1] << endl;
                }
            } while (index < 0 || index >= list_movies.size());
            cout << "Want to rate this movie? (y/n): ";
            while (rateOption != 'y' && rateOption != 'n')
            {
                cin >> rateOption;
                if (rateOption != 'y' && rateOption != 'n')
                {
                    cout << "Invalid option, please try again" << endl;
                }
                else if (rateOption == 'n')
                {
                    cout << "Rating canceled" << endl;
                }
                else
                {
                    list_movies[index - 1].addRating();
                }
            }
            writeMedia("movies.txt", list_movies); // Assuming you have a writeMedia function
            break;
        }

        case EXIT:
            cout << "Exiting the movie menu..." << endl;
            return;

        default:
            cout << "Invalid option, please try again" << endl;
            break;

        }
    }   
}

void App::check_series()
{
    enum SERIE_OPTION {APPEND = 1, GET, EXIT};
    vector<string> filenames = {"./rompiendoalmalo/seasonone.txt"};
    Serie *serie = new Serie(filenames, "rompiendoalmalo");
    while (true)
    {
        cout << *serie << endl;
        int option;
        cout << "___________SERIE MENU___________" << endl;
        cout << "1. Append an episode" << endl;
        cout << "2. Get an episode" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case APPEND:
            serie->append_episode();
            break;
        case GET:
            cout << serie->get_episode() << endl;
            serie->rate_episode(serie->get_season(), serie->get_order());
            break;
        case EXIT:
            cout << "Exiting the serie menu..." << endl;
            return;
        default:
            cout << "Invalid option, please try again" << endl;
            break;
        }
    }
}

void App::debug(){
    list_movies = readMedia("peliculas.txt");
    cout << list_movies.size() << endl;
      for (auto& pelicula : list_movies) {
          cout << pelicula << endl;
    }
    vector<string> filenamess = {"./rompiendoalmalo/seasonone.txt"};
    Serie s1(filenamess,"rompiendoalmalo");
    cout << s1 << endl;
}


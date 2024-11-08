#include "Serie.h"
#include "UtilitiesRead.h"

Serie::Serie()
{
    int season; // season of the episode
    char option = '\0'; // option to add another episode
    cout << "Enter the title of the serie: ";
    cin >> title;
    do
    {
        cout << "Enter amount of season: ";
        cin >> season;
        if (season < 1)
            cout << "Invalid amount of season, please try again" << endl;

    } while (season < 1);

    for (int i = 0; i < season; i++)
    {
        cout << "Enter the episodes of season " << i + 1 << endl;
        vector<Episode> season_with_episodes; // List of episodes
        Episode *newEpisode = new Episode();
        newEpisode->set_STitle(title);
        season_with_episodes.push_back(*newEpisode);
        do
        {
            cout << "Want to add another episode? (y/n): ";
            cin >> option;
            if (option != 'y' && option != 'n')
            {
                cout << "Invalid option, please try again" << endl;
            }
            else if (option == 'n')
            {
                break;
            }
            else
            {
                cout << "Adding another episode" << endl;
                newEpisode = new Episode();
                newEpisode->set_STitle(title);
                season_with_episodes.push_back(*newEpisode);
            }
        } while (true);
    Episodes.push_back(season_with_episodes);
    }

    cout << "Serie created successfully" << endl;
}

void Serie::append_episode()
{   
    Episode *episode = new Episode(); // title of the episode
    int season = 0; // season of the episode
    int order = 0; // order of the episode in the season
    
    cout << "Enter the season of the episode: ";
    cin >> season;

    if (Episodes.size() < season)
    {
        vector<Episode> new_season;
        Episodes.push_back(new_season);
        Episodes.back().push_back(*episode);
        cout << "Sesion with episode added successfully" << endl;
    }
    else
    {
        Episodes[season - 1].push_back(*episode);
        cout << "Episode addded successfully" << endl;
    }
}

Episode Serie::get_episode()
{
    int season = 0; // season of the episode
    int order = 0; // order of the episode in the season
    char option = '\0'; // rate the episode

    // Get the season from user
    do
    {
        cout << "Enter the season of the episode: ";
        cin >> season;
        this->season = season;
        if(Episodes.size() < season)
        {
            cout << "Season not found" << endl;
        }
        else
        {
            cout << "Season found: " << season << endl;
        }
    } while (season < 1 || season > Episodes.size());
    
    // Get the order from user
    do
    {
        cout << "Enter the number of episode: ";
        cin >> order;
        this->order = order;

        if (order < 1 || order > Episodes[season - 1].size())
        {
            cout << "Invalid episode number, please try again" << endl;
        }
        else
        {
            cout << "--Episode found--" << endl;
        }

    } while (order < 1 || order > Episodes[season - 1].size());
    
    return Episodes[season - 1][order - 1];
}

Serie::Serie(vector<string> filenames, string newTitle){
  title = newTitle;
  for (const auto& filename : filenames) {
    add_season(filename);
  }
}

void Serie::rate_episode(int season, int order)
{
    char option = '\0'; // rate the episode
    //float rating = 0; // rating of the episode
    cout << "Want to rate this episode? (y/n): ";
    while (option != 'y' && option != 'n')
    {
        cin >> option;
        if (option != 'y' && option != 'n')
        {
            cout << "Invalid option, please try again" << endl;
        }
        else if (option == 'n')
        {
            cout << "Rating canceled" << endl;
        }
        else
        {

            Episodes[season - 1][order - 1].addRating();
            
        }
    }
}

int Serie::get_season()
{
    return season;
}

int Serie::get_order()
{
    return order;
}

ostream &operator<<(ostream &os, const Serie &serie)
{
    os << "Serie title: " << serie.title << endl;
    for (int i = 0; i < serie.Episodes.size(); i++)
    {
        os << "//Season " << i + 1 << "//" << endl;
        os << "Episodes: ";
        for (int j = 0; j < serie.Episodes[i].size(); j++)
        {
            os << "| "<< serie.Episodes[i][j].GetTitle() << " | ";
        }
        os << endl;
    }
    return os;
}

void Serie::add_season(string filename){
  vector <Episode> Season_n= readEpisodes(filename, title);
  Episodes.push_back(Season_n);
}

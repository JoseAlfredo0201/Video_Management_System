#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

inline vector<Episode> readEpisodes(const string& archivo, string Stitle) {
    vector<Episode> Episodes;
    ifstream infile(archivo);

    if (!infile.is_open()) {
        cerr << "Could not open the file" << archivo << endl;
        return Episodes;
    }

    string linea;
    while (getline(infile, linea)) {
        stringstream ss(linea);
        string id, titulo, duracion, genero;
        getline(ss, id, '|');
        getline(ss, titulo, '|');
        getline(ss, duracion, '|');
        getline(ss, genero, '|');

        Episode Media(stoi(id),titulo,stoi(duracion),genero);
        Media.set_STitle(Stitle);
        Episodes.push_back(Media);
    }

    infile.close();
    return Episodes;
}

inline vector<Video> readMedia(const string& archivo) {
    vector<Video> Medias;
    ifstream infile(archivo);

    if (!infile.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivo << endl;
        return Medias;
    }

    string linea;
    while (getline(infile, linea)) {
        stringstream ss(linea);
        string id, titulo, duracion, score, user, genero;
        getline(ss, id, '|');
        getline(ss, titulo, '|');
        getline(ss, duracion, '|');
        getline(ss, user, '|');
        getline(ss, score, '|');
        getline(ss, genero, '|');

        Video Media;
        Media.ID = stoi(id);
        Media.title = titulo;
        Media.minutes = stoi(duracion);
        Media.users = stoi(user);
        Media.rating = stoi(score);
        Media.genre = genero;
        Medias.push_back(Media);
    }

    infile.close();
    return Medias;
}


inline void writeMedia(const string& file, const vector<Video>& Medias) {
    ofstream outfile(file);

    if (!outfile.is_open()) {
        cerr << "We were not able to open: " << file << endl;
        return;
    }

    for (const auto& Media: Medias) {
        outfile << Media.ID << "|"
                << Media.title << "|" 
                << Media.minutes << "|"
                << Media.users << "|"
                << Media.rating << "|"
                << Media.genre << "\n";
    }

    outfile.close();
}

#endif // UTILITIES_H

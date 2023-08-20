#include <bits/stdc++.h>
#include <string>

#define endl '\n'

using namespace std;

struct Team {

    string name, percentage;
    int score;
    int games;
    int golsScored;
    int golsConceded;
};

bool compareTeams(const Team &a, const Team &b) {

    if (a.score != b.score) { // comparando a maior pontuação
        return a.score > b.score;
    }
    if ((a.golsScored - a.golsConceded) != (b.golsScored - b.golsConceded)) { // comparando saldo de gols
        return (a.golsScored - a.golsConceded) > (b.golsScored - b.golsConceded);
    }
    if (a.golsScored != b.golsScored) { // comparando gols marcados 
        return a.golsScored > b.golsScored;
    }

    return a.name < b.name; // ordem alfabética
}

int findTeam(vector<Team> Teams, int T, string name){
    int position;

    for(int i=0; i<T; i++){

        if(Teams[i].name == name){
            position = i;
            break;
        }
    }
    return position;
}
void percentage (vector<Team> &Teams, int T){

    double value;

    for(int i=0; i<T; i++){

        if(Teams[i].games == 0){

            Teams[i].percentage = "N/A";
        }else{

            value = (((double)(Teams[i].score))/(Teams[i].games*3))*100;
            Teams[i].percentage = to_string(value);
        }
    }
}
void printTeams(vector<Team> Teams,int T){

    for(int i=0; i<T; i++){

        cout << i + 1
             << "             " << Teams[i].name
             << " " << Teams[i].score
             << " " << Teams[i].games
             << " " << Teams[i].golsScored
             << " " << Teams[i].golsConceded
             << " " << Teams[i].golsScored - Teams[i].golsConceded
             << " " << Teams[i].percentage << endl;
    }
} 

int main(){

    int T,G;

    while(cin >>T >>G){

        vector<Team>teams;

        if(T == 0 && G == 0){
            break;
        }

        for(int i=0; i<T; i++){

            Team A;
            string names;
            cin >> names;
            //cout << names;

            A.name = names;

            teams.push_back(A);    
        }

        for(int i=0; i<G; i++){
            
            int aux1,aux2;
            string team1, team2, trav;
            int gols1, gols2;

            cin >> team1 >> gols1 >> trav >> gols2 >> team2;
            //cout << team1 << gols1 << trav << gols2 << team2;
            
            aux1 = findTeam(teams,T,team1);
            aux2 = findTeam(teams,T,team2);
            
            if(gols1 > gols2){
                teams[aux1].score +=3;
            }else if (gols2>gols1){
                teams[aux2].score +=3;
            }else {
                teams[aux1].score +=1;
                teams[aux2].score +=1;
            }

            teams[aux1].games +=1;
            teams[aux2].games +=1;
            
            teams[aux1].golsScored += gols1;
            teams[aux2].golsScored += gols2;

            teams[aux1].golsConceded += gols2;
            teams[aux2].golsConceded += gols1;
        }
        cout << endl;
        percentage(teams, T);
        sort(teams.begin(), teams.end(), compareTeams);
        printTeams(teams, T);
    }
    return 0;
}
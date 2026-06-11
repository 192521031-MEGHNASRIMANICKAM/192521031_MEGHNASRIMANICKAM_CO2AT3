#include <iostream>
#include <string>
using namespace std;
class Team
{
private:
    string name;
    int matches;
    int wins;
    int draws;
    int losses;
    int goalsScored;
    int goalsConceded;
public:
    static int totalTeams;
    void input()
    {
        cout << "Team Name: ";
        cin >> name;
        cout << "Matches Played: ";
        cin >> matches;
        cout << "Wins: ";
        cin >> wins;
        cout << "Draws: ";
        cin >> draws;
        cout << "Losses: ";
        cin >> losses;
        cout << "Goals Scored: ";
        cin >> goalsScored;
        cout << "Goals Conceded: ";
        cin >> goalsConceded;
        totalTeams++;
    }
    int calculatePoints()
    {
        return wins * 3 + draws;
    }
    int goalDifference()
    {
        return goalsScored - goalsConceded;
    }
    int getWins()
    {
        return wins;
    }
    string getName()
    {
        return name;
    }
    void display()
    {
        cout << name
             << " | Points = "
             << calculatePoints()
             << " | GD = "
             << goalDifference()
             << endl;
    }
};
int Team::totalTeams = 0;
int main()
{
    int groups;
    cout << "Enter Number of Groups: ";
    cin >> groups;
    Team groupWinner[20];
    for(int g=0; g<groups; g++)
    {
        cout << "\n GROUP "
             << g+1
             << "\n";
        int n;
        cout << "Enter Number of Teams: ";
        cin >> n;
        Team team[50];
        for(int i=0;i<n;i++)
            team[i].input();
        int winner = 0;
        for(int i=1;i<n;i++)
        {
            if(team[i].calculatePoints() >
               team[winner].calculatePoints())
            {
                winner = i;
            }
            else if(team[i].calculatePoints() ==
                    team[winner].calculatePoints())
            {
                if(team[i].goalDifference() >
                   team[winner].goalDifference())
                {
                    winner = i;
                }
                else if(team[i].goalDifference() ==
                        team[winner].goalDifference())
                {
                    if(team[i].getWins() >
                       team[winner].getWins())
                    {
                        winner = i;
                    }
                }
            }
        }
        cout << "\nGroup Winner: "
             << team[winner].getName()
             << endl;
        groupWinner[g] = team[winner];
    }
    int champion = 0;
    for(int i=1;i<groups;i++)
    {
        if(groupWinner[i].calculatePoints() >
           groupWinner[champion].calculatePoints())
        {
            champion = i;
        }
        else if(groupWinner[i].calculatePoints() ==
                groupWinner[champion].calculatePoints())
        {
            if(groupWinner[i].goalDifference() >
               groupWinner[champion].goalDifference())
            {
                champion = i;
            }
        }
    }
    cout << "\n TOURNAMENT CHAMPION \n";
    cout << groupWinner[champion].getName()
         << endl;
    cout << "\nTotal Teams Participated = "
         << Team::totalTeams
         << endl;
    return 0;
}

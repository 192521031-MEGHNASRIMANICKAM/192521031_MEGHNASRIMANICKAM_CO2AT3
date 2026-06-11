#include <iostream>
#include <string>
using namespace std;
class Candidate
{
private:
    string name;
    int votes;
public:
    static int totalCandidates;
    void input()
    {
        cout << "Enter Candidate Name: ";
        cin >> name;
        cout << "Enter Votes: ";
        cin >> votes;
        if(votes < 0)
            votes = 0;
        totalCandidates++;
    }
    string getName()
    {
        return name;
    }
    int getVotes()
    {
        return votes;
    }
};
int Candidate::totalCandidates = 0;
class Region
{
private:
    string regionName;
    Candidate candidates[50];
    int n;
public:
    void input()
    {
        cout << "\nEnter Region Name: ";
        cin >> regionName;
        cout << "Enter Number of Candidates: ";
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cout << "\nCandidate " << i+1 << endl;
            candidates[i].input();
        }
    }
    void regionalWinner()
    {
        if(n==0)
        {
            cout << "No candidates.\n";
            return;
        }
        int maxVotes = candidates[0].getVotes();
        int pos = 0;
        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(candidates[i].getVotes() > maxVotes)
            {
                maxVotes = candidates[i].getVotes();
                pos = i;
                count = 1;
            }
            else if(candidates[i].getVotes() == maxVotes)
            {
                count++;
            }
        }
        cout << "\nRegion: " << regionName << endl;
        if(count > 1)
            cout << "Result: Tie\n";
        else
            cout << "Winner: "
                 << candidates[pos].getName()
                 << " (" << maxVotes << " votes)\n";
    }
    int getCandidateCount()
    {
        return n;
    }
    Candidate getCandidate(int i)
    {
        return candidates[i];
    }
};
int main()
{
    int regions;
    cout << "Enter Number of Regions: ";
    cin >> regions;
    Region r[20];
    for(int i=0;i<regions;i++)
        r[i].input();
    cout << "\n REGIONAL RESULTS \n";
    for(int i=0;i<regions;i++)
        r[i].regionalWinner();
    string overallWinner;
    int highestVotes = -1;
    string names[100];
    int totalVotes[100];
    int uniqueCount = 0;
    for(int i=0;i<regions;i++)
    {
        for(int j=0;j<r[i].getCandidateCount();j++)
        {
            Candidate c = r[i].getCandidate(j);
            bool found = false;
            for(int k=0;k<uniqueCount;k++)
            {
                if(names[k] == c.getName())
                {
                    totalVotes[k] += c.getVotes();
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                names[uniqueCount] = c.getName();
                totalVotes[uniqueCount] = c.getVotes();
                uniqueCount++;
            }
        }
    }
    int winnerIndex = 0;
    for(int i=1;i<uniqueCount;i++)
    {
        if(totalVotes[i] > totalVotes[winnerIndex])
            winnerIndex = i;
    }
    cout << "\n===== OVERALL WINNER =====\n";
    cout << names[winnerIndex]
         << " with "
         << totalVotes[winnerIndex]
         << " votes\n";
    return 0;
}


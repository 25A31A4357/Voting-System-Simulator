#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Voter {
    int id;
    string name;
    string password;
    bool hasVoted;
};

vector<Voter> loadVoters() {
    vector<Voter> voters;
    ifstream file("voters.txt");

    if (!file) return voters;

    Voter v;
    while (file >> v.id >> v.name >> v.password >> v.hasVoted) {
        voters.push_back(v);
    }

    file.close();
    return voters;
}

void saveVoters(vector<Voter> &voters) {
    ofstream file("voters.txt");

    for (auto &v : voters) {
        file << v.id << " " << v.name << " " << v.password << " " << v.hasVoted << endl;
    }

    file.close();
}

map<string, int> loadVotes() {
    map<string, int> votes;
    ifstream file("votes.txt");

    if (!file) {
        votes["Alice"] = 0;
        votes["Bob"] = 0;
        votes["Charlie"] = 0;
        return votes;
    }

    string name;
    int count;
    while (file >> name >> count) {
        votes[name] = count;
    }

    file.close();
    return votes;
}


void saveVotes(map<string, int> &votes) {
    ofstream file("votes.txt");

    for (auto &v : votes) {
        file << v.first << " " << v.second << endl;
    }

    file.close();
}


void registerVoter(vector<Voter> &voters) {
    Voter v;

    cout << "Enter ID: ";
    cin >> v.id;

    for (auto &x : voters) {
        if (x.id == v.id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> v.name;

    cout << "Enter Password: ";
    cin >> v.password;

    v.hasVoted = false;

    voters.push_back(v);
    saveVoters(voters);

    cout << "Registration successful!\n";
}

void loginAndVote(vector<Voter> &voters, map<string, int> &votes) {
    int id;
    string password;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> password;

    for (auto &v : voters) {
        if (v.id == id && v.password == password) {

            if (v.hasVoted) {
                cout << "You have already voted!\n";
                return;
            }

            cout << "\nCandidates:\n";
            int i = 1;
            vector<string> names;

            for (auto &c : votes) {
                cout << i << ". " << c.first << endl;
                names.push_back(c.first);
                i++;
            }

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice < 1 || choice > names.size()) {
                cout << "Invalid choice!\n";
                return;
            }

            votes[names[choice - 1]]++;
            v.hasVoted = true;

            saveVotes(votes);
            saveVoters(voters);

            cout << "Vote cast successfully!\n";
            return;
        }
    }

    cout << "Invalid ID or Password!\n";
}

void showResults(map<string, int> &votes) {
    cout << "\n--- Voting Results ---\n";

    string winner;
    int maxVotes = -1;

    for (auto &v : votes) {
        cout << v.first << " : " << v.second << " votes\n";

        if (v.second > maxVotes) {
            maxVotes = v.second;
            winner = v.first;
        }
    }

    cout << "Winner: " << winner << endl;
}

int main() {
    vector<Voter> voters = loadVoters();
    map<string, int> votes = loadVotes();

    int choice;

    do {
        cout << "\n--- Voting System ---\n";
        cout << "1. Register\n";
        cout << "2. Login & Vote\n";
        cout << "3. Show Results\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerVoter(voters);
                break;
            case 2:
                loginAndVote(voters, votes);
                break;
            case 3:
                showResults(votes);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
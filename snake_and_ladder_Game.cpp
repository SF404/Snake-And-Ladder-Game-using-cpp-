#include <bits/stdc++.h>
using namespace std;
struct snake_and_ladder_game
{
    string name;   // to store names of players
    int score = 0; // to store score of players
    int dice()     // function to generate random number ranging 1-6
    {
        srand(time(NULL));
        int roll = (rand() % 6 + 1);

        if (roll == 6) // To give 2nd chance when 6 comes
        {
            cout << "You got 6, You have 1 more chance : ";
            char enter;
            cin >> enter;
            int k = dice();
            // cout << "You got: " << k;
            roll += k;
            if (roll >= 18) // your current dice roll gets equal to zero if you get 6 maore than 2 times
                return 0;
        }

        return roll;
    }
};

int main()
{
    int n;
    cout << "Enter the Number of players = ";
    cin >> n;
    snake_and_ladder_game p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of player " << i + 1 << " = ";
        cin >> p[i].name;
    }

    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << p[i].name << "'s turn: ";
            char x;
            cin >> x;
            int dice = p[i].dice();
            p[i].score += dice;
            int s = p[i].score;

            if (p[i].score > 100)
                p[i].score -= dice;

            if (s == 7 || s == 21 || s == 50 || s == 68) // Short stair Positions
            {
                cout << "You got upstairs\n";
                p[i].score += 21;
            }
            else if (s == 32 || s == 34 || s == 9) // Long stair Position
            {
                cout << "You got upstairs\n";
                p[i].score += 35;
            }

            if (s == 29 || s == 40 || s == 53 || s == 81) // small snake bite Position
            {
                cout << "Oops!!! Snake Bite\n";
                p[i].score -= 23;
            }
            else if (s == 98 || s == 85 || s == 74 || s == 50) // big snake bite Position
            {
                cout << "Oops!!! Snake Bite\n";
                p[i].score -= 47;
            }

            cout << p[i].name << " got " << dice << ": Position = " << p[i].score << "\n"; //printing your dice roll and current position

            if (p[i].score == 100) // when a player reaches finish line
            {
                cout << "Conguratulations!! " << p[i].name << " you won the Game\n";
                exit(0);
            }
        }
    }

    return 0;
}

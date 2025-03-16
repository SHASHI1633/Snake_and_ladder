
#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <mysql/mysql.h> // MySQL Connector for C++

using namespace std;

// Database Connection Setup
MYSQL* connect_db() {
    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        cerr << "MySQL initialization failed!" << endl;
        exit(1);
    }
    conn = mysql_real_connect(conn, "localhost", "root", "password", "snakeladderdb", 3306, NULL, 0);
    if (conn == NULL) {
        cerr << "Database connection failed!" << endl;
        exit(1);
    }
    return conn;
}

// Function to insert game results
void insert_game_result(MYSQL* conn, string player_name, int total_moves, int duration, bool won) {
    string query = "INSERT INTO SnakeLadderGame (player_name, total_moves, duration_seconds, won) VALUES ('" +
                   player_name + "', " + to_string(total_moves) + ", " + to_string(duration) + ", " + (won ? "1" : "0") + ")";
    mysql_query(conn, query.c_str());
}

// Function to insert move history
void insert_move_history(MYSQL* conn, string player_name, int dice_roll, int start_pos, int end_pos) {
    string query = "INSERT INTO SnakeLadderMoves (player_name, dice_roll, start_position, end_position) VALUES ('" +
                   player_name + "', " + to_string(dice_roll) + ", " + to_string(start_pos) + ", " + to_string(end_pos) + ")";
    mysql_query(conn, query.c_str());
}

// Dice roll function
int rollDice() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 6);
    return dis(gen);
}

// Main game function
void playGame() {
    MYSQL* conn = connect_db();

    cout << "Enter player name: ";
    string playerName;
    cin >> playerName;

    int position = 0, moves = 0;
    auto start_time = time(nullptr);

    while (position < 100) {
        cout << playerName << "'s turn. Press Enter to roll the dice.";
        cin.ignore();
        cin.get();

        int diceValue = rollDice();
        int newPosition = position + diceValue;

        if (newPosition <= 100) {
            cout << playerName << " rolled " << diceValue << ", moved to " << newPosition << endl;
            insert_move_history(conn, playerName, diceValue, position, newPosition);
            position = newPosition;
        }
        moves++;
    }

    int duration = time(nullptr) - start_time;
    insert_game_result(conn, playerName, moves, duration, true);

    cout << "Congratulations, " << playerName << " wins in " << moves << " moves and " << duration << " seconds!" << endl;

    mysql_close(conn);
}

int main() {
    playGame();
    return 0;
}

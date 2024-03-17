#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

// Node structure for the graph
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void addNode(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    Node* getHead() {
        return head;
    }
};

// Graph class
class Graph {
private:
    vector<LinkedList> nodes;
public:
    Graph(int size) {
        nodes.resize(size);
    }

    void addEdge(int u, int v) {
        nodes[u].addNode(v);
    }

    Node* getNext(int u) {
        return nodes[u].getHead();
    }
};

// Function to simulate dice roll
int rollDice() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 6);
    return dis(gen);
}

// Main function to play the game
void playGame() {
    Graph g(101);
    // Add edges for snakes and ladders
    g.addEdge(14, 7);
    g.addEdge(17, 4);
    g.addEdge(31, 14);
    g.addEdge(35, 22);
    g.addEdge(38, 20);
    g.addEdge(49, 11);
    g.addEdge(54, 19);
    g.addEdge(62, 33);
    g.addEdge(64, 36);
    g.addEdge(87, 24);
    g.addEdge(93, 73);
    g.addEdge(95, 75);
    g.addEdge(98, 78);

    // Get number of players
    int numPlayers;
    cout << "Enter number of players: ";
    cin >> numPlayers;

    // Initialize player positions
    vector<int> playerPositions(numPlayers, 0);

    // Get player names
    vector<string> playerNames(numPlayers);
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter name for Player " << i + 1 << ": ";
        cin >> playerNames[i];
    }

    // Game loop
    int currentPlayer = 0;
    while (true) {
        cout << playerNames[currentPlayer] << "'s turn. Press Enter to roll the dice.";
        cin.get(); // Wait for the user to press Enter
        int diceValue = rollDice();
        cout << playerNames[currentPlayer] << " rolled a " << diceValue << endl;
        int& currentPlayerPos = playerPositions[currentPlayer];
        int newPos = currentPlayerPos + diceValue;
        if (newPos <= 100) {
            Node* nextNode = g.getNext(newPos);
            if (nextNode) {
                newPos = nextNode->val;
                cout << playerNames[currentPlayer] << " was eaten by a snake! Moved to " << newPos << endl;
            }
            currentPlayerPos = newPos;
            cout << playerNames[currentPlayer] << " moved to " << newPos << endl;
            if (newPos == 100) {
                cout << "Congratulations, " << playerNames[currentPlayer] << " wins!" << endl;
                break;
            }
        }
        currentPlayer = (currentPlayer + 1) % numPlayers; // Switch players
    }
}

int main() {
    playGame();
    return 0;
}

🔥 Complete Function Breakdown of the Movie Ticket Booking System (C++)
Below is a detailed explanation of every function in your project, explaining its purpose, how it works, and its role in the system.

🔷 1. Movie Class Functions
Movie Constructor
cpp
Copy
Edit
Movie(string name, vector<string> showTimings) {
    this->name = name;
    this->showTimings = showTimings;
}
📌 Purpose: Initializes a Movie object with a name and available show timings.

🔹 Parameters:

name → Name of the movie.
showTimings → List of available show times.
🔹 How it Works:

Uses this->name = name; to assign the provided name to the object's attribute.
Uses this->showTimings = showTimings; to store the available timings.
🔹 Role: When a movie is created in the system, this function ensures that its details are stored correctly.

🔷 2. Ticket Class Functions
Ticket Constructor
cpp
Copy
Edit
Ticket(string customerName, string phoneNumber, int seatNumber) {
    this->customerName = customerName;
    this->phoneNumber = phoneNumber;
    this->seatNumber = seatNumber;
}
📌 Purpose: Initializes a Ticket object with customer details and seat number.

🔹 Parameters:

customerName → The name of the person booking the ticket.
phoneNumber → The contact number of the person.
seatNumber → The seat number booked.
🔹 How it Works:

Assigns the given values to the object's variables.
🔹 Role: Every time a user books a ticket, this function creates a new ticket with customer details.

🔷 3. Movie Sorting Function
compareMoviesByName
cpp
Copy
Edit
bool compareMoviesByName(const Movie* a, const Movie* b) {
    return a->name < b->name;
}
📌 Purpose: Helps sort movies alphabetically.

🔹 Parameters:

a → First movie.
b → Second movie.
🔹 How it Works:

Uses a->name < b->name; to compare movie names.
Returns true if a comes before b alphabetically.
🔹 Role: Used in sortMoviesByName() to organize movies from A to Z.

🔷 4. Node Class Functions
Node Constructor
cpp
Copy
Edit
Node(Ticket* ticket) {
    this->ticket = ticket;
    this->next = nullptr;
}
📌 Purpose: Creates a linked list node containing a Ticket object.

🔹 Parameters:

ticket → A pointer to a Ticket object.
🔹 How it Works:

Stores the ticket inside the node.
Sets next = nullptr, meaning it's the last node (for now).
🔹 Role: Helps maintain a linked list of booked tickets.

🔷 5. TicketList Class Functions
TicketList Constructor
cpp
Copy
Edit
TicketList() {
    head = nullptr;
}
📌 Purpose: Initializes the linked list with no tickets.

🔹 How it Works:

Sets head = nullptr;, meaning the list is empty at first.
🔹 Role: This function ensures a fresh start for the ticket list.

addTicket
cpp
Copy
Edit
void addTicket(Ticket* ticket) {
    Node* newNode = new Node(ticket);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
📌 Purpose: Adds a new ticket to the linked list.

🔹 Parameters:

ticket → The ticket being booked.
🔹 How it Works:

Creates a new node containing the ticket.
If the list is empty, the new ticket becomes the first node.
Otherwise, it traverses the list to find the last ticket and adds the new ticket at the end.
🔹 Role: Stores all tickets in a linked list.

🔷 6. MovieTicketBookingSystem Class Functions
addMovie
cpp
Copy
Edit
void addMovie(Movie* movie) {
    movies.push_back(movie);
}
📌 Purpose: Adds a new movie to the system.

🔹 Parameters:

movie → Pointer to a Movie object.
🔹 How it Works:

Uses push_back(movie); to add the movie to the list.
🔹 Role: Expands the movie selection as new movies are added.

sortMoviesByName
cpp
Copy
Edit
void sortMoviesByName() {
    sort(movies.begin(), movies.end(), compareMoviesByName);
}
📌 Purpose: Sorts movies alphabetically.

🔹 How it Works:

Uses sort() with the compareMoviesByName function.
🔹 Role: Makes the movie list organized for users.

getMovies
cpp
Copy
Edit
vector<Movie*> getMovies() {
    return movies;
}
📌 Purpose: Returns the list of movies.

🔹 How it Works:

Simply returns the movies vector.
🔹 Role: Helps display available movies.

bookTicket
cpp
Copy
Edit
void bookTicket(string customerName, string phoneNumber, int seatNumber) {
    Ticket* ticket = new Ticket(customerName, phoneNumber, seatNumber);
    ticketQueue.push(ticket);
}
📌 Purpose: Books a new ticket.

🔹 Parameters:

customerName → Customer's name.
phoneNumber → Contact number.
seatNumber → The seat number.
🔹 How it Works:

Creates a new ticket.
Adds it to the queue.
🔹 Role: Handles the ticket booking process.

displayTickets
cpp
Copy
Edit
void displayTickets() {
    cout << "\nTickets Booked:\n";
    while (!ticketQueue.empty()) {
        Ticket* ticket = ticketQueue.front();
        cout << "Customer Name: " << ticket->customerName 
             << ", Phone Number: " << ticket->phoneNumber 
             << ", Seat Number: " << ticket->seatNumber << endl;
        ticketQueue.pop();
    }
}
📌 Purpose: Displays all booked tickets.

🔹 How it Works:

Loops through the queue and prints each ticket.
Removes the ticket from the queue after displaying.
🔹 Role: Shows customers their booked tickets.

🔷 7. Main Function Breakdown
Creating Movies
cpp
Copy
Edit
Movie* movie1 = new Movie("Movie1", {"10:00", "13:00", "16:00"});
👉 Creates Movie 1 with three show timings.

Adding Movies to the System
cpp
Copy
Edit
ticketBookingSystem.addMovie(movie1);
👉 Adds the movie to the system.

Menu System
cpp
Copy
Edit
do {
    cout << "<1> Pick a Movie and Timing";
    cout << "<2> Display Tickets";
    cout << "<3> Exit";
    cin >> choice;
👉 Keeps asking users for input.

Handling User Choices
cpp
Copy
Edit
case 1:
    cout << "Enter the movie number: ";
    cin >> movieChoice;
    cout << "Enter the timing number: ";
    cin >> timingChoice;
👉 Lets the user pick a movie and time.

cpp
Copy
Edit
case 2:
    ticketBookingSystem.displayTickets();
    break;
👉 Displays all booked tickets.


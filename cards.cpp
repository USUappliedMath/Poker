// using some STL algorithms and containters to define a deck of cards
// This code will eventually morph into our Poker game
#include <iostream>
#include <vector>
#include <algorithm> // needed for the algorithms
#include <cstdlib> // for srand
#include <ctime>

using namespace std;

// Check hand for three of a kind -- Ju
bool checkThree(vector<int> &hand)
{}

// Check hand for a Full House -- Jake
bool checkFullHouse(vector<int> &hand)
{}

// Check hand for a straight -- Sergio
bool checkStraight(vector<int> &hand)
{}

// Check hand for a flush -- Jon
bool checkFlush(vector<int> &hand)
{}

// Check hand for a straight flush -- Eric
bool checkStFlush(vector<int> &hand)
{}

// Check hand for Four of a kind -- Audrey
bool checkFour(vector<int> &hand)
{}

// Check hand for a single pair -- class
bool checkPair(vector<int> &hand)
{

	for( int ii=0; ii<hand.size(); ii++)
	{
		for(int jj=ii+1; jj<hand.size(); jj++)
		{
			if(hand[ii]/4 == hand[jj]/4)
			return true;
		}
	}
	return false;
}

// a function to print the contents of your hand of cards
void print_hand(vector<int> &hand)
{
	for(int ii=0; ii<5; ii++)
	{
		switch (hand[ii]/4)
		{
			case 1:
				cout << "A-";
				break;
			case 11:
				cout << "J-";
				break;
			case 12:
				cout << "Q-";
				break;
			case 13:
                cout << "K-";
                break;
            default:
                cout << hand[ii]/4 << "-";
            }

        switch (hand[ii]%4)
        {
            case 0:
                cout << "H ";
                break;
            case 1:
                cout << "D ";
                break;
            case 2:
                cout << "C ";
                break;
            case 3:
                cout << "S ";
                break;
            default:
                cout << "! ";
        }
    }
}

int main()
{
    srand ( unsigned ( time(0) ) );
    // set up a deck of cards as a vector of values from 4 - 55.
    // The face value of the card will be given by x/4, and the suit will
    // be given by x%4 with:
    // x%4=0 -> hearts,
    // x%4=1 -> diamonds
    // x%4=2 -> clubs
    // x%4=3 -> spades
    //
    // for example, if x=33, then x/4 = 8 and x%4 = 1 => card is 8 of diamonds
    // define the deck as a vector

    vector<int> deck;
    for(int ii=0; ii<52; ii++)
        deck.push_back(ii+4);

    // shuffle the deck using the STL random_shuffle algorithm
    random_shuffle(deck.begin(), deck.end());

    // define an iterator to keep track of where the "top" of the deck is
    vector<int>::iterator deckTop = deck.begin();

    // define a vector for use as a hand of cards
    vector<int> hand(5,0);

    // deal a hand using the STL copy function
    copy(deckTop,deckTop+5,hand.begin());
    deckTop += 5;

    // print out the cards
    cout << "You were dealt: ";
    print_hand(hand);
    cout << "\n\n";

    // use the STL sort algorithm
    cout << "Sorting the hand: ";
    sort(hand.begin(), hand.end());
    print_hand(hand);
    cout << "\n\n";

    // draw a new card
    string discard;
    int disVal = 0;
    cout << "Which card would you like to discard? (1-5)\n>";
    while(true)
    {
        cin >> discard;
				disVal = atoi(discard.c_str())-1;	// using the string method .c_str() to convert from a string object to an old style C string
        if( disVal<0 || disVal>4 || !isdigit(discard[0]) || discard.size() > 1)
        {
            cout << "Invalid selection: " << discard <<". ";
            cout << "Which card would you like to discard? (1-5)\n>";
            continue;
        }
        break;
    }

    // replace with the card at deckTop
    copy(deckTop,deckTop+1,hand.begin()+disVal);
    deckTop++;
    cout << "your new hand is: ";
    print_hand(hand);
    cout << "\n\n";

    if(checkPair(hand))
        cout << "You have a pair!\n";
    else
        cout << "No pair for you\n";

    // cin.gets() for running on Microsoft VS
		cout << "\n\nPress enter to quit\n\n";
    cin.get();
    cin.get();
    return 0;
 }

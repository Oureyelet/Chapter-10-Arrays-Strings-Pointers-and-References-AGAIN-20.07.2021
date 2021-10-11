#include <iostream>
#include <array>

namespace N{

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_Jack,
    rank_Queen,
    rank_King,
    rank_Ace,

    max_ranks
};

enum class CardSuit
{
    clubs,
    diamonds,
    hearts, 
    spades,

    max_suits
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};


void printCard(const Card& op)
{
    switch (op.rank)
    {
        case CardRank::rank_2:      std::cout << '2';    break;
        case CardRank::rank_3:      std::cout << '3';    break;
        case CardRank::rank_4:      std::cout << '4';    break;
        case CardRank::rank_5:      std::cout << '5';    break;
        case CardRank::rank_6:      std::cout << '6';    break;
        case CardRank::rank_7:      std::cout << '7';    break;
        case CardRank::rank_8:      std::cout << '8';    break;
        case CardRank::rank_9:      std::cout << '9';    break;
        case CardRank::rank_10:     std::cout << 'T';    break;
        case CardRank::rank_Jack:   std::cout << 'J';    break;
        case CardRank::rank_Queen:  std::cout << 'Q';    break;
        case CardRank::rank_King:   std::cout << 'K';    break;
        case CardRank::rank_Ace:    std::cout << 'A';    break;
        
        default:
            std::cout << '?';
            break;
    }

    switch (op.suit)
    {
        case CardSuit::clubs:       std::cout << 'C';    break;
        case CardSuit::diamonds:    std::cout << 'D';    break;
        case CardSuit::hearts:      std::cout << 'H';    break;
        case CardSuit::spades:      std::cout << 'S';    break;
        
        default:
            std::cout << '?';
            break;
    }
}

// We'll need these many more times, create an aliases.
using deck_t = std::array<Card, 52>;
using index_type = deck_t::size_type;

deck_t createDeck()
{
    deck_t deck{};

    // We could initialize each card individually, but that would be a pain.  Let's use a loop.

    index_type index{ 0 };

    for(int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
    {
        for(int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
        {
            deck[index].suit = static_cast<CardSuit>(suit);
            deck[index].rank = static_cast<CardRank>(rank);
            ++index;
        }
    }
   

    return deck;
}

void printDeck(const deck_t& dc)
{
    for(const auto& i : dc )
    {
        printCard(i);
        std::cout << ' ';
    }
    std::cout << std::endl;
}


}

int main()
{
    /*
    Let’s pretend we’re writing a card game.

    a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks 
    (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). 
    Those enumerators will not be used to index arrays.
    */

    /*
    b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.
    */

    /*
    c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and 
    suit as a 2-letter code (e.g. the jack of spades would print as JS).
    */
   
    /*
    d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize 
    it with one of each card. Do this in a function named createDeck and call createDeck from main. createDeck should 
    return the deck to main.
    */

    auto deck{ N::createDeck() };

    /*
    e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the cards in the deck. 
    Use a range-based for-loop. When you can printDeck with the deck you generated in the previous task, the output should be
    */

    N::printDeck(deck);

    /*
    f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle. 
    Update your main function to shuffle the deck and print out the shuffled deck.

    Reminder: Only seed your random number generator once.
    */

    



  

    return 0;
}   
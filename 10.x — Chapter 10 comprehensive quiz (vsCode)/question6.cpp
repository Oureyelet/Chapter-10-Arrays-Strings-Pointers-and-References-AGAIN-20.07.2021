#include <iostream>
#include <array>

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

void printCard(const Card&)
{
    switch (rank::)
    {
        case CardRank::rank_2:

            switch (Card::suit)
            {
            case CardSuit::clubs:
                std::cout << "C" << '\n';
                break;
            case CardSuit::diamonds:
                std::cout << "D" << '\n';
                break;
            case CardSuit::hearts:
                std::cout << "H" << '\n';
                break;
            case CardSuit::spades:
                std::cout << "S" << '\n';
                break;
            default:
                break;
            }
            
        break;
    
        default:
        break;
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

  

    return 0;
}   
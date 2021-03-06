#include <iostream>
#include <array>
#include <algorithm> // for std::shuffle
#include <random> // for  std::mt19937
#include <ctime>
#include <cassert> 
#include <vector>

namespace N
{
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

    struct Player
    {
        int score{};
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

    void shuffleDeck(deck_t& dc)
    {
        std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(dc.begin(), dc.end(), mt);
    }

    int getCardValue(const Card& op)
    {
        switch (op.rank)
        {
        case CardRank::rank_2:      return 2;
        case CardRank::rank_3:      return 3;   
        case CardRank::rank_4:      return 4;
        case CardRank::rank_5:      return 5;
        case CardRank::rank_6:      return 6;
        case CardRank::rank_7:      return 7;
        case CardRank::rank_8:      return 8;
        case CardRank::rank_9:      return 9;
        case CardRank::rank_10:     return 10;
        case CardRank::rank_Jack:   return 11;
        case CardRank::rank_Queen:  return 11;
        case CardRank::rank_King:   return 11;
        case CardRank::rank_Ace:    return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }

    }

    // Maximum score before losing.
    constexpr int max_score{ 21 };

    // Minimum score that the dealer has to have.
    constexpr int minimumDealerScore{ 17 };

    bool playerWantsHit()
    {
        while (true)
        {
            std::cout << "(h) to hit, or (s) to stand: ";

            char ch{};
            std::cin >> ch;

            switch (ch)
            {
            case 'h':
                return true;
            case 's':
                return false;
            }
        }
    }

    // Returns true if the player went bust. False otherwise.
    bool playerTurn(const deck_t& deck, index_type& nextCardIndex, Player& player)
    {
        while (true)
        {
            if (player.score > N::max_score)
            {
                // This can happen even before the player had a choice if they drew 2
                // aces.
                std::cout << "You busted!\n";
                return true;
            }
            else
            {
                if( playerWantsHit() )
                {
                    int cardValue{ N::getCardValue( deck.at(nextCardIndex++) ) };
                    player.score += cardValue;
                    std::cout << "You were dealt a " << cardValue << " and now have " << player.score << '\n';
                }
                else
                {
                    // The player didn't go bust.
                    return false;
                }
            }
        }
    }

    // Returns true if the dealer went bust. False otherwise.
    bool dealTurn(const deck_t& deck, index_type& nextCardIndex, Player& dealer)
    {
        while (dealer.score < minimumDealerScore)
        {
            int cardValue{ getCardValue( deck.at(nextCardIndex++) ) };
            dealer.score += cardValue;
            std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';
        }

        // If the dealer's score is too high, they went bust.
        if(dealer.score > max_score)
        {
            std::cout << "The dealer busted!\n";
            return true;
        }
        return false;
    }

    bool playBlackjack(const deck_t& deck)
    {
        // Index of the card that will be drawn next. This cannot overrun
        // the array, because a player will lose before all cards are used up.
        index_type nextCardIndex{ 0 };

        Player dealer{ getCardValue( deck.at(nextCardIndex++) ) };

        // The dealer's card is face up, the player can see it.
        std::cout << "The dealer is showing: " << dealer.score << '\n';

        // Create the player and give them 2 cards.
        Player player{ getCardValue(deck.at(nextCardIndex)) + getCardValue(deck.at(nextCardIndex+1)) };
        nextCardIndex += 2;

        std::cout << "You have: " << player.score << '\n';

        if(playerTurn(deck, nextCardIndex, player))
        {
            // The player went bust.
            return false;
        }

        if(dealTurn(deck, nextCardIndex, dealer))
        {
            // The dealer went bust, the player wins.
            return true;
        }

        return ( player.score > dealer.score );
    }
}



int main()
{
    /*
    Let???s pretend we???re writing a card game.

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

    //auto deck{ N::createDeck() };

    /*
    e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the cards in the deck. 
    Use a range-based for-loop. When you can printDeck with the deck you generated in the previous task, the output should be
    */

    //N::printDeck(deck);

    /*
    f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle. 
    Update your main function to shuffle the deck and print out the shuffled deck.

    Reminder: Only seed your random number generator once.
    */

    //N::shuffleDeck(deck);

    //N::printDeck(deck);

    /*
    g) Write a function named getCardValue() that returns the value of a Card 
    (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Question #7" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Alright, challenge time! Let???s write a simplified version of Blackjack. If you???re not already familiar with Blackjack, 
    the Wikipedia article for Blackjack has a summary.

    Here are the rules for our version of Blackjack:

        The dealer gets one card to start (in real life, the dealer gets two, but one is face down so it doesn???t matter at 
        this point).
        The player gets two cards to start.
        The player goes first.
        A player can repeatedly ???hit??? or ???stand???.
        If the player ???stands???, their turn is over, and their score is calculated based on the cards they have been dealt.
        If the player ???hits???, they get another card and the value of that card is added to their total score.
        An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, we???ll count it as 
        an 11 here.
        If the player goes over a score of 21, they bust and lose immediately.
        The dealer goes after the player.
        The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
        If the dealer goes over a score of 21, they bust and the player wins immediately.
        Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses (we???ll 
        consider ties as dealer wins for simplicity).

    In our simplified version of Blackjack, we???re not going to keep track of which specific cards the player and the dealer 
    have been dealt. We???ll only track the sum of the values of the cards they have been dealt for the player and dealer. 
    This keeps things simpler.

    Start with the code you wrote in quiz #6. Create a function named playBlackjack(). This function should:

        Accept a shuffled deck of cards as a parameter.
        Implement Blackjack as defined above.
        Returns true if the player won, and false if they lost. 

    Also write a main() function to play a single game of Blackjack.


    Once you???ve solved the quiz, have a look at some of the most common mistakes:


    b) Extra credit: Critical thinking time: Describe how you could modify the above program to handle the case where aces can 
    be equal to 1 or 11.

    It???s important to note that we???re only keeping track of the sum of the cards, not which specific cards the user has.


    c) In actual blackjack, if the player and dealer have the same score (and the player has not gone bust), the result is a 
    tie and neither wins. Describe how you???d modify the above program to account for this.
    */
    auto deck{ N::createDeck() };

    N::shuffleDeck(deck);

    if(N::playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}   
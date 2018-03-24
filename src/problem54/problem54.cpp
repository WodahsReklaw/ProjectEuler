/* In the card game poker, a hand consists of five cards and are ranked, from
  lowest to highest, in the following way:

  High Card: Highest value card.
  One Pair: Two cards of the same value.
  Two Pairs: Two different pairs.
  Three of a Kind: Three cards of the same value.
  Straight: All cards are consecutive values.
  Flush: All cards of the same suit.
  Full House: Three of a kind and a pair.
  Four of a Kind: Four cards of the same value.
  Straight Flush: All cards are consecutive values of same suit.
  Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
  The cards are valued in the order:
  2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

  If two players have the same ranked hands then the rank made up of the highest
  value wins; for example, a pair of eights beats a pair of fives (see example 1
  below). But if two ranks tie, for example, both players have a pair of queens,
  then highest cards in each hand are compared (see example 4 below); if the
  highest cards tie then the next highest cards are compared, and so on.

  Consider the following five hands dealt to two players:

  Hand Player 1 Player 2 Winner
  1 5H 5C 6S 7S KD
  Pair of Fives
  2C 3S 8S 8D TD
  Pair of Eights
  Player 2
  2 5D 8C 9S JS AC
  Highest card Ace
  2C 5C 7D 8S QH
  Highest card Queen
  Player 1
  3 2D 9C AS AH AC
  Three Aces
  3D 6D 7D TD QD
  Flush with Diamonds
  Player 2
  4 4D 6S 9H QH QC
  Pair of Queens
  Highest card Nine
  3D 6D 7H QD QS
  Pair of Queens
  Highest card Seven
  Player 1
  5 2H 2D 4C 4D 4S
  Full House
  With Three Fours
  3C 3D 3S 9S 9D
  Full House
  with Three Threes
  Player 1
  The file, poker.txt, contains one-thousand random hands dealt to two players.
  Each line of the file contains ten cards (separated by a single space): the
  first five are Player 1's cards and the last five are Player 2's cards. You
  can assume that all hands are valid (no invalid characters or repeated cards),
  each player's hand is in no specific order, and in each hand there is a clear
  winner.

  How many hands does Player 1 win?
 */

#include <tuple>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::tuple;
using std::size_t;
using std::map;
using std::unordered_set;
using std::vector;

typedef unordered_map<char, unsigned> hist_t;

enum HandType {
  HighCard, OnePair, TwoPair, ThreeOfAKind, Straight,
  Flush, FullHouse, FourOfAKind, StraightFlush, RoyalFlush
};

const vector<char> RANKS{'2', '3', '4', '5', '6', '7', '8'
      '9', '10', 'J', 'Q', 'K', 'A'};
const unordered_map<char, int>RANK_MAP{
  {'2', 0},
  {'3', 1},
  {'4', 2},
  {'5', 3},
  {'6', 4},
  {'7', 5},
  {'8', 6},
  {'9', 7},
  {'10', 8},
  {'J', 9},
  {'Q', 10},
  {'K', 11},
  {'A', 12}
}
const vector<char> SUITS{'D', 'C', 'H', 'S'};

const unsigned HAND_SIZE = 5;

// Generate a set of all possible straights.
const unordered_set<hist_t> Straights() {
  unordered_set<hist_t> straight_set;
  for (auto itr = RANKS.begin(); itr + HAND_SIZE != RANKS.end(); ++i) {
    hist_t entry;
    for (auto j_itr = itr; j_itr != itr + HAND_SIZE; ++j_itr) {
      entry[*j_itr] = 1;
    }
    straight_set.emplace(entry);
  }
  return straight_set;
}

// Generate a set of all possible flushes.
const unordered_set<hist_t> Flushes() {
  unordered_set<hist_t> flush_set;
  for (const auto& suit : SUITS) {
    flush_set.emplace({suit, 4});
  }
  return flush_set;
}

class Card {
  char rank;
  char suit;
 public:
  char getRank() const { return rank; }
  char getSuit() const { return suit; }
  Card(const char& t_rank, const char& t_suit) : rank(t_rank), suit(t_suit) {};
};

// Main class for classifying the value of Cards given.
class CardHistogram{
 private:
  hist_t rank_histogram;
  hist_t suit_histogram;
  std::pair<unsigned, char>  most_freq;
  std::pair<unsigned, char>  sec_most_freq;
  static const unordered_set<hist_t> straight_lut;
  static const unordered_set<hist_t> flush_lut;
  HandType hand_type;
 public:
  CardHistogram(const vector<Card>& cards);
  HandType getType();
  hist_t getRankHist() const { return rank_histogram; }
  hist_t getSuitHist() const { return suit_histogram; }
  HandType getHandType() const { return hand_type; }
  std::pair<unsigned, char> getMostFreq() const {return most_freq;}
  std::pair<unsigned, char> getSecMostFreq() const {return sec_most_freq;}
};

const unordered_set<hist_t> CardHistogram::straight_lut(Straights());
const unordered_set<hist_t> CardHistogram::flush_lut();

HandType CardHistogram::getType() {
  const bool is_straight = (straight_lut.find(rank_histogram)
                            != straight_table.end());
  const bool is_flush = (flush_lut.find(suit_histogram)
                         != flush_lut.end());

  if (is_straight and is_flush){
    return (rank_histogram[RANK_MAP.at('A')]) ?
        HandType::RoyalFlush : HandType::StraightFlush;
  }
  auto r_it = rank_histogram.rbegin();
  if (std::get<0>most_freq == 4) {
    return HandType::FourOfAKind;
  }
  if (std::get<0>most_freq == 3) {
    return (std::get<0>sec_most_freq == 2) ?
        HandType::FullHouse : HandType::ThreeOfAKind;
  }
  if (is_flush){
    return HandType::Flush;
  }
  if (is_straight) {
    return HandType::Straight;
  }
  if (std::get<0>most_freq == 2) {
    return (std::get<0>sec_most_freq == 2) ? HandType::TwoPair : HandType::Pair;
  }
  return HandType::HighCard;
}

CardHistogram::CardHistogram(const vector<Card>& cards)
    : rank_histogram(RANKS.size(), 0), suit_histogram(SUITS.size(), 0) {
  for (const auto& c : cards) {
    ++rank_histogram[c.getRank()];
    ++suit_histogram[c.getSuit()];
  }
  map<unsigned, char> freq_map;
  for (const auto& e : rank_histogram) {
    freq_map.emplace(std::get<1>e, std::get<0>e);
  }
  most_freq = *freq_map.rbegin();
  sec_most_feq = *(freq_map.rbegin() + 1);
  hand_type = getType();
}


class Hand {
 private:
  vector<Card> cards;
  HandType hand_type;
  CardHistogram card_hist;
 public:
  int compare(const Hand& h);
  Hand(vector<Card> t_cards);
};

int Hand::highestCard(const Hand& h) {
  while ()
}

Hand::Hand(vector<Card> t_cards) : cards(t_cards), card_hist(t_cards) { };

Hand::compare(const Hand& h) {
  if (h.card_hist.getHandType() < card_hist.getHandType) {
    return 1;
  }
  if (h.card_hist.getHandType() > card_hist.getHandType) {
    return -1;
  }
  HandType hand_t = card_hist.getHandType();
  if (hand_t == HandType::HighCard or
      hand_t == HandType::Straight or
      hand_t == HandType::Flush or
      hand_t == HandType::StraightFlush) {
    // Get the absolute high card
  }
  if (hand_t == HandType::Pair or
      hand_t == HandType::ThreeOfAKind or
      hand_t == HandType::FourOfAKind) {
    // Get best most_freq_card
    // Else get absolute high card
  }
  if (hand_t == HandType::TwoPair or
      hand_t == HandType::FullHouse) {
    // Get best most_freq_pair
    // Else get best second pair
    // Else get best high card
  }
}

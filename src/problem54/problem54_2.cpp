#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

const unordered_map<char, unsigned> RANK_MAP {
  {'2', 0},
  {'3', 1},
  {'4', 2},
  {'5', 3},
  {'6', 4},
  {'7', 5},
  {'8', 6},
  {'9', 7},
  {'T', 8}, // Short for 10.
  {'J', 9},
  {'Q', 10},
  {'K', 11},
  {'A', 12}
};

// RF, SF, FK, FH, FL, ST, TK, TP, OP, HC
// For FK, FH, TK, TP, OP all need to track pair_values.
enum class HandEnum{
  HC, OP, TP, TK, ST, FL, FH, FK, SF, RF
};

std::ostream& operator<< (std::ostream& os, const HandEnum& hand) {
  switch (hand) {
    case HandEnum::HC: return os <<  "HC";
    case HandEnum::OP: return os <<  "OP";
    case HandEnum::TP: return os <<  "TP";
    case HandEnum::TK: return os <<  "TK";
    case HandEnum::ST: return os <<  "ST";
    case HandEnum::FL: return os <<  "FL";
    case HandEnum::FH: return os <<  "FH";
    case HandEnum::FK: return os <<  "FK";
    case HandEnum::SF: return os <<  "SF";
    case HandEnum::RF: return os <<  "RF";
  }
  return os << static_cast<unsigned>(hand);
}

class HandType {
 private:
  HandEnum hand_class;
  char first_rank;
  char second_rank;
 public:
  int compare(const HandType& ht);
  HandType(HandEnum cls) : hand_class(cls), first_rank(0), second_rank(0) {} ;
  HandType(HandEnum cls, char fv) : hand_class(cls),
                                    first_rank(fv), second_rank(0) {} ;
  HandType(HandEnum cls, char fv, char sv) :
      hand_class(cls), first_rank(fv), second_rank(sv) {} ;
  friend std::ostream& operator<<(std::ostream&, const HandType&);
};


std::ostream& operator<<(std::ostream& os, const HandType& ht) {
  os << ht.hand_class;
  if (ht.first_rank) {
    os << " " << ht.first_rank;
  }
  if (ht.second_rank) {
    os << " " << ht.second_rank;
  }
  return os;
}


int HandType::compare(const HandType& ht) {
  if (hand_class > ht.hand_class) {
    return 1;
  } else if (hand_class < ht.hand_class) {
    return -1;
  }
  if (first_rank) {
    if (RANK_MAP.at(first_rank) > RANK_MAP.at(ht.first_rank)) {
      return 1;
    } else if (RANK_MAP.at(first_rank) < RANK_MAP.at(ht.first_rank)) {
      return -1;
    }
  }
  if (second_rank) {
    if (RANK_MAP.at(second_rank) > RANK_MAP.at(ht.second_rank)) {
      return 1;
    } else if (RANK_MAP.at(second_rank) < RANK_MAP.at(ht.second_rank)) {
      return -1;
    }
  }
  return 0;
}

struct Card{
  char rank;
  char suit;
  Card(char t_rank, char t_suit) : rank(t_rank), suit(t_suit) {}
};

class HandValue{
 private:
  bool is_flush;
  bool is_straight;
  char one_pair;
  char two_pair;
  char tok;
  char fok;
  vector<unsigned> hist;
  vector<unsigned> card_rank_vals;
  HandType hand_type;
  void setHandType();
 public:
  HandValue(const vector<Card>& cards);
  int compare(const HandValue& t_hv);
  HandType getHandType() const {return hand_type;};
};

void HandValue::setHandType() {

  // RF and SF
  if (is_flush and is_straight) {
    if (*hist.rbegin()) {
      hand_type = HandType(HandEnum::RF);
    } else {
      hand_type = HandType(HandEnum::SF);
    }
    return;
  }

  // FK
  if (fok) {
    hand_type = HandType(HandEnum::FK, fok);
    return;
  }

  // FH
  if (tok and one_pair) {
    hand_type = HandType(HandEnum::FH, tok, one_pair);
    return;
  }

  // FL
  if (is_flush) {
    hand_type = HandType(HandEnum::FL);
    return;
  }

  // ST
  if (is_straight) {
    hand_type = HandType(HandEnum::ST);
    return;
  }
  // TK
  if (tok) {
    hand_type = HandType(HandEnum::TK, tok);
    return;
  }

  // TP
  if (two_pair) {
    hand_type = HandType(HandEnum::TP, one_pair, two_pair);
    return;
  }

  if (one_pair) {
    // No other pairs possible or found.
    hand_type = HandType(HandEnum::OP, one_pair);
    return;
  }

  // HC
  hand_type = HandType(HandEnum::HC);
  return;
}

HandValue::HandValue(const vector<Card>& cards) :
    hist(RANK_MAP.size(), 0), hand_type(HandEnum::HC){

  is_flush = true;
  one_pair = 0;
  two_pair = 0;
  tok = 0;
  fok = 0;

  const auto first_suit = cards[0].suit;
  for (const auto& card : cards) {
    ++hist[RANK_MAP.at(card.rank)];
    card_rank_vals.push_back(RANK_MAP.at(card.rank));
    if(card.suit != first_suit) {
      is_flush = false;
    }
    const unsigned& this_card_count = hist[RANK_MAP.at(card.rank)];
    if (this_card_count == 2) {
      if (one_pair) {
        two_pair = card.rank;
      } else {
        one_pair = card.rank;
      }
    } else if (this_card_count == 3) {
      tok = card.rank;
      if (one_pair == card.rank) {
        one_pair = two_pair;
        two_pair = 0;
      } else if (two_pair == card.rank) {
        two_pair = 0;
      }
    } else if (this_card_count == 4) {
      fok = card.rank;
      tok = 0;
    }
  }
  std::sort(card_rank_vals.begin(), card_rank_vals.end());

  unsigned max_run = 0;
  unsigned current_run = 0;
  is_straight = false;
  for (const auto& e : hist){
    if (e){
      ++current_run;
    } else {
      current_run = 0;
    }
    max_run = std::max(max_run, current_run);
  }
  if (max_run == 5) {
    std::cout << "straight?" << std:: endl;
    is_straight = true;
  }
  this->setHandType();
}

int HandValue::compare(const HandValue& t_hv) {
  int cmp_type = hand_type.compare(t_hv.hand_type);
  if (cmp_type) {
    return cmp_type;
  }
  size_t i = card_rank_vals.size() - 1;
  while (true){
    if (card_rank_vals[i] != t_hv.card_rank_vals[i]) {
      return (int)card_rank_vals[i] - (int)t_hv.card_rank_vals[i];
    }
    if (!i) {
      return 0;
    }
    i--;
  }
  return 0;
}

void PrintCards(vector<Card> cards) {
  for (const auto& c : cards) {
    std::cout << c.rank << c.suit << " ";
  }
}

int main() {
  // Open the file handle.
  string card_string;
  int count = 0;
  while (cin >> card_string) {
    vector<Card> input_cards;
    input_cards.push_back(Card(card_string[0], card_string[1]));
    for (int i = 0; i < 4; ++i){
      cin >> card_string;
      input_cards.push_back(Card(card_string[0], card_string[1]));
    }
    HandValue p1_hand(input_cards);
    std::cout << "Player 1: ";
    PrintCards(input_cards);
    std::cout << " " <<  p1_hand.getHandType() << "\n";
    input_cards.clear();
    for (int i = 0; i < 5; ++i){
      cin >> card_string;
      input_cards.push_back(Card(card_string[0], card_string[1]));
    }
    HandValue p2_hand(input_cards);
    std::cout << "Player 2: ";
    PrintCards(input_cards);
    std::cout << " " <<  p2_hand.getHandType() << "\n";
    std::cout << "P1 value - P2 value = " << p1_hand.compare(p2_hand) << "\n";
    if (p1_hand.compare(p2_hand) > 0) {
      ++count;
    }
  }
  std::cout << "\nCount: " <<  count << std::endl;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define RANK_LEN 13
#define SUIT_LEN 4
#define HAND_LEN 5

int find(char arr[], int size, int obj);
int find_int(int arr[], int size, int obj);
char* get_rank_name(char rank_abbr);
char* get_suit_name(char suit_abbr);

char ranks[RANK_LEN] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'};
char suits[SUIT_LEN] = {'S', 'C', 'D', 'H'};

char poker_hand[5][2] = {0};

int main(void) {
    
    //Inputting Cards
    int i = 0;
    while (i < 5) {
        char rank, suit;
        printf("Enter card <Rank><Suit>: ");
        scanf(" %c%c", &rank, &suit);
        
        if (find(ranks, RANK_LEN, rank) == -1 || find(suits, SUIT_LEN, suit) == -1) {
            printf("Not a valid card type. Retry.\n");
            continue;
        }
        
        for (int j = 0; j < i; j++) {
            if (poker_hand[j][0] == rank && poker_hand[j][1] == suit) {
                printf("%c%c already in your hand. Retry.\n", rank, suit);
                continue;
            }
        }

        poker_hand[i][0] = rank;
        poker_hand[i][1]= suit;
        i++;
    }

    //Printing Poker Hand
    
    for (int i = 0; i < HAND_LEN; i++) {
        if (i == 0) printf("Your Hand: ");
        printf("%s of %s, ", get_rank_name(poker_hand[i][0]), get_suit_name(poker_hand[i][1]) );
        if (i == HAND_LEN - 1) printf("\n");
    }
    

    //Calculating Hand Type
    int rank_counts[RANK_LEN] = {0};
    int suit_counts[SUIT_LEN] = {0};

    for (int i = 0; i < HAND_LEN; i++) {
        rank_counts[ find(ranks, RANK_LEN, poker_hand[i][0]) ] ++;
        suit_counts[ find(suits, SUIT_LEN, poker_hand[i][1]) ] ++;
    }

    bool is_flush = (find_int(suit_counts, SUIT_LEN, 5) != -1);
    bool is_straight = false;

    //Calculate Straight
    int run_count = -1;
    for (int i = 0; i < RANK_LEN + 1; i++) {
        if (run_count == -1 && rank_counts[i % RANK_LEN] == 1) {
            run_count = 0;
        } 

        if (rank_counts[i % RANK_LEN] == 1) {
            run_count++;
            if (run_count == 5) {
                is_straight = true;
                break;
            } 
        } else if (run_count > -1) {
            if (i == 1) run_count = -1;
            else break; 
        }
    }

    if (is_straight && is_flush) {
        printf("Straight Flush! \n");
    } else if (find_int(rank_counts, RANK_LEN, 4) != -1 ) {
        printf("Four of a Kind! \n");
    } else if (find_int(rank_counts, RANK_LEN, 3) != -1  && find_int(rank_counts, RANK_LEN, 2) != -1  ) {
        printf("Full House! \n");
    } else if (is_flush) {
        printf("Flush! \n");
    } else if (is_straight) {
        printf("Straight! \n");
    } else if (find_int(rank_counts, RANK_LEN, 3) != -1 ) {
        printf("Three of a Kind! \n");
    } else if (find_int(rank_counts, RANK_LEN, 2) != -1 ) {
        printf("Pair! \n");
    } else {
        printf("High Card! \n");
    }
    


    /*
    for (int i = 0; i < RANK_LEN; i++) {
        printf("%c: %d, ", ranks[i], rank_counts[i]);
        if (i == RANK_LEN - 1) printf("\n");
    }

    for (int i = 0; i < SUIT_LEN; i++) {
        printf("%c: %d, ", suits[i], suit_counts[i]);
        if (i == SUIT_LEN - 1) printf("\n");
    }
    */
    return 0;
}

int find(char arr[], int size, int obj) {
    
    for (int i = 0; i < size; i++)  {
        if (arr[i] == obj) {return i; }    
    } 
    return -1;
}

int find_int(int arr[], int size, int obj) {
    
    for (int i = 0; i < size; i++)  {
        if (arr[i] == obj) {return i; }    
    } 
    return -1;
}

char* get_rank_name(char rank_abbr) {
    switch (rank_abbr) {
    case 'A':
        return "Ace";
    case 'X':
        return "10";
    case 'J':
        return "Jack";
    case 'Q':
        return "Queen";
    case 'K':
        return "King";
    
    default:
        char *ptr = malloc(2*sizeof(char));
        ptr[0] = rank_abbr;
        ptr[1] = '\0';

        return ptr;
    }
}

char* get_suit_name(char suit_abbr) {
    switch (suit_abbr) {
    case 'S':
        return "Spades";
    case 'H':
        return "Hearts";
    case 'C':
        return "Clubs";
    case 'D':
        return "Diamonds";
    
    default:
        return "Error";
    }
}
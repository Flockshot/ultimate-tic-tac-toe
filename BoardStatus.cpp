/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "BoardStatus.h"

const char* boardStatusInText(BoardStatus status)
{
    switch (status)
    {
        case DRAW:
            return "Draw";
            break;
        case P1_WON:
            return "P1 Won";
            break;
        case P2_WON:
            return "P2 Won";
            break;
        default:
            return "Ongoing";
            break;
    }
}
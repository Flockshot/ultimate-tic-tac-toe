/* Muhammad Somaan 2528404
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */
#include "Game.h"

int main()
{
    Player* p1 = new Player("Zekican", 'X');
    Player* p2 = new Player("Yagmur", 'O');
    
    Game g1('-', p1, p2);

    g1.start();
    



    delete p1;
    delete p2;

    return 0;
}



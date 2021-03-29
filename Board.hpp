#include "Direction.hpp"
using ariel::Direction;
#include <string>
using namespace std;
#include <map>


namespace ariel{

    class Board
    {
    private:
        /* data */
        typedef pair <unsigned int,unsigned int> palce; //Saves the ad coordinate
        map < palce, char> msg_board; // our message board
        
    public:
        Board(/* args */);

        void post(unsigned int row,unsigned int colum,Direction direction,string st);
        string read(unsigned int row,unsigned int colum,Direction direction,unsigned int len);
        void show();

    };
    

}
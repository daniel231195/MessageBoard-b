
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Direction.hpp"
#include "Board.hpp"

using ariel::Direction;
using namespace std;

namespace ariel{
    Board::Board(){}
   //The reading function
    string Board::read(unsigned int row,unsigned int colum, Direction direction,unsigned int len){
        string msg; //A variable that keeps the string
        char sign='_';

        //A loop that passes over the position we were given and reads the word

        for (size_t i = 0; i < len; i++)
        {           
          if(msg_board[make_pair(row,colum)] > 0){ //Check that the signal in the ad according to the coordinate is correct
              sign=msg_board[make_pair(row,colum)];
          }
          else{
                sign='_'; //A place without a signal
            }
            msg+=sign;
            if(Direction::Horizontal==direction){  //Check the direction you need to go
                colum++;
            }
            else{
                row++; 
            }   
        }       
        return msg;
    }
    //A function that infects the ad
    void Board::post(unsigned int row,unsigned int colum,Direction direction,string st){
        for (size_t i = 0; i < st.length(); i++)
        {
            msg_board[make_pair(row,colum)]=st.at(i); //Reaching the coordinate you want and pasting the signal
            
            //Check the direction you need to go
            if(Direction::Horizontal==direction){
                colum++;
            }
            else{
                row++;    
            }
        }
     cout<< "post" <<endl;
    }
//Function for displaying the board
    void Board::show(){
        unsigned int col,i=0;
        for(auto elem : msg_board){  // An iterator that goes over the locations of the board
            
           // First condition for passing on the first element
            if(i==0){
                std::cout << elem.second<<endl;
                i++;
                col=elem.first.first; // Save the previous position (vertical) to know when to go down a line
            }
            else{
                if(col != elem.first.first){ //If we are not in the same line we should go down a line and then print
                    std::cout<<endl;
                    std::cout << elem.second;
                    col=elem.first.first;
                }
                else{
                   std::cout << elem.second; //Just printing
                }         
            }    
        }
        cout<<endl;
        cout<< "show" <<endl;
    }
}

#include <iostream>
#include <vector>

using namespace std;

vector <vector <string>> maze;

int row = 0;
int column = 2; 

void method1(string ask1) {
  if (ask1 != "UP" && ask1 != "DOWN"&& ask1 != "LEFT" && ask1 != "RIGHT") {
    throw logic_error ("YOU CANNOT CHOOSE THAT");
  }

  int new_row;
  int new_column;

  if(ask1 == "UP"){
    new_row = row - 1;
    new_column = column;
  }
  if(ask1 == "DOWN"){
    new_row = row + 1;
    new_column = column;
  }
  if(ask1 == "LEFT"){
    new_row = row;
    new_column = column - 1;
  }
  if(ask1 == "RIGHT"){
    new_row = row;
    new_column = column + 1;
  }
  
  if(new_row < 0 || new_row > 20){
    throw logic_error ("YOU CANNOT GO OUT OF BOUNDS");
  }
  if(new_column < 0 || new_column > 7){
    throw logic_error ("YOU CANNOT GO OUT OF BOUNDS");
  }
  if(maze[new_row][new_column] == "🌫️"){
    throw logic_error ("YOU CANNOT THROUGH WALLS");
  }
  
  row = new_row;
  column = new_column;
}

int main () { 
  maze = {
  {"🌫️","🌫️","🫄","🌫️","🌫️","🌫️","🌫️"},
  {"🌫️","🌫️",".","🌫️","🌫️","🌫️","🌫️"},
  {".",".",".","🌫️","🌫️","🌫️","🌫️"},
  {".","🌫️",".",".",".",".","🌫️"},
  {".","🌫️","🌫️","🌫️","🌫️",".","🌫️"},
  {".",".",".",".",".",".","🌫️"},
  {"🌫️",".","🌫️","🌫️",".",".","🌫️"},
  {"🌫️",".",".","🌫️",".",".","🌫️"},
  {"🌫️",".",".","🌫️",".",".","🌫️"},
  {"🌫️",".",".","🌫️","🌫️",".","🌫️"},
  {"🌫️",".",".",".",".",".","🌫️"},
  {"🌫️",".","🌫️","🌫️","🌫️",".","🌫️"},
  {"🌫️",".",".",".",".",".","🌫️"},
  {"🌫️","🌫️","🌫️","🌫️","🌫️",".","🌫️"},
  {"🌫️","🌫️","🌫️","🌫️","🌫️",".","🌫️"},
  {"🌫️","🌫️","🌫️","🌫️","🌫️",".","🌫️"},
  {"🌫️","🌫️",".",".",".",".","🌫️"},
  {"🌫️","🌫️",".","🌫️","🌫️",".","🌫️"},
  {"🌫️","🌫️",".","🌫️","🌫️",".","🌫️"},
  {"🌫️","🌫️",".","🌫️","🌫️",".","🌫️"},
  {"🌫️","🌫️","🫃","🌫️","🌫️",".","🌫️"}
  };
  
  while(true){
    cout << "\n";
    for(int i = 0; i < maze.size(); i++){
      for(int j = 0; j < maze[i].size(); j++){
        cout << maze[i][j] << " ";
      }
      cout << "\n";
    }
    
    string ask1;
    cout << "\nUP\nDOWN\nLEFT\nRIGHT\n";
    cin >> ask1;
    
    try { 
      int previous_row = row;
      int previous_column = column;
      
      method1 (ask1);
      
      maze[previous_row][previous_column] = ".";
      maze[row][column] = "🫄";
    } catch (logic_error e) {
      cout << e.what ( ) << "\n";
    }
    
    if(row == 20 && column == 2){
      break;
    }
  }

}

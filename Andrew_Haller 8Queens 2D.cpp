#include <iostream>
using namespace std;
int main() {
  int b[8][8] = {};
  int r, c = 0;
  int S = 0;

  b[0][0] = 1; // Places the first queen on the upper left corner
   Nc: c++; // Move to the next column
  if (c == 8) // Checks to see your inbounds
  goto print; 

  r = -1; // So you can pickup where you left off. + Make sure's to                check the top row. cuz r++ will skip Row 0, and go                    straight to Row 1, without checking Row 0.

  Nr: r++; // Move to the next row
  if (r == 8) // Checks to see your inbounds
    goto backtrack; // If you are inbounds, you can move on to the                           next row.

  // Row test
  for (int i = 0; i < c; i++) // i goes across the columns, you wanna                                  go uo to but not including C                                          (Current collumm)
    if (b[r][i] == 1)
      goto Nr;

  // Up Diagnol test 
  for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) 
    //Condition: (r - i) >= 0 && (c - i) >= 0: make sure to stay in       bounds. AND As i gets higher, the more you are subtracting by,        the more you are going up and to the left.

    if (b[r - i][c - i] == 1)
      goto Nr;

  // Down Diagnol test
  for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++)
  if (b[r + i][c - i] == 1)
    goto Nr;

  // Place the Queen
  b[r][c] = 1;
  goto Nc;
  
  // Backtracking
  backtrack: c--; // Goes back a column.
  if (c == -1) // If you are out of bounds, program hits return 0 and                   your done.
    return 0; // Becuase the code will hit out of bounds, so once you                 hit "out" your done with the program.

  r = 0; // Starts at top Row, and goes down.
  
  while (b[r][c] != 1) // While the queen is NOT in the current                                 collumm
    
    r++; // Goes down a row.

    b[r][c] = 0; // Finds the queen and gets rid of it.
    
    goto Nr;

  //Print 
  print: S++;
  
  cout<<"Solutions: "<<S<<endl;
  for (int y=0; y<8; y++){
     for (int x=0; x<8; x++){
         cout<<b[y][x]<<" ";
     }
    
  cout<<endl;
  }
  goto backtrack;
}
  
#include <bits/stdc++.h>
using namespace std;
#define row 9
#define col 20
int main()
{
    char inverted[9][20], temp[9][20];
    int count = 0, total = 0;
  //The after taking input
   char arr[row][col]={
   {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
   {'*','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','*'},
   {'*','.','.','c','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','*'},
   {'*','.','.','.','.','c','.','.','.','.','.','.','.','.','.','.','.','.','.','*'},
   {'*','.','.','.','.','.','.','.','.','.','a','.','.','.','.','.','.','.','.','*'},
	{'*','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','*'},
	{'*','.','.','.','.','.','.','.','a','.','.','.','.','.','.','c','.','.','.','*'},
	{'*','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
   };
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j < 20; j++) {
          //mirror the matrix about x-axis.
            inverted[i][j] = arr[8 - i][j];
        }
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j < 20; j++) {
          //count total number of citizens.
            if (inverted[i][j] == 'a'
                || inverted[i][j] == 'c') {
                total++;
            }
          //copy inverted array in temp
            temp[i][j] = inverted[i][j];
        }
    }
  //bound: number of times virus encountered a boundary
  // i: row-wise traversal variable
  // j: colomn-wise traversal variable
  // direct: direction variable
  // count: number of infected citizens
  // total: total number of citizens('a','c')
    int bound = 0, i = 1, j = 1, direct = 1;
   //the virus starts from (0,0) always
    cout << "0 0" << endl;
    int flag = 0; //to break infinite looping
    while (bound <= 1 && flag < 1000) {
        flag++;
        cout << i << " " << j << endl;
      //virus has striked the boundary twice.
      //end loop
        if (inverted[j][i] == '*' && bound == 1) {
            break;
        }
      //virus striked the corners. end loop
        if (inverted[j][i] == '*') {
            if (i == 0 && j == 8 || i == 20 && j == 8
                || i == 20 && j == 0) {
                break;
            }
        }
      //first time for the virus to hit the boundary
        if (inverted[j][i] == '*' && bound == 0) {
         	//increment bound variable
            bound++;
          //strikes the left wall
            if (i == 0 && j != 8 && j != 0) {
              //turns 90 degree clockwise
                if (direct == 2) {
                    direct = 1;
                    i++;
                    j++;
                }
              //turns 90 degree anticlockwise 
                else if (direct == 4) {
                    direct = 3;
                    j--;
                    i++;
                }
            }
          //strikes the right wall
            else if (i == 20 && j != 0 && j != 8) {
              //turns 90 degree anticlockwise
                if (direct == 1) {
                    direct = 2;
                    i--;
                    j++;
                }
              //turns 90 degree clockwise
                else if (direct == 3) {
                    direct = 4;
                    i--;
                    j--;
                }
            }
          //strikes the upper wall
            else if (j == 8 && i != 0 && i != 20) {
                //	turns 90 degree anticlockwise
                if (direct == 2) {
                    direct = 4;
                    i--;
                    j--;
                }
              // turns 90 degree clockwise
                else if (direct == 1) {
                    direct = 3;
                    j--;
                    i++;
                }
            }
          //strikes the lower wall
            else if (j == 0 && i != 0 && i != 20) {
                //	turns 90 degree clockwise
                if (direct == 4) {
                    direct = 2;
                    i--;
                    j++;
                }
              // turns 90 degree anticlockwise 
                else if (direct == 3) {
                    direct = 1;
                    i++;
                    j++;
                }
            }
            continue;
        }
		//make c visited by replacing it by'-'
        if (inverted[j][i] == 'c') {
            temp[j][i] = '-';
		//turns all directions 90 degree clockwise
            if (direct == 1) {
                direct = 3;
                j--;
                i++;
            }

            else if (direct == 2) {
                direct = 1;
                i++;
                j++;
            }
            else if (direct == 3) {
                direct = 4;
                i--;
                j--;
            }
            else if (direct == 4) {
                direct = 2;
                i--;
                j++;
            }
         //increment count of infected citizens
            count++;
            continue;
        }
      //make a visited by replacing it by'-'
        if (inverted[j][i] == 'a') {
            temp[j][i] = '-';
	//turns all directions by 90 degree anticlockwise
            if (direct == 1) {
                direct = 2;
                i--;
                j++;
            }
            else if (direct == 2) {
                direct = 4;
                i--;
                j--;
            }
            else if (direct == 3) {
                direct = 1;
                i++;
                j++;
            }
            else if (direct == 4) {
                direct = 3;
                j--;
                i++;
            }
       //increment count of infected citizens
            count++;
            continue;
        }
      //just increment the counter diagonally 
      //in the given direction. Refer the diagram.
        if (inverted[j][i] == '.') {
            if (direct == 1) {
                i++;
                j++;
            }
            else if (direct == 2) {
                i--;
                j++;
            }
            else if (direct == 3) {
                j--;
                i++;
            }
            else if (direct == 4) {
                i--;
                j--;
            }
            continue;
        }
    }
  //print the mirror of the array
  //i.e. last row must be printed first.
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j < 20; j++) {
            cout << temp[8 - i][j];
        }
        cout << endl;
    }
  
    cout << "safe=" << (total - count) << endl;
    cout << "infected=" << (count) << endl;
    return 0;
}

#include "../Headers/Calculations.hpp"
unsigned int Calculations::count = 0;
bool Calculations::checkRow(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum)
{
    for (unsigned short i = 0; i < Row; i++) // chcek row
    {
        if (board[i][col] == currNum)
            return false;
    }
    return true;
}
bool Calculations::checkCol(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum)
{
    for (unsigned short i = 0; i < Col; i++) // chcek col
    {
        if (board[row][i] == currNum)
            return false;
    }
    return true;
}
bool Calculations::check_3by3_grid(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum)
{
    // check 3 x 3
    unsigned short startCol = col - (col % 3);
    unsigned short startRow = row - (row % 3);
    for (unsigned short i = 0; i < 3; i++)
    {
        for (unsigned short k = 0; k < 3; k++)
        {
            if (board[i + startRow][k + startCol] == currNum)
            {
                return false;
            }
        }
    }
    return true;
}
bool Calculations::isSafe(const std::vector<std::vector<unsigned short>>& board, const unsigned short& row, const unsigned short& col, const unsigned short& currNum)
{
    return checkRow(board, row, col, currNum) && checkCol(board, row, col, currNum) && check_3by3_grid(board, row, col, currNum);// return true if it is a unique numbers
}
bool Calculations::solveSudoku(std::vector<std::vector<unsigned short>>& board, unsigned short row, unsigned short col)
{
    // Check if we have reached the 8th 
    // row and 9th column (0
    // indexed matrix) , we are 
    // returning true to avoid
    // further backtracking
    count++;
    if (row == 8 && col == 9) // the output will be true if the target value has reached. Row = 8 and Col = 9 (max) with no issue or mistake 
        return true;

    // Check if column value  becomes 9 , 
    // we move to next row and
    //  column start from 0
    if (col == 9)
    {
        row++;
        col = 0;
    }

    // Check if the current position of 
    // the grid already contains any number or value
    // value > 0, we iterate for next column
    if (board[row][col] > 0)
        return solveSudoku(board, row, col + 1);

    for (int num = 1; num <= 9; num++)
    {

        // Check if it is safe to place 
        // the num (1-9)  in the
        // given row ,col  ->we 
        // move to next column
        if (isSafe(board, row, col, num))
        {

            /* Assigning the num in
               the current (row,col)
               position of the grid
               and assuming our assigned
               num in the position
               is correct     */
            board[row][col] = num;
            //  Checking for next possibility with next
            //  column
            if (solveSudoku(board, row, col + 1)) // this will make the solveSudoku true if it satisfies the condition
                return true;
        }

        // Removing the assigned num , 
        // since our assumption
        // was wrong , and we go for 
        // next assumption with
        // diff num value
        board[row][col] = 0; // yes undoing the previous number if the assumption is not correct
    }
    return false;
}
void Calculations::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            std::cout << tileMapSolution[i][j] << " ";
        std::cout << "\n";
    }
}
void Calculations::initPermanentNumbers()
{
    std::vector<std::pair<unsigned short, unsigned short>> posPermanentNums;
}
Calculations::Calculations()
{
    count = 0;
    if (this->solveSudoku(tileMapSolution, 0, 0))
    {
        //this->printBoard();
    }
    else
    {
        std::cout << "no solution\n";
    }
    this->printBoard();
    std::cout << "count: " << count << "\n";
}
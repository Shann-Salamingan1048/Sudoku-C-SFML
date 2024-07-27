#include "../Headers/UI.hpp"

void UI::updateNumbers(sf::Vector2f& mousePos)
{
    for (unsigned short i = 0; i < Row; i++)
    {
        for (unsigned short k = 0; k < Col; k++)
        {
            this->btn_state = this->btn_idle;
            sf::FloatRect bound = this->numTileVec[i][k]->getGlobalBounds();
            if (bound.contains(mousePos))
            {
                this->btn_state = this->btn_hover;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (!this->isLeftClicked)
                    {
                        std::cout << i << ", " << k << "\n";
                        this->btn_state = this->btn_clicked;
                        this->clickedOrNot[i][k] = true; // if clicked using left click then turn it to true
                        this->isLeftClicked = true;
                    }
                }
                else
                {
                    this->isLeftClicked = false;
                }
            }
            else
            {
                this->clickedOrNot[i][k] = false; // if the mouse is not in the tile that has been clicked then set that to false already
            }

            switch (this->btn_state) // check if it is permanent or a permanent number tile so it wont be colored
            {
            case btn_idle:
                if (!this->numTilePermanentOrNot[i][k] && !this->clickedOrNot[i][k] && tileMap[i][k] == 0 ) // if it is 0 or empty tile then make it orig Color(pink)
                    this->numTileVec[i][k]->setFillColor(this->OrigColorTile);
                else if (!this->numTilePermanentOrNot[i][k] && !this->clickedOrNot[i][k] && tileMap[i][k] != 0 ) // if it is not 0 or empty tile then make it grey
                    this->numTileVec[i][k]->setFillColor(sf::Color(128, 128, 128, 128)); // half transparent grey
                break;
            case btn_hover:
                if (!this->numTilePermanentOrNot[i][k] && !this->clickedOrNot[i][k])
                    this->numTileVec[i][k]->setFillColor(sf::Color(0, 255, 0, 128)); // half transparent green
                break;
            case btn_clicked:
                if (this->clickedOrNot[i][k] && !this->numTilePermanentOrNot[i][k]) // so that it wont color the permanent numbers when clicked. Temporary
                    this->numTileVec[i][k]->setFillColor(sf::Color(0, 0, 255, 128)); // half transparent blue
                break;
            }
            
            if (this->clickedOrNot[i][k])
            {
                if (this->tempNum1 != 10 && !this->numTilePermanentOrNot[i][k]) // out of scope of the sudoku 1 - 9. 0 is erase
                {
                    std::unique_ptr<sf::RectangleShape> rectTemp = std::make_unique<sf::RectangleShape>();
                    rectTemp->setSize(this->numTileVec[i][k]->getSize());
                    rectTemp->setTexture(this->numbers[tempNum1].get());
                    rectTemp->setPosition(this->numTileVec[i][k]->getPosition());
                    rectTemp->setFillColor(sf::Color(128, 128, 128, 128)); // half transparent grey
                    if (this->tempNum1 == 0) // if it is transparent
                    {
                        rectTemp->setTextureRect(sf::IntRect(29, 29, 103, 103));
                        rectTemp->setFillColor(this->OrigColorTile);
                    }

                    tileMap[i][k] = this->tempNum1; // update tileMap
                   
                    this->numTileVec[i][k] = std::move(rectTemp);

                   
                }
                if (cal.checkCol(tileMap, i, k, this->tempNum1) && cal.checkRow(tileMap, i, k, this->tempNum1) && cal.check_3by3_grid(tileMap, i, k, this->tempNum1))
                {
                    this->tempNum1 = 10; // back to 10
                    break;
                }
                else if (!cal.checkCol(tileMap, i, k, this->tempNum1) && cal.checkRow(tileMap, i, k, this->tempNum1) && cal.check_3by3_grid(tileMap, i, k, this->tempNum1))
                {
                    this->makeColRed(i, k);
                }
                else if (!cal.checkRow(tileMap, i, k, this->tempNum1) && cal.check_3by3_grid(tileMap, i, k, this->tempNum1) && cal.checkCol(tileMap, i, k, this->tempNum1))
                {
                    this->makeRowRed(i, k);
                }
                else if (!cal.check_3by3_grid(tileMap, i, k, this->tempNum1) && cal.checkCol(tileMap, i, k, this->tempNum1) && cal.checkRow(tileMap, i, k, this->tempNum1))
                {
                    this->make_3by3_Red(i, k);
                }
                else if (!cal.check_3by3_grid(tileMap, i, k, this->tempNum1) && !cal.checkCol(tileMap, i, k, this->tempNum1) && !cal.checkRow(tileMap, i, k, this->tempNum1))
                {
                    this->makeColRed(i, k);
                    this->makeRowRed(i, k);
                    this->make_3by3_Red(i, k);
                }

                this->tempNum1 = 10; // back to 10
            }
            
        }
    }

}
void UI::make_3by3_Red(const unsigned short& row, const unsigned short& col)
{
    // check 3 x 3
    unsigned short startCol = col - (col % 3);
    unsigned short startRow = row - (row % 3);
    for (unsigned short i = 0; i < 3; i++)
    {
        for (unsigned short k = 0; k < 3; k++)
        {
            this->numTileVec[i + startRow][k + startCol]->setFillColor(sf::Color::Red);
            
        }
    }

}
void UI::makeRowRed(const unsigned short& row, const unsigned short& col)
{
    for (unsigned short i = 0; i < Row; i++) // chcek col
    {
        this->numTileVec[i][col]->setFillColor(sf::Color::Red);
    }
}
void UI::makeColRed(const unsigned short& row, const unsigned short& col)
{
    for (unsigned short i = 0; i < Col; i++) // chcek col
    {
        this->numTileVec[row][i]->setFillColor(sf::Color::Red);
    }
}
unsigned short UI::pollEvents(sf::Event& evnt)
{
    if (evnt.type == sf::Event::KeyPressed)
    {
        switch (evnt.key.code)
        {
        case sf::Keyboard::Num0:
            return 0;
        case sf::Keyboard::Num1:
            return 1;
        case sf::Keyboard::Num2:
            return 2;
        case sf::Keyboard::Num3:
            return 3;
        case sf::Keyboard::Num4:
            return 4;
        case sf::Keyboard::Num5:
            return 5;
        case sf::Keyboard::Num6:
            return 6;
        case sf::Keyboard::Num7:
            return 7;
        case sf::Keyboard::Num8:
            return 8;
        case sf::Keyboard::Num9:
            return 9;
        default:
            break;
        }
    }
    return 10;
}

void UI::initTextureNumbers()
{
    // numbers
    auto temp = std::make_unique<sf::Texture>();
    temp->loadFromFile("Core/Assets/Grid.png"); // transparent or 0
    this->numbers.push_back(std::move(temp));
    //temp.reset();
    for (unsigned short i = 1; i <= 9; ++i)
    {
        auto num = std::make_unique<sf::Texture>();
        std::string filePath = "Core/Assets/" + std::to_string(i) + ".png";
        if (!num->loadFromFile(filePath))
        {
            // Handle error loading texture
            continue; // Skip to next iteration on error
        }
        this->numbers.push_back(std::move(num)); // Move texture into numbers vector
        // numbers are 99 x 99 pictures
    }
}
void UI::initTextureNumbersTick()
{
    // tick numbers
    for (unsigned short i = 1; i <= 9; ++i)
    {
        auto num = std::make_unique<sf::Texture>();
        std::string filePath = "Core/Assets/Tick" + std::to_string(i) + ".png";
        if (!num->loadFromFile(filePath))
        {
            // Handle error loading texture
            continue; // Skip to next iteration on error
        }
        this->numbersTick.push_back(std::move(num)); // Move texture into numbers vector
    }
}
void UI::initNumberTiles()
{
    unsigned short gapDetectorX = 0, gapDetectorY = 0;
    unsigned short s_gapX_Count = 0, s_gapY_Count = 0; // small
    unsigned short b_gapX_Count = 0, b_gapY_Count = 0; // big

    unsigned short gapX_Sum = 0, gapY_Sum = 0;

    for (unsigned short i = 0; i < Row; i++)
    {
        gapDetectorY++;
        unsigned short Gap_Y = (i > 0 && (gapDetectorY == 4 || gapDetectorY == 7)) ? big_Gap : small_Gap;
        s_gapY_Count += (i > 0) ? (Gap_Y == small_Gap) : 0;
        b_gapY_Count += (Gap_Y == big_Gap);
        gapY_Sum = (small_Gap * s_gapY_Count) + (big_Gap * b_gapY_Count);

        std::vector<std::unique_ptr<sf::RectangleShape>> tempShape;
        for (unsigned short k = 0; k < Col; k++)
        {
            gapDetectorX++;
            unsigned short Gap_X = (k > 0 && (gapDetectorX == 4 || gapDetectorX == 7)) ? big_Gap : small_Gap;
            s_gapX_Count += (k > 0) ? (Gap_X == small_Gap) : 0;
            b_gapX_Count += (Gap_X == big_Gap);
            gapX_Sum = (small_Gap * s_gapX_Count) + (big_Gap * b_gapX_Count);

            /*if (i == 0)
            {
                std::cout << s_gapX_Count << ", " << b_gapX_Count << ", Sum X Gap: " << gapX_Sum << "\n";
            }*/

            auto shape = std::make_unique<sf::RectangleShape>();
            shape->setSize(sf::Vector2f(tileHeight, tileWidth));
            shape->setTexture(this->numbers[tileMap[i][k]].get());
            shape->setPosition(sf::Vector2f(startUpPos + (tileWidth * k) + gapX_Sum, startUpPos + (tileHeight * i) + gapY_Sum));

            if (tileMap[i][k] == 0) // if transparent or just a tile with no numbers
            {
                shape->setTextureRect(sf::IntRect(29, 29, 103, 103));
            }
            tempShape.push_back(std::move(shape));
        }
        this->numTileVec.push_back(std::move(tempShape));

        // Reset X counters for the next row
        gapDetectorX = 0;
        s_gapX_Count = 0;
        b_gapX_Count = 0;
        gapX_Sum = 0;
    }

}
void UI::printNumbers(sf::RenderTarget& target)
{
    for (const auto& i : this->numTileVec)
    {
        for (const auto& k : i)
        {
            target.draw(*k);
        }
    }
}
void UI::printGrid(sf::RenderTarget& target)
{
    target.draw(this->Grid);

}
void UI::initGrid()
{
    // Background / tiles
    this->textGrid.loadFromFile("Core/Assets/Grid.png");
    this->Grid.setTexture(&this->textGrid);
    this->Grid.setSize(sf::Vector2f(GridHeight, GridWidth));
    //
}
void UI::initNumTilePermanentOrNot()
{
    for (const auto& i : tileMap)
    {
        std::vector<bool>  tempVec;
        for (const auto& k : i)
        {
            if (k != 0)
                tempVec.push_back(true);
            else
                tempVec.push_back(false);
        }
        this->numTilePermanentOrNot.push_back(tempVec);
    }
}
void UI::initClickedOrNot()
{
    for (unsigned short i = 0; i < Row; i++)
    {
        std::vector<bool> tempVec;
        for (unsigned short k = 0; k < Col; k++)
        {
            tempVec.push_back(false);
        }
        this->clickedOrNot.push_back(tempVec);
    }

}
UI::UI()
{
    this->isLeftClicked = false;
    this->initTextureNumbersTick();
    this->initTextureNumbers();
    this->initNumberTiles();

    this->initNumTilePermanentOrNot();
    this->initClickedOrNot();

    this->initGrid();


    this->imageTemp.loadFromFile("Core/Assets/Grid.png");
    this->OrigColorTile = this->imageTemp.getPixel(48, 41); // pink tiles


    this->tempNum1 = 10;
    std::cout << this->numbers.size() << "\n";
    std::cout << this->numbersTick.size() << "\n";
}
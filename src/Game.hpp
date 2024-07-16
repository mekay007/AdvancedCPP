#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <array>
#include <random>

class Game {
    friend class GameRenderer;
public:
    static constexpr int IS_BOMB = -1;
    bool isWon();
    Game(int width, int height, int mines);

    void reset();
    int reveal(int x, int y);
    bool isRevealed(int x, int y);
    bool isGameOver() const noexcept { return gameOver; }

    const std::vector<std::vector<int>>& getBoard() const noexcept { return board; }

    int getWidth() const noexcept { return width; }
    int getHeight() const noexcept { return height; }

protected:
    void placeMines();
    void calculateAdjacentMines();
    int width;
    int height;
    int mines;
    std::vector<std::vector<int>> board;
    std::vector<std::vector<bool>> reveal_board;
    bool gameOver{false};

};

#endif // GAME_HPP
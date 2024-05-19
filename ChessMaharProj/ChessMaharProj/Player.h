#pragma once
namespace ChessMaharProj {
    enum class PlayerColor {
        White,
        Black
    };

    ref class Player {
        PlayerColor color;
    public:
        Player()
        {
            this->color = PlayerColor::White;
        }
        Player(PlayerColor color)
        {
            this->color = color;
        }

        PlayerColor getColor()
        {
            return color;
        }

        static bool operator==(const Player% player1, const Player% player2) {
            return player1.color == player2.color;
        }

        static bool operator!=(const Player% player1, const Player% player2) {
            return !(player1 == player2);
        }

        bool isSame(Object^ object)
        {
            Player^ player = (Player^)object;
            if (player == nullptr)
            {
                return false;
            }

            return this == player;
        }
    };
}
#include"FigureInt.h"
#pragma once
namespace ChessMaharProj {
    ref class Rook :public FigureInterface
    {
        bool isFirstmove = true;
    public:
        Rook(Position^ pos, Player^ play)
        {
            this->img = gcnew Bitmap("Rook.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
            isRook = true;
        }

        void move(Position^ newpos) override
        {
            pos = gcnew Position(newpos->getX(), newpos->getY());
            isFirstmove = false;
        }

        DListPos^ FindMoveCurFigure(array <FigureInterface^, 2>^ map, int numberbool) override
        {
            DListPos^ result = gcnew DListPos;
            UnuversalFindMove(result, 0, 1, map, numberbool);
            UnuversalFindMove(result, 0, -1, map, numberbool);
            UnuversalFindMove(result, 1, 0, map, numberbool);
            UnuversalFindMove(result, -1, 0, map, numberbool);
            return result;
        }

        bool getIsfirstmove()
        {
            return isFirstmove;
        }
    };
}
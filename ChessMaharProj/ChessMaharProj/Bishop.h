#include"FigureInt.h"
#pragma once
namespace ChessMaharProj {
    ref class Bishop :public FigureInterface
    {
    public:
        Bishop(Position^ pos, Player^ play)
        {
            this->img = gcnew Bitmap("Bishop.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
        }

        DListPos^ FindMoveCurFigure(array <FigureInterface^, 2>^ map, int numberbool) override
        {
            DListPos^ result = gcnew DListPos;
            for (int i = -1; i < 2;i += 2)
            {
                for (int j = -1; j < 2;j += 2)
                {
                    UnuversalFindMove(result, i, j, map, numberbool);
                }
            }
            return result;
        }
    };
}
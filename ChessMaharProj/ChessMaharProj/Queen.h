#include"FigureInt.h"
#pragma once
namespace ChessMaharProj {
    ref class Queen :public FigureInterface
    {
    public:
        Queen(Position^ pos, Player^ play)
        {
            this->img = gcnew Bitmap("Queen.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
        }

        DListPos^ FindMoveCurFigure(array <FigureInterface^, 2>^ map, int numberbool) override
        {
            DListPos^ result = gcnew DListPos;
            for (int i = -1; i < 2;i++)
            {
                for (int j = -1; j < 2;j++)
                {
                    if (!(i == j && i == 0))
                    {
                        UnuversalFindMove(result, i, j, map, numberbool);
                    }
                }
            }
            return result;
        }
    };
}
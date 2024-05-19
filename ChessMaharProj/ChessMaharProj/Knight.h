#include"FigureInt.h"
#pragma once
namespace ChessMaharProj {
    ref class Knight :public FigureInterface
    {
    public:
        Knight(Position^ pos, Player^ play)
        {
            this->img = gcnew Bitmap("Knight.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
            isKnight = true;
        }

        void UnuversalFindMove(DListPos^ posCurF, int fx, int fy, array <FigureInterface^, 2>^ map, int numberbool) override
        {
            int x = pos->getX() + fx;
            int y = pos->getY() + fy;

            if (CheckOut(x, y))
            {
                if (map[x, y] == nullptr)
                {
                    posCurF->AddPos(gcnew Position(x, y));
                }
                else if (MethodCheakerBreker(numberbool / 10, x, y, map))
                {
                    posCurF->AddPos(gcnew Position(x, y));
                }
            }
        }

        DListPos^ FindMoveCurFigure(array <FigureInterface^, 2>^ map, int numberbool) override
        {
            DListPos^ result = gcnew DListPos;
            UnuversalFindMove(result, 1, 2, map, numberbool);
            UnuversalFindMove(result, 1, -2, map, numberbool);
            UnuversalFindMove(result, -1, 2, map, numberbool);
            UnuversalFindMove(result, -1, -2, map, numberbool);
            UnuversalFindMove(result, 2, 1, map, numberbool);
            UnuversalFindMove(result, 2, -1, map, numberbool);
            UnuversalFindMove(result, -2, 1, map, numberbool);
            UnuversalFindMove(result, -2, -1, map, numberbool);
            return result;
        }

        DListPos^ FinalMoveCurF(array <FigureInterface^, 2>^ map) override
        {
            return FindMoveCurFigure(map, 10);
        }
    };
}

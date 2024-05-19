#include"FigureInt.h"
#pragma once
namespace ChessMaharProj {
    ref class Mah :public FigureInterface
    {
    public:
        Mah(Position^ pos, Player^ play)
        {
            this->img = gcnew Bitmap("Mah.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
        }

        void LikeKnight(DListPos^ posCurF, int fx, int fy, array <FigureInterface^, 2>^ map, int numberbool)
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
            LikeKnight(result, 1, 2, map, numberbool);
            LikeKnight(result, 1, -2, map, numberbool);
            LikeKnight(result, -1, 2, map, numberbool);
            LikeKnight(result, -1, -2, map, numberbool);
            LikeKnight(result, 2, 1, map, numberbool);
            LikeKnight(result, 2, -1, map, numberbool);
            LikeKnight(result, -2, 1, map, numberbool);
            LikeKnight(result, -2, -1, map, numberbool);
            return result;
        }

        DListPos^ FinalMoveForKing(array <FigureInterface^, 2>^ map) override
        {
            return FindMoveCurFigure(map, 24);
        }
    };
}
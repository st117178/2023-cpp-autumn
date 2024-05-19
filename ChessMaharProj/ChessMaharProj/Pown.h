#include"FigureInt.h"
#pragma once
namespace ChessMaharProj {
    ref class Pawn :public FigureInterface
    {
        bool isFirstmove = true;
    public:
        void move(Position^ newpos) override
        {
            pos = gcnew Position(newpos->getX(), newpos->getY());
            isFirstmove = false;
        }

        Pawn(Position^ pos, Player^ play)
        {
            this->img = gcnew Bitmap("Pawn.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
            isPawn = true;
        }

        DListPos^ FindMoveCurFigure(array <FigureInterface^, 2>^ arraymap, int numberbool) override
        {
            DListPos^ result = gcnew DListPos;
            SupportFindMove(result, arraymap);
            return result;
        }

        void SupportFindMove(DListPos^ listpos, array <FigureInterface^, 2>^ map)
        {
            int x = pos->getX() - 1;
            for (int i = -1;i < 2;i++)
            {
                int y = pos->getY() + i;
                if (CheckOut(x, y))
                {
                    if (map[x, y] != nullptr && map[x, y]->getPlayer() != player && i != 0)
                    {
                        listpos->AddPos(gcnew Position(x, y));
                    }
                    else if (i == 0 && map[x, y] == nullptr)
                    {
                        if (isFirstmove && map[x - 1, y] == nullptr)
                        {
                            listpos->AddPos(gcnew Position(x - 1, y));
                        }
                        listpos->AddPos(gcnew Position(x, y));
                    }
                }
            }
        }

        DListPos^ FinalMoveCurF(array <FigureInterface^, 2>^ map) override
        {
            return FindMoveCurFigure(map, 0);
        }
    };
}
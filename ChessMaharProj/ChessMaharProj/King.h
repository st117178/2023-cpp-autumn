#include"FigureInt.h"
#include"Rook.h"
#pragma once
namespace ChessMaharProj {
    ref class King :public FigureInterface
    {
        bool isFirstmove = true;
    public:
        King(Position^ pos, Player^ play)
        {
            isKing = true;
            this->img = gcnew Bitmap("King.png");
            pos = gcnew Position(pos->getX(), pos->getY());
            this->pos = pos;
            player = play;
        }

        void move(Position^ newpos) override
        {
            pos = gcnew Position(newpos->getX(), newpos->getY());
            isFirstmove = false;
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

        DListPos^ FinalMoveCurF(array <FigureInterface^, 2>^ map) override
        {
            DListPos^ posiblemoves = FindMoveCurFigure(map, 10);

            DListPos^ unrealmoves = gcnew DListPos;
            for (int i = 0; i < 8;i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    FigureInterface^ figure = map[i, j];
                    if (figure != nullptr && player != figure->getPlayer())
                    {
                        unrealmoves->AddNewList(figure->FinalMoveForKing(map));
                    }
                }
            }
            posiblemoves->MList(unrealmoves);

            array <Position^>^ rookPos = gcnew array <Position^>(2) { gcnew Position(7, 0), gcnew Position(7, 7) };

            for each (Position ^ CurRookPos in rookPos)
            {
                FigureInterface^ figure = map[CurRookPos->getX(), CurRookPos->getY()];
                if (figure != nullptr)
                {
                    if (figure->getIsRook())
                    {
                        Rook^ rook = (Rook^)map[CurRookPos->getX(), CurRookPos->getY()];
                        if (IsCastling(rook, map))
                        {
                            if (CurRookPos->getY() == 0)
                            {
                                CurRookPos->setY(2);
                            }

                            if (CurRookPos->getY() == 7)
                            {
                                CurRookPos->setY(6);
                            }
                            posiblemoves->AddPos(CurRookPos);
                        }
                    }
                }
            }

            return posiblemoves;
        }

        bool IsCastling(Rook^ rook, array <FigureInterface^, 2>^ map)
        {
            if (!isFirstmove || !rook->getIsfirstmove() || rook == nullptr)
            {
                return false;
            }

            int fy = -1;
            int leftfig = rook->getPos()->getY();
            int rightfig = pos->getY();
            if (rook->getPos()->getY() > pos->getY())
            {
                fy = 1;
                leftfig = pos->getY();
                rightfig = rook->getPos()->getY();
            }

            for (int i = leftfig + 1; i < rightfig; i++)
            {
                if (map[pos->getX(), i] != nullptr)
                {
                    return false;
                }
            }

            for (int i = 0; i < 2; i++)
            {
                Position^ impos = gcnew Position(pos->getX(), pos->getY() + i * fy);
                if (isCheak(impos, map))
                {
                    return false;
                }
            }

            return true;
        }

        bool isCheak(Position^ pos, array <FigureInterface^, 2>^ map)
        {
            for (int i = 0; i < 8;i++)
            {
                for (int j = 0;j < 8;j++)
                {
                    FigureInterface^ figure = map[i, j];
                    if (figure != nullptr && figure->getPlayer() != player && figure->FinalMoveCurF(map)->FindSamePos(pos))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };
}
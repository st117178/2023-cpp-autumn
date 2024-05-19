#include"Position.h"
#include"Player.h"
#include"DListPos.h"
#pragma once
namespace ChessMaharProj {
    ref class FigureInterface : public System::Windows::Forms::Form
    {
    protected:
        Position^ pos = gcnew Position();
        Player^ player = gcnew Player();
        Image^ img;

        bool isKing = false;
        bool isKnight = false;
        bool isPawn = false;
        bool isRook = false;
    public:

        virtual Position^ getPos()
        {
            return pos;
        }

        virtual void setPos(int x, int y)
        {
            pos = gcnew Position(x, y);
        }

        virtual Player^ getPlayer()
        {
            return player;
        }

        virtual Image^ getimage()
        {
            return img;
        }

        virtual bool getIsKing()
        {
            return isKing;
        }

        virtual bool getIsKnight()
        {
            return isKnight;
        }

        virtual bool getIsPawn()
        {
            return isPawn;
        }

        virtual bool getIsRook()
        {
            return isRook;
        }

        virtual void move(Position^ newpos)
        {
            pos = gcnew Position(newpos->getX(), newpos->getY());
        }

        virtual bool MethodCheakerBreker(int numberbool, int x, int y, array <FigureInterface^, 2>^ map)//переделать
        {
            bool cheaker1 = player != map[x, y]->getPlayer();
            bool cheaker2 = map[x, y] != nullptr;
            bool breaker1 = map[x, y] != nullptr;
            bool breaker2 = !(map[x, y]->getIsKing() && player != map[x, y]->getPlayer());
            switch (numberbool)
            {
            case 1:
                return cheaker1;
            case 2:
                return cheaker2;
            case 3:
                return breaker1;
            case 4:
                return breaker2;
            }

        }

        virtual void UnuversalFindMove(DListPos^ posCurF, int fx, int fy, array <FigureInterface^, 2>^ map, int numberbool)
        {
            int x = pos->getX() + fx;
            int y = pos->getY() + fy;

            while (CheckOut(x, y))
            {
                if (map[x, y] == nullptr)
                {
                    posCurF->AddPos(gcnew Position(x, y));
                }
                else
                {
                    if (MethodCheakerBreker(numberbool / 10, x, y, map))
                    {
                        posCurF->AddPos(gcnew Position(x, y));
                    }
                    if (MethodCheakerBreker(numberbool % 10, x, y, map))
                    {
                        break;
                    }
                }
                x += fx;
                y += fy;
            }
        }

        virtual bool CheckOut(int i, int j)
        {
            if (i >= 8 || i < 0 || j >= 8 || j < 0)
            {
                return false;
            }

            else
            {
                return true;
            }
        }

        virtual DListPos^ FindMoveCurFigure(array <FigureInterface^, 2>^ map, int numberbool)
        {
            return nullptr;
        }

        virtual DListPos^ FinalMoveCurF(array <FigureInterface^, 2>^ map)
        {
            return FindMoveCurFigure(map, 13);
        }

        virtual DListPos^ FinalMoveForKing(array <FigureInterface^, 2>^ map)
        {
            return nullptr;
        }
    };
}
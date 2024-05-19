#include"Bishop.h"
#include"Map.h"
#include"Pown.h"
#include"King.h"
#include"Knight.h"
#include"Queen.h"
#include"Rook.h"
#include"Maharaji.h"

#pragma once
namespace ChessMaharProj {
    ref class InitFDesk
    {
        Player^ black = gcnew Player(PlayerColor::Black);
        Player^ white = gcnew Player(PlayerColor::White);
        Player^ curPlayer;

        Map^ map = gcnew Map();

        FigureInterface^ curFig;
        FigureInterface^ prevFig;

        Position^ PosCurFig;
        Position^ PosPrevFig;

        DListPos^ MovePosition;

    public:
        InitFDesk()
        {
            CreateDesk();
        }

        Player^ getPlayer()
        {
            return curPlayer;
        }

        FigureInterface^ getMapMas(int i, int j)
        {
            return map->MasIF(i, j);
        }

        void SetCurFig(Position^ posfigure)
        {
            prevFig = curFig;
            curFig = map->MasIF(posfigure->getX(), posfigure->getY());
        }

        FigureInterface^ getCurFig()
        {
            return curFig;
        }

        FigureInterface^ getPrevFig()
        {
            return prevFig;
        }

        Position^ getDeskPosCurFig()
        {
            return PosCurFig;
        }

        Position^ getDeskPosPrevFig()
        {
            return PosPrevFig;
        }

        DListPos^ getList()
        {
            return MovePosition;
        }

        void Start()
        {
            curPlayer = black;
        }

        void AddBlackfigure()
        {
            for (int j = 0; j < 8; j++)
            {
                map->AddF(gcnew Pawn(gcnew Position(6, j), black));
            }

            map->AddF(gcnew Rook(gcnew Position(7, 0), black));
            map->AddF(gcnew Rook(gcnew Position(7, 7), black));

            map->AddF(gcnew Knight(gcnew Position(7, 1), black));
            map->AddF(gcnew Knight(gcnew Position(7, 6), black));

            map->AddF(gcnew Bishop(gcnew Position(7, 2), black));
            map->AddF(gcnew Bishop(gcnew Position(7, 5), black));

            map->AddF(gcnew Queen(gcnew Position(7, 3), black));

            map->AddF(gcnew King(gcnew Position(7, 4), black));
        }

        void AddMah(int i, int j)
        {
            map->AddF(gcnew Mah(gcnew Position(i, j), white));
        }

        void DeleteF(int i, int j)
        {
            map->DeleteF(i, j);
        }

        void CreateDesk()
        {
            AddBlackfigure();
        }

        void swapPlyer()
        {
            if (curPlayer == white)
            {
                curPlayer = black;
            }
            else
            {
                curPlayer = white;
            }

            prevFig = nullptr;
            curFig = nullptr;
        }

        void findmove()
        {
            if (curFig->getPlayer()->getColor() == PlayerColor::White)
            {
                MovePosition = gcnew DListPos();
                MovePosition = curFig->FinalMoveCurF(map->getMap());
            }
            else
            {
                MovePosition = gcnew DListPos();
                King^ king = FindKing();
                SupportFinderMoves(curFig, king->getPos(), MovePosition);
            }
        }

        bool getIssameplayer()
        {
            if ((curFig != nullptr && prevFig == nullptr) || (curFig == nullptr && prevFig != nullptr))
            {
                return false;
            }
            return curFig->getPlayer() == prevFig->getPlayer();
        }

        void Move(Position^ pos, FigureInterface^ figure)
        {
            map->SetMasIF(figure->getPos()->getX(), figure->getPos()->getY(), nullptr);
            map->SetMasIF(pos->getX(), pos->getY(), figure);
            PosPrevFig = gcnew Position(figure->getPos()->getX(), figure->getPos()->getY());
            PosCurFig = gcnew Position(pos->getX(), pos->getY());
            figure->move(pos);
        }

        void FigureMove(Position^ newpos)
        {
            Move(newpos, prevFig);
        }

        void SupportFinderMoves(FigureInterface^ figure, Position^ kingPos, DListPos^ positions)
        {
            DListPos^ figureAllMoves = figure->FinalMoveCurF(map->getMap());
            Position^ figurePos = gcnew Position(figure->getPos()->getX(), figure->getPos()->getY());
            for each (Position ^ pos in figureAllMoves->getCurF())
            {
                Map^ tempM = map->copy();

                tempM->MasIF(figurePos->getX(), figurePos->getY())->setPos(pos->getX(), pos->getY());
                tempM->SetMasIF(pos->getX(), pos->getY(), tempM->MasIF(figurePos->getX(), figurePos->getY()));
                tempM->SetMasIF(figurePos->getX(), figurePos->getY(), nullptr);

                FigureInterface^ cheakF;
                if (!isCheak(tempM, (King^)map->MasIF(kingPos->getX(), kingPos->getY()), cheakF))
                {
                    positions->AddPos(pos);
                }
                figure->setPos(figurePos->getX(), figurePos->getY());
                FigureInterface^ newf = cheakF;
            }
        }

        King^ FindKing()
        {
            King^ king = nullptr;
            for (int i = 0;i < 8;i++)
            {
                for (int j = 0; j < 8;j++)
                {
                    FigureInterface^ figure = map->MasIF(i, j);
                    if (figure != nullptr && figure->getIsKing() && figure->getPlayer() == curPlayer)
                    {
                        king = (King^)figure;
                    }
                }
            }
            return king;
        }

        bool isCheak(FigureInterface^% cheakF, King^% cheakKing)
        {
            cheakKing = FindKing();
            return isCheak(map, cheakKing, cheakF);
        }

        bool isCheak(Map^ map, King^ cheakKing, FigureInterface^% cheakF)
        {
            if (getPlayer()->getColor() == PlayerColor::Black)
            {
                for (int i = 0;i < 8;i++)
                {
                    for (int j = 0; j < 8;j++)
                    {
                        FigureInterface^ figure = map->MasIF(i, j);
                        if (figure != nullptr && figure->getPlayer() != cheakKing->getPlayer())
                        {
                            DListPos^ figurePos = figure->FinalMoveCurF(map->getMap());
                            if (figurePos->FindSamePos(cheakKing->getPos()))
                            {
                                cheakF = figure;
                                return true;
                            }
                        }
                    }
                }
            }

            cheakF = nullptr;
            return false;
        }

        bool isCastling()
        {

            Rook^ rook = (Rook^)curFig;
            King^ king = (King^)prevFig;
            return king->IsCastling(rook, map->getMap());
        }

        void DoCastle()
        {
            Rook^ rook = (Rook^)map->MasIF(7, 0);
            if (PosPrevFig->getY() < PosCurFig->getY())
            {
                rook = (Rook^)map->MasIF(7, 7);
            }
            King^ king = (King^)prevFig;
            int x = king->getPos()->getX();
            Position^ newKingPos = gcnew Position(x, 6);
            Position^ newRookPos = gcnew Position(x, 5);
            if (king->getPos()->getY() > rook->getPos()->getY())
            {
                newKingPos = gcnew Position(x, 2);
                newRookPos = gcnew Position(x, 3);
            }
            Move(newKingPos, king);
            Move(newRookPos, rook);
        }

        String^ gamestatus()
        {
            King^ king = FindKing();
            if (isBlackWin())
            {
                return "Магараджа погиб. Чёрные выйграли.";
            }


            FigureInterface^ cheakF = FindKing();
            if (isCheak(map, king, cheakF))
            {
                if (isMate(king, cheakF))
                {
                    return "Мат на доске. Магараджа победил.";
                }
            }
            else if (isStaleMate(king))
            {
                return "Ничья";
            }
            return nullptr;
        }

        bool isStaleMate(King^ king)
        {
            if (curPlayer->getColor() == PlayerColor::Black)
            {
                DListPos^ posL = gcnew DListPos;
                for each (FigureInterface ^ figure in map->getMap())
                {
                    if (figure != nullptr && figure->getPlayer()->isSame(king->getPlayer()))
                    {
                        SupportFinderMoves(figure, king->getPos(), posL);
                    }

                    if (posL->getLength() > 0)
                    {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        bool isMate(King^ king, FigureInterface^ cheakF)
        {
            DListPos^ LPos = gcnew DListPos;
            DListPos^ moves = DifendKingForMate(king->getPos(), cheakF->getPos());
            if (king->FinalMoveCurF(map->getMap())->getLength() == 0)
            {
                for each (FigureInterface ^ figure in map->getMap())
                {
                    if (figure != nullptr && figure->getPlayer()->Equals(king->getPlayer()))
                    {
                        SupportFinderMoves(figure, king->getPos(), LPos);
                    }
                }

                for each (Position ^ pos in LPos->getCurF())
                {
                    if (moves->FindSamePos(pos))
                    {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        bool isBlackWin()
        {
            for (int i = 0; i < 8;i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    FigureInterface^ figure = map->MasIF(i, j);
                    if (figure != nullptr)
                    {
                        if (figure->getPlayer()->getColor() == PlayerColor::White)
                        {
                            return false;
                        }
                    }
                }
            }

            return true;
        }

        bool CheakerIsDifend(Position^ kingPos, Position^ figurePos, int numberbool)//переделать
        {
            switch (numberbool)
            {
            case 1:
                return (kingPos->getX() > figurePos->getX() && kingPos->getY() > figurePos->getY());
            case 2:
                return (kingPos->getX() > figurePos->getX() && kingPos->getY() < figurePos->getY());
            case 3:
                return (kingPos->getX() > figurePos->getX() && kingPos->getY() == figurePos->getY());
            case 4:
                return (kingPos->getX() < figurePos->getX() && kingPos->getY() > figurePos->getY());
            case 5:
                return (kingPos->getX() < figurePos->getX() && kingPos->getY() < figurePos->getY());
            case 6:
                return (kingPos->getX() < figurePos->getX() && kingPos->getY() == figurePos->getY());
            case 7:
                return (kingPos->getX() == figurePos->getX() && kingPos->getY() > figurePos->getY());
            case 8:
                return (kingPos->getX() == figurePos->getX() && kingPos->getY() < figurePos->getY());
            }
        }

        void SupDifendKing(Position^ kingPos, Position^ figurePos, DListPos^ move, DListPos^ result, int numberbool)
        {
            if (CheakerIsDifend(kingPos, figurePos, numberbool))
            {
                for each (Position ^ pos in move->getCurF())
                {
                    if (CheakerIsDifend(pos, figurePos, numberbool))
                    {
                        result->AddPos(pos);
                    }
                }
            }
        }

        DListPos^ DifendKingForMate(Position^ kingPos, Position^ figurePos)
        {
            int x = figurePos->getX();
            int y = figurePos->getY();

            DListPos^ result = gcnew DListPos;

            FigureInterface^ figure = map->MasIF(x, y);

            DListPos^ moves = figure->FinalMoveCurF(map->getMap());

            if (!(figure->getIsKnight()) && !(figure->getIsPawn()))
            {
                SupDifendKing(kingPos, figurePos, moves, result, 1);
                SupDifendKing(kingPos, figurePos, moves, result, 2);
                SupDifendKing(kingPos, figurePos, moves, result, 3);
                SupDifendKing(kingPos, figurePos, moves, result, 4);
                SupDifendKing(kingPos, figurePos, moves, result, 5);
                SupDifendKing(kingPos, figurePos, moves, result, 6);
                SupDifendKing(kingPos, figurePos, moves, result, 7);
                SupDifendKing(kingPos, figurePos, moves, result, 8);
            }

            result->AddPos(figure->getPos());
            return result;
        }
    };
}
#include"Position.h"
#pragma once
namespace ChessMaharProj {
    ref class CButton :public Button
    {
        Position^ posbut = gcnew Position();
    public:
        CButton(Position^ posbut)
        {
            this->posbut = posbut;
        }

        Position^ getposbut()
        {
            return posbut;
        }
    };
}
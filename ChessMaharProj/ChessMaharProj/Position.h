#pragma once
namespace ChessMaharProj {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    ref class Position
    {
        int x;
        int y;

    public:
        Position()
        {
            setX(0);
            setY(0);
        }

        Position(int x, int y) {
            setX(x);
            setY(y);
        }

        int getX() {
            return x;
        }

        void setX(int value) {
            if (value >= 0 && value < 8)
            {
                x = value;
            }
            else
            {
                throw gcnew Exception("setY = " + Convert::ToString(value));
            }
        }

        int getY() {
            return y;
        }

        void setY(int value) {
            if (value >= 0 && value < 8)
            {
                y = value;
            }
            else
            {
                throw gcnew Exception("setY = " + Convert::ToString(value));
            }
        }

        void operator=(Position% pos)
        {
            pos.x = this->x;
            pos.y = this->y;
        }

        bool operator==(System::Object^ sender)
        {
            Position^ pos = (Position^)sender;
            if (x == pos->getX() && y == pos->getY())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };
}
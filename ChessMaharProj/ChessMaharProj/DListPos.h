#include"Position.h"
#pragma once
namespace ChessMaharProj {
    ref class DListPos {
        int length = 0;

        array <Position^>^ posCurF;
    public:

        DListPos()
        {
            this->length = 0;
            this->posCurF = gcnew array <Position^>(length);
        }

        DListPos(array <Position^>^ posCurF, int length)
        {
            this->length = length;
            this->posCurF = posCurF;
        }

        DListPos(DListPos^ newpos)
        {
            this->posCurF = newpos->getCurF();
            this->length = newpos->getLength();
        }

        int getLength()
        {
            return length;
        }

        Position^ getPosCurF(int i)
        {
            if (i < length)
            {
                return posCurF[i];
            }
        }

        array <Position^>^ getCurF()
        {
            return posCurF;
        }

        ~DListPos()
        {
            dispose();
        }

        void AddPos(Position^ newPos)
        {
            length++;
            array <Position^>^ newposCurF = gcnew array <Position^>(length);
            for (int i = 0; i < length - 1; i++)
            {
                newposCurF[i] = posCurF[i];
            }
            posCurF = newposCurF;
            delete[] newposCurF;
            posCurF[length - 1] = newPos;
        }

        void MList(DListPos^ minuslist)
        {
            DListPos^ result = gcnew DListPos;
            for (int i = 0;i < length; i++)
            {
                for (int j = 0; j < minuslist->getLength();j++)
                {
                    if (minuslist->getPosCurF(j) == posCurF[i])
                    {
                        break;
                    }
                    else if (j == minuslist->getLength() - 1)
                    {
                        result->AddPos(posCurF[i]);
                    }
                }
            }
            posCurF = result->getCurF();
            length = result->getLength();
        }

        void AddNewList(DListPos^ newlist)
        {
            DListPos^ result;
            if (length == 0)
            {
                result = gcnew DListPos(newlist);
            }
            else
            {
                result = gcnew DListPos(posCurF, length);
                for (int i = 0; i < newlist->getLength(); i++)
                {
                    for (int j = 0; j < length;j++)
                    {
                        if (newlist->getPosCurF(i) == posCurF[j])
                        {
                            break;
                        }
                        if (j == length - 1)
                        {
                            result->AddPos(newlist->getPosCurF(i));
                        }
                    }
                }
            }
            posCurF = result->getCurF();
            length = result->getLength();
        }

        void ClearSamePos()
        {
            DListPos^ result = gcnew DListPos;

            for (int i = 0;i < length; i++)
            {
                if (posCurF[i] != nullptr)
                {
                    result->AddPos(posCurF[i]);
                }
                for (int j = i + 1; j < length;j++)
                {
                    if (posCurF[j] == posCurF[i])
                    {
                        posCurF[j] = nullptr;
                    }
                }
            }
            posCurF = result->getCurF();
            length = result->getLength();
        }

        void dispose()
        {
            if (posCurF != nullptr)
            {
                delete[] posCurF;
                length = 0;
            }
        }

        bool FindSamePos(Position^ pos)
        {
            for (int i = 0; i < length; i++)
            {
                if (pos == posCurF[i])
                {
                    return true;
                }
            }
            return false;
        }
    };
}

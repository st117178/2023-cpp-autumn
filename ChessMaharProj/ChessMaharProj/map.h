#pragma once
namespace ChessMaharProj {
    ref class Map
    {
        array <FigureInterface^, 2>^ map = gcnew array <FigureInterface^, 2>(8, 8);
    public:
        array <FigureInterface^, 2>^ getMap()
        {
            return map;
        }

        void SetMasIF(int x, int y, FigureInterface^ figure)
        {
            map[x, y] = figure;
        }

        FigureInterface^ MasIF(int x, int y)
        {
            return map[x, y];
        }

        void AddF(FigureInterface^ fig)
        {
            int i = fig->getPos()->getX();
            int j = fig->getPos()->getY();
            map[i, j] = fig;
        }

        void DeleteF(int i, int j)
        {
            map[i, j] = nullptr;
        }


        Map^ copy()
        {
            Map^ copymap = gcnew Map();
            copymap->map = (array <FigureInterface^, 2>^)map->Clone();
            return copymap;
        }

        void clean()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    map[i, j] = nullptr;
                }
            }
        }
    };
}
#include"InitDesk.h"
#include"Button.h"
#include"map.h"
#pragma once

namespace ChessMaharProj {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// —водка дл€ ChessDesk
    /// </summary>
    ref class ChessDesk : public System::Windows::Forms::Form
    {
    private:
        Form^ endF;

        CButton^ pressButton;
        CButton^ prevButton;

        array <CButton^, 2>^ butts = gcnew array <CButton^, 2>(8, 8);

        InitFDesk^ desk = gcnew InitFDesk();

        bool mahExist = false;

        Image^ dot = gcnew Bitmap("Dot.png");

        Image^ frame = gcnew Bitmap("Frame.png");

    public:
        ChessDesk()
        {
            mahExist = false;
            CreateButts();
            InitializeComponent();
            desk->Start();
            PrintDesk();
            AddMah();
            ChekerSwaper();
        }

        void PrintDesk()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    CButton^ butt = gcnew CButton(gcnew Position(i, j));
                    butt = butts[i, j];
                    if ((i + j) % 2 == 1)
                    {
                        butt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                            static_cast<System::Int32>(static_cast<System::Byte>(192)));
                    }
                    else
                    {
                        butt->BackColor = System::Drawing::Color::Peru;
                    }

                    butt->Image = nullptr;

                    FigureInterface^ figure = desk->getMapMas(i, j);

                    if (mahExist)
                    {
                        if (figure != nullptr)
                        {
                            butt->BackgroundImage = desk->getMapMas(i, j)->getimage();
                            if (figure->getPlayer() == desk->getPlayer())
                            {
                                butt->Enabled = true;
                            }
                            else
                            {
                                butt->Enabled = false;
                            }
                        }
                        else
                        {
                            butt->BackgroundImage = nullptr;
                            butt->Enabled = false;
                        }
                    }
                }
            }
            ShowCheak();
        }

        void AddMah()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {

                    CButton^ butt = gcnew CButton(gcnew Position(i, j));
                    butt = butts[i, j];

                    butt->Enabled = true;

                    FigureInterface^ figure = desk->getMapMas(i, j);

                    if (figure != nullptr)
                    {
                        butt->BackgroundImage = desk->getMapMas(i, j)->getimage();
                    }

                    butt->MouseLeave += gcnew System::EventHandler(this, &ChessDesk::MahLeave);
                    butt->MouseEnter += gcnew System::EventHandler(this, &ChessDesk::MahEnter);

                    butt->Click += gcnew System::EventHandler(this, &ChessDesk::MahClick);

                }
            }
        }

        void MahClick(System::Object^ sender, System::EventArgs^ e)
        {
            CButton^ pressButton = (CButton^)sender;
            int x = pressButton->getposbut()->getX();
            int y = pressButton->getposbut()->getY();

            FigureInterface^ figure = desk->getMapMas(x, y);

            if (!mahExist && figure->getPlayer()->getColor() != PlayerColor::Black)
            {
                int x = pressButton->getposbut()->getX();
                int y = pressButton->getposbut()->getY();
                desk->AddMah(x, y);
                pressButton->BackgroundImage = desk->getMapMas(x, y)->getimage();
                mahExist = true;
                DeleteMahClick();
                PrintDesk();
                ChekerSwaper();
            }
        }

        void MahEnter(System::Object^ sender, System::EventArgs^ e)
        {
            if (!mahExist)
            {
                CButton^ entButton = (CButton^)sender;
                int x = entButton->getposbut()->getX();
                int y = entButton->getposbut()->getY();
                FigureInterface^ figure = desk->getMapMas(x, y);
                if (figure == nullptr)
                {
                    desk->AddMah(x, y);
                    entButton->BackgroundImage = desk->getMapMas(x, y)->getimage();
                }

                else
                {
                    entButton->Cursor = System::Windows::Forms::Cursors::No;
                }
            }
        }

        void MahLeave(System::Object^ sender, System::EventArgs^ e)
        {
            if (!mahExist)
            {
                CButton^ entButton = (CButton^)sender;
                int x = entButton->getposbut()->getX();
                int y = entButton->getposbut()->getY();
                FigureInterface^ figure = desk->getMapMas(x, y);
                if (figure != nullptr && (figure->getPlayer()->getColor()) != PlayerColor::Black)
                {
                    entButton->BackgroundImage = nullptr;
                    desk->DeleteF(x, y);
                }

                else
                {
                    entButton->Cursor = nullptr;
                }
            }
        }

        void DeleteMahClick()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    butts[i, j]->MouseLeave -= gcnew System::EventHandler(this, &ChessDesk::MahLeave);
                    butts[i, j]->MouseEnter -= gcnew System::EventHandler(this, &ChessDesk::MahEnter);

                    butts[i, j]->Click -= gcnew System::EventHandler(this, &ChessDesk::MahClick);
                    butts[i, j]->Click += gcnew System::EventHandler(this, &ChessDesk::DoMove);

                }
            }
        }

        void DoMove(System::Object^ sender, System::EventArgs^ e)
        {
            pressButton = (CButton^)sender;
            desk->SetCurFig(pressButton->getposbut());
            if (prevButton == pressButton)
            {
                PrintDesk();
                pressButton = nullptr;
            }
            else if ((desk->getCurFig() != nullptr && (desk->getIssameplayer() || desk->getPrevFig() == nullptr)))
            {
                if (desk->getIssameplayer() && desk->getPrevFig() != nullptr)
                {
                    PrintDesk();
                }

                if (desk->getPrevFig() == nullptr || desk->getIssameplayer())
                {
                    ShowMove(pressButton);
                }

            }
            else if (desk->getCurFig() == nullptr || !(desk->getIssameplayer()))
            {
                desk->FigureMove(pressButton->getposbut());
                if (desk->getPrevFig()->getIsKing() && ((desk->getDeskPosCurFig()->getY() - desk->getDeskPosPrevFig()->getY()) == 2 || (desk->getDeskPosCurFig()->getY() - desk->getDeskPosPrevFig()->getY()) == -2))
                {
                    desk->DoCastle();
                }
                ChekerSwaper();
            }
            prevButton = pressButton;
        }


        void ShowMove(CButton^ pressedbut)
        {
            desk->findmove();
            for (int i = 0; i < desk->getList()->getLength();i++)
            {
                int x = desk->getList()->getPosCurF(i)->getX();
                int y = desk->getList()->getPosCurF(i)->getY();

                if (desk->getMapMas(x, y) != nullptr)
                {
                    if (desk->getMapMas(x, y)->getPlayer()->getColor() != desk->getCurFig()->getPlayer()->getColor())
                    {
                        butts[x, y]->Image = frame;
                    }
                }
                else
                {
                    butts[x, y]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
                    butts[x, y]->BackgroundImage = dot;
                }
                butts[x, y]->Enabled = true;
            }
            if (pressedbut->BackColor == Color::Peru)
            {
                pressedbut->BackColor = Color::DarkGreen;
            }

            if (pressedbut->BackColor == Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(192))))
            {
                pressedbut->BackColor = Color::LimeGreen;
            }
        }

        void ShowCheak()
        {
            FigureInterface^ cheakF;
            King^ king;

            if (desk->isCheak(cheakF, king))
            {
                butts[king->getPos()->getX(), king->getPos()->getY()]->BackColor = Color::Red;
            }

        }

        void TurnAllBut(bool disen)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    butts[i, j]->Enabled = disen;
                }
            }
            this->Click -= gcnew System::EventHandler(this, &ChessDesk::ChessDesk_Click);
        }

        void ChekerSwaper()
        {
            desk->swapPlyer();
            PrintDesk();
            String^ text = desk->gamestatus();
            if (text != nullptr && mahExist)
            {
                TurnAllBut(false);
                endF = gcnew Form();
                endF->ClientSize = System::Drawing::Size(500, 300);
                endF->MaximumSize = System::Drawing::Size(500, 300);
                endF->MinimumSize = System::Drawing::Size(500, 300);
                endF->Name = L"EndGame";
                endF->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
                endF->Text = L"EndGame";
                Label^ label = (gcnew System::Windows::Forms::Label());
                label->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(204)));
                label->Location = System::Drawing::Point(90, 100);
                label->Name = L"label1";
                label->Size = System::Drawing::Size(309, 19);
                label->TabIndex = 0;
                label->Text = text;
                label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
                Button^ button = (gcnew System::Windows::Forms::Button());
                button->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(204)));
                button->Location = System::Drawing::Point(195, 130);
                button->Name = L"button";
                button->Size = System::Drawing::Size(100, 50);
                button->Text = L"Restart";
                button->Click += gcnew System::EventHandler(this, &ChessDesk::Restart);
                endF->Controls->Add(button);
                endF->Controls->Add(label);
                endF->ShowDialog();
            }
        }

        void Restart(System::Object^ sender, System::EventArgs^ e)
        {
            this->Controls->Clear();
            desk = gcnew InitFDesk();
            mahExist = false;
            CreateButts();
            InitializeComponent();
            desk->Start();
            PrintDesk();
            AddMah();
            ChekerSwaper();
            endF->Close();
        }

        void CreateButts()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    CButton^ butt = gcnew CButton(gcnew Position(i, j));
                    if ((i + j) % 2 == 1)
                    {
                        butt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                            static_cast<System::Int32>(static_cast<System::Byte>(192)));
                    }
                    else
                    {
                        butt->BackColor = System::Drawing::Color::Peru;
                    }
                    butt->Size = System::Drawing::Size(80, 80);
                    butt->Location = Point(125 + j * 80, 669 - i * 80);
                    butt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                    butt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
                    if (i == 0)
                    {
                        String^ word = "\n\n\n\n\n";
                        switch (j)
                        {
                        case 0:
                            word = word + "a";
                            break;
                        case 1:
                            word = word + "b";
                            break;
                        case 2:
                            word = word + "c";
                            break;
                        case 3:
                            word = word + "d";
                            break;
                        case 4:
                            word = word + "e";
                            break;
                        case 5:
                            word = word + "f";
                            break;
                        case 6:
                            word = word + "g";
                            break;
                        }
                        butt->Text = word;
                        butt->Font = (gcnew System::Drawing::Font(L"Arial Black", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                            static_cast<System::Byte>(204)));
                        butt->TextAlign = System::Drawing::ContentAlignment::TopLeft;
                    }

                    if (j == 7)
                    {
                        if (i == 0)
                        {
                            butt->Text = "1\n\n\n\n\nh                    ";//мда
                        }
                        else
                        {
                            butt->Text = Convert::ToString(i + 1);
                        }
                        butt->Font = (gcnew System::Drawing::Font(L"Arial Black", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                            static_cast<System::Byte>(204)));
                        butt->TextAlign = System::Drawing::ContentAlignment::TopRight;
                    }
                    butts[i, j] = butt;
                    this->Controls->Add(butt);
                }
            }
        }
    protected:
        /// <summary>
        /// ќсвободить все используемые ресурсы.
        /// </summary>
        ~ChessDesk()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        /// <summary>
        /// ќб€зательна€ переменна€ конструктора.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChessDesk::typeid));
            this->SuspendLayout();
            // 
            // ChessDesk
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->ClientSize = System::Drawing::Size(885, 867);
            this->DoubleBuffered = true;
            this->MaximumSize = System::Drawing::Size(901, 906);
            this->MinimumSize = System::Drawing::Size(901, 906);
            this->Name = L"ChessDesk";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"ChessDesk";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ChessDesk::ChessDesk_FormClosed);
            this->Load += gcnew System::EventHandler(this, &ChessDesk::ChessDesk_Load);
            this->Click += gcnew System::EventHandler(this, &ChessDesk::ChessDesk_Click);
            this->ResumeLayout(false);

        }

#pragma endregion
    private: System::Void ChessDesk_Load(System::Object^ sender, System::EventArgs^ e) {

    }

    private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void ChessDesk_Click(System::Object^ sender, System::EventArgs^ e) {
        PrintDesk();
        prevButton = nullptr;
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void ChessDesk_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
    }
    };
}

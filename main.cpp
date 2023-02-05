//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "advisor_type.h"
#include "class_characters.h"
#include "results.h"
#include "game_rules.h"
#include "form_reasonOfDeath.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Game *game = new Game();
Advisor a;
TImage *Advisor::im;
AdvisorType Advisor::adv;  
AdvisorType a_type;
King *king = new King;
int years_by_rule = 0;
void StartUp();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	a.im = Image1;
	a.adv = AdvisorType::MILITARY;
	game->StartUpFunc = StartUp;
	game->pbPep = pbPeople;
	game->pbRel = pbReligion;
	game->pbMil = pbMilitary;
	game->pbTre = pbTreasury;
	game->gbUp = gbUpper;
	game->gbDw = gbDown;
	game->lQuest = Label5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StartUp();
}
//---------------------------------------------------------------------------

void StartUp()
{
	king->name = "";
	king->year_count = 0;
	Form1->gbUpper->Visible = false;
	Form1->gbDown->Visible = false;
	Form1->Label5->Caption = "яким буде твоЇ ≥м'€, м≥й Ћорде?";
	Form1->Edit1->Visible = true;
	Form1->Button1->Visible = true;
	Form1->Info1->Enabled = false;
}

void TForm1::EndOfTheGame()
{
	king->year_count = years_by_rule;
	years_by_rule = 0;
	Form2->king1 = king;
	Form2->ShowModal();
	bReplay->Visible = true;
	Label5->Caption = "";
	Edit1->Text = "";
	gbUpper->Visible = false;
	gbDown->Visible = false;
	Info1->Enabled = true;
}

void __fastcall TForm1::bYesClick(TObject *Sender)
{
	years_by_rule++;
	if ((pbPeople->Position < 100 && pbPeople->Position > 0) &
		 (pbReligion->Position < 100 && pbReligion->Position > 0) &
		 (pbMilitary->Position < 100 && pbMilitary->Position > 0) &
		 (pbTreasury->Position < 100 && pbTreasury->Position > 0))
		{
		if (game->CheckQuestion()) {
			switch (game->a_current->CheckAdvisorType()) {
				case AdvisorType::MILITARY:
					pbMilitary->Position += 10;
					break;
				case AdvisorType::TREASURY:
					pbTreasury->Position += 10;
					break;
				case AdvisorType::PEOPLE:
					pbPeople->Position += 10;
					break;
				case AdvisorType::RELIGION:
					pbReligion->Position += 10;
					break;
			}
		}
		else
		{
			switch (game->a_current->CheckAdvisorType()) {
				case AdvisorType::MILITARY:
					pbMilitary->Position -= 10;
					break;
				case AdvisorType::TREASURY:
					pbTreasury->Position -= 10;
					break;
				case AdvisorType::PEOPLE:
					pbPeople->Position -= 10;
					break;
				case AdvisorType::RELIGION:
					pbReligion->Position -= 10;
					break;
			}
		}
		Label5->Caption = game->GenerateRandomQuestion();
	}
	else
	{
		EndOfTheGame();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::bNoClick(TObject *Sender)
{
	years_by_rule++;
	if ((pbPeople->Position < 100 && pbPeople->Position > 0) &
		 (pbReligion->Position < 100 && pbReligion->Position > 0) &
		 (pbMilitary->Position < 100 && pbMilitary->Position > 0) &
		 (pbTreasury->Position < 100 && pbTreasury->Position > 0))
		{
		if (!game->CheckQuestion()) {
			switch (game->a_current->CheckAdvisorType()) {
			case AdvisorType::MILITARY:
				pbMilitary->Position += 10;
				break;
			case AdvisorType::TREASURY:
				pbTreasury->Position += 10;
				break;
			case AdvisorType::PEOPLE:
				pbPeople->Position += 10;
				break;
			case AdvisorType::RELIGION:
				pbReligion->Position += 10;
				break;
			}
		}
        else
		{
			switch (game->a_current->CheckAdvisorType()) {
				case AdvisorType::MILITARY:
					pbMilitary->Position -= 10;
					break;
				case AdvisorType::TREASURY:
					pbTreasury->Position -= 10;
					break;
				case AdvisorType::PEOPLE:
					pbPeople->Position -= 10;
					break;
				case AdvisorType::RELIGION:
					pbReligion->Position -= 10;
					break;
			}
		}
		Label5->Caption = game->GenerateRandomQuestion();
	}
	else
	{
        EndOfTheGame();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	game->LevelInitialization();
	king->name = Edit1->Text;
	gbUpper->Visible = true;
	gbDown->Visible = true;
	Label5->Caption = game->GenerateRandomQuestion();
	Button1->Visible = false;
    Edit1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::bReplayClick(TObject *Sender)
{
	game->LevelInitialization();
    bReplay->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rules1Click(TObject *Sender)
{
	Form5->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Info1Click(TObject *Sender)
{
	Form3->Show();
	if (pbReligion->Position == 100) {
		Form3->ReasonOfDeath(1);    
	}
	if (pbReligion->Position == 0) {
		Form3->ReasonOfDeath(2);    
	}
	if (pbMilitary->Position == 100) {
		Form3->ReasonOfDeath(3);    
	}
	if (pbMilitary->Position == 0) {
		Form3->ReasonOfDeath(4);    
	}
	if (pbPeople->Position == 100) {
		Form3->ReasonOfDeath(5);    
	}
	if (pbPeople->Position == 0) {
		Form3->ReasonOfDeath(6);    
	}
	if (pbTreasury->Position == 100) {
		Form3->ReasonOfDeath(7);    
	}
	if (pbTreasury->Position == 0) {
		Form3->ReasonOfDeath(8);    
	}
}
//---------------------------------------------------------------------------


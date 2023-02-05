//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "results.h"
#include "class_LoadToGrid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
ResultLogin *rl;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	rl = new ResultLogin();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
	rl->sgResults = StringGrid1;
	rl->LoadDataToGrid(king1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "Ім'я монарха:";
	StringGrid1->Cells[1][0] = "Роки правління:";
}
//---------------------------------------------------------------------------


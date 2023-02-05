//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TButton *bYes;
	TButton *bNo;
	TProgressBar *pbReligion;
	TProgressBar *pbPeople;
	TProgressBar *pbMilitary;
	TProgressBar *pbTreasury;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label5;
	TEdit *Edit1;
	TButton *Button1;
	TGroupBox *gbDown;
	TGroupBox *gbUpper;
	TButton *bReplay;
	TMainMenu *MainMenu1;
	TMenuItem *Rules1;
	TMenuItem *Info1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bYesClick(TObject *Sender);
	void __fastcall bNoClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall bReplayClick(TObject *Sender);
	void __fastcall Rules1Click(TObject *Sender);
	void __fastcall Info1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void EndOfTheGame();
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

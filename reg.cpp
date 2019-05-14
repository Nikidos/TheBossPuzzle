//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "reg.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString myName;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  if(Edit1->Text=="") return;
  myName=Edit1->Text.UpperCase();
  Form2->Show();
  Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)  TForm1::SpeedButton1Click(Sender);
}
//---------------------------------------------------------------------------


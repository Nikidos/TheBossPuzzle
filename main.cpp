//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main.h"
#include "reg.h"
#include "tableRez.h"
#include <algorithm>
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int arr[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11 ,12 ,13 ,14 ,15, -1 };
int xCell=0,yCell=0;
int result=0;
bool reztable=false;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner){}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)    // ������ �� �������� �������
{
        Resize=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender) // ��������� �������� ����
{
    result=0;
    for(int i=0;i<StringGrid1->ColCount;i++) StringGrid1->Cols[i]->Clear();
    int tmp[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11 ,12 ,13 ,14 ,15, -1 };
    srand( time(0) );
    int SIZE = sizeof(tmp) / sizeof(*tmp);
    std::random_shuffle(tmp, tmp + SIZE ); // ������������� �������
    int n=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4;j++)
        {
           if(tmp[n]==-1){ // ���� -1 ��������� ������ ������ � ���������� ����������
              n++;
              xCell=i;
              yCell=j;
              continue;
           }
           StringGrid1->Cells[j][i]=tmp[n];
           n++;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N6Click(TObject *Sender) // �������� ����� �������� ����
{
    result=0;
    for(int i=0;i<StringGrid1->ColCount;i++) StringGrid1->Cols[i]->Clear();
    int tmp[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11 ,12 ,13 ,14 ,15, -1 };
    int n=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4;j++)
        {
           if(tmp[n]==-1){
              n++;
              xCell=i;
              yCell=j;
              continue;
           }
           StringGrid1->Cells[j][i]=tmp[n];
           n++;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action) // �������� ����
{
    Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
   Application->MessageBox("���������� ����������� ����� � ������� �� ��������� �����, �� ��� ���� ���� �� ����� ��������� ������������ �������, ��� ���������� ������� ����� ���������, � ��� ���������� ��������� � �������","�������",MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N4Click(TObject *Sender)
{
   Application->MessageBox("����������� ������ ���-11, �����","�� ������",MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N3Click(TObject *Sender)
{
   reztable=true;
   Form3->ShowModal();

}
//---------------------------------------------------------------------------
bool checkSolution(TStringGrid *Grid) // ������� �������� �� �������
{
  int n=0;
  bool solution=true;
  for(int i=0; i<4; i++)
  {
     for(int j=0; j<4;j++,n++)
     {
        if(Grid->Cells[j][i]!=arr[n])
        {
          if(n==15) break;
          solution=false;
        }
     }
  }
  return solution;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::StringGrid1SelectCell(TObject *Sender, int ACol,      // ACol � ARow ���������� ���������� ������
      int ARow, bool &CanSelect) // ������� �������� �� ����������� ����
{
   if(((ACol+1==yCell || ACol-1==yCell) && (ARow==xCell)) ||
           ((ARow+1==xCell || ARow-1==xCell) && (ACol==yCell)))
        {                                                                      // �������� �� ����� ���������� �� �����
           Label2->Caption=StringGrid1->Cells[ACol][ARow];
           Label4->Caption="{ "+IntToStr(yCell+1)+", "+IntToStr(xCell+1)+" }";

           StringGrid1->Cells[yCell][xCell]=StringGrid1->Cells[ACol][ARow];
           StringGrid1->Cells[ACol][ARow]="";
           xCell=ARow;                                                       // �����
           yCell=ACol;
           result++;
           if(checkSolution(StringGrid1)==true)    // �������� �� �������
           {
               reztable=false;
               Form3->ShowModal();
               TForm2::FormShow(Sender);
               result=0;
           }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)   // ��������� �����(�� �����)
{
  int x, y;
  x = Rect.Left + (Rect.Width() - StringGrid1->Canvas->TextWidth(StringGrid1->Cells[ACol][ARow]))/2;
  y = Rect.Top + (Rect.Height() - StringGrid1->Canvas->TextHeight(StringGrid1->Cells[ACol][ARow]))/2;
  StringGrid1->Canvas->FillRect(Rect);
  StringGrid1->Canvas->TextOut(x,y,StringGrid1->Cells[ACol][ARow]);

}
//---------------------------------------------------------------------------


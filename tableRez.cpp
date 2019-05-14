//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tableRez.h"
#include "reg.h"
#include "main.h"
#include <vector>
#include <fstream.h>
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
struct statusIg  // ��������� ������(��� � ��� ���������� �����)
{
   AnsiString name;
   int score;
};
struct pred  // ��� ���������� ���������
{
    bool operator()(const statusIg& ig1, const statusIg& ig2)
    {
        return ig1.score < ig2.score;
    }
};
vector<statusIg> status;  // ������ �������
extern bool reztable;
extern AnsiString myName;
extern result;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{}
//---------------------------------------------------------------------------
void readFile()     // ������ � �����
{
     char line[1024];
     statusIg user;
     ifstream File("data.txt");
     int i=1;
     while(File.getline(line, sizeof(line)))
     {
        if(i%2!=0)
        {
           user.name=line;
        }
        else
        {
           user.score=StrToInt(line);
           status.push_back(user);
        }
        i++;
     }
     File.close();
}
void writeFile()     // ������ � ����
{
     bool hasChange=false;
     bool heExists=false;
     ofstream File;

     for(int i=0; i<(int)status.size();i++)
     {
        if(status[i].name==myName && result<status[i].score)
        {
          status[i].score=result;
          hasChange=true;
        }
        if(status[i].name==myName)
        {
          heExists=true;
        }
     }

     if(hasChange==true)      // ���� ���������� ���������� ����� � ������� �������, �� ������������
     {
        File.open("data.txt");
        for(int i=0; i<(int)status.size();i++)
        {
            File<<status[i].name.c_str()<<endl;
            File<<IntToStr(status[i].score).c_str()<<endl;
        }
        File.close();
        status.clear();
        readFile();
     }

     if(heExists==false)  // ���� ������ �� ���� ������, �������� ���
     {
       File.open("data.txt",std::ios::app);
       File<<myName.c_str()<<endl;
       File<<result<<endl;
       File.close();
       status.clear();
       readFile();
     }
}

void __fastcall TForm3::FormShow(TObject *Sender)  // �������� ����
{
  status.clear();
  ListBox1->Items->Clear();
  readFile();
  if(reztable==true) // ���� ������ ������ ������
  {
     Label1->Caption="���������� :";
     Label2->Caption="";
     std::sort(status.begin(), status.end(), pred());
     for(int i=0; i<(int)status.size();i++)
     {

        ListBox1->Items->Add(IntToStr(i+1)+": "+status[i].name+", ���-�� �����= "+status[i].score);
     }
  }
  else // ���� ��������
  {
     writeFile();
     Label1->Caption="�� �������� :)";
     Label2->Caption="��� ���������: "+IntToStr(result);
     std::sort(status.begin(), status.end(), pred());
     for(int i=0; i<(int)status.size();i++)
     {
        ListBox1->Items->Add(IntToStr(i+1)+": "+status[i].name+", ���-�� ����� = "+status[i].score);
     }
  }
}
//---------------------------------------------------------------------------



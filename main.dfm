object Form2: TForm2
  Left = 376
  Top = 157
  BorderStyle = bsSingle
  Caption = #1055#1103#1090#1085#1072#1096#1082#1080
  ClientHeight = 440
  ClientWidth = 677
  Color = clTeal
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -29
  Font.Name = 'Times New Roman'
  Font.Style = [fsBold]
  Menu = MainMenu1
  OldCreateOrder = False
  OnCanResize = FormCanResize
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 32
  object Label1: TLabel
    Left = 456
    Top = 88
    Width = 205
    Height = 40
    Caption = #1055#1077#1088#1077#1084#1077#1097#1072#1077#1084
    Color = clTeal
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -35
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 536
    Top = 160
    Width = 12
    Height = 55
    Color = clTeal
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clYellow
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label3: TLabel
    Left = 456
    Top = 232
    Width = 193
    Height = 40
    Caption = #1053#1072' '#1087#1086#1079#1080#1094#1080#1102
    Color = clTeal
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -35
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label4: TLabel
    Left = 488
    Top = 304
    Width = 12
    Height = 55
    Color = clTeal
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 433
    Height = 425
    Style = bsRaised
  end
  object Bevel2: TBevel
    Left = 448
    Top = 64
    Width = 225
    Height = 313
    Shape = bsFrame
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 16
    Width = 409
    Height = 409
    Cursor = crHandPoint
    ColCount = 4
    DefaultColWidth = 100
    DefaultRowHeight = 100
    FixedCols = 0
    RowCount = 4
    FixedRows = 0
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = 'Lobster'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 0
    OnDrawCell = StringGrid1DrawCell
    OnSelectCell = StringGrid1SelectCell
  end
  object MainMenu1: TMainMenu
    object N1: TMenuItem
      Caption = #1048#1075#1088#1072
      object N5: TMenuItem
        Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
        OnClick = FormShow
      end
      object N6: TMenuItem
        Caption = #1058#1077#1089#1090#1086#1074#1099#1081' '#1088#1077#1078#1080#1084
        OnClick = N6Click
      end
    end
    object N2: TMenuItem
      Caption = #1055#1088#1072#1074#1080#1083#1072
      OnClick = N2Click
    end
    object N3: TMenuItem
      Caption = #1058#1072#1073#1083#1080#1094#1072' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074
      OnClick = N3Click
    end
    object N4: TMenuItem
      Caption = #1054#1073' '#1072#1074#1090#1086#1088#1077
      OnClick = N4Click
    end
  end
end

object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Hello, King!'
  ClientHeight = 164
  ClientWidth = 307
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 291
    Height = 38
    Caption = #1050#1072#1082' '#1090#1074#1086#1105' '#1080#1084#1103', '#1050#1086#1088#1086#1083#1100'?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 88
    Top = 52
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 88
    Top = 79
    Width = 121
    Height = 42
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 1
    OnClick = BitBtn1Click
  end
end

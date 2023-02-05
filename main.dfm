object Form1: TForm1
  Left = 0
  Top = 0
  ClientHeight = 512
  ClientWidth = 632
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label5: TLabel
    Left = 236
    Top = 97
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object bReplay: TButton
    Left = 236
    Top = 143
    Width = 121
    Height = 25
    Caption = 'Replay'
    TabOrder = 4
    Visible = False
    OnClick = bReplayClick
  end
  object gbDown: TGroupBox
    Left = 8
    Top = 186
    Width = 616
    Height = 303
    TabOrder = 0
    object Image1: TImage
      Left = 168
      Top = 15
      Width = 281
      Height = 272
      Stretch = True
    end
    object bNo: TButton
      Left = 56
      Top = 273
      Width = 75
      Height = 25
      Caption = 'No'
      TabOrder = 0
      OnClick = bNoClick
    end
    object bYes: TButton
      Left = 488
      Top = 273
      Width = 75
      Height = 25
      Caption = 'Yes'
      TabOrder = 1
      OnClick = bYesClick
    end
  end
  object gbUpper: TGroupBox
    Left = 8
    Top = 5
    Width = 616
    Height = 86
    TabOrder = 1
    object Label1: TLabel
      Left = 192
      Top = 13
      Width = 29
      Height = 13
      Caption = #1051#1102#1076#1080
    end
    object Label2: TLabel
      Left = 64
      Top = 13
      Width = 38
      Height = 13
      Caption = #1062#1077#1088#1082#1074#1072
    end
    object Label3: TLabel
      Left = 320
      Top = 16
      Width = 45
      Height = 13
      Caption = #1042#1110#1081#1089#1100#1082#1086#1074#1110
    end
    object Label4: TLabel
      Left = 448
      Top = 16
      Width = 55
      Height = 13
      Caption = #1057#1082#1072#1088#1073#1085#1080#1094#1103
    end
    object pbMilitary: TProgressBar
      Left = 320
      Top = 32
      Width = 97
      Height = 17
      TabOrder = 0
    end
    object pbPeople: TProgressBar
      Left = 192
      Top = 32
      Width = 97
      Height = 17
      TabOrder = 1
    end
    object pbReligion: TProgressBar
      Left = 64
      Top = 32
      Width = 97
      Height = 17
      TabOrder = 2
    end
    object pbTreasury: TProgressBar
      Left = 448
      Top = 32
      Width = 97
      Height = 17
      TabOrder = 3
    end
  end
  object Button1: TButton
    Left = 256
    Top = 143
    Width = 81
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 236
    Top = 116
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 576
    Top = 120
    object Rules1: TMenuItem
      Caption = 'Rules'
      OnClick = Rules1Click
    end
    object Info1: TMenuItem
      Caption = 'Info'
      Enabled = False
      OnClick = Info1Click
    end
  end
end

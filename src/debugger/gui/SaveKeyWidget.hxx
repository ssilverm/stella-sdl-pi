//============================================================================
//
//   SSSS    tt          lll  lll       
//  SS  SS   tt           ll   ll        
//  SS     tttttt  eeee   ll   ll   aaaa 
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2014 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//
// $Id: SaveKeyWidget.hxx 2937 2014-06-29 23:25:53Z stephena $
//============================================================================

#ifndef SAVEKEY_WIDGET_HXX
#define SAVEKEY_WIDGET_HXX

class ButtonWidget;

#include "Control.hxx"
#include "ControllerWidget.hxx"

class SaveKeyWidget : public ControllerWidget
{
  public:
    SaveKeyWidget(GuiObject* boss, const GUI::Font& font, int x, int y,
                  Controller& controller);
    virtual ~SaveKeyWidget() { }

    void loadConfig() { }
    void handleCommand(CommandSender* sender, int cmd, int data, int id);

  private:
    ButtonWidget* myEEPROMErase;
    enum { kEEPROMErase  = 'eeER' };
};

#endif

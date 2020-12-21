/***************************************************************
 * Name:      dep3App.cpp
 * Purpose:   Code for Application Class
 * Author:    cpde template ()
 * Created:   2012-07-19
 * Copyright: cpde template ()
 * License:
 **************************************************************/

#include "dep3App.h"

//(*AppHeaders
#include "dep3Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dep3App);

bool dep3App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	dep3Frame* Frame = new dep3Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

dep3Frame* dep3App::GetFrame()
{
   return (dep3Frame*)GetTopWindow();
}

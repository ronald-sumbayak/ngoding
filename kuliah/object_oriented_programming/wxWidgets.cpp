#include "wx/wx.h"
#ifndef WX_PRECOMP
#endif

class MyApp : public wxApp {
public:
    virtual bool OnInit ();
};

class MyFrame : public wxFrame {
    wxDECLARE_EVENT_TABLE ();
public:
    MyFrame (const wxString &title);
    void OnQuit (wxCommandEvent &event);
    void OnAbout (wxCommandEvent &event);
};

wxBEGIN_EVENT_TABLE (MyFrame, wxFrame)
EVT_MENU (wxID_EXIT, MyFrame::OnQuit)
EVT_MENU (wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE ()
IMPLEMENT_APP (MyApp)

bool MyApp::OnInit () {
    if (!wxApp::OnInit ()) return false;
    MyFrame * frame = new MyFrame ("Minimal wxWidgets App");
    frame->Show (true);
    return true;
}

MyFrame::MyFrame (const wxString &title) : wxFrame (NULL, wxID_ANY, title) {
    #if wxUSE_MENUS
        wxMenu *fileMenu = new wxMenu;
        wxMenu *helpMenu = new wxMenu;helpMenu-> Append (wxID_ABOUT, "&About\tF1", "Show about dialog");
        fileMenu-> Append (wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
        wxMenuBar *menuBar = new wxMenuBar ();
        menuBar-> Append (fileMenu, "&File");
        menuBar->Append (helpMenu, "&Help");
        SetMenuBar (menuBar);
    #endif
    #if wxUSE_STATUSBAR
        CreateStatusBar (2);
        SetStatusText ("Welcome to wxWidgets!");
    #endif
}
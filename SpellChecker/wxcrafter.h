//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef WXCRAFTER_BASE_CLASSES_H
#define WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/hyperlink.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/imaglist.h>
#include <wx/bitmap.h>
#include <map>
#include <wx/icon.h>

class SpellCheckerSettings_base : public wxDialog
{
protected:
    wxStaticText* m_staticText2;
    wxDirPickerCtrl* m_pDirPicker;
    wxHyperlinkCtrl* m_pHyperlink;
    wxStaticText* m_staticText4;
    wxTextCtrl* m_pCurrentLanguage;
    wxListBox* m_pLanguageList;
    wxCheckBox* m_pStrings;
    wxCheckBox* m_pCppComments;
    wxCheckBox* m_pC_Comments;
    wxCheckBox* m_pDox1;
    wxCheckBox* m_pDox2;
    wxButton* m_buttonClearIgnoreList;
    wxStdDialogButtonSizer* m_stdBtnSizer12;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:
    virtual void OnInitDialog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnDirChanged(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnLanguageSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnClearIgnoreList(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOk(wxCommandEvent& event) { event.Skip(); }
    virtual void OnUpdateOk(wxUpdateUIEvent& event) { event.Skip(); }

public:
    SpellCheckerSettings_base(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SpellChecker Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~SpellCheckerSettings_base();
};


class CorrectSpellingDlg_base : public wxDialog
{
protected:
    wxStaticText* m_staticText1;
    wxTextCtrl* m_pMisspelling;
    wxStaticText* m_staticText2;
    wxListBox* m_pSuggestions;
    wxButton* m_button1;
    wxButton* m_button2;
    wxButton* m_button4;
    wxButton* m_button5;
    wxButton* m_button3;

protected:
    virtual void OnInitDialog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnSuggestionSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDblClickSuggestions(wxCommandEvent& event) { event.Skip(); }
    virtual void OnChangeClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnIgnoreClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnAddClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSuggestClick(wxCommandEvent& event) { event.Skip(); }

public:
    CorrectSpellingDlg_base(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Misspelling found!"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CorrectSpellingDlg_base();
};


class SpellCheckerImages16 : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;


protected:

public:
    SpellCheckerImages16();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name) )
            return wxNullBitmap;
        return m_bitmaps.find(name)->second;
    }
    virtual ~SpellCheckerImages16();
};


class SpellCheckerImages24 : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;


protected:

public:
    SpellCheckerImages24();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name) )
            return wxNullBitmap;
        return m_bitmaps.find(name)->second;
    }
    virtual ~SpellCheckerImages24();
};

#endif

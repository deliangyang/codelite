#include "LLDBBreakpoint.h"
#include "json_node.h"
#include <wx/filename.h>
#include "workspace.h"

LLDBBreakpoint::~LLDBBreakpoint()
{
}

LLDBBreakpoint::LLDBBreakpoint(const wxFileName& filename, int line)
    : m_id(wxNOT_FOUND)
    , m_type(kFileLine)
    , m_filename(filename.GetFullPath())
    , m_lineNumber(line)
    , m_parentBP(NULL)
{
}

LLDBBreakpoint::LLDBBreakpoint(const wxString& name)
    : m_id(wxNOT_FOUND)
    , m_type(kFunction)
    , m_name(name)
    , m_lineNumber(wxNOT_FOUND)
    , m_parentBP(NULL)
{
}

bool LLDBBreakpoint::SameAs(LLDBBreakpoint::Ptr_t other) const
{
    return  m_type == other->m_type &&
            m_name == other->m_name &&
            m_filename == other->m_filename &&
            m_lineNumber == other->m_lineNumber;
}

LLDBBreakpoint::Vec_t LLDBBreakpoint::FromBreakpointInfoVector(const BreakpointInfo::Vec_t& breakpoints)
{
    LLDBBreakpoint::Vec_t bps;
    for(size_t i=0; i<breakpoints.size(); ++i) {
        if ( breakpoints.at(i).bp_type == BP_type_break ) {
            LLDBBreakpoint::Ptr_t bp(new LLDBBreakpoint() );
            const BreakpointInfo &gdbBp = breakpoints.at(i);
            bp->SetName( gdbBp.function_name );
            bp->SetFilename( gdbBp.file );
            bp->SetLineNumber( gdbBp.lineno );
            bp->SetType( gdbBp.function_name.IsEmpty() ? kFileLine : kFunction );
            bps.push_back( bp );
        }
    }
    return bps;
}

BreakpointInfo::Vec_t LLDBBreakpoint::ToBreakpointInfoVector(const LLDBBreakpoint::Vec_t& breakpoints)
{
    BreakpointInfo::Vec_t bps;
    for(size_t i=0; i<breakpoints.size(); ++i) {
        LLDBBreakpoint::Ptr_t bp = breakpoints.at(i);
        BreakpointInfo gdbBp;
        gdbBp.function_name = bp->GetName();
        gdbBp.lineno = bp->GetLineNumber();
        gdbBp.file = bp->GetFilename();
        gdbBp.bp_type = BP_type_break;
        bps.push_back( gdbBp );
    }
    return bps;
}

wxString LLDBBreakpoint::ToString() const
{
    wxString str;
    if ( GetType() == kFileLine ) {
        str << "Normal breakpoint. " << GetFilename() << "," << GetLineNumber();

    } else if ( GetType() == kFunction ) {
        str << "Normal breakpoint. " << GetName() << "()";
    }
    return str;
}

bool LLDBBreakpoint::IsValid() const
{
    switch ( GetType() ) {
    case kFileLine:
        return m_lineNumber != wxNOT_FOUND && !m_filename.IsEmpty();
    case kFunction:
        return !m_name.IsEmpty();
    case kInvalid:
    default:
        return false;
    }
}

void LLDBBreakpoint::Copy(LLDBBreakpoint::Ptr_t other)
{
    m_type       = other->m_type;
    m_name       = other->m_name;
    m_filename   = other->m_filename;
    m_lineNumber = other->m_lineNumber;
    m_children   = other->m_children;
    m_id = wxNOT_FOUND;
}

void LLDBBreakpoint::Invalidate()
{
    m_id = wxNOT_FOUND;
    // remove all children for this breakpoint
    m_children.clear();
}

void LLDBBreakpoint::FromJSON(const JSONElement& json)
{
    m_children.clear();
    m_type = json.namedObject("m_type").toInt(kInvalid);
    m_name = json.namedObject("m_name").toString();
    m_filename = json.namedObject("m_filename").toString();
    m_lineNumber = json.namedObject("m_lineNumber").toInt();
    JSONElement arr = json.namedObject("m_children");
    for(int i=0; i<arr.arraySize(); ++i) {
        LLDBBreakpoint bp;
        bp.FromJSON( arr.arrayItem(i) );
        m_children.push_back( bp );
    }
}

JSONElement LLDBBreakpoint::ToJSON() const
{
    JSONElement json = JSONElement::createObject();
    json.addProperty("m_type", m_type);
    json.addProperty("m_name", m_name);
    json.addProperty("m_filename", m_filename);
    json.addProperty("m_lineNumber", m_lineNumber);
    
    JSONElement arr = JSONElement::createArray("m_children");
    json.append( arr );
    for(size_t i=0; i<m_children.size(); ++i) {
        arr.arrayAppend( m_children.at(i)->ToJSON() );
    }
    return json;
}

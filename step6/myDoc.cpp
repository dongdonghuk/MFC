#include "pch.h"
#include "myDoc.h"

IMPLEMENT_DYNCREATE(CMyDoc, CDocument);

BOOL CMyDoc::OnNewDocument() {
	return TRUE;
}

void CMyDoc::Serialize(CArchive& ar) {

}
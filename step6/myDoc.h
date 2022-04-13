#pragma once

class CMyDoc : public CDocument {
public:

	DECLARE_DYNCREATE(CMyDoc);

	virtual BOOL OnNewDocument() override;
	virtual void Serialize(CArchive& ar) override;
};

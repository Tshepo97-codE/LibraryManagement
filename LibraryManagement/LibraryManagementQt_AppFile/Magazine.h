#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Libraryitem.h"
#include <string>

using namespace std;

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:

    Magazine(const QString& title, const QString& author, int id, int issueNumber, bool isBorrowed = false); // Constructor

    int getIssueNumber() const;

    QString getType() const override { return "Magazine"; }
    QString getExtra() const override { return QString::number(issueNumber); }
    void setIssueNumber(int issueNumber);

    virtual QString displayInfo() const override;
};

#endif // MAGAZINE_H


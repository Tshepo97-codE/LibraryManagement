#include "Magazine.h"
#include <sstream> // For building display string

using namespace std;

Magazine::Magazine(const QString& title, const QString& author, int id, int issueNumber, bool isBorrowed):LibraryItem(title, author, id, isBorrowed), issueNumber(issueNumber){}

int Magazine::getIssueNumber() const {return issueNumber;} // Getter
void Magazine::setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }

// Override displayInfo
QString Magazine::displayInfo() const{
    return QString("Magazine: %1 (Issue #%2, ID: %3)")
        .arg(getTitle())
        .arg(issueNumber)
        .arg(getId());
}


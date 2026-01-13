#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>
#include <QDateTime>

class LibraryItem {
protected:
    QString title;
    QString author;
    int id;
    bool isBorrowed;
    QString borrowerName;
    QDateTime borrowDate;

public:
    LibraryItem(const QString& title, const QString& author, int id, bool isBorrowed = false);
    virtual ~LibraryItem();

    // Pure virtual functions
    virtual QString getType() const = 0;
    virtual QString getExtra() const = 0;
    virtual QString displayInfo() const = 0;

    // Getters
    const QString& getTitle() const { return title; }
    const QString& getAuthor() const { return author; }
    int getId() const { return id; }
    bool getIsBorrowed() const { return isBorrowed; }
    const QString& getBorrowerName() const { return borrowerName; }
    const QDateTime& getBorrowDate() const { return borrowDate; }

    // Setters
    void setTitle(const QString& title) { this->title = title; }
    void setAuthor(const QString& author) { this->author = author; }
    void setId(int id) { this->id = id; }
    void setIsBorrowed(bool borrowed) { isBorrowed = borrowed; }
    void setBorrowerInfo(const QString& name, const QDateTime& date) {
        borrowerName = name;
        borrowDate = date;
    }
};

#endif // LIBRARYITEM_H

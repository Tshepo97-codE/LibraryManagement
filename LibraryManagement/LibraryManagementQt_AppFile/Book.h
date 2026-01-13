#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    QString genre;

public:
    // Constructor
    Book(const QString& title, const QString& author, int id, const QString& genre, bool isBorrowed = false);

    // Accessors
    const QString& getGenre() const { return genre; }
    void setGenre(const QString& genre) { this->genre = genre; }

    // Overridden virtual functions
    QString getType() const override { return "Book"; }
    QString getExtra() const override { return genre; }
    QString displayInfo() const override;
};

#endif // BOOK_H

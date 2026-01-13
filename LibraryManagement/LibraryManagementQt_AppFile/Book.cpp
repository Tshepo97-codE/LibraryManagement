#include "Book.h"

Book::Book(const QString& title, const QString& author, int id, const QString& genre, bool isBorrowed)
    : LibraryItem(title, author, id, isBorrowed), genre(genre) {}

QString Book::displayInfo() const {
    return QString("Book: %1 by %2 (Genre: %3, ID: %4)")
        .arg(getTitle())
        .arg(getAuthor())
        .arg(genre)
        .arg(getId());
}

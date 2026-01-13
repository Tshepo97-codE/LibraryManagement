#include "LibraryItem.h"

LibraryItem::LibraryItem(const QString& title, const QString& author, int id, bool isBorrowed)
    : title(title), author(author), id(id), isBorrowed(isBorrowed) {}

LibraryItem::~LibraryItem() {}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QCloseEvent>   // Needed for closeEvent
#include "libraryitem.h"
#include "book.h"
#include "magazine.h"
#include <vector>
#include <QInputDialog>
#include <QString>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect signals
    connect(ui->borrowReturnButton, &QPushButton::clicked, this, &MainWindow::onBorrowedReturnClicked);
    connect(ui->addItemButton, SIGNAL(clicked()), this, SLOT(onAddItemClicked()));
    connect(ui->removeItemButton, SIGNAL(clicked()), this, SLOT(onRemoveItemClicked()));
    connect(ui->toggleBorrowedButton, SIGNAL(clicked()), this, SLOT(onToggleBorrowedClicked()));
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->typeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onTypeChanged(int)));

    // Connect searchButton for click-triggered filtering
    connect(ui->searchButton, &QPushButton::clicked, this, [this]() {
        QString text = ui->searchLineEdit->text();
        populateTable(text);
    });

    // Populate typeComboBox
    ui->typeComboBox->addItem("Book");
    ui->typeComboBox->addItem("Magazine");

    loadLibrary(); // Load previous library data

    // Show/hide extra fields depending on type
    onTypeChanged(ui->typeComboBox->currentIndex());

    populateTable();
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < library.size(); ++i)
        delete library[i];
    delete ui;
}

// Populate Table
void MainWindow::populateTable(const QString &filter) {
    ui->libraryTableWidget->clearContents();

    // Count only items that match the filter to set row count correctly
    int rowCount = 0;
    for (LibraryItem* item : library) {
        QString title = item->getTitle();
        QString author = item->getAuthor();
        if (filter.isEmpty() || title.contains(filter, Qt::CaseInsensitive) || author.contains(filter, Qt::CaseInsensitive)) {
            rowCount++;
        }
    }
    ui->libraryTableWidget->setRowCount(rowCount);

    int row = 0;
    for (LibraryItem* item : library) {
        QString title = item->getTitle();  // Directly use QString
        QString author = item->getAuthor();

        // Apply filter
        if (!filter.isEmpty() && !title.contains(filter, Qt::CaseInsensitive) && !author.contains(filter, Qt::CaseInsensitive)) {
            continue;
        }

        // Column 0: Type
        QString type = "Unknown";
        if (dynamic_cast<Book*>(item)) type = "Book";
        else if (dynamic_cast<Magazine*>(item)) type = "Magazine";
        ui->libraryTableWidget->setItem(row, 0, new QTableWidgetItem(type));

        // Column 1: Title
        ui->libraryTableWidget->setItem(row, 1, new QTableWidgetItem(title));

        // Column 2: Author
        ui->libraryTableWidget->setItem(row, 2, new QTableWidgetItem(author));

        // Column 3: ID
        ui->libraryTableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(item->getId())));

        // Column 4: Genre / Issue
        QString extra;
        if (Book* b = dynamic_cast<Book*>(item)) {
            extra = b->getGenre();  // getGenre() now returns QString
        } else if (Magazine* m = dynamic_cast<Magazine*>(item)) {
            extra = QString::number(m->getIssueNumber());
        }
        ui->libraryTableWidget->setItem(row, 4, new QTableWidgetItem(extra));

        // Column 5: Borrowed
        ui->libraryTableWidget->setItem(row, 5, new QTableWidgetItem(item->getIsBorrowed() ? "Yes" : "No"));

        ui->libraryTableWidget->setItem(row, 6, new QTableWidgetItem(item->getBorrowerName()));
        ui->libraryTableWidget->setItem(row, 7, new QTableWidgetItem(item->getBorrowDate().isValid() ? item->getBorrowDate().toString("yyyy-MM-dd hh:mm") : ""));

        row++;
    }

    // Optional: stretch columns for better appearance
    ui->libraryTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->libraryTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->libraryTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}


// Add Item
void MainWindow::onAddItemClicked() {
    QString type = ui->typeComboBox->currentText();
    QString title = ui->titleLineEdit->text();
    QString author = ui->authorLineEdit->text();
    bool ok;
    int id = ui->idLineEdit->text().toInt(&ok);

    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid ID number");
        return;
    }

    if (type == "Book") {
        QString genre = ui->genreLineEdit->text();
        library.append(new Book(title, author, id, genre));
    } else if (type == "Magazine") {
        int issue = ui->issueLineEdit->text().toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid issue number");
            return;
        }
        library.append(new Magazine(title, author, id, issue));
    }

    populateTable(ui->searchLineEdit->text());
}


// Borrow or Return Item
void MainWindow::onBorrowedReturnClicked() {
    int row = ui->libraryTableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an item to borrow or return.");
        return;
    }

    LibraryItem* item = library[row];
    bool isBorrowed = item->getIsBorrowed();
    QString title = item->getTitle();

    if (!isBorrowed) {
            bool ok;
            QString borrower = QInputDialog::getText(this, "Borrow Item", "Enter borrower's name:", QLineEdit::Normal, "", &ok);
            if (!ok || borrower.isEmpty()) return;

            item->setIsBorrowed(true);
            item->setBorrowerInfo(borrower, QDateTime::currentDateTime());

            QMessageBox::information(this, "Item Borrowed",
                                 QString("\"%1\" borrowed by %2 on %3")
                                 .arg(title)
                                 .arg(borrower)
                                 .arg(item->getBorrowDate().toString("yyyy-MM-dd hh:mm")));
        } else {
            item->setIsBorrowed(false);
            item->setBorrowerInfo("", QDateTime());
            QMessageBox::information(this, "Item Returned",
                                 QString("\"%1\" returned successfully.").arg(title));
        }

    populateTable();
}

// Loading data from txt file
void MainWindow::loadLibrary() {
    QFile file("library_data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() >= 7) {
            QString type = parts[0];
            QString title = parts[1];
            QString author = parts[2];
            QString extra = parts[3];
            bool borrowed = (parts[4] == "1");
            QString borrower = parts[5];
            QDateTime date = QDateTime::fromString(parts[6], Qt::ISODate);

            LibraryItem *newItem;
            if (type == "Book") {
                newItem = new Book(title, author, 0, extra);
            } else {
                newItem = new Magazine(title, author, 0, extra.toInt());
            }

            if (newItem) {
                newItem->setIsBorrowed(borrowed);
                newItem->setBorrowerInfo(borrower, date);
                library.append(newItem);
            }

        }
    }
    file.close();
}
// Remove Item
void MainWindow::onRemoveItemClicked() {
    int row = ui->libraryTableWidget->currentRow();
    if (row >= 0 && row < library.size()) {
        delete library[row];
        library.removeAt(row);
        populateTable(ui->searchLineEdit->text());
    }
}

// Toggle Borrowed
void MainWindow::onToggleBorrowedClicked() {
    int row = ui->libraryTableWidget->currentRow();
    if (row >= 0 && row < library.size()) {
        LibraryItem* item = library[row];
        item->setIsBorrowed(!item->getIsBorrowed());
        populateTable(ui->searchLineEdit->text());
    }
}

// Search Filter
void MainWindow::onSearchTextChanged(const QString &text) {
    populateTable(text);
}

// Show/Hide Fields Depending on Type
void MainWindow::onTypeChanged(int) {
    if (ui->typeComboBox->currentText() == "Book") {
        ui->genreLineEdit->setVisible(true);
        ui->issueLineEdit->setVisible(false);
    } else {
        ui->genreLineEdit->setVisible(false);
        ui->issueLineEdit->setVisible(true);
    }
}

// Saving data in txt file
void MainWindow::saveLibrary() {
    QFile file("library_data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream out(&file);
    for (LibraryItem* item : library) {
        QString type = (dynamic_cast<Book*>(item)) ? "Book" : "Magazine";
        out << item->getType() << "|"
            << item->getTitle() << "|"
            << item->getAuthor() << "|"
            << item->getExtra() << "|"
            << (item->getIsBorrowed() ? "1" : "0") << "|"
            << item->getBorrowerName() << "|"
            << item->getBorrowDate().toString(Qt::ISODate) << "\n";

    }
    file.close();
}

// Save on exit
void MainWindow::closeEvent(QCloseEvent *event) {
    saveLibrary();
    event->accept();
}

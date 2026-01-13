#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QVector>
#include <QTableWidgetItem>
#include "Book.h"
#include "Magazine.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override; // Save on close

private slots:
    void onSearchTextChanged(const QString &text);
    void onToggleBorrowedClicked();
    void onAddItemClicked();
    void onRemoveItemClicked();
    void onTypeChanged(int);
    void onBorrowedReturnClicked(); // Borrow / Return toggle


private:
    Ui::MainWindow *ui;
    QList<LibraryItem*> library;

    void populateTable(const QString &filter = QString());
    void saveLibrary(); // Save to file
    void loadLibrary(); // Load from file
    void clearLibrary(); // Delete all from memory
};

#endif // MAINWINDOW_H

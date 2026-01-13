/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *typeLabel;
    QComboBox *typeComboBox;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *authorLabel;
    QLineEdit *authorLineEdit;
    QLabel *iDLabel;
    QLineEdit *idLineEdit;
    QLabel *genreLabel;
    QLineEdit *genreLineEdit;
    QLabel *issueNoLabel;
    QLineEdit *issueLineEdit;
    QPushButton *addItemButton;
    QGroupBox *groupBox_2;
    QTableWidget *libraryTableWidget;
    QPushButton *toggleBorrowedButton;
    QPushButton *removeItemButton;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QPushButton *borrowReturnButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1997, 1120);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(-30, 840, 41, 241));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 411, 511));
        formLayoutWidget_2 = new QWidget(groupBox);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(30, 20, 351, 201));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        typeLabel = new QLabel(formLayoutWidget_2);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, typeLabel);

        typeComboBox = new QComboBox(formLayoutWidget_2);
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, typeComboBox);

        titleLabel = new QLabel(formLayoutWidget_2);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(formLayoutWidget_2);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, titleLineEdit);

        authorLabel = new QLabel(formLayoutWidget_2);
        authorLabel->setObjectName(QStringLiteral("authorLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, authorLabel);

        authorLineEdit = new QLineEdit(formLayoutWidget_2);
        authorLineEdit->setObjectName(QStringLiteral("authorLineEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, authorLineEdit);

        iDLabel = new QLabel(formLayoutWidget_2);
        iDLabel->setObjectName(QStringLiteral("iDLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, iDLabel);

        idLineEdit = new QLineEdit(formLayoutWidget_2);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, idLineEdit);

        genreLabel = new QLabel(formLayoutWidget_2);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, genreLabel);

        genreLineEdit = new QLineEdit(formLayoutWidget_2);
        genreLineEdit->setObjectName(QStringLiteral("genreLineEdit"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, genreLineEdit);

        issueNoLabel = new QLabel(formLayoutWidget_2);
        issueNoLabel->setObjectName(QStringLiteral("issueNoLabel"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, issueNoLabel);

        issueLineEdit = new QLineEdit(formLayoutWidget_2);
        issueLineEdit->setObjectName(QStringLiteral("issueLineEdit"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, issueLineEdit);

        addItemButton = new QPushButton(groupBox);
        addItemButton->setObjectName(QStringLiteral("addItemButton"));
        addItemButton->setGeometry(QRect(30, 230, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(640, 20, 891, 621));
        libraryTableWidget = new QTableWidget(groupBox_2);
        if (libraryTableWidget->columnCount() < 8)
            libraryTableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        libraryTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        libraryTableWidget->setObjectName(QStringLiteral("libraryTableWidget"));
        libraryTableWidget->setGeometry(QRect(40, 60, 811, 481));
        toggleBorrowedButton = new QPushButton(groupBox_2);
        toggleBorrowedButton->setObjectName(QStringLiteral("toggleBorrowedButton"));
        toggleBorrowedButton->setGeometry(QRect(440, 30, 211, 23));
        removeItemButton = new QPushButton(groupBox_2);
        removeItemButton->setObjectName(QStringLiteral("removeItemButton"));
        removeItemButton->setGeometry(QRect(240, 30, 201, 23));
        searchButton = new QPushButton(groupBox_2);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(40, 30, 75, 23));
        searchLineEdit = new QLineEdit(groupBox_2);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        searchLineEdit->setGeometry(QRect(120, 30, 113, 20));
        borrowReturnButton = new QPushButton(groupBox_2);
        borrowReturnButton->setObjectName(QStringLiteral("borrowReturnButton"));
        borrowReturnButton->setGeometry(QRect(650, 30, 131, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1997, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        typeLabel->setText(QApplication::translate("MainWindow", "Type", 0));
        titleLabel->setText(QApplication::translate("MainWindow", "Title", 0));
        authorLabel->setText(QApplication::translate("MainWindow", "Author", 0));
        iDLabel->setText(QApplication::translate("MainWindow", "ID", 0));
        genreLabel->setText(QApplication::translate("MainWindow", "Genre", 0));
        issueNoLabel->setText(QApplication::translate("MainWindow", "Issue No.", 0));
        addItemButton->setText(QApplication::translate("MainWindow", "Add Item", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        QTableWidgetItem *___qtablewidgetitem = libraryTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem1 = libraryTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem2 = libraryTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Author", 0));
        QTableWidgetItem *___qtablewidgetitem3 = libraryTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem4 = libraryTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Genre/Issue Number", 0));
        QTableWidgetItem *___qtablewidgetitem5 = libraryTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Borrowed", 0));
        QTableWidgetItem *___qtablewidgetitem6 = libraryTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Borrower Name", 0));
        QTableWidgetItem *___qtablewidgetitem7 = libraryTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Borrow Date", 0));
        toggleBorrowedButton->setText(QApplication::translate("MainWindow", "Toggle Borrowed Status", 0));
        removeItemButton->setText(QApplication::translate("MainWindow", "Remove selected item", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        borrowReturnButton->setText(QApplication::translate("MainWindow", "Borrow/Return", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cwchar>
#include <iomanip>
#include <iostream>
#include <shlwapi.h>
#include <sstream>
#include <string>
#include <urlmon.h>
#include <vector>
#include <windows.h>
#include <xlsxio_read.h>

#include <QStyledItemDelegate>
#include <QtSql>
#include <QtWidgets>

#include "row.h"
#include "ui_bookwindow.h"

#pragma comment(lib, "urlmon.lib")

using namespace std;

class Window : public QMainWindow
{
    Q_OBJECT
public:
    Window();
private:
    vector<Row> entireTable;

    void setUp_temp_folder();
    void downloadExcelFile_and_storeItsData();
    wchar_t* pathToTempFolder();
    char* wideToNarrow(const wchar_t* wideStr);
    void storeExcelFileData(const char* destination);
    bool isLeapYear(const int year);
    int daysInMonth(const int year, const int month);
    string convertDate(const char* excelDate);
    string convertTime(const char* excelTime);

    void createTable_and_displayIt();
};

#endif

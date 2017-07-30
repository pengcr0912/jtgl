#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diagramscene.h"
#include "propertiesdialog.h"
#include <QtWidgets>
#include <QGraphicsView>
#include <QDatetime>
#include <QTimer>
#include "mysql.h"
#include "queryresult.h"
#include <QUdpSocket>
//#include "deviceinfo.h"

#pragma execution_character_set("utf-8");

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QToolBar;
class QUndoStack;
class QFontComboBox;
class QFont;
class QToolBox;
QT_END_NAMESPACE
class DiagramScene;
class BaseItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsView *view;

    QTimer *timer;
    QDateTimeEdit* timeStart;
    QDateTimeEdit* timeEnd;
    QComboBox* comboBox_style;
    QComboBox* comboBox_code;
    QTableWidget* selectable;
    QTableWidget* selected;
    QStringList codeList;
    QStringList paramList;
    QMultiMap<QString, QString> multiMap;
    int rowCnt;
    QStringList selectedList;
    QStringList columnList;

    QMap<QString, QString> paramValueMap;

    int genDataCnt;
    QList<double> genDataList;
    QUdpSocket* socket;
    QSqlQuery query;
    QString insertline;
    QMap<BYTE, QString> logTypeMap;
    QMap<QString,bool> onlineMap;

protected:
//    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void bringToFront();
    void sendToBack();
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void cut();
    void copy();
    void paste();
    void addCircle();
    void addRect();
    void addLine();
    void addText();
    void addPix();
    void addArrow();
    void addDoubleArrow();
    void deleteItem();
    void updateActions();
    QString strippedName(const QString &fullFileName);
    void itemSelected(QGraphicsItem *item);
    void handleFontChange();

    void startQuery();
    void styleChanged(const QString& style);
    void codeChanged(const QString& code);
    void addParam(int i, int j);
    void deleteParam(int i, int j);
private slots:
    void fillColorChanged();
    void fillColorButtonTriggered();

    void outlineColorChanged();
    void outlineColorButtonTriggered();

    void outlineWidthChanged();
    void outlineWidthButtonTriggered();

    void pointerButtonClicked();

    void openRecentFile();
    void updateRecentFileActions();

    void currentFontChanged(const QFont &font);
    void fontSizeChanged(const QString &size);
    void sceneScaleChanged(const QString &scale);
    void sceneScaleChanged(double newScale);
    void lineWidthChanged();

    void properties();
    void textColor();
    void fillColor();
    void lineColor();

    void group();
    void ungroup();

    void insertValue();
    void startInsert();
    void stopInsert();

    void genData();
    void dataReceived();
    void isOnline();

private:
    void createActions();
    void createMenus();
    void createToolbars();
    void createToolBox();

    void sleep(unsigned int msec);

    void writeLog(int iType, QString strLog);

    QMenu *createColorMenu(const char *slot, QColor defaultColor);
    QMenu *createLineMenu(const char *slot );
    QIcon createColorIcon(QColor color);
    QIcon creatTextColorIcon(QColor color);
    QIcon creatFillColorIcon(QColor color);
    QIcon creatLineColorIcon(QColor color);
    QIcon createColorToolButtonIcon(const QString &imageFile, QColor color);
    QIcon createLineToolButtonIcon();
    QIcon createLineIcon(const int width);

    bool okToContinue();
    bool saveFile(const QString &fileName);
    bool loadFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *arrangeMenu;
    QMenu *tableMenu;
    QMenu *toolMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;

    QToolBox *toolBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *backgroundButtonGroup;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QToolBar *ItemToolBar;
    QToolBar *colorToolBar;
    QToolBar *textToolBar;
    QToolBar *scaleToolBar;
    QToolBar *pointToolBar;
    QToolButton *fillColorToolButton;
    QToolButton *lineColorToolButton;
    QToolButton *lineWidthToolButton;

    QComboBox *fontSizeCombo;
    QFontComboBox *fontCombo;
    QComboBox *sceneScaleCombo;
    QComboBox *lineWidthCombo;

    QListWidget* logWidget;
    int logRowCnt;

    QStringList recentFiles;
    QString curFile;

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;


    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *exitAction;
    QAction *toFrontAction;
    QAction *sendBackAction;
    QAction *addCircleAction;
    QAction *addRectangleAction;
    QAction *addTriangleAction;
    QAction *addLineAction;
    QAction *addTextAction;
    QAction *addPixAction;
    QAction *addArrowAction;
    QAction *addDoubleArrowAction;
    QAction *deleteAction;
    QAction *fillAction;
    QAction *lineAction;
    QAction *lineWidthAction;
    QAction *boldAction;
    QAction *underlineAction;
    QAction *italicAction;
    QAction *propertiesAction;
    QAction *textColorAction;
    QAction *fillColorAction;
    QAction *lineColorAction;
    QAction *groupAction;
    QAction *ungroupAction;

    DiagramScene *myDiagramScene;
};

#endif // MAINWINDOW_H

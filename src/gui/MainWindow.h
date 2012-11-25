#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QWidget>
#include "Core.h"


namespace Robomongo
{
    class LogWidget;
    class ExplorerWidget;
    class MongoManager;
    class SettingsManager;
    class Dispatcher;
    class ConnectionFailedEvent;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow();
        bool event(QEvent *event);

    private:
        /*
        ** Status
        */
        QLabel *_status;

        /*
        ** Log panel
        */
        LogWidget *_log;

        /*
        ** The only Explorer in the window
        */
        ExplorerWidget *_explorer;

        /**
         * @brief MongoManager
         */
        MongoManager &_mongoManager;
        SettingsManager &_settingsManager;
        Dispatcher &_dispatcher;

        void createDatabaseExplorer();

    signals:

    public slots:
        void manageConnections();
        void refreshConnections();

    private:
        void handle(ConnectionFailedEvent *event);
    };

}

#endif // MAINWINDOW_H
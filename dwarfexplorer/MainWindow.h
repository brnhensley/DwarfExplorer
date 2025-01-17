/*
 * Copyright 2019 Clement Vuchener
 *
 * This file is part of qtlabors plugin for DFHack
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef DWARFEXPLORER_MAIN_WINDOW_H
#define DWARFEXPLORER_MAIN_WINDOW_H

#include <QMainWindow>

#include <Core.h>
#include <QCloseEvent>
#include <QSortFilterProxyModel>

#include <memory>
#include <utility>
#include <vector>
#include "df_model.h"
#include "QtModel/df_proxy_model.h"

    class EventProxy;

    namespace Ui
    {
        class MainWindow;
    }

    class DFStructure_Window;

    class MainWindow: public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow(std::shared_ptr<EventProxy> &&proxy, QWidget *parent = nullptr);
        ~MainWindow() override;

    signals:
        void resumed_signal();

    private slots:
        void on_suspend_action_triggered();
        void on_resume_action_triggered();
        void on_treeView_expanded(const QModelIndex& p_index);
        void on_actionOpen_in_new_window_triggered();
        void on_actionOpen_in_hex_viewer_triggered();
        void on_actionOpenPointer_in_hex_viewer_triggered();
        void on_filter_textChanged(const QString &arg1);
    protected:
        void closeEvent(QCloseEvent* p_close_event);
    private:
        std::unique_ptr<Ui::MainWindow>        ui;
        std::shared_ptr<EventProxy>            event_proxy;
        std::unique_ptr<DF_Model>              m_model;
        std::unique_ptr<QSortFilterProxyModel> m_proxy_model;
        DFHack::CoreSuspender*                 m_core_suspender;
        bool                                   m_suspended;
    };

#endif

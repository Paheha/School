/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/*
    This file defines a helper function to open a connection to an
    in-memory SQLITE database and to create a test table.

    If you want to use another database, simply modify the code
    below. All the examples in this directory use this function to
    connect to a database.
*/
//! [0]
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("create table class1 (id int primary key, "
               "firstname varchar(20), middlename varchar(20), lastname varchar(20), gender varchar(20), level varchar(20), contract varchar(20))");
    query.exec("insert into class1 values(1, 'Петрова', 'Маша', 'Сергеевна', 'Ж', 'Высокий', 'Да')");
    query.exec("insert into class1 values(2, 'Петрова', 'Маша', 'Сергеевна', 'Ж', 'Высокий', 'Да')");

    query.exec("create table class2 (id int primary key, "
               "firstname varchar(20), middlename varchar(20), lastname varchar(20), gender varchar(20), level varchar(20), contract varchar(20))");
    query.exec("insert into class2 values(1, 'Петрова', 'Катя', 'Сергеевна', 'Ж', 'Высокий', 'Да')");
    query.exec("insert into class2 values(2, 'Петрова', 'Катя', 'Сергеевна', 'Ж', 'Высокий', 'Да')");

    query.exec("create table reserve (id int primary key, "
               "firstname varchar(20), middlename varchar(20), lastname varchar(20), gender varchar(20), level varchar(20), contract varchar(20))");
    return true;
}
//! [0]

#endif

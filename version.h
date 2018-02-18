#ifndef VERSION_H
#define VERSION_H
#include <QString>
#include <QDate>
#include <QApplication>

#include "app_features.h"

const int VERSION_MAJOR = 1;//0;
const int VERSION_MINOR = 0;//8;
const int BUILD_NUM = 101;

static const QDate TRIAL_DATE(2016,7,11);
#undef SVN_REV
static QString versionFull()
{
    QString ver = QString::number(VERSION_MAJOR)
          + "." + QString::number(VERSION_MINOR)
#ifndef SVN_REV
          + "." + QString::number(BUILD_NUM);
#else
          + " r" + QString(SVN_REV);
#endif
#ifdef TRIAL_VERSION
    ver+=QString("<br><b>Пробна версія до ")+TRIAL_DATE.toString();
#endif
#ifdef TEST_BASE
    ver+=QString("<br>ТЕСТОВА БАЗА ДАНИХ");
#endif
#ifdef DISABLE_CACHE
    ver+=QString("<br>Кеш вимкнено");
#endif
    return ver;
}

#ifdef TRIAL_VERSION
inline void trial_exit()
{
    if (QDate::currentDate() > TRIAL_DATE)
        QApplication::exit(0);
}
#else
inline void trial_exit()
{

};

#endif

#endif // VERSION_H

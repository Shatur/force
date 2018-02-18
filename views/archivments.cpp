#include "archivments.h"
#include "ui_archivments.h"

#include "backend/api.h"
#include "uihelper.h"
#include "viewmanager.h"
#include "widgets/archivment.h"

Archivments::Archivments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Archivments)
{
    ui->setupUi(this);

    uiHelper.setupListWidget(ui->archList);

}

Archivments::~Archivments()
{
    delete ui;
}

bool Archivments::setup()
{
    Fesko::TArchivments archs;
    int err = Fesko::API.getArchivments(archs);

    if (Fesko::NO_ERROR != err) return false;

    for(int i=archs.size()-1; i>=0; i--)
    {
        uiHelper.addWidgetToList(ui->archList, new Archivment(archs[i]));
    }

    return true;
}

void Archivments::on_backButton_clicked()
{
    views.pop();
}

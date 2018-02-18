#include "reportitem.h"
#include "ui_reportitem.h"
#include "backend/sqldataprovider.h"

#include "uihelper.h"



ReportItem::ReportItem(int id, const QVector<QString> &staticReportFields,
                       const QVector<QString> &reportFields,
                       Fesko::SReportItem *report_item, bool isRO, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportItem)
{
    Q_UNUSED(staticReportFields);

    ui->setupUi(this);

    widthParent = uiHelper.viewProperties().winWidth - 5;

    readOnly = isRO;//буде зумовлювати чи можли внести зміна до полів вводу
    rpItem = report_item;
    idPosition = id;
    sizeRatio = Fesko::sql_provider()->fontSize();
    font.setPixelSize(sizeRatio);
    setRowName();
    setRowAttr();
    setRowEdit();
//конструктор
}

ReportItem::~ReportItem()
{
    delete ui;
}

void ReportItem::updateData()
{    
    QMap<QString*, QLineEdit*>::iterator it = valuesBinding.begin();
    while (it != valuesBinding.end())
    {
        QLineEdit* wgt = it.value();
        QString* val = it.key();

        QString wgt_val = wgt->text();

        if (editToCb.contains(wgt))
        {
            //if has checkbox get it
            QCheckBox* cb = editToCb[wgt];
            if (cb->isChecked())
            {
                wgt_val = "on";
            }
        }

        *val = wgt_val;

        ++it;
    }
}

void ReportItem::stateChanged(int state)
{
    QCheckBox* cb = dynamic_cast<QCheckBox*>(QObject::sender());
    if (!cb) return;
    if (!cbToEdit.contains(cb)) return;
    QLineEdit* edit = cbToEdit[cb];
    edit->setEnabled(!state);
}

void ReportItem::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<"next control";
    switch (e->key ()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        focusNextPrevChild (true);
        break;

    default:
        QWidget::keyPressEvent (e);
    }
}

void ReportItem::typeSeven(QLineEdit *edit, int i)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QCheckBox* chekBox = new QCheckBox(this);
    chekBox->setEnabled(!readOnly);

    if (rpItem->reportValues[i].value == "on")
    {
        chekBox->setChecked(true);
        edit->setText("");
        edit->setEnabled(false);
    }
    cbToEdit[chekBox] = edit;
    editToCb[edit] = chekBox;
    connect(chekBox, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int)));

    edit->setMaximumWidth((widthParent*(0.0425*sizeRatio))/2);
    chekBox->setMaximumWidth(sizeRatio*3);
    chekBox->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed);
    layout->addWidget(edit);
    layout->addWidget(chekBox);
    ui->uiRgColumn->addLayout(layout);
//якщо type == 7 добавляємо чек бокс. Поле вводу йде сумісно.
}

void ReportItem::setRowName()
{    

    QLabel *nameLabel = new QLabel;
    nameLabel->setMaximumWidth(widthParent-50);

    QString val;
    val.append('[');
    val.append(QString::number(idPosition+1));//id йде із католопейдж
    val.append(']');
    val.append(' ');
    val.append(rpItem->staticValues[0]);
    ui->uiLabelName->setText(val);
    font.setBold(true);
    ui->uiLabelName->setFont(font);
    font.setBold(false);
    ui->uiLabelName->setMaximumWidth(widthParent-50);

//зробили рядок із назвою позиції
//далі піде понад колонками
}

void ReportItem::setRowAttr()
{
    for(int i=1; i<rpItem->staticValues.size(); i++)
    {
        QLabel* attrLabel = new QLabel(this);
        font.setItalic(true);
        attrLabel->setFont(font);
        font.setItalic(false);
        attrLabel->setText(rpItem->staticValues[i]);
        ui->uiLfColumn->addWidget(attrLabel);
    }
    //зробили рядок із атрибутами. їх може бути декілька
//формує ліву колонку із статичними даними
}

void ReportItem::setRowEdit()
{

    for(int i=0; i<rpItem->reportValues.size(); i++)
    {
        QLineEdit* lineEdit = new QLineEdit(this);
        lineEdit->setMaxLength(5);
        lineEdit->setMaximumWidth(widthParent*(0.0525*sizeRatio));//коефіцієт обумовлює розмір поля в залежності від сайза фонту
        lineEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        lineEdit->setAlignment(Qt::AlignRight);
        lineEdit->setReadOnly(readOnly);
        lineEdit->setFont(font);
        lineEdit->setText(rpItem->reportValues[i].value);
        if(rpItem->reportValues[i].type != 7)
            ui->uiRgColumn->addWidget(lineEdit);
        else
            typeSeven(lineEdit,i);
    }
//формує праву колонку із полями вводу
}

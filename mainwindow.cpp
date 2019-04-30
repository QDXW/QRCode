#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <QValidator>
#include <QFileDialog>
#include "QDir"
#include "QTextCodec"
#include "QMessageBox"
#include "QStandardPaths"
#include "QTextStream"
#include "QTextEdit"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox msg;

    Init();
    QRPixmap = NULL;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
   Password_Information = new Password;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Init(void)
{
    /* 限定S100&C100试剂卡名称格式 */
    QRegExp Reagent_name("[a-zA-z0-9_ _]{19}");
    QValidator *Reagent_Name = new QRegExpValidator(Reagent_name,this);
    ui->ProductType_Name ->setValidator(Reagent_Name);
    ui->ProductType_Name_S ->setValidator(Reagent_Name);

    /* 限定S100&C100生产批号格式 */
    QRegExp Reagent_SN("[0-9]{8}");
    QValidator *reagent_SN = new QRegExpValidator(Reagent_SN,this);
    ui->ProductSN ->setValidator(reagent_SN);
    ui->ProductSN_S ->setValidator(reagent_SN);

    /* 限定S100&C100反应时间格式 */
    QRegExp Reagent_time("[0-9]{2}");
    QValidator *Reagent_Time = new QRegExpValidator(Reagent_time,this);
    ui->time ->setValidator(Reagent_Time);
    ui->time_S ->setValidator(Reagent_Time);

    /* 限定所有阈值格式 */
    QRegExp rx("^(500|[0-4]?\\d?\\d(\\.\\d{1,2})?)$");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);

    /* 限定S100阈值1 */
    ui->CH1_threshold1_S->setValidator(pReg);
    ui->CH2_threshold1_S->setValidator(pReg);
    ui->CH3_threshold1_S->setValidator(pReg);
    ui->CH4_threshold1_S->setValidator(pReg);
    ui->CH5_threshold1_S->setValidator(pReg);
    ui->CH6_threshold1_S->setValidator(pReg);
    ui->CH7_threshold1_S->setValidator(pReg);
    ui->CH8_threshold1_S->setValidator(pReg);
    ui->CH9_threshold1_S->setValidator(pReg);
    ui->CH10_threshold1_S->setValidator(pReg);

    /* 限定S100阈值3 */
    ui->CH1_threshold2_S->setValidator(pReg);
    ui->CH2_threshold2_S->setValidator(pReg);
    ui->CH3_threshold2_S->setValidator(pReg);
    ui->CH4_threshold2_S->setValidator(pReg);
    ui->CH5_threshold2_S->setValidator(pReg);
    ui->CH6_threshold2_S->setValidator(pReg);
    ui->CH7_threshold2_S->setValidator(pReg);
    ui->CH8_threshold2_S->setValidator(pReg);
    ui->CH9_threshold2_S->setValidator(pReg);
    ui->CH10_threshold2_S->setValidator(pReg);

    /* 限定S100阈值3 */
    ui->CH1_threshold3_S->setValidator(pReg);
    ui->CH2_threshold3_S->setValidator(pReg);
    ui->CH3_threshold3_S->setValidator(pReg);
    ui->CH4_threshold3_S->setValidator(pReg);
    ui->CH5_threshold3_S->setValidator(pReg);
    ui->CH6_threshold3_S->setValidator(pReg);
    ui->CH7_threshold3_S->setValidator(pReg);
    ui->CH8_threshold3_S->setValidator(pReg);
    ui->CH9_threshold3_S->setValidator(pReg);
    ui->CH10_threshold3_S->setValidator(pReg);

    /* 限定C100阈值1 */
    ui->CH1_threshold1->setValidator(pReg);
    ui->CH2_threshold1->setValidator(pReg);
    ui->CH3_threshold1->setValidator(pReg);
    ui->CH4_threshold1->setValidator(pReg);
    ui->CH5_threshold1->setValidator(pReg);
    ui->CH6_threshold1->setValidator(pReg);
    ui->CH7_threshold1->setValidator(pReg);
    ui->CH8_threshold1->setValidator(pReg);
    ui->CH9_threshold1->setValidator(pReg);
    ui->CH10_threshold1->setValidator(pReg);
    ui->CH11_threshold1->setValidator(pReg);
    ui->CH12_threshold1->setValidator(pReg);
    ui->CH13_threshold1->setValidator(pReg);
    ui->CH14_threshold1->setValidator(pReg);
    ui->CH15_threshold1->setValidator(pReg);
    ui->CH16_threshold1->setValidator(pReg);
    ui->CH17_threshold1->setValidator(pReg);

    /* 限定C100阈值2 */
    ui->CH1_threshold2->setValidator(pReg);
    ui->CH2_threshold2->setValidator(pReg);
    ui->CH3_threshold2->setValidator(pReg);
    ui->CH4_threshold2->setValidator(pReg);
    ui->CH5_threshold2->setValidator(pReg);
    ui->CH6_threshold2->setValidator(pReg);
    ui->CH7_threshold2->setValidator(pReg);
    ui->CH8_threshold2->setValidator(pReg);
    ui->CH9_threshold2->setValidator(pReg);
    ui->CH10_threshold2->setValidator(pReg);
    ui->CH11_threshold2->setValidator(pReg);
    ui->CH12_threshold2->setValidator(pReg);
    ui->CH13_threshold2->setValidator(pReg);
    ui->CH14_threshold2->setValidator(pReg);
    ui->CH15_threshold2->setValidator(pReg);
    ui->CH16_threshold2->setValidator(pReg);
    ui->CH17_threshold2->setValidator(pReg);

    /* 限定C100阈值2 */
    ui->CH1_threshold3->setValidator(pReg);
    ui->CH2_threshold3->setValidator(pReg);
    ui->CH3_threshold3->setValidator(pReg);
    ui->CH4_threshold3->setValidator(pReg);
    ui->CH5_threshold3->setValidator(pReg);
    ui->CH6_threshold3->setValidator(pReg);
    ui->CH7_threshold3->setValidator(pReg);
    ui->CH8_threshold3->setValidator(pReg);
    ui->CH9_threshold3->setValidator(pReg);
    ui->CH10_threshold3->setValidator(pReg);
    ui->CH11_threshold3->setValidator(pReg);
    ui->CH12_threshold3->setValidator(pReg);
    ui->CH13_threshold3->setValidator(pReg);
    ui->CH14_threshold3->setValidator(pReg);
    ui->CH15_threshold3->setValidator(pReg);
    ui->CH16_threshold3->setValidator(pReg);
    ui->CH17_threshold3->setValidator(pReg);

    /* 限定C100试剂卡名称格式 */
    QRegExp regxuser("[A-Z0-9]{6}");
    QValidator *validator = new QRegExpValidator(regxuser,this);
    ui->CH1_name->setValidator(validator);
    ui->CH2_name->setValidator(validator);
    ui->CH3_name->setValidator(validator);
    ui->CH4_name->setValidator(validator);
    ui->CH5_name->setValidator(validator);
    ui->CH6_name->setValidator(validator);
    ui->CH8_name->setValidator(validator);
    ui->CH9_name->setValidator(validator);
    ui->CH10_name->setValidator(validator);
    ui->CH11_name->setValidator(validator);
    ui->CH12_name->setValidator(validator);
    ui->CH13_name->setValidator(validator);
    ui->CH14_name->setValidator(validator);
    ui->CH15_name->setValidator(validator);
    ui->CH16_name->setValidator(validator);
    ui->CH17_name->setValidator(validator);

    /* 限定S100试剂卡名称格式 */
    ui->CH1_name_S->setValidator(validator);
    ui->CH2_name_S->setValidator(validator);
    ui->CH3_name_S->setValidator(validator);
    ui->CH4_name_S->setValidator(validator);
    ui->CH5_name_S->setValidator(validator);
    ui->CH6_name_S->setValidator(validator);
    ui->CH7_name_S->setValidator(validator);
    ui->CH8_name_S->setValidator(validator);
    ui->CH9_name_S->setValidator(validator);
    ui->CH10_name_S->setValidator(validator);

    setFixedSize(this->width(), this->height());

    ui->QRlabel_C100->setText(tr("No Data"));
    ui->QRlabel_C100->setAlignment(Qt::AlignCenter);

    ui->QRlabel_S100->setText(tr("No Data"));
    ui->QRlabel_S100->setAlignment(Qt::AlignCenter);

    ui->groupBox->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
}
/*************************************************
Function:
Description:
Input:
Return:
Others: C100二维码
*************************************************/
void MainWindow::on_Generate_pushButton_clicked()
{
    /* 0.清空结构体数据 */
    memset((uint8 *)&ReagentSrtipQRcode, 0, sizeof(ReagentSrtipQRcode));

    uint16 length = 0;
    uint8 stripNum = 0;

    /**********************************************************************/
    /* 1.数据头数据导入 */
    memcpy(ReagentSrtipQRcode.head.name, ui->ProductType_Name->text().toLatin1().data(), ui->ProductType_Name->text().toLatin1().length());
    memcpy(ReagentSrtipQRcode.head.SN, ui->ProductSN->text().toLatin1().data(), ui->ProductSN->text().toLatin1().length());
    ReagentSrtipQRcode.head.time = ui->time->text().toInt();
    ReagentSrtipQRcode.head.midC = ui->Center_LineC->text().toInt();
    ReagentSrtipQRcode.head.distC_T = ui->T1_Ccenter->text().toInt();
    ReagentSrtipQRcode.head.distC_Base1 = ui->base_CAndEdge->text().toInt();
    ReagentSrtipQRcode.head.distC_Base2 = ui->base_CAndT1_1->text().toInt();
    ReagentSrtipQRcode.head.distC_Base3 = ui->base_CAndT1_2->text().toInt();
    ReagentSrtipQRcode.head.distC_Base4 = ui->base_TAndEdge->text().toInt();
    stripNum = ui->ProductNum->text().toInt();
    ReagentSrtipQRcode.head.stripNum = stripNum;
    ReagentSrtipQRcode.head.searchHalfRadius_C = ui->SearchHalfRadius_C->text().toInt();
    ReagentSrtipQRcode.head.searchHalfRadius_T = ui->SearchHalfRadius_T->text().toInt();
    ReagentSrtipQRcode.head.areaC_HalfRadius = ui->AreaC_HalfRadius->text().toInt();
    ReagentSrtipQRcode.head.areaT_HalfRadius = ui->AreaT_HalfRadius->text().toInt();
    ReagentSrtipQRcode.head.winSize = ui->WinSize->text().toInt();
    ReagentSrtipQRcode.head.limitEnabled = ui->LimitEnabled->text().toInt();
    ReagentSrtipQRcode.head.C_stepSize = ui->C_StepSize->text().toInt();
    ReagentSrtipQRcode.head.C_magnitude = ui->C_Magnitude->text().toInt();
    ReagentSrtipQRcode.head.C_MIN = ui->C_Min->text().toInt();
    ReagentSrtipQRcode.head.Model = 4;

    /*3.2名称及阈值*/
    memcpy(ReagentSrtipQRcode.ch_data[0].TName,ui->CH1_name->text().toLatin1().data(),ui->CH1_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[0].Switch_Bool = ui->CheckBox1->isChecked();
    ReagentSrtipQRcode.ch_data[0].threshold1 = ui->CH1_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[0].threshold2 = ui->CH1_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[0].threshold3 = ui->CH1_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[1].TName,ui->CH2_name->text().toLatin1().data(),ui->CH2_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[1].Switch_Bool = ui->CheckBox2->isChecked();
    ReagentSrtipQRcode.ch_data[1].threshold1 = ui->CH2_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[1].threshold2 = ui->CH2_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[1].threshold3 = ui->CH2_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[2].TName,ui->CH3_name->text().toLatin1().data(),ui->CH3_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[2].Switch_Bool = ui->CheckBox3->isChecked();
    ReagentSrtipQRcode.ch_data[2].threshold1 = ui->CH3_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[2].threshold2 = ui->CH3_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[2].threshold3 = ui->CH3_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[3].TName,ui->CH4_name->text().toLatin1().data(),ui->CH4_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[3].Switch_Bool = ui->CheckBox4->isChecked();
    ReagentSrtipQRcode.ch_data[3].threshold1 = ui->CH4_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[3].threshold2 = ui->CH4_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[3].threshold3 = ui->CH4_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[4].TName,ui->CH5_name->text().toLatin1().data(),ui->CH5_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[4].Switch_Bool = ui->CheckBox5->isChecked();
    ReagentSrtipQRcode.ch_data[4].threshold1 = ui->CH5_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[4].threshold2 = ui->CH5_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[4].threshold3 = ui->CH5_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[5].TName,ui->CH6_name->text().toLatin1().data(),ui->CH6_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[5].Switch_Bool = ui->CheckBox6->isChecked();
    ReagentSrtipQRcode.ch_data[5].threshold1 = ui->CH6_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[5].threshold2 = ui->CH6_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[5].threshold3 = ui->CH6_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[6].TName,ui->CH7_name->text().toLatin1().data(),ui->CH7_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[6].Switch_Bool = ui->CheckBox7->isChecked();
    ReagentSrtipQRcode.ch_data[6].threshold1 = ui->CH7_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[6].threshold2 = ui->CH7_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[6].threshold3 = ui->CH7_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[7].TName,ui->CH8_name->text().toLatin1().data(),ui->CH8_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[7].Switch_Bool = ui->CheckBox8->isChecked();
    ReagentSrtipQRcode.ch_data[7].threshold1 = ui->CH8_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[7].threshold2 = ui->CH8_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[7].threshold3 = ui->CH8_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[8].TName,ui->CH9_name->text().toLatin1().data(),ui->CH9_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[8].Switch_Bool = ui->CheckBox9->isChecked();
    ReagentSrtipQRcode.ch_data[8].threshold1 = ui->CH9_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[8].threshold2 = ui->CH9_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[8].threshold3 = ui->CH9_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[9].TName,ui->CH10_name->text().toLatin1().data(),ui->CH10_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[9].Switch_Bool = ui->CheckBox10->isChecked();
    ReagentSrtipQRcode.ch_data[9].threshold1 = ui->CH10_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[9].threshold2 = ui->CH10_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[9].threshold3 = ui->CH10_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[10].TName,ui->CH11_name->text().toLatin1().data(),ui->CH11_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[10].Switch_Bool = ui->CheckBox11->isChecked();
    ReagentSrtipQRcode.ch_data[10].threshold1 = ui->CH11_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[10].threshold2 = ui->CH11_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[10].threshold3 = ui->CH11_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[11].TName,ui->CH12_name->text().toLatin1().data(),ui->CH12_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[11].Switch_Bool = ui->CheckBox12->isChecked();
    ReagentSrtipQRcode.ch_data[11].threshold1 = ui->CH12_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[11].threshold2 = ui->CH12_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[11].threshold3 = ui->CH12_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[12].TName,ui->CH13_name->text().toLatin1().data(),ui->CH13_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[12].Switch_Bool = ui->CheckBox13->isChecked();
    ReagentSrtipQRcode.ch_data[12].threshold1 = ui->CH13_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[12].threshold2 = ui->CH13_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[12].threshold3 = ui->CH13_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[13].TName,ui->CH14_name->text().toLatin1().data(),ui->CH14_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[13].Switch_Bool = ui->CheckBox14->isChecked();
    ReagentSrtipQRcode.ch_data[13].threshold1 = ui->CH14_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[13].threshold2 = ui->CH14_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[13].threshold3 = ui->CH14_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[14].TName,ui->CH15_name->text().toLatin1().data(),ui->CH15_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[14].Switch_Bool = ui->CheckBox15->isChecked();
    ReagentSrtipQRcode.ch_data[14].threshold1 = ui->CH15_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[14].threshold2 = ui->CH15_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[14].threshold3 = ui->CH15_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[15].TName,ui->CH16_name->text().toLatin1().data(),ui->CH16_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[15].Switch_Bool = ui->CheckBox16->isChecked();
    ReagentSrtipQRcode.ch_data[15].threshold1 = ui->CH16_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[15].threshold2 = ui->CH16_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[15].threshold3 = ui->CH16_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[16].TName,ui->CH17_name->text().toLatin1().data(),ui->CH17_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[16].Switch_Bool = ui->CheckBox17->isChecked();
    ReagentSrtipQRcode.ch_data[16].threshold1 = ui->CH17_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[16].threshold2 = ui->CH17_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[16].threshold3 = ui->CH17_threshold3->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[17].TName,ui->CH18_name->text().toLatin1().data(),ui->CH18_name->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[17].Switch_Bool = ui->CheckBox18->isChecked();
    ReagentSrtipQRcode.ch_data[17].threshold1 = ui->CH18_threshold1->text().toFloat();
    ReagentSrtipQRcode.ch_data[17].threshold2 = ui->CH18_threshold2->text().toFloat();
    ReagentSrtipQRcode.ch_data[17].threshold3 = ui->CH18_threshold3->text().toFloat();

    length = sizeof(QRCODE_HEAD_STRUCT) - 2 + 18 * sizeof(QRCODE_SINGLE_LINE);
    ReagentSrtipQRcode.head.crc = CRC16_Calculate((uint8 *)&ReagentSrtipQRcode.head.Model, length,
                                         CRC_INITIAL_REMAINDER,CRC_FINAL_XOR_VALUE);
    QR = QRcode_encodeData(length + 2, (const unsigned char *)&ReagentSrtipQRcode, 2, QR_ECLEVEL_Q);

    quint16 scale_x = ui->QRlabel_C100->width()/QR->width;

    /*6.可能会出现余数的情况，此中方法为避免出现QR的宽度大于屏幕显示*/
    while((QR->width)*scale_x > ui->QRlabel_C100->width())
    {
        scale_x--;
    }

    if(QRPixmap!=0)
    {
        delete QRPixmap;
    }
    QRPixmap = new QPixmap((QR->width)*scale_x,(QR->width)*scale_x);

    QPainter Painter(QRPixmap);

    QColor background(Qt::white);
    Painter.setBrush(background);
    Painter.setPen(Qt::NoPen);
    Painter.drawRect(0, 0, QRPixmap->width(), QRPixmap->height());
    QColor foreground(Qt::black);
    Painter.setBrush(foreground);

    for( qint32 y = 0; y < QR->width; y ++)
    {
        for(qint32 x = 0; x < QR->width; x++)
        {
            unsigned char b = QR->data[y * QR->width + x];
            if(b & 0x01)
            {
                QRectF r(x * scale_x, y * scale_x, scale_x, scale_x);
                Painter.drawRects(&r, 1);
            }
        }
    }

    ui->QRlabel_C100->setPixmap(*QRPixmap);
    ui->QRlabel_C100->setAlignment(Qt::AlignCenter);
    ui->QRlabel_C100->setVisible(true);
}

void MainWindow::on_Create_Image_pushButton_clicked()
{
#define WHITEEDGE 20
    if(QRPixmap == NULL)
    {
        QMessageBox::warning(this,tr("警告"),tr("没有图片数据"));
        return;
    }
    QString dir = QFileDialog::getSaveFileName(this,
                                               tr("文件保存"),
                                               tr("/%1").arg(ui->ProductType_Name ->text()),
                                               tr("(*.png)")
                                                     );
    QPixmap SavePixmap(QRPixmap->width()+WHITEEDGE,QRPixmap->width()+WHITEEDGE);
    SavePixmap.fill(Qt::white);

    QPainter Painter(&SavePixmap);

    QColor background(Qt::white);
    Painter.setBrush(background);
    Painter.setPen(Qt::SolidLine);
    Painter.setFont(this->font());
   // Painter.drawRect(0, 0, SavePixmap.width(), SavePixmap.height());

    Painter.drawPixmap(WHITEEDGE/2,WHITEEDGE/2,QRPixmap->width(),QRPixmap->width(),*QRPixmap);
   // Painter.drawText(WHITEEDGE/2,QRPixmap->width()+WHITEEDGE+15,ui->ProductType_lineEdit->text());

    if(dir.isEmpty())
    {

    }
    else
    {
        SavePixmap.save(dir);
    }
    QRcode_Information_C100();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/* S100二维码 */
void MainWindow::on_Generate_pushButton_S_clicked()
{
    /* 0.清空结构体数据 */
    memset((uint8 *)&ReagentSrtipQRcode, 0, sizeof(ReagentSrtipQRcode));

    uint16 length = 0;
    uint8 stripNum = 0;

    /**********************************************************************/
    /* 1.数据头数据导入 */
    memcpy(ReagentSrtipQRcode.head.name, ui->ProductType_Name_S->text().toLatin1().data(), ui->ProductType_Name_S->text().toLatin1().length());
    memcpy(ReagentSrtipQRcode.head.SN, ui->ProductSN_S->text().toLatin1().data(), ui->ProductSN_S->text().toLatin1().length());
    ReagentSrtipQRcode.head.time = ui->time_S->text().toInt();
    ReagentSrtipQRcode.head.midC = ui->Center_LineC_S->text().toInt();
    ReagentSrtipQRcode.head.distC_T = ui->T1_Ccenter_S->text().toInt();
    ReagentSrtipQRcode.head.distC_Base1 = ui->base_CAndEdge_S->text().toInt();
    ReagentSrtipQRcode.head.distC_Base2 = ui->base_CAndT1_1_S->text().toInt();
    ReagentSrtipQRcode.head.distC_Base3 = ui->base_CAndT1_2_S->text().toInt();
    ReagentSrtipQRcode.head.distC_Base4 = ui->base_TAndEdge_S->text().toInt();
    stripNum = ui->ProductNum_S->text().toInt();
    ReagentSrtipQRcode.head.stripNum = stripNum;
    ReagentSrtipQRcode.head.searchHalfRadius_C = ui->SearchHalfRadius_C_S->text().toInt();
    ReagentSrtipQRcode.head.searchHalfRadius_T = ui->SearchHalfRadius_T_S->text().toInt();
    ReagentSrtipQRcode.head.areaC_HalfRadius = ui->AreaC_HalfRadius_S->text().toInt();
    ReagentSrtipQRcode.head.areaT_HalfRadius = ui->AreaT_HalfRadius_S->text().toInt();
    ReagentSrtipQRcode.head.winSize = ui->WinSize_S->text().toInt();
    ReagentSrtipQRcode.head.limitEnabled = ui->LimitEnabled_S->text().toInt();
    ReagentSrtipQRcode.head.C_stepSize = ui->C_StepSize_S->text().toInt();
    ReagentSrtipQRcode.head.C_magnitude = ui->C_Magnitude_S->text().toInt();
    ReagentSrtipQRcode.head.C_MIN = ui->C_Min_S->text().toInt();
    ReagentSrtipQRcode.head.Model = 3;

    /*3.2名称及阈值*/
    memcpy(ReagentSrtipQRcode.ch_data[0].TName,ui->CH1_name_S->text().toLatin1().data(),ui->CH1_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[0].Switch_Bool = ui->CheckBox1_S->isChecked();
    ReagentSrtipQRcode.ch_data[0].threshold1 = ui->CH1_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[0].threshold2 = ui->CH1_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[0].threshold3 = ui->CH1_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[1].TName,ui->CH2_name_S->text().toLatin1().data(),ui->CH2_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[1].Switch_Bool = ui->CheckBox2_S->isChecked();
    ReagentSrtipQRcode.ch_data[1].threshold1 = ui->CH2_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[1].threshold2 = ui->CH2_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[1].threshold3 = ui->CH2_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[2].TName,ui->CH3_name_S->text().toLatin1().data(),ui->CH3_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[2].Switch_Bool = ui->CheckBox3_S->isChecked();
    ReagentSrtipQRcode.ch_data[2].threshold1 = ui->CH3_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[2].threshold2 = ui->CH3_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[2].threshold3 = ui->CH3_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[3].TName,ui->CH4_name_S->text().toLatin1().data(),ui->CH4_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[3].Switch_Bool = ui->CheckBox4_S->isChecked();
    ReagentSrtipQRcode.ch_data[3].threshold1 = ui->CH4_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[3].threshold2 = ui->CH4_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[3].threshold3 = ui->CH4_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[4].TName,ui->CH5_name_S->text().toLatin1().data(),ui->CH5_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[4].Switch_Bool = ui->CheckBox5_S->isChecked();
    ReagentSrtipQRcode.ch_data[4].threshold1 = ui->CH5_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[4].threshold2 = ui->CH5_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[4].threshold3 = ui->CH5_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[5].TName,ui->CH6_name_S->text().toLatin1().data(),ui->CH6_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[5].Switch_Bool = ui->CheckBox6_S->isChecked();
    ReagentSrtipQRcode.ch_data[5].threshold1 = ui->CH6_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[5].threshold2 = ui->CH6_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[5].threshold3 = ui->CH6_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[6].TName,ui->CH7_name_S->text().toLatin1().data(),ui->CH7_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[6].Switch_Bool = ui->CheckBox7_S->isChecked();
    ReagentSrtipQRcode.ch_data[6].threshold1 = ui->CH7_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[6].threshold2 = ui->CH7_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[6].threshold3 = ui->CH7_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[7].TName,ui->CH8_name_S->text().toLatin1().data(),ui->CH8_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[7].Switch_Bool = ui->CheckBox8_S->isChecked();
    ReagentSrtipQRcode.ch_data[7].threshold1 = ui->CH8_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[7].threshold2 = ui->CH8_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[7].threshold3 = ui->CH8_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[8].TName,ui->CH9_name_S->text().toLatin1().data(),ui->CH9_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[8].Switch_Bool = ui->CheckBox9_S->isChecked();
    ReagentSrtipQRcode.ch_data[8].threshold1 = ui->CH9_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[8].threshold2 = ui->CH9_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[8].threshold3 = ui->CH9_threshold3_S->text().toFloat();
    memcpy(ReagentSrtipQRcode.ch_data[9].TName,ui->CH10_name_S->text().toLatin1().data(),ui->CH10_name_S->text().toLatin1().length());
    ReagentSrtipQRcode.ch_data[9].Switch_Bool = ui->CheckBox10_S->isChecked();
    ReagentSrtipQRcode.ch_data[9].threshold1 = ui->CH10_threshold1_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[9].threshold2 = ui->CH10_threshold2_S->text().toFloat();
    ReagentSrtipQRcode.ch_data[9].threshold3 = ui->CH10_threshold3_S->text().toFloat();

    length = sizeof(QRCODE_HEAD_STRUCT) - 2 + 10 * sizeof(QRCODE_SINGLE_LINE);
    ReagentSrtipQRcode.head.crc = CRC16_Calculate((uint8 *)&ReagentSrtipQRcode.head.Model, length,
                                         CRC_INITIAL_REMAINDER,CRC_FINAL_XOR_VALUE);
    QR = QRcode_encodeData(length + 2, (const unsigned char *)&ReagentSrtipQRcode, 2, QR_ECLEVEL_Q);

    quint16 scale_x = ui->QRlabel_S100->width()/QR->width;

    /*6.可能会出现余数的情况，此中方法为避免出现QR的宽度大于屏幕显示*/
    while((QR->width)*scale_x > ui->QRlabel_S100->width())
    {
        scale_x--;
    }

    if(QRPixmap!=0)
    {
        delete QRPixmap;
    }
    QRPixmap = new QPixmap((QR->width)*scale_x,(QR->width)*scale_x);

    QPainter Painter(QRPixmap);

    QColor background(Qt::white);
    Painter.setBrush(background);
    Painter.setPen(Qt::NoPen);
    Painter.drawRect(0, 0, QRPixmap->width(), QRPixmap->height());
    QColor foreground(Qt::black);
    Painter.setBrush(foreground);

    for( qint32 y = 0; y < QR->width; y ++)
    {
        for(qint32 x = 0; x < QR->width; x++)
        {
            unsigned char b = QR->data[y * QR->width + x];
            if(b & 0x01)
            {
                QRectF r(x * scale_x, y * scale_x, scale_x, scale_x);
                Painter.drawRects(&r, 1);
            }
        }
    }

    ui->QRlabel_S100->setPixmap(*QRPixmap);
    ui->QRlabel_S100->setAlignment(Qt::AlignCenter);
    ui->QRlabel_S100->setVisible(true);
}

void MainWindow::on_Create_Image_pushButton_S_clicked()
{
#define WHITEEDGE 20
    if(QRPixmap == NULL)
    {
        QMessageBox::warning(this,tr("警告"),tr("没有图片数据"));
        return;
    }
    QString dir = QFileDialog::getSaveFileName(this,
                                               tr("文件保存"),
                                               tr("/%1").arg(ui->ProductType_Name ->text()),
                                               tr("(*.png)")
                                                     );
    QPixmap SavePixmap(QRPixmap->width()+WHITEEDGE,QRPixmap->width()+WHITEEDGE);
    SavePixmap.fill(Qt::white);

    QPainter Painter(&SavePixmap);

    QColor background(Qt::white);
    Painter.setBrush(background);
    Painter.setPen(Qt::SolidLine);
    Painter.setFont(this->font());
   // Painter.drawRect(0, 0, SavePixmap.width(), SavePixmap.height());

    Painter.drawPixmap(WHITEEDGE/2,WHITEEDGE/2,QRPixmap->width(),QRPixmap->width(),*QRPixmap);
   // Painter.drawText(WHITEEDGE/2,QRPixmap->width()+WHITEEDGE+15,ui->ProductType_lineEdit->text());

    if(dir.isEmpty())
    {

    }
    else
    {
        SavePixmap.save(dir);
    }

    QRcode_Information_S100();
}

void MainWindow::QRcode_Information_C100(void)
{
    quint8 i;
    QString sFilePath = QDir::currentPath();
    sFilePath += "\\C100二维码信息.txt";
    QFile file(sFilePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"),QMessageBox::Ok);
        return;
    }
    else
    {
        QTextStream textStream(&file);
        QString str = "测试名称：";
        str += "\t";
        str += "\t";
        str += ui->ProductType_Name->text();
        str += "\tC100";

        str += "\n";
        str += "生产批号：";
        str += "\t";
        str += "\t";
        str += ui->ProductSN->text();

        str += "\n";
        str += "反应时间：";
        str += "\t";
        str += "\t";
        str += ui->time->text();
        str += "\t分钟";

        str += "\n";
        str += "C线中心位置：";
        str += "\t";
        str += "\t";
        str += ui->Center_LineC->text();
        str += "\n";
        str += "C线中心到T线中心距离：";
        str += "\t";
        str += ui->T1_Ccenter->text();

        str += "\n";
        str += "C线中心到C线边界距离：";
        str += "\t";
        str += ui->base_CAndEdge->text();

        str += "\n";
        str += "C线中心到T线1距离：";
        str += "\t";
        str += ui->base_CAndT1_1->text();

        str += "\n";
        str += "C线中心到T线2距离：";
        str += "\t";
        str += ui->base_CAndT1_2->text();

        str += "\n";
        str += "T线中心到T线边界距离：";
        str += "\t";
        str += ui->base_TAndEdge->text();

        str += "\n";
        str += "试剂卡条数：";
        str += "\t";
        str += "\t";
        str += ui->ProductNum->text();

        str += "\n";
        str += "C线的搜索范围：";
        str += "\t";
        str += "\t";
        str += ui->SearchHalfRadius_C->text();

        str += "\n";
        str += "T线的搜索范围：";
        str += "\t";
        str += "\t";
        str += ui->SearchHalfRadius_T->text();

        str += "\n";
        str += "C线的计算半径：";
        str += "\t";
        str += "\t";
        str += ui->AreaC_HalfRadius->text();

        str += "\n";
        str += "T线的计算半径：";
        str += "\t";
        str += "\t";
        str += ui->AreaT_HalfRadius->text();

        str += "\n";
        str += "平均窗口：";
        str += "\t";
        str += "\t";
        str += ui->WinSize->text();

        str += "\n";
        str += "使能约束：";
        str += "\t";
        str += "\t";
        str += ui->LimitEnabled->text();

        str += "\n";
        str += "步长：";
        str += "\t";
        str += "\t";
        str += "\t";
        str += ui->C_StepSize->text();

        str += "\n";
        str += "幅度值：";
        str += "\t";
        str += "\t";
        str += ui->C_Magnitude->text();

        str += "\n";
        str += "C线最小值：";
        str += "\t";
        str += "\t";
        str += ui->C_Min->text();

        str += "\n";
        str += "\n";
        str += "\n";
        str += "试剂";
        str += "\t";
        for(i = 1;i < 18;i++)
        {
          str += "试剂";
          str +=  QString::number(i);
          str += "\t";
        }

        str += "\n";
        str += "\n";
        str += "名称：";
        str += "\t";
        str +=  ui->CH1_name->text();
        str += "\t";
        str +=  ui->CH2_name->text();
        str += "\t";
        str +=  ui->CH3_name->text();
        str += "\t";
        str +=  ui->CH4_name->text();
        str += "\t";
        str +=  ui->CH5_name->text();
        str += "\t";
        str +=  ui->CH6_name->text();
        str += "\t";
        str +=  ui->CH7_name->text();
        str += "\t";
        str +=  ui->CH8_name->text();
        str += "\t";
        str +=  ui->CH9_name->text();
        str += "\t";
        str +=  ui->CH10_name->text();
        str += "\t";
        str +=  ui->CH11_name->text();
        str += "\t";
        str +=  ui->CH12_name->text();
        str += "\t";
        str +=  ui->CH13_name->text();
        str += "\t";
        str +=  ui->CH14_name->text();
        str += "\t";
        str +=  ui->CH15_name->text();
        str += "\t";
        str +=  ui->CH16_name->text();
        str += "\t";
        str +=  ui->CH17_name->text();

        str += "\t";
        str += "\n";
        str += "\n";
        str += "阈值1：";
        str += "\t";
        str +=  ui->CH1_threshold1->text();
        str += "\t";
        str +=  ui->CH2_threshold1->text();
        str += "\t";
        str +=  ui->CH3_threshold1->text();
        str += "\t";
        str +=  ui->CH4_threshold1->text();
        str += "\t";
        str +=  ui->CH5_threshold1->text();
        str += "\t";
        str +=  ui->CH6_threshold1->text();
        str += "\t";
        str +=  ui->CH7_threshold1->text();
        str += "\t";
        str +=  ui->CH8_threshold1->text();
        str += "\t";
        str +=  ui->CH9_threshold1->text();
        str += "\t";
        str +=  ui->CH10_threshold1->text();
        str += "\t";
        str +=  ui->CH11_threshold1->text();
        str += "\t";
        str +=  ui->CH12_threshold1->text();
        str += "\t";
        str +=  ui->CH13_threshold1->text();
        str += "\t";
        str +=  ui->CH14_threshold1->text();
        str += "\t";
        str +=  ui->CH15_threshold1->text();
        str += "\t";
        str +=  ui->CH16_threshold1->text();
        str += "\t";
        str +=  ui->CH17_threshold1->text();

        str += "\t";
        str += "\n";
        str += "\n";
        str += "阈值2：";
        str += "\t";
        str +=  ui->CH1_threshold2->text();
        str += "\t";
        str +=  ui->CH2_threshold2->text();
        str += "\t";
        str +=  ui->CH3_threshold2->text();
        str += "\t";
        str +=  ui->CH4_threshold2->text();
        str += "\t";
        str +=  ui->CH5_threshold2->text();
        str += "\t";
        str +=  ui->CH6_threshold2->text();
        str += "\t";
        str +=  ui->CH7_threshold2->text();
        str += "\t";
        str +=  ui->CH8_threshold2->text();
        str += "\t";
        str +=  ui->CH9_threshold2->text();
        str += "\t";
        str +=  ui->CH10_threshold2->text();
        str += "\t";
        str +=  ui->CH11_threshold2->text();
        str += "\t";
        str +=  ui->CH12_threshold2->text();
        str += "\t";
        str +=  ui->CH13_threshold2->text();
        str += "\t";
        str +=  ui->CH14_threshold2->text();
        str += "\t";
        str +=  ui->CH15_threshold2->text();
        str += "\t";
        str +=  ui->CH16_threshold2->text();
        str += "\t";
        str +=  ui->CH17_threshold2->text();

        str += "\t";
        str += "\n";
        str += "\n";
        str += "阈值3：";
        str += "\t";
        str +=  ui->CH1_threshold3->text();
        str += "\t";
        str +=  ui->CH2_threshold3->text();
        str += "\t";
        str +=  ui->CH3_threshold3->text();
        str += "\t";
        str +=  ui->CH4_threshold3->text();
        str += "\t";
        str +=  ui->CH5_threshold3->text();
        str += "\t";
        str +=  ui->CH6_threshold3->text();
        str += "\t";
        str +=  ui->CH7_threshold3->text();
        str += "\t";
        str +=  ui->CH8_threshold3->text();
        str += "\t";
        str +=  ui->CH9_threshold3->text();
        str += "\t";
        str +=  ui->CH10_threshold3->text();
        str += "\t";
        str +=  ui->CH11_threshold3->text();
        str += "\t";
        str +=  ui->CH12_threshold3->text();
        str += "\t";
        str +=  ui->CH13_threshold3->text();
        str += "\t";
        str +=  ui->CH14_threshold3->text();
        str += "\t";
        str +=  ui->CH15_threshold3->text();
        str += "\t";
        str +=  ui->CH16_threshold3->text();
        str += "\t";
        str +=  ui->CH17_threshold3->text();

        str += "\t";
        str += "\n";
        str += "\n";
        str += "是否使用：";
        str += QString::number(ui->CheckBox1->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox2->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox3->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox4->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox5->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox6->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox7->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox8->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox9->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox10->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox11->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox12->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox13->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox14->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox15->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox16->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox17->isChecked());
        str += "\n";

        textStream<<str;
    }
//    QMessageBox::information(this,"保存文件","C100二维码信息保存成功",QMessageBox::Ok);
    file.close();
}

void MainWindow::QRcode_Information_S100(void)
{
    quint8 i;
    QString sFilePath = QDir::currentPath();
    sFilePath += "\\S100二维码信息.txt";
    QFile file(sFilePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"),QMessageBox::Ok);
        return;
    }
    else
    {
        QTextStream textStream(&file);
        QString str = "测试名称：";
        str += "\t";
        str += "\t";
        str += ui->ProductType_Name_S->text();
        str += "\tS100";

        str += "\n";
        str += "生产批号：";
        str += "\t";
        str += "\t";
        str += ui->ProductSN_S->text();

        str += "\n";
        str += "反应时间：";
        str += "\t";
        str += "\t";
        str += ui->time_S->text();
        str += "\t分钟";

        str += "\n";
        str += "C线中心位置：";
        str += "\t";
        str += "\t";
        str += ui->Center_LineC_S->text();
        str += "\n";
        str += "C线中心到T线中心距离：";
        str += "\t";
        str += ui->T1_Ccenter_S->text();

        str += "\n";
        str += "C线中心到C线边界距离：";
        str += "\t";
        str += ui->base_CAndEdge_S->text();

        str += "\n";
        str += "C线中心到T线1距离：";
        str += "\t";
        str += ui->base_CAndT1_1_S->text();

        str += "\n";
        str += "C线中心到T线2距离：";
        str += "\t";
        str += ui->base_CAndT1_2_S->text();

        str += "\n";
        str += "T线中心到T线边界距离：";
        str += "\t";
        str += ui->base_TAndEdge_S->text();

        str += "\n";
        str += "试剂卡条数：";
        str += "\t";
        str += "\t";
        str += ui->ProductNum_S->text();

        str += "\n";
        str += "C线的搜索范围：";
        str += "\t";
        str += "\t";
        str += ui->SearchHalfRadius_C_S->text();

        str += "\n";
        str += "T线的搜索范围：";
        str += "\t";
        str += "\t";
        str += ui->SearchHalfRadius_T_S->text();

        str += "\n";
        str += "C线的计算半径：";
        str += "\t";
        str += "\t";
        str += ui->AreaC_HalfRadius_S->text();

        str += "\n";
        str += "T线的计算半径：";
        str += "\t";
        str += "\t";
        str += ui->AreaT_HalfRadius_S->text();

        str += "\n";
        str += "平均窗口：";
        str += "\t";
        str += "\t";
        str += ui->WinSize_S->text();

        str += "\n";
        str += "使能约束：";
        str += "\t";
        str += "\t";
        str += ui->LimitEnabled_S->text();

        str += "\n";
        str += "步长：";
        str += "\t";
        str += "\t";
        str += "\t";
        str += ui->C_StepSize_S->text();

        str += "\n";
        str += "幅度值：";
        str += "\t";
        str += "\t";
        str += ui->C_Magnitude_S->text();

        str += "\n";
        str += "C线最小值：";
        str += "\t";
        str += "\t";
        str += ui->C_Min_S->text();

        str += "\n";
        str += "\n";
        str += "\n";
        str += "试剂";
        str += "\t";
        for(i = 1;i <9;i++)
        {
          str += "试剂";
          str +=  QString::number(i);
          str += "\t";
        }

        str += "\n";
        str += "\n";
        str += "名称：";
        str += "\t";
        str +=  ui->CH1_name_S->text();
        str += "\t";
        str +=  ui->CH2_name_S->text();
        str += "\t";
        str +=  ui->CH3_name_S->text();
        str += "\t";
        str +=  ui->CH4_name_S->text();
        str += "\t";
        str +=  ui->CH5_name_S->text();
        str += "\t";
        str +=  ui->CH6_name_S->text();
        str += "\t";
        str +=  ui->CH7_name_S->text();
        str += "\t";
        str +=  ui->CH8_name_S->text();
        str += "\t";
        str += "\n";
        str += "\n";
        str += "阈值1：";
        str += "\t";
        str +=  ui->CH1_threshold1_S->text();
        str += "\t";
        str +=  ui->CH2_threshold1_S->text();
        str += "\t";
        str +=  ui->CH3_threshold1_S->text();
        str += "\t";
        str +=  ui->CH4_threshold1_S->text();
        str += "\t";
        str +=  ui->CH5_threshold1_S->text();
        str += "\t";
        str +=  ui->CH6_threshold1_S->text();
        str += "\t";
        str +=  ui->CH7_threshold1_S->text();
        str += "\t";
        str +=  ui->CH8_threshold1_S->text();
        str += "\t";
        str += "\n";
        str += "\n";
        str += "阈值2：";
        str += "\t";
        str +=  ui->CH1_threshold2_S->text();
        str += "\t";
        str +=  ui->CH2_threshold2_S->text();
        str += "\t";
        str +=  ui->CH3_threshold2_S->text();
        str += "\t";
        str +=  ui->CH4_threshold2_S->text();
        str += "\t";
        str +=  ui->CH5_threshold2_S->text();
        str += "\t";
        str +=  ui->CH6_threshold2_S->text();
        str += "\t";
        str +=  ui->CH7_threshold2_S->text();
        str += "\t";
        str +=  ui->CH8_threshold2_S->text();
        str += "\t";
        str += "\n";
        str += "\n";
        str += "阈值3：";
        str += "\t";
        str +=  ui->CH1_threshold3_S->text();
        str += "\t";
        str +=  ui->CH2_threshold3_S->text();
        str += "\t";
        str +=  ui->CH3_threshold3_S->text();
        str += "\t";
        str +=  ui->CH4_threshold3_S->text();
        str += "\t";
        str +=  ui->CH5_threshold3_S->text();
        str += "\t";
        str +=  ui->CH6_threshold3_S->text();
        str += "\t";
        str +=  ui->CH7_threshold3_S->text();
        str += "\t";
        str +=  ui->CH8_threshold3_S->text();
        str += "\t";
        str += "\n";
        str += "\n";
        str += "是否使用：";
        str += QString::number(ui->CheckBox1_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox2_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox3_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox4_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox5_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox6_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox7_S->isChecked());
        str += "\t";
        str += QString::number(ui->CheckBox8_S->isChecked());
        str += "\t";
        str += "\n";

        textStream<<str;
    }
//    QMessageBox::information(this,"保存文件","S100二维码信息保存成功",QMessageBox::Ok);
    file.close();
}

void MainWindow::on_Password_Bntton_clicked()
{
    Password_Information->Clear_Password();
    if(Password_Information->exec() == 1)
    {
        ui->groupBox->setEnabled(true);
        ui->groupBox_2->setEnabled(true);
    }
    else
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
    }
}

void MainWindow::on_Import_Data_C100_clicked()
{
    QString sFilePath = QDir::currentPath();
    sFilePath += "\\C100二维码信息.txt";
    QFile file(sFilePath);
    uint8 Count = 0,i = 0,Data_Count = 0,Plus_Count = 0;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    else
    {

        while(!file.atEnd())
        {
            Count += 1;
            QByteArray line = file.readLine();
            QString str(line);
            QString Data_str;
            qDebug()<<str<<endl;
            switch(Count)
            {
            case 1:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 19;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->ProductType_Name->setText(Data_str);
                        break;
                    }
                }
                break;

            case 2:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->ProductSN->setText(Data_str);
                        break;
                    }
                }
                break;

            case 3:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->time->setText(Data_str);
                        break;
                    }
                }
                break;

            case 4:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->Center_LineC->setText(Data_str);
                        break;
                    }
                }
                break;

            case 5:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->T1_Ccenter->setText(Data_str);
                        break;
                    }
                }
                break;

            case 6:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_CAndEdge->setText(Data_str);
                        break;
                    }
                }
                break;

            case 7:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_CAndT1_1->setText(Data_str);
                        break;
                    }
                }
                break;

            case 8:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_CAndT1_2->setText(Data_str);
                        break;
                    }
                }
                break;

            case 9:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_TAndEdge->setText(Data_str);
                        break;
                    }
                }
                break;

            case 10:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->ProductNum->setText(Data_str);
                        break;
                    }
                }
                break;

            case 11:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->SearchHalfRadius_C->setText(Data_str);
                        break;
                    }
                }
                break;

            case 12:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->SearchHalfRadius_T->setText(Data_str);
                        break;
                    }
                }
                break;

            case 13:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->AreaC_HalfRadius->setText(Data_str);
                        break;
                    }
                }
                break;

            case 14:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->AreaT_HalfRadius->setText(Data_str);
                        break;
                    }
                }
                break;

            case 15:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->WinSize->setText(Data_str);
                        break;
                    }
                }
                break;

            case 16:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->LimitEnabled_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 17:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->C_StepSize->setText(Data_str);
                        break;
                    }
                }
                break;

            case 18:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->C_Magnitude->setText(Data_str);
                        break;
                    }
                }
                break;

            case 19:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->C_Min->setText(Data_str);
                        break;
                    }
                }
                break;

            case 24:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_name->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_name->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_name->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_name->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_name->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_name->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_name->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_name->setText(Data_str);
                            break;

                        case 9:
                            ui->CH9_name->setText(Data_str);
                            break;

                        case 10:
                            ui->CH10_name->setText(Data_str);
                            break;

                        case 11:
                            ui->CH11_name->setText(Data_str);
                            break;

                        case 12:
                            ui->CH12_name->setText(Data_str);
                            break;

                        case 13:
                            ui->CH13_name->setText(Data_str);
                            break;

                        case 14:
                            ui->CH14_name->setText(Data_str);
                            break;

                        case 15:
                            ui->CH15_name->setText(Data_str);
                            break;

                        case 16:
                            ui->CH16_name->setText(Data_str);
                            break;
                        case 17:
                            ui->CH17_name->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 26:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_threshold1->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_threshold1->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_threshold1->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_threshold1->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_threshold1->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_threshold1->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_threshold1->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_threshold1->setText(Data_str);
                            break;

                        case 9:
                            ui->CH9_threshold1->setText(Data_str);
                            break;

                        case 10:
                            ui->CH10_threshold1->setText(Data_str);
                            break;

                        case 11:
                            ui->CH11_threshold1->setText(Data_str);
                            break;

                        case 12:
                            ui->CH12_threshold1->setText(Data_str);
                            break;

                        case 13:
                            ui->CH13_threshold1->setText(Data_str);
                            break;

                        case 14:
                            ui->CH14_threshold1->setText(Data_str);
                            break;

                        case 15:
                            ui->CH15_threshold1->setText(Data_str);
                            break;

                        case 16:
                            ui->CH16_threshold1->setText(Data_str);
                            break;

                        case 17:
                            ui->CH17_threshold1->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 28:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_threshold2->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_threshold2->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_threshold2->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_threshold2->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_threshold2->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_threshold2->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_threshold2->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_threshold2->setText(Data_str);
                            break;

                        case 9:
                            ui->CH9_threshold2->setText(Data_str);
                            break;

                        case 10:
                            ui->CH10_threshold2->setText(Data_str);
                            break;

                        case 11:
                            ui->CH11_threshold2->setText(Data_str);
                            break;

                        case 12:
                            ui->CH12_threshold2->setText(Data_str);
                            break;

                        case 13:
                            ui->CH13_threshold2->setText(Data_str);
                            break;

                        case 14:
                            ui->CH14_threshold2->setText(Data_str);
                            break;

                        case 15:
                            ui->CH15_threshold2->setText(Data_str);
                            break;

                        case 16:
                            ui->CH16_threshold2->setText(Data_str);
                            break;

                        case 17:
                            ui->CH17_threshold2->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 30:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_threshold3->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_threshold3->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_threshold3->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_threshold3->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_threshold3->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_threshold3->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_threshold3->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_threshold3->setText(Data_str);
                            break;

                        case 9:
                            ui->CH9_threshold3->setText(Data_str);
                            break;

                        case 10:
                            ui->CH10_threshold3->setText(Data_str);
                            break;

                        case 11:
                            ui->CH11_threshold3->setText(Data_str);
                            break;

                        case 12:
                            ui->CH12_threshold3->setText(Data_str);
                            break;

                        case 13:
                            ui->CH13_threshold3->setText(Data_str);
                            break;

                        case 14:
                            ui->CH14_threshold3->setText(Data_str);
                            break;

                        case 15:
                            ui->CH15_threshold3->setText(Data_str);
                            break;

                        case 16:
                            ui->CH16_threshold3->setText(Data_str);
                            break;

                        case 17:
                            ui->CH17_threshold3->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 32:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i+1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 2;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        bool ok;
                        int dec=Data_str.toInt(&ok,10);
                        switch(Plus_Count)
                        {
                        case 1:
                            (dec)? ui->CheckBox1->setChecked(true):ui->CheckBox1->setChecked(false);
                            break;

                        case 2:
                            (dec)? ui->CheckBox2->setChecked(true):ui->CheckBox2->setChecked(false);
                            break;

                        case 3:
                            (dec)? ui->CheckBox3->setChecked(true):ui->CheckBox3->setChecked(false);
                            break;

                        case 4:
                            (dec)? ui->CheckBox4->setChecked(true):ui->CheckBox4->setChecked(false);
                            break;

                        case 5:
                            (dec)? ui->CheckBox5->setChecked(true):ui->CheckBox5->setChecked(false);
                            break;

                        case 6:
                            (dec)? ui->CheckBox6->setChecked(true):ui->CheckBox6->setChecked(false);
                            break;

                        case 7:
                            (dec)? ui->CheckBox7->setChecked(true):ui->CheckBox7->setChecked(false);
                            break;

                        case 8:
                            (dec)?(ui->CheckBox8->setChecked(true)):(ui->CheckBox8->setChecked(false));
                            break;

                        case 9:
                            (dec)?(ui->CheckBox9->setChecked(true)):(ui->CheckBox9->setChecked(false));
                            break;

                        case 10:
                            (dec)?(ui->CheckBox10->setChecked(true)):(ui->CheckBox10->setChecked(false));
                            break;

                        case 11:
                            (dec)?(ui->CheckBox11->setChecked(true)):(ui->CheckBox11->setChecked(false));
                            break;

                        case 12:
                            (dec)?(ui->CheckBox12->setChecked(true)):(ui->CheckBox12->setChecked(false));
                            break;

                        case 13:
                            (dec)?(ui->CheckBox13->setChecked(true)):(ui->CheckBox13->setChecked(false));
                            break;

                        case 14:
                            (dec)?(ui->CheckBox14->setChecked(true)):(ui->CheckBox14->setChecked(false));
                            break;

                        case 15:
                            (dec)?(ui->CheckBox15->setChecked(true)):(ui->CheckBox15->setChecked(false));
                            break;

                        case 16:
                            (dec)?(ui->CheckBox16->setChecked(true)):(ui->CheckBox16->setChecked(false));
                            break;

                        case 17:
                            (dec)?(ui->CheckBox17->setChecked(true)):(ui->CheckBox17->setChecked(false));
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            default:
                break;
            }
        str.clear();
        }
    }
    on_Generate_pushButton_clicked();
}

void MainWindow::on_Import_Data_S100_clicked()
{
    QString sFilePath = QDir::currentPath();
    sFilePath += "\\S100二维码信息.txt";
    QFile file(sFilePath);
    uint8 Count = 0,i = 0,Data_Count = 0,Plus_Count = 0;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    else
    {

        while(!file.atEnd())
        {
            Count += 1;
            QByteArray line = file.readLine();
            QString str(line);
            QString Data_str;
            qDebug()<<str<<endl;
            switch(Count)
            {
            case 1:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 19;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->ProductType_Name_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 2:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->ProductSN_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 3:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->time_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 4:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->Center_LineC_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 5:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->T1_Ccenter_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 6:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_CAndEdge_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 7:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_CAndT1_1_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 8:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_CAndT1_2_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 9:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->base_TAndEdge_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 10:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->ProductNum_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 11:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->SearchHalfRadius_C_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 12:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->SearchHalfRadius_T_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 13:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->AreaC_HalfRadius_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 14:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->AreaT_HalfRadius_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 15:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->WinSize_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 16:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->LimitEnabled_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 17:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->C_StepSize_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 18:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 4;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->C_Magnitude_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 19:
                i = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        for(Data_Count = 0;Data_Count < 6;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }
                        ui->C_Min_S->setText(Data_str);
                        break;
                    }
                }
                break;

            case 24:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_name_S->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_name_S->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_name_S->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_name_S->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_name_S->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_name_S->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_name_S->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_name_S->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 26:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_threshold1_S->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_threshold1_S->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_threshold1_S->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_threshold1_S->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_threshold1_S->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_threshold1_S->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_threshold1_S->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_threshold1_S->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 28:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_threshold2_S->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_threshold2_S->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_threshold2_S->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_threshold2_S->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_threshold2_S->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_threshold2_S->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_threshold2_S->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_threshold2_S->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 30:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i-1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 8;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        switch(Plus_Count)
                        {
                        case 1:
                            ui->CH1_threshold3_S->setText(Data_str);
                            break;

                        case 2:
                            ui->CH2_threshold3_S->setText(Data_str);
                            break;

                        case 3:
                            ui->CH3_threshold3_S->setText(Data_str);
                            break;

                        case 4:
                            ui->CH4_threshold3_S->setText(Data_str);
                            break;

                        case 5:
                            ui->CH5_threshold3_S->setText(Data_str);
                            break;

                        case 6:
                            ui->CH6_threshold3_S->setText(Data_str);
                            break;

                        case 7:
                            ui->CH7_threshold3_S->setText(Data_str);
                            break;

                        case 8:
                            ui->CH8_threshold3_S->setText(Data_str);
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            case 32:
                i = 0;
                Plus_Count = 0;
                while(str[i++] !='\n')
                {
                    if((str[i] != '\t')  && (str[i+1] == '\t'))
                    {
                        Plus_Count += 1;
                        Data_str.clear();
                        for(Data_Count = 0;Data_Count < 2;Data_Count++)
                        {
                            if((str[i] != '\t')&&(str[i] != '\n'))
                            {
                                Data_str[Data_Count] = str[i++];
                            }
                            else
                            {
                                break;
                            }
                        }

                        bool ok;
                        int dec=Data_str.toInt(&ok,10);
                        switch(Plus_Count)
                        {
                        case 1:
                            (dec)?(ui->CheckBox1_S->setChecked(true)):(ui->CheckBox1_S->setChecked(false));
                            break;

                        case 2:
                            (dec)?(ui->CheckBox2_S->setChecked(true)):(ui->CheckBox2_S->setChecked(false));
                            break;

                        case 3:
                            (dec)?(ui->CheckBox3_S->setChecked(true)):(ui->CheckBox3_S->setChecked(false));
                            break;

                        case 4:
                            (dec)?(ui->CheckBox4_S->setChecked(true)):(ui->CheckBox4_S->setChecked(false));
                            break;

                        case 5:
                            (dec)?(ui->CheckBox5_S->setChecked(true)):(ui->CheckBox5_S->setChecked(false));
                            break;

                        case 6:
                            (dec)?(ui->CheckBox6_S->setChecked(true)):(ui->CheckBox6_S->setChecked(false));
                            break;

                        case 7:
                            (dec)?(ui->CheckBox7_S->setChecked(true)):(ui->CheckBox7_S->setChecked(false));
                            break;

                        case 8:
                            (dec)?(ui->CheckBox8_S->setChecked(true)):(ui->CheckBox8_S->setChecked(false));
                            break;

                        default:
                            break;
                        }
                    }
                }
                break;

            default:
                break;
            }
        str.clear();
        }
    }
    on_Generate_pushButton_S_clicked();
}

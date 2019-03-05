#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qrencode.h"
#include <QPixmap>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include "CRC16.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <password.h>


#define QRCODE_TEST_NAME_MAX 8

/******************************************************************************/
typedef struct {
    uint16 crc;
    uint8 Model;
    uint8 name[20];
    uint8 SN[10];
    uint8 time;
    uint8 midC;
    uint8 distC_T;
    uint8 distC_Base1;
    uint8 distC_Base2;
    uint8 distC_Base3;
    uint8 distC_Base4;
    uint8 stripNum;
    uint16 searchHalfRadius_C;
    uint16 searchHalfRadius_T;
    uint16 areaC_HalfRadius;
    uint16 areaT_HalfRadius;
    uint16 winSize;
    uint8 limitEnabled;
    uint8 Invalied;
    uint16 C_stepSize;
    uint16 C_magnitude;
    uint16 C_MIN;
} QRCODE_HEAD_STRUCT;

/******************************************************************************/
typedef struct {
    uint8 TName[QRCODE_TEST_NAME_MAX];
    uint8 Switch_Bool;
    float threshold1;
    float threshold2;
    float threshold3;
} QRCODE_SINGLE_LINE;

/******************************************************************************/
typedef struct {
    QRCODE_HEAD_STRUCT head;
    QRCODE_SINGLE_LINE ch_data[18];
} QRCODE_STRUCT;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init(void);
    void QRcode_Information_C100(void);
    void QRcode_Information_S100(void);

private slots:
    /* C100生成图片按钮  */
    void on_Generate_pushButton_clicked();

    void on_Create_Image_pushButton_clicked();

   /* 切换至S100按钮 */
    void on_pushButton_2_clicked();

    /* 切换至C100按钮 */
    void on_pushButton_clicked();

    /* S100生成图片按钮  */
    void on_Generate_pushButton_S_clicked();

    void on_Create_Image_pushButton_S_clicked();

    void on_Password_Bntton_clicked();

private:
    Password *Password_Information;
    Ui::MainWindow *ui;
    QPixmap *QRPixmap;
    QRcode *QR;
    QRCODE_STRUCT ReagentSrtipQRcode;
};

#endif // MAINWINDOW_H

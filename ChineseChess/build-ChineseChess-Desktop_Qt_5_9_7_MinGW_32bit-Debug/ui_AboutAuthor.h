/********************************************************************************
** Form generated from reading UI file 'AboutAuthor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTAUTHOR_H
#define UI_ABOUTAUTHOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutAuthor
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;
    QLabel *label_5;

    void setupUi(QDialog *AboutAuthor)
    {
        if (AboutAuthor->objectName().isEmpty())
            AboutAuthor->setObjectName(QStringLiteral("AboutAuthor"));
        AboutAuthor->resize(882, 491);
        AboutAuthor->setFocusPolicy(Qt::NoFocus);
        AboutAuthor->setAcceptDrops(false);
        AboutAuthor->setToolTipDuration(0);
        AboutAuthor->setLayoutDirection(Qt::RightToLeft);
        buttonBox = new QDialogButtonBox(AboutAuthor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(730, 450, 151, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(AboutAuthor);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 10, 861, 441));
        textBrowser->setStyleSheet(QString::fromUtf8("border-image: url(:/images/5abc.png);\n"
"font: 9pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        textBrowser->setOpenExternalLinks(true);
        label_5 = new QLabel(AboutAuthor);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 882, 491));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/background.jpg")));
        label_5->setScaledContents(true);
        label_5->raise();
        buttonBox->raise();
        textBrowser->raise();

        retranslateUi(AboutAuthor);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutAuthor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutAuthor, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutAuthor);
    } // setupUi

    void retranslateUi(QDialog *AboutAuthor)
    {
        AboutAuthor->setWindowTitle(QApplication::translate("AboutAuthor", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("AboutAuthor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\346\245\267\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\344\275\234\350\200\205:</span><span style=\" font-size:14pt; font-weight:600; font-style:italic;\">\351\231\210\345\205\264\346\263\242</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">E-mail:terrl"
                        "@foxmal.com </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Github:</span><a href=\"https://github.com/terrl\"><span style=\" font-size:16pt; text-decoration: underline; color:#0000ff;\">https://github.com/terrl</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\203\214\346\231\257\345\233\276\346\217\220\344\276\233\350\200\205\357\274\232\347\210\261\345\223\255\351\254\274\346\235\216\346\226\207</span></p>\n"
"<p s"
                        "tyle=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\257\264\346\230\216\357\274\232\346\255\244\351\241\271\347\233\256\344\270\272\344\270\252\344\272\272\346\257\225\350\256\276\351\241\271\347\233\256\357\274\214\347\216\260\345\234\250\350\256\270\345\244\232\345\260\217\346\270\270\346\210\217\351\203\275\345\270\246\346\234\211\345\225\206\344\270\232\346\200\247\350\264\250\357\274\214\345\271\277\345\221\212\343\200\201\345\274\271\347\252\227\345\275\261\345\223\215\346\270\270\346\210\217\344\275\223\351\252\214\357\274\214\345\233\240\346\255\244\350\207\252\345\267\261\345\274\200\345\217\221\344\272\206\346\255\244\344\270\255\345\233\275\350\261\241\346\243\213\357\274\214\344\273\205\344\276\233\345\250\261\344\271\220\343"
                        "\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\351\241\271\347\233\256\357\274\232\345\205\263\344\272\216\346\255\244\346\257\225\350\256\276\351\241\271\347\233\256\357\274\214\345\256\214\346\210\220release\347\211\210\346\234\254\345\220\216\344\274\232\345\234\250github\345\274\200\346\272\220\345\271\266\346\217\220\344\276\233release\347\211\210\346\234\254\344\270\213\350\275\275\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutAuthor: public Ui_AboutAuthor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTAUTHOR_H
